#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/common/transforms.h>

#include "UserDefinedParams.h"


void tranform_pcd_and_save(FileInputOutputParams& file_input_output_transform_params)
{
    std::cout << "Hello, from Tranform Pcd and Save\n";

    file_input_output_transform_params.output_filename = file_input_output_transform_params.input_filename.substr(0, file_input_output_transform_params.input_filename.size()-4) + "_transformed.pcd";
    pcl::PointCloud<pcl::PointXYZI>::Ptr source_cloud (new pcl::PointCloud<pcl::PointXYZI>);
    pcl::io::loadPCDFile<pcl::PointXYZI>(file_input_output_transform_params.input_filename, *source_cloud);

    float theta = 0; // The angle of rotation in radians
    Eigen::Affine3f transform = Eigen::Affine3f::Identity();
    transform.translation() << -5.0, 0.0, -5.0;
    transform.rotate (Eigen::AngleAxisf (theta, Eigen::Vector3f::UnitZ())); // Rotate about z axis
    pcl::PointCloud<pcl::PointXYZI>::Ptr transformed_cloud (new pcl::PointCloud<pcl::PointXYZI> ());
    pcl::transformPointCloud (*source_cloud, *transformed_cloud, transform);


    pcl::io::savePCDFileASCII(file_input_output_transform_params.output_filename, *transformed_cloud); //Saving the transformed cloud
    std::cout << "Saved " << transformed_cloud->size() << " data points to "<< file_input_output_transform_params.output_filename << std::endl;
}