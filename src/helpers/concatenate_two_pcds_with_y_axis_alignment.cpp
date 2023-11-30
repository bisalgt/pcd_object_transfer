#include <iostream>
#include <pcl/io/pcd_io.h>

#include "main.h"
#include "UserDefinedParams.h"
#include "Constants.h"

void concatenate_two_pcds_with_y_axis_alignment(const ConcatenatePCDParams& concatenate_two_pcds_params)
{
    std::cout << "Hello, from concatenate_two_pcds_target_cloud_and_source_cloud\n";

    // Create input and output pointclouds objects
    pcl::PointCloud<pcl::PointXYZI>::Ptr target_cloud (new pcl::PointCloud<pcl::PointXYZI>);
    pcl::PointCloud<pcl::PointXYZI>::Ptr source_cloud (new pcl::PointCloud<pcl::PointXYZI>);
    pcl::PointCloud<pcl::PointXYZI>::Ptr output_cloud (new pcl::PointCloud<pcl::PointXYZI>);

    // Load pcd files
    pcl::io::loadPCDFile(concatenate_two_pcds_params.input_filename, *target_cloud);
    pcl::io::loadPCDFile(concatenate_two_pcds_params.input_filename_2, *source_cloud);

    // Before concatenating we need to find ROI of source_cloud and region of interest of target_cloud
    // We then need to translate source_cloud to the region of interest of target_cloud.

    // Find ROI of source_cloud
    // selecting a random point from the pointcloud and initializing the ROI variables
    int random_index = std::rand() % source_cloud->size();
    pcl::PointXYZI random_point = source_cloud->points[random_index];

    // Only need to take X and Z axis for reference. We will then use ROI to calculate the y-axis to translate the source_cloud
    ROIParams roi_params;
    roi_params.x_min = random_point.x;
    roi_params.x_max = random_point.x;
    roi_params.z_min = random_point.z;
    roi_params.z_max = random_point.z;

    // To find y minimum from the source_cloud for translation to the nearest top of y-axis
    float source_cloud_y_min_roi {random_point.y};


    for(pcl::PointXYZI& point : source_cloud->points)
    {
        if(point.x <= roi_params.x_min)
        {
            roi_params.x_min = point.x;
        } 
        else {
            roi_params.x_max = point.x;
        }

        // We only need to find the minimum y value from the source_cloud
        if(point.y < source_cloud_y_min_roi)
        {
            source_cloud_y_min_roi = point.y;
        }

        if(point.z <= roi_params.z_min)
        {
            roi_params.z_min = point.z;
        } else {
            roi_params.z_max = point.z;
        }
    }

    // Find y maximum from the OVERLAPPED region of interest of target_cloud
    // Select a random point from target_cloud
    int random_index_2 = std::rand() % target_cloud->size();
    pcl::PointXYZI random_point_2 = target_cloud->points[random_index_2];

    float target_cloud_y_max  {random_point_2.y}; // For now we only consider the max of y axis of the target_cloud to put the source_cloud on top of target_cloud.

    for(pcl::PointXYZI& point : target_cloud->points)
    {
        if(point.x >= roi_params.x_min && point.x <= roi_params.x_max && point.z >= roi_params.z_min && point.z <= roi_params.z_max)
        {
            if(point.y >= target_cloud_y_max)
            {
                target_cloud_y_max = point.y;
            }
        }
        else {
            point.intensity = 0;    
        }
    }

    // Performing translation on source_cloud
    // We translate the y-value of source_cloud to the max y-value of the target_cloud in the overlapped region of interest.
    TransformParams transform_params;
    transform_params.input_filename = concatenate_two_pcds_params.input_filename_2;
    transform_params.output_filename = concatenate_two_pcds_params.input_filename_2.substr(0, concatenate_two_pcds_params.input_filename_2.size()-4) + "_translated.pcd";
    transform_params.y_translate = -(source_cloud_y_min_roi - target_cloud_y_max);
    transform_pcd_and_save(transform_params);

    std::cout<<"translation values : "<< target_cloud_y_max << " souce cloud y min : " << source_cloud_y_min_roi << " y translation value :  " << transform_params.y_translate << std::endl;

    // Load the Translated pcd of source_cloud
    pcl::PointCloud<pcl::PointXYZI>::Ptr source_cloud_translated (new pcl::PointCloud<pcl::PointXYZI>);
    pcl::io::loadPCDFile(transform_params.output_filename, *source_cloud_translated);

    

    // Concatenate the two clouds
    *output_cloud = *target_cloud + *source_cloud_translated;

    // Save the concatenated cloud
    pcl::io::savePCDFileASCII(concatenate_two_pcds_params.output_filename, *output_cloud);
    std::cout<<"Size of input cloud 1: "<<target_cloud->size()<<std::endl;
    std::cout<<"Size of input cloud 2: "<<source_cloud->size()<<std::endl;
    std::cout << "Saved " << output_cloud->size() << " data points to "<< concatenate_two_pcds_params.output_filename << std::endl;
}