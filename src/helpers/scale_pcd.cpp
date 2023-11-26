#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <iostream>
#include "UserDefinedParams.h"


void scale_or_multiply_pcd(const ScalePCDParams& scale_pcd_params)
{
    std::cout << "Running PCD Scale....\n";
    pcl::PointCloud<pcl::PointXYZI>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZI>);
    pcl::io::loadPCDFile<pcl::PointXYZI>(scale_pcd_params.input_filename, *cloud);

    pcl::PointCloud<pcl::PointXYZI>::Ptr cloud_scaled (new pcl::PointCloud<pcl::PointXYZI>);
    pcl::copyPointCloud(*cloud, *cloud_scaled);

    for (int i=0;i<cloud_scaled->points.size();i++)
    {
        cloud_scaled->points[i].x = cloud_scaled->points[i].x * scale_pcd_params.scaling_factor;
        cloud_scaled->points[i].y = cloud_scaled->points[i].y * scale_pcd_params.scaling_factor;
        cloud_scaled->points[i].z = cloud_scaled->points[i].z * scale_pcd_params.scaling_factor;
    }

    pcl::io::savePCDFileASCII(scale_pcd_params.output_filename, *cloud_scaled);
    std::cout << "Saved " << cloud_scaled->size() << " data points to "<< scale_pcd_params.output_filename << std::endl;
}