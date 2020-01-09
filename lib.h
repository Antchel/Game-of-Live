#include <cstdint>

const uint16_t height = 7;
const uint16_t width = 10;

struct dot
{
    uint16_t alive : 1;
};

void init_field(dot a[height][width]);
void show_field(dot a[height][width]);
uint64_t alive_cnt(dot a[height][width]);
uint16_t search_near_alive_dots(dot src[height][width], uint16_t x, uint16_t y);
void field_state_copy(dot real[height][width], dot saved[height][width]);
void calc_new_field(dot new_field[height][width], dot prev_field[height][width]);
int8_t field_cmp(dot curr_field[height][width], dot prev_field[height][width]);