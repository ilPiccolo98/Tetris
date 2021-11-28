#include <iostream>
#include "Matrix.h"
#include "Screen_buffer.h"
#include "Tetromino.h"
#include "Tetrominos.h"
#include <array>
#include "Logic.h"
#include <conio.h>
#include <thread>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;
using namespace Game;

int main()
{
    srand(time(nullptr));

    array<Tetromino, number_of_tetrominos> tetrominos{ get_tetrominos() };
    Matrix<int> field{ 18, 12, 0 };
    Matrix<char> buffer{ 30, 80, '\0' };
    Screen_buffer screen_buffer{};
    vector<int> lines{};

    add_border(field);


    constexpr int margin_left{ 32 };
    constexpr int margin_top{ 3 };
    bool run_game{ true };
    int current_tetromino{ 0 };
    tetrominos[current_tetromino].set_current_x((field.get_columns() - 3) / 2);

    int speed{ 20 };
    int force_down{ 0 };
    int number_of_pieces{ 0 };
    int score{ 0 };

    while(run_game)
    {
        const int current_x{ tetrominos[current_tetromino].get_current_x() };
        const int current_y{ tetrominos[current_tetromino].get_current_y() };
        const int current_rotation{ tetrominos[current_tetromino].get_current_rotation() };

        this_thread::sleep_for(20ms);


        if(kbhit())
        {
            switch(getch())
            {
                case 'a':
                    if(does_piece_fit(tetrominos[current_tetromino], field, current_x - 1, current_y))
                        tetrominos[current_tetromino].set_current_x(current_x - 1);
                    break;
                case 's':
                    if(does_piece_fit(tetrominos[current_tetromino], field, current_x, current_y + 1))
                        tetrominos[current_tetromino].set_current_y(current_y + 1);
                    break;
                case 'd':
                    if(does_piece_fit(tetrominos[current_tetromino], field, current_x + 1, current_y))
                        tetrominos[current_tetromino].set_current_x(current_x + 1);
                    break;
                case 'u':
                    tetrominos[current_tetromino].set_current_rotation(current_rotation + 1);
                    if(!does_piece_fit(tetrominos[current_tetromino], field, current_x, current_y))
                        tetrominos[current_tetromino].set_current_rotation(current_rotation);
                    break;
            }
        }

        if(force_down == speed)
        {
            if(does_piece_fit(tetrominos[current_tetromino], field, current_x, current_y + 1))
                tetrominos[current_tetromino].set_current_y(current_y + 1);
            else
            {
                lock_piece(tetrominos[current_tetromino], field, current_tetromino);

                ++number_of_pieces;
                if(number_of_pieces % 10 == 0 && speed >= 10)
                    --speed;

                check_lines(field, tetrominos[current_tetromino].get_current_y(), lines);
                draw_lines(field, lines);

                score += 25;
                if(!lines.empty())
                    score += lines.size() * 100;

                current_tetromino = rand() % number_of_tetrominos;
                tetrominos[current_tetromino].set_current_y(0);
                tetrominos[current_tetromino].set_current_x((field.get_columns() - 3) / 2);
                tetrominos[current_tetromino].set_current_rotation(0);

                run_game = does_piece_fit(tetrominos[current_tetromino], field, tetrominos[current_tetromino].get_current_x(), tetrominos[current_tetromino].get_current_y());
            }
            force_down = 0;
        }
        else
            ++force_down;


        draw_field(buffer, field, margin_left, margin_top);
        draw_tetromino(buffer, tetrominos[current_tetromino], current_tetromino, margin_left, margin_top);
        sprintf(&buffer.data()[2 * buffer.get_columns() + 6], "SCORE: %8d", score);


        if(!lines.empty())
        {
            screen_buffer.write_characters(buffer.data(), buffer.get_columns(), buffer.get_rows());
            this_thread::sleep_for(400ms);
            remove_lines(field, lines);
        }

        screen_buffer.write_characters(buffer.data(), buffer.get_columns(), buffer.get_rows());
    }
    screen_buffer.close();
    cout << "Game Over!! Score: " << score << '\n';
    system("pause");

    return 0;
}
