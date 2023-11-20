#ifndef MAIN_H

#define MAIN_H

#include <string>
#include "UserDefinedParams.h"

void printsth();
void print_from_semantic_kitti_bin_file(const std::string& filename);
void read_and_write_to_pcd(FileInputOutputParams& file_bin_to_pcd_params);
void pcd_visualizer(const std::string& filename);

void create_cuboid_pcd(const CuboidParams& cuboid_params);
void tranform_pcd_and_save(FileInputOutputParams& file_input_output_transform_params);

#endif // MAIN_H