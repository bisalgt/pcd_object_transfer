#ifndef USER_DEFINED_PARAMS_H

#define USER_DEFINED_PARAMS_H

#include <string>
#include <Eigen/Core>



struct Point {
    float x, y, z, intensity;
};

// struct PointWithLabel {
//     float x, y, z;
//     uint16_t label;
// };

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


struct PCDRegistrationParams {
    std::string source_cloud;
    std::string target_cloud;
    std::string output_cloud;
    Eigen::Matrix4f transformation_matrix;

};


struct PCDTransformParams {
    std::string input_filename;
    std::string output_filename;
    Eigen::Matrix4f transformation_matrix;
};


struct PCDExtractObjectParams : FileInputOutputParams {
    int class_id {-1};
    int instance_id {-1};
};


// struct SourceCloudParams {
//     int r{0};
//     int g{255};
//     int b{0};
//     int point_size{1};
// }

// struct TargetCloudParams {
//     int r{255};
//     int g{255};
//     int b{255};
//     int point_size{1};
// }

// struct SourceTransfCloudParams {
//     int r{255};
//     int g{0};
//     int b{255};
//     int point_size{1};
// }

// struct PCDVisualizerParams {
//     std::string source_cloud_filename;
//     std::string target_cloud_filename;
//     std::string source_transf_cloud_filename;
//     SourceCloudParams source_cloud_params;
//     TargetCloudParams target_cloud_params;
//     SourceTransfCloudParams source_transf_cloud_params;
    
// }

#endif // USER_DEFINED_PARAMS_H