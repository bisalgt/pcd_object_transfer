#ifndef MAIN_H

#define MAIN_H

#include <string>
#include "UserDefinedParams.h"

void printsth();
void print_from_semantic_kitti_bin_file(const std::string& filename);
void read_and_write_to_pcd(FileInputOutputParams& file_bin_to_pcd_params);
void pcd_visualizer(const std::string& filename);

void create_cuboid_pcd(const PCDSolidParams& pcd_solid_params);
void create_plane_pcd(const PCDSolidParams& pcd_solid_params);
void create_spiked_plane_pcd(const PCDSolidParams& pcd_solid_params);

void transform_pcd_and_save(TransformParams& transform_params);

void concatenate_two_pcds(const ConcatenatePCDParams& concatenate_two_pcds_params);
void concatenate_two_pcds_spiked_plane_and_cuboid(const ConcatenatePCDParams& concatenate_two_pcds_params);



#endif // MAIN_H