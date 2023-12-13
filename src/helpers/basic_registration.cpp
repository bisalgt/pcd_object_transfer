#define PCL_NO_PRECOMPILE

#include <pcl/point_types.h>
#include <pcl/registration/icp.h>
#include <pcl/io/pcd_io.h>


#include "UserDefinedParams.h"
#include "Constants.h"
#include "CustomPointTypes.h"


void basic_icp_registration(PCDRegistrationParams& pcd_reistration_params)
{
    pcl::PointCloud<PointXYZIClsIns>::Ptr cloud_source (new pcl::PointCloud<PointXYZIClsIns>);
    pcl::PointCloud<PointXYZIClsIns>::Ptr cloud_target (new pcl::PointCloud<PointXYZIClsIns>);

    // Load the pcd file

    pcl::io::loadPCDFile<PointXYZIClsIns>(pcd_reistration_params.source_cloud, *cloud_source);
    pcl::io::loadPCDFile<PointXYZIClsIns>(pcd_reistration_params.target_cloud, *cloud_target);

    // ICP
    pcl::IterativeClosestPoint<PointXYZIClsIns, PointXYZIClsIns> icp;
    icp.setInputSource(cloud_source);
    icp.setInputTarget(cloud_target);


    icp.setMaximumIterations(1);
    // icp.setMaxCorrespondenceDistance(0.8);
    // icp.setTransformationEpsilon(1e-3);
    // icp.setEuclideanFitnessEpsilon(1e-3);

    pcl::PointCloud<PointXYZIClsIns> aligned_cloud;
    icp.align(aligned_cloud);

    

    pcd_reistration_params.transformation_matrix = icp.getFinalTransformation();

    pcl::io::savePCDFileASCII(pcd_reistration_params.output_cloud, aligned_cloud);
    // Concatenate the aligned cloud and the target cloud
    // pcl::PointCloud<PointXYZIClsIns>::Ptr cloud_merged (new pcl::PointCloud<PointXYZIClsIns>);
    // *cloud_merged = aligned_cloud + *cloud_target;
    // pcl::io::savePCDFileASCII(pcd_reistration_params.output_filename, *cloud_merged);

    std::cout << "has converged:" << icp.hasConverged() << " score: " <<icp.getFitnessScore() << std::endl;
    std::cout << icp.getFinalTransformation() << std::endl;



}