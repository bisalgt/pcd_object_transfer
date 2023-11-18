#include <iostream>
#include <fstream>
#include <cmath>


struct Point {
    float x;
    float y;
    float z;
    float intensity;
};

void print_from_semantic_kitti_bin_file(const std::string& filename)
{
    std::cout << "convert_to_pcd() function called " << filename<< std::endl;

    // const char* filename = "data/000000.bin";

    std::ifstream file(filename, std::ios::binary);
    
    if (!file.is_open())
    {
        std::cout << "Could not open file ssss" << filename << std::endl;
        return;
    }

    // the .bin file has a single column and muliple rows [x,y,z,intensity,x,y,z,intensity,x,y,z,intensity...]
    // float value;
    // int count {0};
    // while (file.read((char*)&value, sizeof(float)))
    // {
    //     count++;
    //     std::cout << value << std::endl;
    // }
    // std::cout<<"The total number of pointsss is: " << count << count/4.0 << std::endl;

    // Printing the content of .bin file
    Point point;
    int count {0};
    while (file.read((char*)&point, sizeof(Point)))
    {
        count++;
        std::cout << "x: " << point.x << " y: " << point.y << " z: " << point.z << " intensity: " << point.intensity << std::endl;
    }
    std::cout<<"The total number of points is: " << count << std::endl;
}