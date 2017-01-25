sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
sudo apt-key adv --keyserver hkp://ha.pool.sks-keyservers.net:80 --recv-key 421C365BD9FF1F717815A3895523BAEEB01FA116
sudo apt-get update
sudo apt-get install ros-kinetic-desktop-full
sudo rosdep init
rosdep update
echo "source /opt/ros/kinetic/setup.bash" >> ~/.bashrc
source ~/.bashrc
sudo apt-get install python-rosinstall
sudo apt-get update && sudo apt-get upgrade
sudo apt-get install libglfw3-dev
sudo cp config/99-realsense-libusb.rules /etc/udev/rules.d/
wget -O enable_kernel_sources.sh http://bit.ly/en_krnl_src
bash ./enable_kernel_sources.sh
sudo apt-get --reinstall install 'ros-*-librealsense'
sudo cp config/99-realsense-libusb.rules /etc/udev/rules.d/
sudo apt-get -- install 'ros-*-librealsense'
sudo apt-get install 'ros-*-realsense-camera'
roslaunch realsense_camera r200_nodelet_default.launch 
clear
roscore
ros
clear
roslaunch realsense_camera r200_nodelet_modify_params.launch 
rviz rviz
ros
gedit ~/.bashrc
gedit .bashrc
gedit~/.bashrc
cd
gedit~/.bashrc
gedit ~/.bashrc
cd 
rosrun pcl_agv filters
cd lyc_realsense_ws/
ls
cd src
ls
cd pcl_agv
cd ..
source devel/setup.bash
rosrun my_pcl_tutorial filters
catkin_make
catkin_create_pkg pcl_filter_agv pcl_conversions pcl_ros roscpp sensor_msgs 
cd src
catkin_create_pkg pcl_filter_agv pcl_conversions pcl_ros roscpp sensor_msgs 
cd ..
catkin_make
cd src
catkin_create_pkg pcl_filter_agv pcl_conversions pcl_ros roscpp sensor_msgs 
cd ..
catkin_make
rosrun pcl_filter_agv filter
cd 
rosrun pcl_filter_agv filters 
roslaunch pcl_filter_agv pcl_filter.launch 
cd lyc_realsense_ws/
catkin_make
roslaunch pcl_filter_agv pcl_filter.launch 
rviz rivz
cd
gedit ~/.bashrc
rviz rivz
source /opt/ros/kinetic/setup.bash
mkdir -p ~/lyc_ws/src
cd ~/lyc_ws/sec
cd ~/lyc_ws/src
catkin_init_workspace 
cd ..
catkin_make
ls
cd devel
ls
pwd
cd
ls
cd lyc_realsense_ws/
catkin_make
cd
cd lyc_realsense_ws/
cd src
catkin_init_workspace 
cd ..
catkin_make
cd src
catkin_create_pkg pcl2_agv std_msgs rospy roscpp
cd ..
catkin_make
catkin_create_pkg pcl_agv pcl_conversions pcl_ros roscpp sensor_msgs
cd src
catkin_create_pkg my_pcl_tutorial pcl_conversions pcl_ros roscpp sensor_msgs
cd ..
catkin_make
ls
cd devel
pwd setup.bash
cd
roslaunch realsense_camera r200_nodelet_modify_params.launch 
rosecho ls
rostopic ls
rostopic list
rostopic echo /raw_xyzrgb_output
