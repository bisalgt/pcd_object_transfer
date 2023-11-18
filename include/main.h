#ifndef MAIN_H

#define MAIN_H

void printsth();
void print_from_semantic_kitti_bin_file(const std::string& filename);
void read_and_write_to_pcd(const std::string& input_filename, const std::string& output_filename);
void pcd_visualizer(const std::string& filename);


#endif // MAIN_H