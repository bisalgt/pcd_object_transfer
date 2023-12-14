#define PCL_NO_PRECOMPILE
#include <pcl/memory.h>
#include <pcl/pcl_macros.h>
#include <pcl/point_types.h>


struct EIGEN_ALIGN16 PointXYZIClsIns // Point type with X, Y, Z, Intensity, Class ID, Instance ID
{
  PCL_ADD_POINT4D; // This adds the members x,y,z which can also be accessed using the point (which is float[4])
  float intensity {0.0f};
  uint16_t class_id {0};
  uint16_t instance_id {0};
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW   // make sure our new allocators are aligned
} ; // enforce SSE padding for correct memory alignment

POINT_CLOUD_REGISTER_POINT_STRUCT (PointXYZIClsIns,
                                   (float, x, x)
                                   (float, y, y)
                                   (float, z, z)
                                   (float, intensity, intensity)
                                   (uint16_t, class_id, class_id)
                                   (uint16_t, instance_id, instance_id)
)





struct EIGEN_ALIGN16 PointXYZINormClsIns // Point type with X, Y, Z, Intensity, Class ID, Instance ID, Normals
{
  PCL_ADD_POINT4D; // This adds the members x,y,z which can also be accessed using the point (which is float[4])
  float intensity {0.0f};
  
  // float data_n[4];
  // float normal[3];
  float normal_x {0.0f};
  float normal_y {0.0f};
  float normal_z {0.0f};
  float curvature {0.0f};
  uint16_t class_id {0};
  uint16_t instance_id {0};

  EIGEN_MAKE_ALIGNED_OPERATOR_NEW   // make sure our new allocators are aligned
} ; // enforce SSE padding for correct memory alignment

POINT_CLOUD_REGISTER_POINT_STRUCT (PointXYZINormClsIns,
                                   (float, x, x)
                                   (float, y, y)
                                   (float, z, z)
                                   (float, intensity, intensity)
                                    // (float[4], data_n, data_n)
                                    // (float[3], normal, normal)
                                    (float, normal_x, normal_x)
                                    (float, normal_y, normal_y)
                                    (float, normal_z, normal_z)
                                    (float, curvature, curvature)
                                    (uint16_t, class_id, class_id)
                                    (uint16_t, instance_id, instance_id)
)


