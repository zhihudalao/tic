
-- WARNING: we create a lot of X-Rays of a potentially large space in this
-- pipeline. For example, running over the
-- ist_slam_paper_deutsches_museum.bag requires ~25GiB of memory. You can
-- reduce this by writing fewer X-Rays or upping VOXEL_SIZE - which is the size
-- of a pixel in a X-Ray.
VOXEL_SIZE = 5e-2

include "transform.lua"

options = {
  tracking_frame = "base_link",
  pipeline = {
    {
      action = "min_max_range_filter",
      min_range = 1.,
      max_range = 60.,
    },
    {
      action = "dump_num_points",
    },
    {
      action = "write_xray_image",
      voxel_size = VOXEL_SIZE,
      filename = "xray_yz_all",
      transform = YZ_TRANSFORM,
    },
    {
      action = "write_xray_image",
      voxel_size = VOXEL_SIZE,
      filename = "xray_xy_all",
      transform = XY_TRANSFORM,
    },
    {
      action = "write_xray_image",
      voxel_size = VOXEL_SIZE,
      filename = "xray_xz_all",
      transform = XZ_TRANSFORM,
    },
  }
}

return options
