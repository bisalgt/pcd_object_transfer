#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <vector>
#include <iostream>

#include "UserDefinedParams.h"


void sub_sample_pcd(const FileInputOutputParams& file_in_out_params)
{
    pcl::PointCloud<pcl::PointXYZI>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZI>);
    pcl::PointCloud<pcl::PointXYZI>::Ptr cloud_subsampled (new pcl::PointCloud<pcl::PointXYZI>);
    pcl::io::loadPCDFile<pcl::PointXYZI>(file_in_out_params.input_filename, *cloud);

    std::cout<<"Loaded pointcloud of size: "<<cloud->points.size()<<std::endl;
    // Find the first 5 minimum points on y-axis.
    std::sort(cloud->points.begin(), cloud->points.end(), [](const pcl::PointXYZI& a, const pcl::PointXYZI& b) { return a.y < b.y; });
    std::vector<pcl::PointXYZI> min_points;
    std::vector<float> min_y_values;
    for (int i = 0; i < 5; i++)
    {
        min_points.push_back(cloud->points[i]);
        min_y_values.push_back(cloud->points[i].y);
    }

    // Subsample the pointcloud based on some threshold on y-axis
    for (int i = 0; i < cloud->points.size(); i++) {
        if (cloud->points[i].y < min_y_values[0] + 0.5) { // Considering minimum y value and adding  0.5 as a threshold to subsample
            cloud_subsampled->points.push_back(cloud->points[i]);
        }
    }
    
    cloud_subsampled->width = cloud_subsampled->points.size();
    cloud_subsampled->height = 1;

    pcl::io::savePCDFileASCII(file_in_out_params.output_filename, *cloud_subsampled);
    std::cout<<"Subsampled pointcloud saved to: "<<file_in_out_params.output_filename<<std::endl;

}