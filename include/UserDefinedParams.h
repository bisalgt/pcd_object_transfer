#ifndef USER_DEFINED_PARAMS_H

#define USER_DEFINED_PARAMS_H

#include <string>


struct Point {
    float x, y, z, intensity;
};

struct PCDSolidParams
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


struct TransformParams : FileInputOutputParams {
    float x_translate = 0;
    float y_translate = 0;
    float z_translate = 0;
    // angle of rotation in radians
    float x_rotation = 0;
    float y_rotation = 0;
    float z_rotation = 0;
};


#endif // USER_DEFINED_PARAMS_H