#define PCL_NO_PRECOMPILE
#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/common/transforms.h>

#include "UserDefinedParams.h"
#include "CustomPointTypes.h"


void transform_pcd_and_save(TransformParams& transform_params)
{
    std::cout << "Hello, from Tranform Pcd and Save\n";

    // Loading the pointcloud
    transform_params.output_filename = transform_params.input_filename.substr(0, transform_params.input_filename.size()-4) + "_transformed.pcd";
    pcl::PointCloud<PointXYZIClsIns>::Ptr source_cloud (new pcl::PointCloud<PointXYZIClsIns>);
    pcl::io::loadPCDFile<PointXYZIClsIns>(transform_params.input_filename, *source_cloud);

    // Defining a rotation matrix and translation vector
    Eigen::Affine3f transform = Eigen::Affine3f::Identity();
    // Translating the pointcloud
    transform.translation() << transform_params.x_translate, transform_params.y_translate, transform_params.z_translate;
    
    // Rotating the PointCloud
    transform.rotate (Eigen::AngleAxisf (transform_params.x_rotation, Eigen::Vector3f::UnitX())); // Rotate about x axis
    transform.rotate (Eigen::AngleAxisf (transform_params.y_rotation, Eigen::Vector3f::UnitY())); // Rotate about y axis
    transform.rotate (Eigen::AngleAxisf (transform_params.z_rotation, Eigen::Vector3f::UnitZ())); // Rotate about z axis
    
    // Executing the transformation
    pcl::PointCloud<PointXYZIClsIns>::Ptr transformed_cloud (new pcl::PointCloud<PointXYZIClsIns> ());
    pcl::transformPointCloud (*source_cloud, *transformed_cloud, transform);

    // Saving transformed cloud
    pcl::io::savePCDFileASCII(transform_params.output_filename, *transformed_cloud); //Saving the transformed cloud
    std::cout << "Saved " << transformed_cloud->size() << " data points to "<< transform_params.output_filename << std::endl;
}