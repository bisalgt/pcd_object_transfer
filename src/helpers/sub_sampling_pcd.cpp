#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <vector>
#include <iostream>

#include "UserDefinedParams.h"


std::vector<float> sub_sample_pcd(const FileInputOutputParams& file_in_out_params)
{
    pcl::PointCloud<pcl::PointXYZI>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZI>);
    pcl::PointCloud<pcl::PointXYZI>::Ptr cloud_subsampled (new pcl::PointCloud<pcl::PointXYZI>);
    pcl::io::loadPCDFile<pcl::PointXYZI>(file_in_out_params.input_filename, *cloud);

    std::cout<<"Loaded pointcloud of size: "<<cloud->points.size()<<std::endl;
    // Find the first 5 minimum points on z-axis.
    std::sort(cloud->points.begin(), cloud->points.end(), [](const pcl::PointXYZI& a, const pcl::PointXYZI& b) { return a.z < b.z; });
    std::vector<pcl::PointXYZI> min_points;
    std::vector<float> min_z_values;
    for (int i = 0; i < 5; i++)
    {
        min_points.push_back(cloud->points[i]);
        min_z_values.push_back(cloud->points[i].z);
    }

    float z_threshold = 0.3;
    float dz = 0.1;

    float lower_limit_z = min_z_values[0] + z_threshold;
    float upper_limit_z = min_z_values[0] + z_threshold + dz;

    std::vector<float> z_values_references;
    z_values_references.push_back(z_threshold);
    z_values_references.push_back(dz);
    z_values_references.push_back(lower_limit_z);
    z_values_references.push_back(upper_limit_z);

    // Subsample the pointcloud based on some threshold on z-axis
    for (int i = 0; i < cloud->points.size(); i++) {
        if (cloud->points[i].z >= lower_limit_z && cloud->points[i].z <= upper_limit_z ) { // Getting the value of point whose z value is between a threshold
            cloud_subsampled->points.push_back(cloud->points[i]);
        }
    }
    
    cloud_subsampled->width = cloud_subsampled->points.size();
    cloud_subsampled->height = 1;

    pcl::io::savePCDFileASCII(file_in_out_params.output_filename, *cloud_subsampled);
    std::cout<<"Subsampled pointcloud saved to: "<<file_in_out_params.output_filename<<std::endl;
    std::cout<<"Subsampled pointcloud size: "<<cloud_subsampled->points.size()<<std::endl;

    return z_values_references;

}