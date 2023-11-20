#include <iostream>
#include <pcl/io/pcd_io.h>

#include "main.h"
#include "UserDefinedParams.h"
#include "Constants.h"

void concatenate_two_pcds_spiked_plane_and_cuboid(const ConcatenatePCDParams& concatenate_two_pcds_params)
{
    std::cout << "Hello, from concatenate_two_pcds_spiked_plane_and_cuboid\n";

    // Create input and output pointclouds objects
    pcl::PointCloud<pcl::PointXYZI>::Ptr spiked_plane_inp_1_cloud (new pcl::PointCloud<pcl::PointXYZI>);
    pcl::PointCloud<pcl::PointXYZI>::Ptr cuboid_inp_2_cloud (new pcl::PointCloud<pcl::PointXYZI>);
    pcl::PointCloud<pcl::PointXYZI>::Ptr output_cloud (new pcl::PointCloud<pcl::PointXYZI>);

    // Load pcd files
    pcl::io::loadPCDFile(concatenate_two_pcds_params.input_filename, *spiked_plane_inp_1_cloud);
    pcl::io::loadPCDFile(concatenate_two_pcds_params.input_filename_2, *cuboid_inp_2_cloud);

    // Before concatenating we need to find ROI of cuboid_inp_2_cloud and region of interest of spiked_plane_inp_1_cloud
    // We then need to translate cuboid_inp_2_cloud to the region of interest of spiked_plane_inp_1_cloud.

    // Find ROI of cuboid_inp_2_cloud
    // selecting a random point from the pointcloud and initializing the ROI variables
    int random_index = std::rand() % cuboid_inp_2_cloud->size();
    pcl::PointXYZI random_point = cuboid_inp_2_cloud->points[random_index];

    // Only need to take X and Z axis for reference. We will then use ROI to calculate the y-axis to translate the cuboid_inp_2_cloud
    ROIParams roi_params;
    roi_params.x_min = random_point.x;
    roi_params.x_max = random_point.x;
    roi_params.z_min = random_point.z;
    roi_params.z_max = random_point.z;


    for(pcl::PointXYZI& point : cuboid_inp_2_cloud->points)
    {
        if(point.x <= roi_params.x_min)
        {
            roi_params.x_min = point.x;
        } 
        else {
            roi_params.x_max = point.x;
        }
        if(point.z <= roi_params.z_min)
        {
            roi_params.z_min = point.z;
        } else {
            roi_params.z_max = point.z;
        }
    }

    // Find y maximum from the OVERLAPPED region of interest of spiked_plane_inp_1_cloud
    // Select a random point from spiked_plane_inp_1_cloud
    int random_index_2 = std::rand() % spiked_plane_inp_1_cloud->size();
    pcl::PointXYZI random_point_2 = spiked_plane_inp_1_cloud->points[random_index_2];

    float spiked_plane_y_max  {random_point_2.y}; // For now we only consider the max of y axis of the spiked plane to put the cuboid on top of spiked plane.

    for(pcl::PointXYZI& point : spiked_plane_inp_1_cloud->points)
    {
        if(point.x >= roi_params.x_min && point.x <= roi_params.x_max && point.z >= roi_params.z_min && point.z <= roi_params.z_max)
        {
            if(point.y >= spiked_plane_y_max)
            {
                spiked_plane_y_max = point.y;
            }
        }
    }

    // Performing translation on cuboid_inp_2_cloud
    // We translate the y-value of cuboid to the max y-value of the spiked plane in the overlapped region of interest.
    TransformParams transform_params;
    transform_params.input_filename = concatenate_two_pcds_params.input_filename_2;
    transform_params.output_filename = concatenate_two_pcds_params.input_filename_2.substr(0, concatenate_two_pcds_params.input_filename_2.size()-4) + "_translated.pcd";
    transform_params.y_translate = spiked_plane_y_max;
    transform_pcd_and_save(transform_params);

    // Load the Translated pcd of cuboid
    pcl::PointCloud<pcl::PointXYZI>::Ptr cuboid_inp_2_cloud_translated (new pcl::PointCloud<pcl::PointXYZI>);
    pcl::io::loadPCDFile(transform_params.output_filename, *cuboid_inp_2_cloud_translated);

    

    // Concatenate the two clouds
    *output_cloud = *spiked_plane_inp_1_cloud + *cuboid_inp_2_cloud_translated;

    // Save the concatenated cloud
    pcl::io::savePCDFileASCII(concatenate_two_pcds_params.output_filename, *output_cloud);
    std::cout<<"Size of input cloud 1: "<<spiked_plane_inp_1_cloud->size()<<std::endl;
    std::cout<<"Size of input cloud 2: "<<cuboid_inp_2_cloud->size()<<std::endl;
    std::cout << "Saved " << output_cloud->size() << " data points to "<< concatenate_two_pcds_params.output_filename << std::endl;
}