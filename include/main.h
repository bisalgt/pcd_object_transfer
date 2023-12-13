#ifndef MAIN_H

#define MAIN_H

#include <string>
#include <vector>
#include "UserDefinedParams.h"

void printsth();
void print_from_semantic_kitti_bin_file(const std::string& filename);
void read_and_write_to_pcd(FileInputOutputParams& file_bin_to_pcd_params);
void pcd_visualizer(const std::string& filename);

void create_cuboid_pcd(const PCDSolidParams& pcd_solid_params);
void create_plane_pcd(const PCDSolidParams& pcd_solid_params);
void create_spiked_plane_pcd(const PCDSolidParams& pcd_solid_params);
void create_inclined_plane_pcd(const PCDSolidParams& pcd_solid_params);

void transform_pcd_and_save(TransformParams& transform_params);

void concatenate_two_pcds(const ConcatenatePCDParams& concatenate_two_pcds_params);
void concatenate_two_pcds_with_y_axis_alignment(const ConcatenatePCDParams& concatenate_two_pcds_params);

void basic_icp_registration(PCDRegistrationParams& pcd_registration_params);

void scale_or_multiply_pcd(const ScalePCDParams& scale_pcd_params);

std::vector<float> sub_sample_pcd(const FileInputOutputParams& file_in_out_params);

void transform_pcd_from_matrix4f(PCDTransformParams& pcd_transform_params);

void read_label_file(std::string filename);

void read_and_write_to_pcd_with_label(std::string bin_filename, std::string label_filename);

void extract_object_from_pcd_with_label(const PCDExtractObjectParams& pcd_extract_object_params);

void pcd_visualizer_icp(const PCDVisualizerICPParams& pcd_vis_icp_params);

void icp_registration_with_iterative_view(PCDVisualizerICPParams& pcd_vis_icp_params);


#endif // MAIN_H