#include <iostream>

#include "main.h"




int main(int, char**){

    std::cout << "Hello, from PointCloudObjTransfer! 1\n";
    printsth();

    std::string bin_filename { "/Users/bisalgt/Projects/pcd_object_transfer/data/000000.bin" };
    std::string pcd_filename { "/Users/bisalgt/Projects/pcd_object_transfer/data/000000.pcd" };
    // print_from_semantic_kitti_bin_file(filename);
    // read_and_write_to_pcd(bin_filename, pcd_filename);

    pcd_visualizer(pcd_filename);
    
    
}
