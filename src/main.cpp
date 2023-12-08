#include <iostream>
#include <string>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/common/transforms.h>

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
    // file_in_out_params.input_filename = "/Users/bisalgt/Projects/pcd_object_transfer/data/bun000_scaled_transformed_transformed.pcd";
    // file_in_out_params.output_filename = PCD_OBJ_TRANSFER_CONSTANTS::PCD_BUNNY_1_SCALED_TRANSFORMED_SUBSAMPLED_FILE_NAME;
    // sub_sample_pcd(file_in_out_params);

    // --> Experimenting with ICP
    // PCDRegistrationParams pcd_registration_params;
    // pcd_registration_params.source_cloud = PCD_OBJ_TRANSFER_CONSTANTS::PCD_BUNNY_1_SCALED_TRANSFORMED_SUBSAMPLED_FILE_NAME;
    // pcd_registration_params.target_cloud = PCD_OBJ_TRANSFER_CONSTANTS::PCD_INCLINED_PLANE_FILE_NAME;
    // pcd_registration_params.output_cloud = PCD_OBJ_TRANSFER_CONSTANTS::PCD_BASIC_ICP_FILE_NAME;
    // basic_icp_registration(pcd_registration_params);

    // --> Transforming a pointcloud
    // PCDTransformParams pcd_transform_params;
    // pcd_transform_params.input_filename = "/Users/bisalgt/Projects/pcd_object_transfer/data/bun000_scaled_transformed_transformed.pcd";
    // pcd_transform_params.output_filename = "/Users/bisalgt/Projects/pcd_object_transfer/data/bun000_scaled_final_transformed.pcd";
    // pcd_transform_params.transformation_matrix = pcd_registration_params.transformation_matrix;
    // transform_pcd_from_matrix4f(pcd_transform_params);

    // --> Concatenating transformed bunny with inclined plane
    // ConcatenatePCDParams concatenate_two_pcds_params;
    // concatenate_two_pcds_params.input_filename = pcd_transform_params.output_filename;
    // concatenate_two_pcds_params.input_filename_2 = PCD_OBJ_TRANSFER_CONSTANTS::PCD_INCLINED_PLANE_FILE_NAME;
    // concatenate_two_pcds_params.output_filename = "/Users/bisalgt/Projects/pcd_object_transfer/data/bun000_scaled_final_transformed_concat_with_inclined_plane.pcd";
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

    pcl::PointCloud<PointXYZIClsIns>::Ptr cloud_with_label(new pcl::PointCloud<PointXYZIClsIns>);
    pcl::io::loadPCDFile<PointXYZIClsIns>(PCD_OBJ_TRANSFER_CONSTANTS::PCD_FILENAME_REFERENCE, *cloud_with_label);

    pcl::PointCloud<PointXYZIClsIns>::Ptr person_cloud(new pcl::PointCloud<PointXYZIClsIns>);

    for (int i = 0; i < cloud_with_label->points.size(); ++i) {
        if (cloud_with_label->points[i].class_id == 30 && cloud_with_label->points[i].instance_id == 3){
            std::cout<<"Aperson"<<std::endl;
            person_cloud->push_back(cloud_with_label->points[i]);
        }
    }

    pcl::io::savePCDFileASCII("/Users/bisalgt/Projects/pcd_object_transfer/data/002617_with_label_filtered_person.pcd", *person_cloud);


    pcd_visualizer("/Users/bisalgt/Projects/pcd_object_transfer/data/002617_with_label_filtered_person.pcd");



    
    
}
