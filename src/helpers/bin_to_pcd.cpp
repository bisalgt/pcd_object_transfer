#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <fstream>

#include "UserDefinedParams.h"



void read_and_write_to_pcd(FileInputOutputParams& file_bin_to_pcd_params) {
    std::ifstream file(file_bin_to_pcd_params.input_filename, std::ios::binary);
    if (!file) {
        std::cerr << "Could not open input file\n";
        return;
    }

    pcl::PointCloud<pcl::PointXYZI> cloud;

    Point point;
    while (file.read((char*)&point, sizeof(Point))) {
        pcl::PointXYZI pcl_point;
        pcl_point.x = point.x;
        pcl_point.y = point.y;
        pcl_point.z = point.z;
        pcl_point.intensity = point.intensity;
        cloud.push_back(pcl_point);
    }

    cloud.width = cloud.size();
    cloud.height = 1;
    cloud.is_dense = false;

    file_bin_to_pcd_params.output_filename = file_bin_to_pcd_params.input_filename.substr(0, file_bin_to_pcd_params.input_filename.size()-4) + ".pcd";

    if (pcl::io::savePCDFileASCII(file_bin_to_pcd_params.output_filename, cloud) == -1) {
        std::cerr << "Could not write output file\n";
        return;
    }

    std::cerr << "Saved " << cloud.size() << " data points to "<< file_bin_to_pcd_params.output_filename << std::endl;
}