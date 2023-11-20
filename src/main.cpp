#include <iostream>

#include "main.h"
#include "UserDefinedParams.h"
#include "Constants.h"




int main(int, char**){

    std::cout << "Hello, from PointCloudObjTransfer!\n";

    // std::string bin_filename { "/Users/bisalgt/Projects/pcd_object_transfer/data/000000.bin" };
    // std::string pcd_filename { "/Users/bisalgt/Projects/pcd_object_transfer/data/cuboid_10by10by10.pcd" };
    // print_from_semantic_kitti_bin_file(bin_filename);

    // Create a struct to hold input bin filename and output pcd filename
    // Reading a bin file and converting to pcd file
    FileInputOutputParams file_bin_to_pcd_params;
    file_bin_to_pcd_params.input_filename = PCD_OBJ_TRANSFER_CONSTANTS::BIN_FILE_NAME;
    read_and_write_to_pcd(file_bin_to_pcd_params);

    // Creating a stuct of type CuboidParams
    // Creating a sample pcd file of a cuboid [default size 10x10x10]
    CuboidParams cuboid_params;
    cuboid_params.pcd_filename = PCD_OBJ_TRANSFER_CONSTANTS::PCD_CUBOID_FILE_NAME;
    create_cuboid_pcd(cuboid_params);

    // Creating a stuct of type FileInputOutputParams and passing it to tranform_pcd_and_save to transform pointcloud and save it
    // Transforming the pointcloud and saving it
    FileInputOutputParams file_input_output_transform_params;
    file_input_output_transform_params.input_filename = cuboid_params.pcd_filename;
    tranform_pcd_and_save(file_input_output_transform_params);
    
    // Visualizing the pointcloud
    pcd_visualizer(file_input_output_transform_params.output_filename);



    
    
}
