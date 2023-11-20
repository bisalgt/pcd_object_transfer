#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <pcl/io/pcd_io.h>

#include "UserDefinedParams.h"


void create_spiked_plane_pcd(const PCDSolidParams& pcd_solid_params)
{
    std::cout << "Hello, from plane\n";

    std::srand(std::time(nullptr)); // use current time as seed for random generator
    std::vector<int> options_for_y_axis = {0, 1, 2, 3, 4};

    // Create a plane of size length x width x height
    pcl::PointCloud<pcl::PointXYZI>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZI>);
    for (int i=0;i<pcd_solid_params.length;i++)
    {
        for (int k=0;k<pcd_solid_params.height;k++)
        {
            // std::cout << "i: " << i << " j: " << j << " k: " << k << std::endl;
            pcl::PointXYZI point;
            point.x = i;
            // generate a random index from options_for_y_axis
            int random_index = std::rand() % options_for_y_axis.size();
            point.y = options_for_y_axis[random_index]; // plane is at y=0
            point.z = k;
            point.intensity = 1;
            cloud->points.push_back(point);
            }
    }
    // height = 1 referes to unorganized point cloud
    cloud->width = cloud->points.size();
    cloud->height = 1;

    pcl::io::savePCDFileASCII(pcd_solid_params.pcd_filename, *cloud);
    std::cout << "Saved " << cloud->size() << " data points to "<< pcd_solid_params.pcd_filename << std::endl;

}