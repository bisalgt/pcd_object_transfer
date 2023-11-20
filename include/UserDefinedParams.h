#ifndef USER_DEFINED_PARAMS_H

#define USER_DEFINED_PARAMS_H

#include <string>


struct Point {
    float x, y, z, intensity;
};

struct CuboidParams
{
    int length = 10;
    int width = 10;
    int height = 10;
    std::string pcd_filename;
};


struct FileInputOutputParams
{
    std::string input_filename;
    std::string output_filename;
};


#endif // USER_DEFINED_PARAMS_H