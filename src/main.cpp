#include <iostream>

#include "main.h"
#include "UserDefinedParams.h"
#include "Constants.h"




int main(int, char**){

    std::cout << "Hello, from PointCloudObjTransfer!\n";

    // std::string bin_filename { "/Users/bisalgt/Projects/pcd_object_transfer/data/000000.bin" };
    // std::string pcd_filename { "/Users/bisalgt/Projects/pcd_object_transfer/data/cuboid_10by10by10.pcd" };
    // print_from_semantic_kitti_bin_file(bin_filename);

    // --> Create a struct to hold input bin filename and output pcd filename
    // Reading a bin file and converting to pcd file
    // FileInputOutputParams file_bin_to_pcd_params;
    // file_bin_to_pcd_params.input_filename = PCD_OBJ_TRANSFER_CONSTANTS::BIN_FILE_NAME;
    // read_and_write_to_pcd(file_bin_to_pcd_params);

    // --> Creating a stuct of type PCDSolidParams
    // Creating a sample pcd file of a cuboid [default size 10x10x10]
    // PCDSolidParams pcd_solid_params;
    // pcd_solid_params.pcd_filename = PCD_OBJ_TRANSFER_CONSTANTS::PCD_CUBOID_HOLLOW_FILE_NAME;
    // create_cuboid_pcd(pcd_solid_params);

    // --> Creating a sample pcd file of a plane [default size 100x100]
    // PCDSolidParams pcd_solid_params;
    // pcd_solid_params.length = 100;
    // pcd_solid_params.height = 100;
    // pcd_solid_params.pcd_filename = PCD_OBJ_TRANSFER_CONSTANTS::PCD_PLANE_FILE_NAME;
    // create_plane_pcd(pcd_solid_params);

    // --> Create a sample spiked plane of pcd [default size 100x100]
    // PCDSolidParams pcd_solid_params;
    // pcd_solid_params.length = 100;
    // pcd_solid_params.height = 100;
    // pcd_solid_params.pcd_filename = PCD_OBJ_TRANSFER_CONSTANTS::PCD_SPIKED_PLANE_FILE_NAME;
    // create_spiked_plane_pcd(pcd_solid_params);


    // --> Create a sample inclined plane of pcd [default size 100x100]
    // PCDSolidParams pcd_solid_params;
    // pcd_solid_params.length = 100;
    // pcd_solid_params.height = 100;
    // pcd_solid_params.pcd_filename = PCD_OBJ_TRANSFER_CONSTANTS::PCD_INCLINED_PLANE_FILE_NAME;
    // create_inclined_plane_pcd(pcd_solid_params);

    

    // --> Creating a stuct of type TransformParams and passing it to tranform_pcd_and_save to transform pointcloud and save it
    // Transforming the pointcloud and saving it
    // TransformParams transform_params;
    // transform_params.x_translate = 0;
    // transform_params.y_translate = 9.0;
    // transform_params.z_translate = 0;
    // // transform_params.x_rotation = 0.0; // 0.78 radians ~ 45 degrees
    // transform_params.input_filename = PCD_OBJ_TRANSFER_CONSTANTS::PCD_BUNNY_1_FILE_NAME;
    // transform_pcd_and_save(transform_params);

    // --> Concatenate two pointclouds simple plane and cuboid
    // ConcatenatePCDParams concatenate_two_pcds_params;
    // concatenate_two_pcds_params.input_filename = transform_params.output_filename;
    // concatenate_two_pcds_params.input_filename_2 = PCD_OBJ_TRANSFER_CONSTANTS::PCD_INCLINED_PLANE_FILE_NAME;
    // concatenate_two_pcds_params.output_filename = PCD_OBJ_TRANSFER_CONSTANTS::PCD_CONCAT_CUBOID_HOLLOW_WITH_INCLINED_PLANE_FILE_NAME;
    // concatenate_two_pcds(concatenate_two_pcds_params);

    // --> Concatenate two pointclouds spiked plane and cuboid
    // ConcatenatePCDParams concatenate_two_pcds_params;
    // concatenate_two_pcds_params.input_filename = PCD_OBJ_TRANSFER_CONSTANTS::PCD_SPIKED_PLANE_FILE_NAME;
    // concatenate_two_pcds_params.input_filename_2 = PCD_OBJ_TRANSFER_CONSTANTS::PCD_CUBOID_FILE_NAME;
    // concatenate_two_pcds_params.output_filename = PCD_OBJ_TRANSFER_CONSTANTS::PCD_CONCAT_WITH_SPIKED_PLANE_FILE_NAME;
    // concatenate_two_pcds_spiked_plane_and_cuboid(concatenate_two_pcds_params);


    // --> Scaling a pointcloud
    ScalePCDParams scale_pcd_params;
    scale_pcd_params.input_filename = PCD_OBJ_TRANSFER_CONSTANTS::PCD_BUNNY_1_FILE_NAME;
    scale_pcd_params.output_filename = PCD_OBJ_TRANSFER_CONSTANTS::PCD_BUNNY_1_TRANSFORMED_FILE_NAME;
    scale_pcd_params.scaling_factor = 100.0;

    scale_or_multiply_pcd(scale_pcd_params);


    // --> Experimenting with ICP
    // ConcatenatePCDParams concatenate_two_pcds_params;
    // concatenate_two_pcds_params.input_filename = transform_params.output_filename;
    // concatenate_two_pcds_params.input_filename_2 = PCD_OBJ_TRANSFER_CONSTANTS::PCD_INCLINED_PLANE_FILE_NAME;
    // concatenate_two_pcds_params.output_filename = PCD_OBJ_TRANSFER_CONSTANTS::PCD_BASIC_ICP_FILE_NAME;
    // basic_icp_registration(concatenate_two_pcds_params);

    // Visualizing the pointcloud
    pcd_visualizer(scale_pcd_params.output_filename);



    
    
}
