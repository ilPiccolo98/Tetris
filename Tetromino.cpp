#include "Tetromino.h"

Game::Tetromino::Tetromino(const std::string &tetromino, int current_x, int current_y, int current_rotation)
    : tetromino{ tetromino }, current_x{ current_x }, current_y{ current_y }, current_rotation{ 0 }
{
    set_current_rotation(current_rotation);
}

char Game::Tetromino::at_rotated(int x, int y) const
{
    switch(current_rotation)
    {
        case 0:
            return tetromino[y * width + x];
        case 1:
            return tetromino[12 + y - (x * width)];
        case 2:
            return tetromino[15 - (y * width) - x];
        case 3:
            return tetromino[3 - y + (x * width)];
    }
    return 0;
}

const char& Game::Tetromino::at(int x, int y) const
{
    return tetromino[y * width + x];
}

int Game::Tetromino::get_current_x() const noexcept
{
    return current_x;
}

int Game::Tetromino::get_current_y() const noexcept
{
    return current_y;
}

void Game::Tetromino::set_current_x(int current_x) noexcept
{
    this->current_x = current_x;
}

void Game::Tetromino::set_current_y(int current_y) noexcept
{
    this->current_y = current_y;
}


void Game::Tetromino::set_current_rotation(int current_rotation) noexcept
{
    this->current_rotation = current_rotation % 4;
}

int Game::Tetromino::get_current_rotation() const noexcept
{
    return current_rotation;
}

