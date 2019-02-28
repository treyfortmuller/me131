# ME131 Vehicle Dynamics and Control
Repository for homework and lab assignments for Berkeley's ME131 class. 

#### Notes

1. SSH into the Odroid, connect to the network: `barc-traxxas-13`

   `ssh -X odroid@10.0.0.1`

   password: `odroid`

2. To copy a directory on the BARC back to the local machine

   `scp -r odroid@10.0.0.1:/path/to/remote/file /destination/path`

   or transfer a file from the local machine to the barc

   `scp /path/to/local/file odroid@10.0.0.1:/destination/path`

3. There's also `stfp` login for transferring files

   `sftp odroid@10.0.0.1` then use `get` and `put` (which have `-r` recursive options) to transfer files back and forth (or `mget` and `mput` for multiple files), you can use wildcard flags like `mget *.jpg` to get all the jpg files in the directory.

4. Lastly, you enter the remote into nautilus like `ssh://odroid@10.0.0.1` (you can also use ``sftp`, it will automatically change `ssh` into `sftp` in nautilus) to view its file system in nautilus and copy and files by drag and drop.



