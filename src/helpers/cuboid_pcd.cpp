#include <iostream>
#include <pcl/io/pcd_io.h>

#include "UserDefinedParams.h"


void create_cuboid_pcd(const CuboidParams& cuboid_params)
{
    std::cout << "Hello, from cuboid_pcd\n";

    pcl::PointCloud<pcl::PointXYZI>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZI>);

    // Create a cuboid of size length x width x height
    for (int i=0;i<cuboid_params.length;i++)
    {
        for (int j=0;j<cuboid_params.width;j++)
        {
            for (int k=0;k<cuboid_params.height;k++)
            {
                // std::cout << "i: " << i << " j: " << j << " k: " << k << std::endl;
                pcl::PointXYZI point;
                point.x = i;
                point.y = j;
                point.z = k;
                point.intensity = 1;
                cloud->points.push_back(point);
            }
        }
    }
    // height = 1 referes to unorganized point cloud
    cloud->width = cloud->points.size();
    cloud->height = 1;

    pcl::io::savePCDFileASCII(cuboid_params.pcd_filename, *cloud);
    std::cout << "Saved " << cloud->size() << " data points to "<< cuboid_params.pcd_filename << std::endl;

}