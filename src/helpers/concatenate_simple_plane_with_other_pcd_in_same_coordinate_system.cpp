#include <iostream>
#include <pcl/io/pcd_io.h>

#include "UserDefinedParams.h"
#include "Constants.h"

void concatenate_two_pcds(const ConcatenatePCDParams& concatenate_two_pcds_params)
{
    std::cout << "Hello, from concatenate_two_pcds\n";

    // Create input and output pointclouds objects
    pcl::PointCloud<pcl::PointXYZI>::Ptr input_cloud_1 (new pcl::PointCloud<pcl::PointXYZI>);
    pcl::PointCloud<pcl::PointXYZI>::Ptr input_cloud_2 (new pcl::PointCloud<pcl::PointXYZI>);
    pcl::PointCloud<pcl::PointXYZI>::Ptr output_cloud (new pcl::PointCloud<pcl::PointXYZI>);

    // Load pcd files
    pcl::io::loadPCDFile(concatenate_two_pcds_params.input_filename, *input_cloud_1);
    pcl::io::loadPCDFile(concatenate_two_pcds_params.input_filename_2, *input_cloud_2);

    // Concatenate the two clouds
    *output_cloud = *input_cloud_1 + *input_cloud_2;

    // Save the concatenated cloud
    pcl::io::savePCDFileASCII(concatenate_two_pcds_params.output_filename, *output_cloud);
    std::cout<<"Size of input cloud 1: "<<input_cloud_1->size()<<std::endl;
    std::cout<<"Size of input cloud 2: "<<input_cloud_2->size()<<std::endl;
    std::cout << "Saved " << output_cloud->size() << " data points to "<< concatenate_two_pcds_params.output_filename << std::endl;
}