#define PCL_NO_PRECOMPILE

#include <pcl/point_types.h>
#include <pcl/registration/icp.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/features/normal_3d.h>
#include <pcl/search/kdtree.h>
#include <pcl/common/transforms.h>

#include "UserDefinedParams.h"
#include "Constants.h"
#include "CustomPointTypes.h"




// void addNormal(pcl::PointCloud<PointXYZIClsInsNormals>::Ptr cloud,
// 	       pcl::PointCloud<PointXYZIClsInsNormals>::Ptr cloud_with_normals
// )
// {
//   pcl::PointCloud<pcl::Normal>::Ptr normals ( new pcl::PointCloud<pcl::Normal> );

//   pcl::search::KdTree<PointXYZIClsInsNormals>::Ptr searchTree (new pcl::search::KdTree<PointXYZIClsInsNormals>);
//   searchTree->setInputCloud ( cloud );

//   pcl::NormalEstimation<PointXYZIClsInsNormals, pcl::Normal> normalEstimator;
//   normalEstimator.setInputCloud ( cloud );
//   normalEstimator.setSearchMethod ( searchTree );
//   normalEstimator.setKSearch ( 15 );
//   normalEstimator.compute ( *normals );
  
//   pcl::concatenateFields( *cloud, *normals, *cloud_with_normals );
// }


// void icp_registration_with_normal_iterative_view(PCDVisualizerICPParams& pcd_vis_icp_params)
// {

//     // Create the viewer
//     pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
//     viewer->setBackgroundColor(0.0, 0.0, 0.0);

//     // Add the source cloud
//     pcl::PointCloud<PointXYZIClsInsNormals>::Ptr source_cloud(new pcl::PointCloud<PointXYZIClsInsNormals>);
//     pcl::io::loadPCDFile<PointXYZIClsInsNormals>(pcd_vis_icp_params.source_cloud_params.filename, *source_cloud);
//     pcl::visualization::PointCloudColorHandlerCustom<PointXYZIClsInsNormals> source_cloud_color (source_cloud, pcd_vis_icp_params.source_cloud_params.r, pcd_vis_icp_params.source_cloud_params.g, pcd_vis_icp_params.source_cloud_params.b);
//     viewer->addPointCloud<PointXYZIClsInsNormals>(source_cloud, source_cloud_color, "source cloud");
//     viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, pcd_vis_icp_params.source_cloud_params.point_size, "source cloud");

    // // Add the target cloud
    // pcl::PointCloud<PointXYZIClsInsNormals>::Ptr target_cloud(new pcl::PointCloud<PointXYZIClsInsNormals>);
    // pcl::io::loadPCDFile<PointXYZIClsInsNormals>(pcd_vis_icp_params.target_cloud_params.filename, *target_cloud);
    // pcl::visualization::PointCloudColorHandlerCustom<PointXYZIClsInsNormals> target_cloud_color (target_cloud, pcd_vis_icp_params.target_cloud_params.r, pcd_vis_icp_params.target_cloud_params.g, pcd_vis_icp_params.target_cloud_params.b);
    // viewer->addPointCloud<PointXYZIClsInsNormals>(target_cloud, target_cloud_color, "target cloud");
    // viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, pcd_vis_icp_params.target_cloud_params.point_size, "target cloud");


    // // Add the source transformed cloud
    // pcl::PointCloud<PointXYZIClsInsNormals>::Ptr source_transf_cloud(new pcl::PointCloud<PointXYZIClsInsNormals>);
    // source_transf_cloud = source_cloud;

    // pcl::visualization::PointCloudColorHandlerCustom<PointXYZIClsInsNormals> source_transf_cloud_color (source_transf_cloud, pcd_vis_icp_params.source_transf_cloud_params.r, pcd_vis_icp_params.source_transf_cloud_params.g, pcd_vis_icp_params.source_transf_cloud_params.b);
    // viewer->addPointCloud<PointXYZIClsInsNormals>(source_transf_cloud, source_transf_cloud_color, "source transformed cloud");
    // viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, pcd_vis_icp_params.source_transf_cloud_params.point_size, "source transformed cloud");

    // // Orthographic (parallel) projection; same with pressing 'o'
    // // viewer->getRenderWindow()->GetRenderers()->GetFirstRenderer()->GetActiveCamera()->SetParallelProjection( 1 );
    
    // viewer->addCoordinateSystem(1.0);

    // viewer->initCameraParameters();
    
    // // viewer->spin();

    

    // // ICP
    // pcl::PointCloud<PointXYZIClsInsNormals>::Ptr source_cloud_with_normals (new pcl::PointCloud<PointXYZIClsInsNormals>);
    // pcl::PointCloud<PointXYZIClsInsNormals>::Ptr target_cloud_with_normals (new pcl::PointCloud<PointXYZIClsInsNormals>);
    // pcl::PointCloud<PointXYZIClsInsNormals>::Ptr source_transf_cloud_with_normals (new pcl::PointCloud<PointXYZIClsInsNormals>);


    // addNormal(source_cloud, source_cloud_with_normals);
    // addNormal(target_cloud, target_cloud_with_normals);
    // addNormal(source_transf_cloud, source_transf_cloud_with_normals);

    // // pcl::IterativeClosestPointWithNormals<PointXYZIClsInsNormals, PointXYZIClsInsNormals>::Ptr icp (new pcl::IterativeClosestPointWithNormals<PointXYZIClsInsNormals, PointXYZIClsInsNormals> ());

    // // icp->setMaximumIterations(1);
    // // icp->setInputSource(source_cloud_with_normals);
    // // icp->setInputTarget(target_cloud_with_normals);
    // // icp->align(*source_transf_cloud_with_normals);

    // // icp.setInputSource(source_cloud);
    // // icp.setInputTarget(target_cloud);


    // // icp.setMaximumIterations(1);
    // // // icp.setMaxCorrespondenceDistance(0.8);
    // // // icp.setTransformationEpsilon(1e-3);
    // // // icp.setEuclideanFitnessEpsilon(1e-3);


    // // while (!viewer->wasStopped ())
    // // {
    // //     icp.align(*source_transf_cloud);

    // //     if (icp.hasConverged ())
    // //     {
    // //         std::cout << "\nICP has converged, score is " << icp.getFitnessScore () << std::endl;
    // //         std::cout << "\nICP transformation " << icp.getFinalTransformation () << std::endl;
    // //         viewer->updatePointCloud(source_transf_cloud, source_transf_cloud_color, "source transformed cloud");
    // //     }
    // //     else
    // //     {
    // //         std::cout << "\nICP has not converged." << std::endl;
    // //     }

    // //     viewer->spinOnce (3000);
        
    // // }

    

    // // pcd_vis_icp_params.transformation_matrix = icp.getFinalTransformation();


    // std::string filename = "/Users/bisalgt/Projects/pcd_object_transfer/data/test_icp_normal_temp.pcd";
    // pcl::io::savePCDFileASCII("/Users/", *source_transf_cloud_with_normals);
    // // // Concatenate the aligned cloud and the target cloud
    // // // pcl::PointCloud<PointXYZIClsInsNormals>::Ptr cloud_merged (new pcl::PointCloud<PointXYZIClsInsNormals>);
    // // // *cloud_merged = aligned_cloud + *cloud_target;
    // // // pcl::io::savePCDFileASCII(pcd_vis_icp_params.output_filename, *cloud_merged);

    // // std::cout << "has converged:" << icp.hasConverged() << " score: " <<icp.getFitnessScore() << std::endl;
    // // std::cout << icp.getFinalTransformation() << std::endl;



// }