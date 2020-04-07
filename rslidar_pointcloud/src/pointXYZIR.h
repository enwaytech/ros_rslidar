#ifndef POINT_XYZIR_H_
#define POINT_XYZIR_H_
#define PCL_NO_PRECOMPILE
//#include <pcl/memory.h>
#include <pcl/pcl_macros.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/io/pcd_io.h>
#include <cstdint>

struct PointXYZIR
{
  PCL_ADD_POINT4D;
  float intensity;
  std::uint8_t ring;
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
} EIGEN_ALIGN16;

POINT_CLOUD_REGISTER_POINT_STRUCT (PointXYZIR,
                                   (float, x, x)
                                   (float, y, y)
                                   (float, z, z)
                                   (float, intensity, intensity)
                                   (uint8_t, ring, ring)
  )

typedef PointXYZIR PointT;

#endif
