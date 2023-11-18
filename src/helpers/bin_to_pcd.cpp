#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <fstream>

struct Point {
    float x, y, z, intensity;
};

void read_and_write_to_pcd(const std::string& input_filename, const std::string& output_filename) {
    std::ifstream file(input_filename, std::ios::binary);
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

    if (pcl::io::savePCDFileASCII(output_filename, cloud) == -1) {
        std::cerr << "Could not write output file\n";
        return;
    }

    std::cerr << "Saved " << cloud.size() << " data points to "<< output_filename << std::endl;
}