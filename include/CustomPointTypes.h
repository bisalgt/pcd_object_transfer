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