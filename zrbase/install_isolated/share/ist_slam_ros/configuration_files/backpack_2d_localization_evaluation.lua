
include "backpack_2d_localization.lua"

-- output map to base_link for evaluation
options.provide_odom_frame = false
POSE_GRAPH.optimization_problem.log_solver_summary = true

-- fast localization
MAP_BUILDER.num_background_threads = 12
POSE_GRAPH.constraint_builder.sampling_ratio = 0.5 * POSE_GRAPH.constraint_builder.sampling_ratio
POSE_GRAPH.global_sampling_ratio = 0.1 * POSE_GRAPH.global_sampling_ratio
POSE_GRAPH.max_num_final_iterations = 1

return options
