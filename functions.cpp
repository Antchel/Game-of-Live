#include <iostream>
#include <ctime>
#include "lib.h"

using namespace std;

void init_field(dot mas[height][width])
{
    uint16_t i, j;
    srand(time(NULL));
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            mas[i][j].alive = rand() % 2;
        }
    }
    show_field(mas);
}

void show_field(dot a[height][width])
{
    uint16_t i, j;
    for (i = 0; i < height; i++)
    {
        if (i != 0)
            cout <<"||"<< endl << "||";
        else
        {
            cout << "  ";
            for (int k = 0; k < width; k++)
                cout << "===";
            cout << endl << "||";
        }
        for (j = 0; j < width; j++)
        {
            if (a[i][j].alive == 0)
                cout << " - ";
            else
                cout << " o ";
        }
    }
    cout <<"||"<< endl << "  ";
    for (i = 0; i < width; i++)
        cout << "===";
    cout << endl;
}

uint64_t alive_cnt(dot a[height][width])
{
    uint64_t count = 0;
    uint16_t i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (a[i][j].alive == 1) {
                count++;
            }
        }
    }
    return count;
}

uint16_t search_near_alive_dots(dot src [height][width], uint16_t x, uint16_t y)
{
    int16_t i, j, cnt = 0, k = 0;

    for (i = x - 1; i <= x + 1; i++)
    {
        for (j = y - 1; j <= y + 1; j++)
        {
            if ((i < 0)||(j < 0)||(i >= height)||(j >= width) || (i == x && j == y)) {
                continue;
            }
            else
            {
                if (src[i][j].alive == 1)
                    cnt++;
            }
        }
    }
    return cnt;
}

void field_state_copy(dot real[height][width], dot saved[height][width])
{
    unsigned int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            saved[i][j] = real[i][j];
        }
    }
}

void calc_new_field(dot new_field[height][width], dot prev_field[height][width])
{
    uint16_t i, j;
    uint8_t live_dots;
    dot p;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            p = prev_field[i][j];
            live_dots = search_near_alive_dots(prev_field, i, j);

            if (p.alive == 0) {
                if (live_dots == 3) {
                    new_field[i][j].alive = 1;
                }
            }
            else {
                if (live_dots < 2 || live_dots > 3) {
                    new_field[i][j].alive = 0;
                }
            }
        }
    }
}

int8_t field_cmp(dot curr_field[height][width], dot prev_field[height][width])
{
    uint16_t i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (curr_field[i][j].alive != prev_field[i][j].alive) {
                return -1;
            }
        }
    }
    return 0;
}
