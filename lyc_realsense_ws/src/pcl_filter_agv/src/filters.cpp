#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/PCLPointCloud2.h>
#include <pcl/conversions.h>

#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/passthrough.h>
#include <pcl/filters/radius_outlier_removal.h>
#include <pcl_ros/point_cloud.h>
ros::Publisher pub;

void cloud_cb(const pcl::PCLPointCloud2::Ptr &input)
{
    //Voxelgrid filter
    pcl::PCLPointCloud2::Ptr cloud_ved (new pcl::PCLPointCloud2); 
    
    pcl::VoxelGrid<pcl::PCLPointCloud2> sor;    
    sor.setInputCloud (input);
    sor.setLeafSize (0.02, 0.02, 0.02);
    sor.filter (*cloud_ved);
    
    //radius filter
    pcl::PCLPointCloud2::Ptr cloud_red (new pcl::PCLPointCloud2);
    
    pcl::RadiusOutlierRemoval<pcl::PCLPointCloud2> outrem;
    outrem.setInputCloud(cloud_ved);
    outrem.setRadiusSearch(0.05);
    outrem.setMinNeighborsInRadius (10);
    outrem.filter (*cloud_red);
    
    //convert to xyz
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr pct_temp (new pcl::PointCloud<pcl::PointXYZRGB>);
    pcl::fromPCLPointCloud2(*cloud_red,*pct_temp);
    
    //Passthrough filter
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_x (new pcl::PointCloud<pcl::PointXYZRGB>);
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_xy (new pcl::PointCloud<pcl::PointXYZRGB>);
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_xyz (new pcl::PointCloud<pcl::PointXYZRGB>);
    
    pcl::PassThrough<pcl::PointXYZRGB> pass_x_filter;
    pass_x_filter.setInputCloud (pct_temp);
    pass_x_filter.setFilterFieldName ("x");
    pass_x_filter.setFilterLimits (-1,1);  
    pass_x_filter.filter (*cloud_x);
    
    pcl::PassThrough<pcl::PointXYZRGB> pass_y_filter;
    pass_y_filter.setInputCloud (cloud_x);
    pass_y_filter.setFilterFieldName ("y");
    pass_y_filter.setFilterLimits (-1,1);
    pass_y_filter.filter (*cloud_xy);

    pcl::PassThrough<pcl::PointXYZRGB> pass_z_filter;
    pass_z_filter.setInputCloud (cloud_xy);
    pass_z_filter.setFilterFieldName ("z");
    pass_z_filter.setFilterLimits (0.5,3.0);
    pass_z_filter.filter (*cloud_xyz);
    
    // Publish the data
    pub.publish (*cloud_xyz);
}

int main (int argc, char** argv)
{
  // Initialize ROS
  ros::init (argc, argv, "filters");
  ros::NodeHandle nh;

  // Create a ROS subscriber for the input point cloud
  ros::Subscriber sub = nh.subscribe("camera/depth/points", 1, cloud_cb);

  // Create a ROS publisher for the output point cloud
  pub = nh.advertise<pcl::PointCloud<pcl::PointXYZRGB> > ("raw_xyzrgb_output", 1);

  // Spin
  ros::spin ();
}
