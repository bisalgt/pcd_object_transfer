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


struct SourceCloudParams {
    std::string filename;
    double r{0.0};
    double g{255.0};
    double b{0.0};
    int point_size{1};
};

struct TargetCloudParams {
    std::string filename;
    double r{255.0};
    double g{255.0};
    double b{255.0};
    int point_size{1};
};

struct SourceTransfCloudParams {
    std::string filename;
    double r{255.0};
    double g{0.0};
    double b{255.0};
    int point_size{1};
};

struct PCDVisualizerICPParams {
    SourceCloudParams source_cloud_params;
    TargetCloudParams target_cloud_params;
    SourceTransfCloudParams source_transf_cloud_params;
    
};


struct ICPParams {

    // Source: PCL Documentation

    // IterativeClosestPoint provides a base implementation of the Iterative Closest Point algorithm.

    // The transformation is estimated based on Singular Value Decomposition (SVD).

    // The algorithm has several termination criteria:

    // Number of iterations has reached the maximum user imposed number of iterations (via setMaximumIterations)
    // The epsilon (difference) between the previous transformation and the current estimated transformation is smaller than an user imposed value (via setTransformationEpsilon)
    // The sum of Euclidean squared errors is smaller than a user defined threshold (via setEuclideanFitnessEpsilon)


    int max_iterations{1};
    double transformation_epsilon{1e-6};
    double euclidean_fitness_epsilon{1e-6};
    double max_correspondence_distance{0.1}; // 10 cm // Set the maximum correspondence distance threshold (correspondences with higher distances will be ignored)
};

#endif // USER_DEFINED_PARAMS_H