''' 
Updated log-parsing script. Now puts everything in easy-to-use dicts, which 
are all time-stamped with local time of receipt. Should be easier to use. 

Unfortunately, not compatible with old style scripts.

Copied a lot from here: https://github.com/aktaylor08/RosbagPandas/blob/master/rosbag_pandas.py

mwm
'''
from __future__ import print_function, division

import sys, os
import pickle
import numpy as np
import warnings


def strip_name(fname):
    if fname[-1] == '.':
        return fname[:-1]
    elif fname[-4:]=='.bag':
        return fname[:-4]
    elif fname[-7:]=='.pickle':
        return fname[:-7]
    else:
        return fname


def get_data(argv):
    # load data from a pickle file
    if len(argv) < 2:
        print('Must provide filename')
        return None

    fname0 = strip_name(argv[1])+'.pickle'

    print('Opening ', fname0)
    if not os.path.isfile(fname0):
        print('No such file <'+fname0+'>')
        print(' -> create the pickle first!')
        return None


    pickleFile = open(fname0, 'rb')
    [out,fname] = pickle.load(pickleFile)
    pickleFile.close()
    return out, fname


def get_base_fields(msg, prefix='', parse_header=True):
    '''function to get the full names of every message field in the message'''
    slots = msg.__slots__
    ret_val = []
    msg_types = dict()
    for i in slots:
        slot_msg = getattr(msg, i)
        if not parse_header and i == 'header':
            continue
        if hasattr(slot_msg, '__slots__'):
                (subs, type_map) = get_base_fields(
                    slot_msg, prefix=prefix + i + '.',
                    parse_header=parse_header,
                )

                for i in subs:
                    ret_val.append(i)
                for k, v in type_map.items():
                    msg_types[k] = v
        else:
            ret_val.append(prefix + i)
            msg_types[prefix + i] = slot_msg
    return (ret_val, msg_types)


def get_msg_info(yaml_info, topics, parse_header=True):
    from roslib.message import get_message_class
    '''
    Get info from all of the messages about what they contain
    and will be added to the dataframe
    '''
    topic_info = yaml_info['topics']
    msgs = {}
    classes = {}

    for topic in topics:
        base_key = topic
        msg_paths = []
        msg_types = {}
        for info in topic_info:
            if info['topic'] == topic:
                msg_class = get_message_class(info['type'])
                if msg_class is None:
                    warnings.warn(
                        'Could not find types for ' + topic + ' skpping ')
                else:
                    (msg_paths, msg_types) = get_base_fields(msg_class(), "",
                                                             parse_header)
                msgs[topic] = msg_paths
                classes[topic] = msg_types
    return (msgs, classes)



def parse_bag(fname):
    import rosbag, yaml, subprocess
    bag = rosbag.Bag(fname)

    tMin = np.inf  # first time we see

    yaml_info =yaml.load(subprocess.Popen(['rosbag', 'info', '--yaml', fname],
        stdout=subprocess.PIPE).communicate()[0]) 

    topicNames = [t['topic'] for t in yaml_info['topics']]
    numRowsData = 0
    for t in yaml_info['topics']:
        numRowsData += t['messages']

    msgs_to_read, msg_type = get_msg_info(yaml_info, topicNames)

    count = 0
    out = {}

    dispNextPercent = 0
    dispPercentGap = 10

    skipTopics = ['/tf']

    for topic, msg, t in bag.read_messages():
        count += 1

        if count*100//numRowsData > dispNextPercent:
            print(str(dispNextPercent)+'% done')
            dispNextPercent += dispPercentGap


        if topic in skipTopics:
            continue

        try:
            if not topic in out.keys():
                #print('First message of topic '+topic)
                out[topic] = {}
                subs = msgs_to_read[topic]
                out[topic]['t'] = []
                for s in subs:
                    if s[:7] == 'header.':
                        #print('HEADER SKIP', s)
                        continue

                    out[topic][s] = []


            #t_sec = msg.header.stamp.secs+msg.header.stamp.nsecs/1e9
            #mark with time received, not sent
            t_sec = t.to_sec()
            out[topic]['t'] += [t_sec]
            tMin = min([tMin, out[topic]['t'][0]])

            for k in out[topic].keys():
                if k == 't':
                    continue
                out[topic][k] += [getattr(msg,k)]
                
        except:
            print('Exception parsing topic <'+topic+'>, skipping...')
            skipTopics += [topic]


    bag.close()
    
    #make everything a numpy array, rather than a list
    for topic in out.keys():
        for k in out[topic].keys():
            out[topic][k] = np.array(out[topic][k])


        out[topic]['t'] -= tMin

    return out



#if run from the interpreter, convert bag to pickle
if __name__ == '__main__':
    if len(sys.argv) < 2:
        print('Must provide filename')

    else:
        for fname in sys.argv[1:]:
            fname0 = strip_name(fname)

            #find pickle file
            if not os.path.isfile(fname0+'.pickle'):
                bagFile = fname0+'.bag'
                if not os.path.isfile(bagFile):
                    print('File not found: <'+bagFile+'>')

                print('Converting <'+bagFile+'>')

                out = parse_bag(bagFile)

                pickleFile = open(fname0+'.pickle', 'wb')
                pickle.dump([out,fname0], pickleFile)
                pickleFile.close()
                print('Saved to pickle file.')
            else:
                print('Pickle file already exists: ',fname0+'.pickle')



