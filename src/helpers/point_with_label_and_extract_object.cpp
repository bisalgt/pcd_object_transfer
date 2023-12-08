#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <vector>
#include <fstream>

#include "UserDefinedParams.h"
#include "CustomPointTypes.h"



void read_and_write_to_pcd_with_label(std::string bin_filename, std::string label_filename) {
    std::ifstream bin_file(bin_filename, std::ios::binary);
    std::ifstream label_file(label_filename, std::ios::binary);

    if (!bin_file || !label_file) { 
        std::cerr << "Could not open either of the file\n";
        return;
    }

    pcl::PointCloud<PointXYZIClsIns> cloud_with_label;

    Point point;
    while (bin_file.read((char*)&point, sizeof(Point))) {
        PointXYZIClsIns pcl_point_with_label;
        pcl_point_with_label.x = point.x;
        pcl_point_with_label.y = point.y;
        pcl_point_with_label.z = point.z;
        pcl_point_with_label.intensity = point.intensity;
        cloud_with_label.push_back(pcl_point_with_label);
    }

    uint32_t label;
    uint64_t indx = 0;

    for (indx = 0; indx < cloud_with_label.size(); ++indx) {
        label_file.read(reinterpret_cast<char*>(&label), sizeof(label));
        uint16_t first_half = label >> 16; // Shift right by 16 bits to get the first half
        uint16_t second_half = label & 0xFFFF; // Bitwise AND with 0xFFFF to get the second half

        cloud_with_label.points[indx].instance_id = first_half;
        cloud_with_label.points[indx].class_id = second_half;
    }

    std::cout<<"Index is: "<<indx<<std::endl;
    std::cout << "cloud size is: " << cloud_with_label.size() << std::endl;
    std::cout<<"Size of label : "<<sizeof(label)<<std::endl;

    cloud_with_label.width = cloud_with_label.size();
    cloud_with_label.height = 1;
    cloud_with_label.is_dense = false;

    std::string output_filename = bin_filename.substr(0, bin_filename.size()-4) + "_with_label.pcd";

    if (pcl::io::savePCDFileASCII(output_filename, cloud_with_label) == -1) {
        std::cerr << "Could not write output file\n";
        return;
    }

    std::cerr << "Saved " << cloud_with_label.size() << " data points to "<< output_filename << std::endl;
}



void read_label_file(std::string filename)
{
    std::ifstream file(filename, std::ios::binary);

    if (!file)
    {
        std::cerr << "Could not open file: " << filename << std::endl;
        return;
    }

    uint32_t label;

    std::cout<<"Size of uint32_t: "<<sizeof(uint32_t)<<std::endl;

    while (file.read(reinterpret_cast<char*>(&label), sizeof(label)))
    {
        uint16_t first_half = label >> 16; // Shift right by 16 bits to get the first half
        uint16_t second_half = label & 0xFFFF; // Bitwise AND with 0xFFFF to get the second half

        std::cout << "First half: " << first_half << ", Second half: " << second_half << std::endl;
    }
}