/*
	Author: Golovenko Anton
	Data: 16.10.2019
	Project: Game of live
	Rules link: https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
	IDE: Clion 2019
*/

#include <iostream>
#include <thread>
#include <chrono>
#include "lib.h"

int main()
{
    uint32_t iteration = 0;
    bool win_game = false;

    dot field[height][width];
    dot prev_field[height][width];

    init_field(field);

    do
    {
        iteration++;
        field_state_copy(field, prev_field);
        calc_new_field(field, prev_field);
        //system("clear"); // comment if you want track a history
        show_field(field);
        if ((alive_cnt == 0) || field_cmp(field, prev_field) == 0)
            win_game = true;

        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // delay for comfortable display

    } while (!win_game);
    std::cout << std::endl << "Game finished succesfully on " << iteration << "th iterations" << std::endl;
}