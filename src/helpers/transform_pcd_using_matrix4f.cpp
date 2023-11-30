#include <iostream>
#include <string>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/common/transforms.h>

#include "UserDefinedParams.h"

void transform_pcd_from_matrix4f(PCDTransformParams& pcd_transform_params)
{
    pcl::PointCloud<pcl::PointXYZI>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZI>);
    pcl::PointCloud<pcl::PointXYZI>::Ptr cloud_transformed (new pcl::PointCloud<pcl::PointXYZI>);
    pcl::io::loadPCDFile<pcl::PointXYZI>(pcd_transform_params.input_filename, *cloud);

    // Transform the pointcloud
    pcl::transformPointCloud(*cloud, *cloud_transformed, pcd_transform_params.transformation_matrix);

    pcl::io::savePCDFileASCII(pcd_transform_params.output_filename, *cloud_transformed);
    std::cout<<"Transformed pointcloud saved to: "<<pcd_transform_params.output_filename<<std::endl;
}