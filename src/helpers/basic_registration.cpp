#include <pcl/point_types.h>
#include <pcl/registration/icp.h>
#include <pcl/io/pcd_io.h>


#include "UserDefinedParams.h"
#include "Constants.h"


void basic_icp_registration(const ConcatenatePCDParams& concatenated_pcd_params)
{
    pcl::PointCloud<pcl::PointXYZI>::Ptr cloud_source (new pcl::PointCloud<pcl::PointXYZI>);
    pcl::PointCloud<pcl::PointXYZI>::Ptr cloud_target (new pcl::PointCloud<pcl::PointXYZI>);

    // Load the pcd file

    pcl::io::loadPCDFile<pcl::PointXYZI>(concatenated_pcd_params.input_filename, *cloud_source);
    pcl::io::loadPCDFile<pcl::PointXYZI>(concatenated_pcd_params.input_filename_2, *cloud_target);

    // ICP
    pcl::IterativeClosestPoint<pcl::PointXYZI, pcl::PointXYZI> icp;
    icp.setInputSource(cloud_source);
    icp.setInputTarget(cloud_target);

    // icp.setMaximumIterations(100);
    icp.setMaxCorrespondenceDistance(1);

    pcl::PointCloud<pcl::PointXYZI> aligned_cloud;
    icp.align(aligned_cloud);

    // pcl::io::savePCDFileASCII(concatenated_pcd_params.output_filename, aligned_cloud);
    // Concatenate the aligned cloud and the target cloud
    pcl::PointCloud<pcl::PointXYZI>::Ptr cloud_merged (new pcl::PointCloud<pcl::PointXYZI>);
    *cloud_merged = aligned_cloud + *cloud_target;
    pcl::io::savePCDFileASCII(concatenated_pcd_params.output_filename, *cloud_merged);

    std::cout << "has converged:" << icp.hasConverged() << " score: " <<icp.getFitnessScore() << std::endl;
    std::cout << icp.getFinalTransformation() << std::endl;



}