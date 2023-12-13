#define PCL_NO_PRECOMPILE

#include <pcl/point_types.h>
#include <pcl/registration/icp.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/pcl_visualizer.h>

#include "UserDefinedParams.h"
#include "Constants.h"
#include "CustomPointTypes.h"


void icp_registration_with_iterative_view(PCDVisualizerICPParams& pcd_vis_icp_params)
{

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
    source_transf_cloud = source_cloud;

    pcl::visualization::PointCloudColorHandlerCustom<PointXYZIClsIns> source_transf_cloud_color (source_transf_cloud, pcd_vis_icp_params.source_transf_cloud_params.r, pcd_vis_icp_params.source_transf_cloud_params.g, pcd_vis_icp_params.source_transf_cloud_params.b);
    viewer->addPointCloud<PointXYZIClsIns>(source_transf_cloud, source_transf_cloud_color, "source transformed cloud");
    viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, pcd_vis_icp_params.source_transf_cloud_params.point_size, "source transformed cloud");

    // Orthographic (parallel) projection; same with pressing 'o'
    // viewer->getRenderWindow()->GetRenderers()->GetFirstRenderer()->GetActiveCamera()->SetParallelProjection( 1 );
    
    viewer->addCoordinateSystem(1.0);

    viewer->initCameraParameters();
    
    // viewer->spin();

    

    // ICP
    pcl::IterativeClosestPoint<PointXYZIClsIns, PointXYZIClsIns> icp;
    icp.setInputSource(source_cloud);
    icp.setInputTarget(target_cloud);


    icp.setMaximumIterations(1);
    // icp.setMaxCorrespondenceDistance(0.8);
    // icp.setTransformationEpsilon(1e-3);
    // icp.setEuclideanFitnessEpsilon(1e-3);


    while (!viewer->wasStopped ())
    {
        icp.align(*source_transf_cloud);

        if (icp.hasConverged ())
        {
            std::cout << "\nICP has converged, score is " << icp.getFitnessScore () << std::endl;
            std::cout << "\nICP transformation " << icp.getFinalTransformation () << std::endl;
            viewer->updatePointCloud(source_transf_cloud, source_transf_cloud_color, "source transformed cloud");
        }
        else
        {
            std::cout << "\nICP has not converged." << std::endl;
        }

        viewer->spinOnce (3000);
        
    }

    

    pcd_vis_icp_params.transformation_matrix = icp.getFinalTransformation();



    pcl::io::savePCDFileASCII(pcd_vis_icp_params.source_transf_cloud_params.filename, *source_transf_cloud);
    // Concatenate the aligned cloud and the target cloud
    // pcl::PointCloud<PointXYZIClsIns>::Ptr cloud_merged (new pcl::PointCloud<PointXYZIClsIns>);
    // *cloud_merged = aligned_cloud + *cloud_target;
    // pcl::io::savePCDFileASCII(pcd_vis_icp_params.output_filename, *cloud_merged);

    std::cout << "has converged:" << icp.hasConverged() << " score: " <<icp.getFitnessScore() << std::endl;
    std::cout << icp.getFinalTransformation() << std::endl;



}