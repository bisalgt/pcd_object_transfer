#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <iostream>

#include "Constants.h"
#include "UserDefinedParams.h"
#include "CustomPointTypes.h"

void extract_object_from_pcd_with_label(const PCDExtractObjectParams& pcd_extract_object_params);

void extract_object_from_pcd_with_label(const PCDExtractObjectParams& pcd_extract_object_params) {
    pcl::PointCloud<PointXYZIClsIns>::Ptr cloud_with_label(new pcl::PointCloud<PointXYZIClsIns>);
    pcl::io::loadPCDFile<PointXYZIClsIns>(pcd_extract_object_params.input_filename, *cloud_with_label);

    pcl::PointCloud<PointXYZIClsIns>::Ptr custom_cloud(new pcl::PointCloud<PointXYZIClsIns>);

    for (int i = 0; i < cloud_with_label->points.size(); ++i) {
        if (cloud_with_label->points[i].class_id == pcd_extract_object_params.class_id){
            if (pcd_extract_object_params.instance_id != -1) { // if instance id is not -1, then we need to extract object with instance id
                if (cloud_with_label->points[i].instance_id == pcd_extract_object_params.instance_id) 
                {
                    custom_cloud->push_back(cloud_with_label->points[i]);
                }
            } 
            else {
                custom_cloud->push_back(cloud_with_label->points[i]);
            }
        }
    }

    // pcd_extract_object_params.output_filename = pcd_extract_object_params.input_filename.substr(0, pcd_extract_object_params.input_filename.size()-4) + "_extracted_object.pcd";

    pcl::io::savePCDFileASCII(pcd_extract_object_params.output_filename, *custom_cloud);

    std::cout<<"Extracted object saved to: "<<pcd_extract_object_params.output_filename<<std::endl;
    std::cout<<"Number of points in the extracted object: "<<custom_cloud->points.size()<<std::endl;

}