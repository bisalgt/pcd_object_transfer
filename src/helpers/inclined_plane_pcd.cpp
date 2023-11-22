#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <pcl/io/pcd_io.h>

#include "UserDefinedParams.h"


void create_inclined_plane_pcd(const PCDSolidParams& pcd_solid_params)
{
    std::cout << "Hello, from inclined plane\n";

    

    // Create a plane of size length x width x height
    pcl::PointCloud<pcl::PointXYZI>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZI>);
    for (int i=0;i<pcd_solid_params.length;i++)
    {
        for (int k=0;k<pcd_solid_params.height;k++)
        {
            // std::cout << "i: " << i << " j: " << j << " k: " << k << std::endl;
            pcl::PointXYZI point;
            point.x = i;
            point.y = point.x; // y = x for inclined plane
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