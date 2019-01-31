# ME131 Lab 1 Deliverables

Trey Fortmuller, SID: 26037758

#### Navigating the CLI

1. Bad vibes directory and stresses.txt

![](./del1.png)

#### Using the Sublime Text Editor

2. Python Hello World output

   Python code at https://github.com/treyfortmuller/me131

![](./del2.png)

#### Turtlesim

3. Turtle keyboard teleoperation

   Link to video:

https://drive.google.com/open?id=1Z2C-CCBdfcOmCmpeeHc1dNffXDeRylG7

4. rqt_graph

![](./del4.png)

The `rqt_graph` shows that a node called `/teleop_turtle` is publishing to the `/turtle1/cmd_vel` topic, which the `turtlesim` node is subscribing to.

5. rostopic pub

   Link to video: 

https://drive.google.com/open?id=1iUvn4PzbReiJmPpkvCDxcJCUKXeikCXW

6. Circle movement graph

![](./del5-2.png)

The graph shows that the `teleop_turtle` node is publishing to the `/turtle1/cmd_vel` node (because I never terminated that process). The new node `/rostopic_938...` is given an arbitrary identifier because it doesn't belong to a named process  and is also publishing to `/turtle1/cmd_vel`. This node is publishing the circular `geometry_msgs/Twist` commands. Finally,  the`/turtlesim` node is still subscribed to the `/turtle1/cmd_vel` , thus the visualized turtle is shown moving in a circle.

7. rqt_plot

   Link to video:

https://drive.google.com/open?id=1IBcwL6C2qRjT2s07Ca9KKTE4YudiSQ8r

These x and y position values make sense because the projection of the turtle's position onto the x and y axis as a function of time should look like two sinusoids  (cosine and sine for x and y respectively) oscillating 90 degrees out of phase, which can we see in the plot. The sinusoid's position along the y axis of the plot will be determined by the coordinates of the turtle in its window. It appears that the origin of the world frame for the turtle resides in the lower left corner of the rectangular blue window.