#define PCL_NO_PRECOMPILE

#include <iostream>
#include <string>
#include <cmath>
#include <vector>


#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
// #include <pcl/common/transforms.h>
#include <pcl/common/io.h>
// #include <pcl/registration/icp.h>
#include <pcl/features/normal_3d.h>
#include <pcl/visualization/pcl_visualizer.h>


#include "main.h"
#include "UserDefinedParams.h"
#include "Constants.h"
#include "CustomPointTypes.h"






int main(int, char**){

    std::cout << "Hello, from PointCloudObjTransfer!\n";

    // --> Concatenate two pointclouds
    // ConcatenatePCDParams concatenate_two_pcds_params;
    // concatenate_two_pcds_params.input_filename = PCD_OBJ_TRANSFER_CONSTANTS::PCD_INCLINED_PLANE_FILE_NAME;
    // concatenate_two_pcds_params.input_filename_2 = PCD_OBJ_TRANSFER_CONSTANTS::PCD_BUNNY_1_SCALED_TRANSFORMED_FILE_NAME;
    // concatenate_two_pcds_params.output_filename = PCD_OBJ_TRANSFER_CONSTANTS::PCD_CONCAT_BUNNY_1_SCALED_TRANSFORMED_WITH_INCLINED_PLANE_FILE_NAME;
    // concatenate_two_pcds_with_y_axis_alignment(concatenate_two_pcds_params);


    // --> Scaling a pointcloud
    // ScalePCDParams scale_pcd_params;
    // scale_pcd_params.input_filename = PCD_OBJ_TRANSFER_CONSTANTS::PCD_BUNNY_1_FILE_NAME;
    // scale_pcd_params.output_filename = PCD_OBJ_TRANSFER_CONSTANTS::PCD_BUNNY_1_TRANSFORMED_FILE_NAME;
    // scale_pcd_params.scaling_factor = 100.0;
    // scale_or_multiply_pcd(scale_pcd_params);

    // --> Subsampling a pointcloud
    // goal is to extract the base and perform icp
    // FileInputOutputParams file_in_out_params;
    // file_in_out_params.input_filename = "/Users/bisalgt/Projects/pcd_object_transfer/data/002617_with_label_filtered_person_transformed.pcd";
    // file_in_out_params.output_filename = "/Users/bisalgt/Projects/pcd_object_transfer/data/002617_with_label_filtered_person_transformed_subsampled.pcd";
    // std::vector<float> z_values_references = sub_sample_pcd(file_in_out_params);

    // // --> Experimenting with ICP
    // PCDRegistrationParams pcd_registration_params;
    // pcd_registration_params.source_cloud = file_in_out_params.output_filename;
    // pcd_registration_params.target_cloud = "/Users/bisalgt/Projects/pcd_object_transfer/data/002617_with_label_filtered_road.pcd";
    // pcd_registration_params.output_cloud = "/Users/bisalgt/Projects/pcd_object_transfer/data/basic_icp_registration.pcd";
    // basic_icp_registration(pcd_registration_params);

    // // --> Transforming a pointcloud
    // PCDTransformParams pcd_transform_params;
    // pcd_transform_params.input_filename = "/Users/bisalgt/Projects/pcd_object_transfer/data/002617_with_label_filtered_person_transformed.pcd";
    // pcd_transform_params.output_filename = "/Users/bisalgt/Projects/pcd_object_transfer/data/002617_person_registered.pcd";
    // pcd_registration_params.transformation_matrix(2,3) = pcd_registration_params.transformation_matrix(2,3) + z_values_references[0]; // index 0 is threshold, index 2 is lower limit z
    // pcd_transform_params.transformation_matrix = pcd_registration_params.transformation_matrix;
    // transform_pcd_from_matrix4f(pcd_transform_params);

    // // --> Concatenating 
    // ConcatenatePCDParams concatenate_two_pcds_params;
    // concatenate_two_pcds_params.input_filename = pcd_transform_params.output_filename;
    // concatenate_two_pcds_params.input_filename_2 = "/Users/bisalgt/Projects/pcd_object_transfer/data/002617_with_label_filtered_road.pcd";
    // concatenate_two_pcds_params.output_filename = "/Users/bisalgt/Projects/pcd_object_transfer/data/002617_person_registered_with_road.pcd";
    // concatenate_two_pcds(concatenate_two_pcds_params);
    

    // std::string pcd_target_filename = PCD_OBJ_TRANSFER_CONSTANTS::PCD_000333_FILE_NAME;
    // std::string pcd_target_labelfilename = "/Users/bisalgt/Projects/pcd_object_transfer/data/000333.label";
    // Visualizing the pointcloud

    // read_label_file(pcd_target_labelfilename);

    // pcd_visualizer(pcd_target_filename);


    // FileInputOutputParams file_bin_to_pcd_params;
    // file_bin_to_pcd_params.input_filename = "/Users/bisalgt/Projects/pcd_object_transfer/data/3.bin";
    // // file_bin_to_pcd_params.output_filename = "/Users/bisalgt/Projects/pcd_object_transfer/data/3.pcd";
    // read_and_write_to_pcd(file_bin_to_pcd_params);

    // std::string bin_filename = PCD_OBJ_TRANSFER_CONSTANTS::BIN_FILENAME_REFERENCE;
    // std::string label_filename = PCD_OBJ_TRANSFER_CONSTANTS::LABEL_FILENAME_REFERENCE;
    // read_and_write_to_pcd_with_label(bin_filename, label_filename);

    // Extracting objects from pcd 

    // PCDExtractObjectParams pcd_extract_object_params;
    // pcd_extract_object_params.input_filename = "/Users/bisalgt/Projects/pcd_object_transfer/data/002617_with_label.pcd";
    // pcd_extract_object_params.output_filename = "/Users/bisalgt/Projects/pcd_object_transfer/data/002617_with_label_filtered_cars.pcd";
    // pcd_extract_object_params.class_id = 10;

    // extract_object_from_pcd_with_label(pcd_extract_object_params);


    // Concatenate two pcds
    // ConcatenatePCDParams concatenate_two_pcds_params;
    // concatenate_two_pcds_params.input_filename = "/Users/bisalgt/Projects/pcd_object_transfer/data/002617_with_label_filtered_road.pcd";
    // concatenate_two_pcds_params.input_filename_2 = "/Users/bisalgt/Projects/pcd_object_transfer/data/002617_with_label_filtered_person.pcd";
    // concatenate_two_pcds_params.output_filename = "/Users/bisalgt/Projects/pcd_object_transfer/data/002617_with_label_filtered_road_person.pcd";
    // concatenate_two_pcds(concatenate_two_pcds_params);

    // Translate to origin and Rotate
    // Eigen::Vector4f centroid;
    // pcl::PointCloud<PointXYZIClsIns>::Ptr cloud (new pcl::PointCloud<PointXYZIClsIns>);
    // pcl::io::loadPCDFile<PointXYZIClsIns>("/Users/bisalgt/Projects/pcd_object_transfer/data/002617_with_label_filtered_person.pcd", *cloud);
    // pcl::compute3DCentroid(*cloud, centroid);

    

    // Transform source cloud

    // TransformParams transform_params;
    // transform_params.input_filename = "/Users/bisalgt/Projects/pcd_object_transfer/data/002617_with_label_filtered_person.pcd";
    // // // transform_params.x_translate = -centroid[0];
    // // // transform_params.y_translate = -centroid[1];
    // // // transform_params.z_translate = -centroid[2];
    // transform_params.x_translate = 6.0;
    // transform_params.y_translate = 6.0;
    // transform_params.z_translate = 0.5;
    // // // // transform_params.x_rotation = 90.0  * (M_PI/180.0);
    // // // // transform_params.y_rotation = 90.0  * (M_PI/180.0); // degrees in radians
    // // // // transform_params.z_rotation = 90.0  * (M_PI/180.0); // degrees in radians
    // // transform_params.output_filename = "/Users/bisalgt/Projects/pcd_object_transfer/data/002617_with_label_filtered_person_transformed.pcd";
    
    // transform_pcd_and_save(transform_params);

    // pcd_visualizer(transform_params.output_filename);


    // Concate with target cloud == road

    // ConcatenatePCDParams concatenate_two_pcds_params;
    // concatenate_two_pcds_params.input_filename = "/Users/bisalgt/Projects/pcd_object_transfer/data/002617_with_label_filtered_road.pcd";
    // concatenate_two_pcds_params.input_filename_2 = transform_params.output_filename;
    // concatenate_two_pcds_params.output_filename = "/Users/bisalgt/Projects/pcd_object_transfer/data/002617_with_label_filtered_road_person_transformed.pcd";
    // concatenate_two_pcds(concatenate_two_pcds_params);


    // Using ICP and visualizer------------

    // PCDRegistrationParams pcd_registration_params{
    //     .source_cloud {"/Users/bisalgt/Projects/pcd_object_transfer/data/002617_with_label_filtered_person_transformed.pcd"},
    //     .target_cloud {"/Users/bisalgt/Projects/pcd_object_transfer/data/002617_with_label_filtered_road.pcd"},
    //     .output_cloud {"/Users/bisalgt/Projects/pcd_object_transfer/data/002617_person_registered_with_road.pcd"},
    // };

    // basic_icp_registration(pcd_registration_params);

    // // // // Visualize

    // PCDVisualizerICPParams pcd_visalize_icp_params {
    //     .source_cloud_params {
    //         .filename {"/Users/bisalgt/Projects/pcd_object_transfer/data/002617_person_registered_with_road.pcd"},
    //     },
    //     .target_cloud_params {
    //         .filename {"/Users/bisalgt/Projects/pcd_object_transfer/data/002617_with_label_filtered_road.pcd"},
    //     },
    //     .source_transf_cloud_params {
    //         .filename {"/Users/bisalgt/Projects/pcd_object_transfer/data/icp_iterative_reg_output.pcd"},
    //     },
    // };


    // pcd_visualizer_icp(pcd_visalize_icp_params);


    // icp_registration_with_iterative_view(pcd_visalize_icp_params);
    // icp_registration_with_normal_iterative_view(pcd_visalize_icp_params);


    

    // SourceCloudParams source_cloud_params {
    //     .filename {"/Users/bisalgt/Projects/pcd_object_transfer/data/002617_with_label_filtered_person.pcd"},
    //     .r {255},
    //     .g {0},
    //     .b {0},
    //     .point_size {1},
    // };

    // // Add the source cloud
    // pcl::PointCloud<PointXYZIClsIns>::Ptr source_cloud(new pcl::PointCloud<PointXYZIClsIns>);
    // pcl::io::loadPCDFile<PointXYZIClsIns>(source_cloud_params.filename, *source_cloud);
    // // pcl::visualization::PointCloudColorHandlerCustom<PointXYZIClsIns> source_cloud_color (source_cloud, source_cloud_params.r, source_cloud_params.g, source_cloud_params.b);
    // // viewer->addPointCloud<PointXYZIClsIns>(source_cloud, source_cloud_color, "source cloud");

    // boost::shared_ptr< pcl::visualization::PCLVisualizer > viewer ( new pcl::visualization::PCLVisualizer ("3D Viewer") );
    // viewer->setBackgroundColor(0.0, 0.0, 0.0);
    // viewer->addPointCloud<PointXYZIClsIns>(source_cloud, "source cloud");
    // // viewer->showCloud(source_cloud, "source cloud");


    // viewer->addCoordinateSystem(1.0);

    // viewer->initCameraParameters();
    
    // viewer->spin();


    // pcd_visualizer(concatenate_two_pcds_params.output_filename);




    // Read a point cloud as a custom point type
    // add normal to the point type
    // visualize the point cloud with normals

    // std::string filename {"/Users/bisalgt/Projects/pcd_object_transfer/data/002617_with_label_filtered_person.pcd"};

    // pcl::PointCloud<PointXYZINormClsIns>::Ptr cloud_source (new pcl::PointCloud<PointXYZINormClsIns>);
    
    // pcl::io::loadPCDFile<PointXYZINormClsIns>(filename, *cloud_source);


    // pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
    // viewer->setBackgroundColor(0.0, 0.0, 0.0);

    
    // add normals

    // std::cout<<"Normals calculation started\n"<<std::endl;

    // pcl::NormalEstimation<PointXYZINormClsIns, pcl::Normal> normalEstimator;
    // normalEstimator.setInputCloud ( cloud_source );
    // pcl::search::KdTree<PointXYZINormClsIns>::Ptr searchTree (new pcl::search::KdTree<PointXYZINormClsIns> ());
    // normalEstimator.setSearchMethod ( searchTree );
    // normalEstimator.setKSearch ( 15 );

    // pcl::PointCloud<pcl::Normal>::Ptr normals (new pcl::PointCloud<pcl::Normal>);
    // normalEstimator.compute ( *normals );

    // std::cout<<"Normals calculation finished\n"<<std::endl;
    // std::cout<<"Normals size: "<<normals->size()<<std::endl;
    // std::cout<<"Cloud size: "<<cloud_source->size()<<std::endl;



    // pcl::PointCloud<PointXYZINormClsIns>::Ptr cloud_with_normals (new pcl::PointCloud<PointXYZINormClsIns>);

    // pcl::concatenateFields( *cloud_source, *normals, *cloud_with_normals );



    // pcl::io::savePCDFileASCII ("/Users/bisalgt/Projects/pcd_object_transfer/data/test_pointxyzicinormals_.pcd", *cloud_with_normals);

    pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
    viewer->setBackgroundColor(0.0, 0.0, 0.0);

    std::string filename{"/Users/bisalgt/Projects/pcd_object_transfer/data/test_pointxyzicinormals_.pcd"};
    pcl::PointCloud<PointXYZINormClsIns>::Ptr cloud_source (new pcl::PointCloud<PointXYZINormClsIns>);
    pcl::io::loadPCDFile<PointXYZINormClsIns>(filename, *cloud_source);
    pcl::visualization::PointCloudColorHandlerCustom<PointXYZINormClsIns> source_cloud_color (cloud_source, 255, 0, 0);
    viewer->addPointCloud<PointXYZINormClsIns>(cloud_source, source_cloud_color, "cloud with normals");
    viewer->addCoordinateSystem(1.0);
    viewer->initCameraParameters();
    viewer->spin();

    // viewer->addPointCloud<PointXYZINormClsIns>(cloud_with_normals, "cloud with normals");

    // viewer->addCoordinateSystem(1.0);

    // viewer->initCameraParameters();

    // viewer->spin();
    
}
