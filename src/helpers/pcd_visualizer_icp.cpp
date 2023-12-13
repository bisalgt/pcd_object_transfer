#define PCL_NO_PRECOMPILE
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/visualization/point_cloud_geometry_handlers.h>
#include <iostream>

#include "UserDefinedParams.h"
#include "CustomPointTypes.h"



void pcd_visualizer_icp(const PCDVisualizerICPParams& pcd_vis_icp_params)
{
    std::cout << "Running PCD Visualizer for ICP....\n";
    
    // Create the viewer
    pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
    viewer->setBackgroundColor(0.0, 0.0, 0.0);

    // Add the source cloud
    pcl::PointCloud<PointXYZIClsIns>::Ptr source_cloud(new pcl::PointCloud<PointXYZIClsIns>);
    pcl::io::loadPCDFile<PointXYZIClsIns>(pcd_vis_icp_params.source_cloud_params.filename, *source_cloud);
    pcl::visualization::PointCloudColorHandlerCustom<PointXYZIClsIns> source_cloud_color (source_cloud, pcd_vis_icp_params.source_cloud_params.r, pcd_vis_icp_params.source_cloud_params.g, pcd_vis_icp_params.source_cloud_params.b);
    viewer->addPointCloud<PointXYZIClsIns>(source_cloud, source_cloud_color, "source cloud");
    viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, pcd_vis_icp_params.source_cloud_params.point_size, "source cloud");

    // Add the target cloud
    pcl::PointCloud<PointXYZIClsIns>::Ptr target_cloud(new pcl::PointCloud<PointXYZIClsIns>);
    pcl::io::loadPCDFile<PointXYZIClsIns>(pcd_vis_icp_params.target_cloud_params.filename, *target_cloud);
    pcl::visualization::PointCloudColorHandlerCustom<PointXYZIClsIns> target_cloud_color (target_cloud, pcd_vis_icp_params.target_cloud_params.r, pcd_vis_icp_params.target_cloud_params.g, pcd_vis_icp_params.target_cloud_params.b);
    viewer->addPointCloud<PointXYZIClsIns>(target_cloud, target_cloud_color, "target cloud");
    viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, pcd_vis_icp_params.target_cloud_params.point_size, "target cloud");


    // Add the source transformed cloud
    pcl::PointCloud<PointXYZIClsIns>::Ptr source_transf_cloud(new pcl::PointCloud<PointXYZIClsIns>);
    pcl::io::loadPCDFile<PointXYZIClsIns>(pcd_vis_icp_params.source_transf_cloud_params.filename, *source_transf_cloud);
    pcl::visualization::PointCloudColorHandlerCustom<PointXYZIClsIns> source_transf_cloud_color (source_transf_cloud, pcd_vis_icp_params.source_transf_cloud_params.r, pcd_vis_icp_params.source_transf_cloud_params.g, pcd_vis_icp_params.source_transf_cloud_params.b);
    viewer->addPointCloud<PointXYZIClsIns>(source_transf_cloud, source_transf_cloud_color, "source transformed cloud");
    viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, pcd_vis_icp_params.source_transf_cloud_params.point_size, "source transformed cloud");

    // Orthographic (parallel) projection; same with pressing 'o'
    // viewer->getRenderWindow()->GetRenderers()->GetFirstRenderer()->GetActiveCamera()->SetParallelProjection( 1 );
    
    viewer->addCoordinateSystem(1.0);

    viewer->initCameraParameters();
    
    viewer->spin();

}