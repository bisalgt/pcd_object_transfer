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


struct ConcatenatePCDParams : FileInputOutputParams {
    std::string input_filename_2;
};

struct ROIParams {
    float x_min;
    float x_max;
    float y_min;
    float y_max;
    float z_min;
    float z_max;
};


struct ScalePCDParams : FileInputOutputParams {
    float scaling_factor = 1.0; // all same for x, y or z
};


#endif // USER_DEFINED_PARAMS_H