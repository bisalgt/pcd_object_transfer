#include <pcl/point_types.h>
#include <pcl/registration/icp.h>
#include <pcl/io/pcd_io.h>


#include "UserDefinedParams.h"
#include "Constants.h"


void basic_icp_registration(PCDRegistrationParams& pcd_reistration_params)
{
    pcl::PointCloud<pcl::PointXYZI>::Ptr cloud_source (new pcl::PointCloud<pcl::PointXYZI>);
    pcl::PointCloud<pcl::PointXYZI>::Ptr cloud_target (new pcl::PointCloud<pcl::PointXYZI>);

    // Load the pcd file

    pcl::io::loadPCDFile<pcl::PointXYZI>(pcd_reistration_params.source_cloud, *cloud_source);
    pcl::io::loadPCDFile<pcl::PointXYZI>(pcd_reistration_params.target_cloud, *cloud_target);

    // ICP
    pcl::IterativeClosestPoint<pcl::PointXYZI, pcl::PointXYZI> icp;
    icp.setInputSource(cloud_source);
    icp.setInputTarget(cloud_target);


    pcl::PointCloud<pcl::PointXYZI> aligned_cloud;
    icp.align(aligned_cloud);

    pcd_reistration_params.transformation_matrix = icp.getFinalTransformation();

    pcl::io::savePCDFileASCII(pcd_reistration_params.output_cloud, aligned_cloud);
    // Concatenate the aligned cloud and the target cloud
    // pcl::PointCloud<pcl::PointXYZI>::Ptr cloud_merged (new pcl::PointCloud<pcl::PointXYZI>);
    // *cloud_merged = aligned_cloud + *cloud_target;
    // pcl::io::savePCDFileASCII(pcd_reistration_params.output_filename, *cloud_merged);

    std::cout << "has converged:" << icp.hasConverged() << " score: " <<icp.getFitnessScore() << std::endl;
    std::cout << icp.getFinalTransformation() << std::endl;



}