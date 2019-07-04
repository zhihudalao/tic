
uint8 ACTIVE = 0
uint8 FINISHED = 1
uint8 FROZEN = 2
uint8 DELETED = 3

std_msgs/Header header
int32[] trajectory_id
uint8[] trajectory_state
