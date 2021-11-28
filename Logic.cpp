#include "Logic.h"
#include <error.h>
#include <iostream>

bool is_it_border(int row, int column, int rows, int columns) noexcept
{
    return (column == 0 || column == columns - 1 || row == rows - 1) ? true : false;
}

char mapped_skin(int skin) noexcept
{
    return " ABCDEFG=#"[skin];
}

std::array<Game::Tetromino, Game::number_of_tetrominos> Game::get_tetrominos() noexcept
{
    Tetromino tetromino1{ get_tetromino_1() };
    Tetromino tetromino2{ get_tetromino_2() };
    Tetromino tetromino3{ get_tetromino_3() };
    Tetromino tetromino4{ get_tetromino_4() };
    Tetromino tetromino5{ get_tetromino_5() };
    Tetromino tetromino6{ get_tetromino_6() };
    Tetromino tetromino7{ get_tetromino_7() };
    std::array<Tetromino, number_of_tetrominos> tetrominos=
    {
        tetromino1,
        tetromino2,
        tetromino3,
        tetromino4,
        tetromino5,
        tetromino6,
        tetromino7,
    };

    return tetrominos;
}

void Game::add_border(Matrix<int> &field) noexcept
{
    for(int row{ 0 }; row != field.get_rows(); ++row)
        for(int column{ 0 }; column != field.get_columns(); ++column)
            field.at(row, column) = (is_it_border(row, column, field.get_rows(), field.get_columns())) ? 9 : 0;
}

void Game::draw_field(Matrix<char> &buffer, const Matrix<int> &field, int margin_left, int margin_top) noexcept
{
    for(int row{0}; row != field.get_rows(); ++row)
        for(int column{0}; column != field.get_columns(); ++column)
            buffer.at(row + margin_top, column + margin_left) = mapped_skin(field.at(row, column));
}

void Game::draw_tetromino(Matrix<char> &buffer, const Tetromino &tetromino, int current_tetromino, int margin_left, int margin_top) noexcept
{
    for(int row{0}; row != Tetromino::height; ++row)
        for(int column{0}; column != Tetromino::width; ++column)
            if(tetromino.at_rotated(column, row) == 'X')
                buffer.at(row + margin_top + tetromino.get_current_y(),
                          column + margin_left + tetromino.get_current_x()) = mapped_skin(current_tetromino + 1);
}

bool Game::does_piece_fit(const Tetromino &tetromino, const Matrix<int> &field, int new_x, int new_y) noexcept
{
    for(int x{0}; x != Tetromino::width; ++x)
        for(int y{0}; y != Tetromino::height; ++y)
           if(x + new_x >= 0 && x + new_x < field.get_columns())
               if(y + new_y >= 0 && y + new_y < field.get_rows())
                    if(tetromino.at_rotated(x, y) == 'X' && field.at(y + new_y, x + new_x) != 0)
                        return false;
    return true;
}

void Game::lock_piece(const Tetromino &tetromino, Matrix<int> &field, int current_tetromino) noexcept
{
    for(int x{0}; x != Tetromino::width; ++x)
        for(int y{0}; y != Tetromino::height; ++y)
            if(tetromino.at_rotated(x, y) == 'X')
                field.at(y + tetromino.get_current_y(), x + tetromino.get_current_x()) = current_tetromino + 1;
}

void Game::check_lines(const Matrix<int> &field, int first_row, std::vector<int> &lines) noexcept
{
    for(int row{ first_row }; row != first_row + Tetromino::width; ++row)
        if(row < field.get_rows() - 1)
        {
            bool line{ true };
            for(int column{ 1 }; column != field.get_columns() - 1; ++column)
            {
                if(field.at(row, column) == 0)
                    line = false;
            }
            if(line)
                 lines.push_back(row);
        }
}

void Game::draw_lines(Matrix<int> &field, const std::vector<int> &lines) noexcept
{
    for(int line : lines)
        for(int column{1}; column != field.get_columns() - 1; ++column)
            field.at(line, column) = 8;
}

void Game::remove_lines(Matrix<int> &field, std::vector<int> &lines)
{
    for(int line : lines)
        for(int column{1}; column != field.get_columns() - 1; ++column)
        {
            for(int row{line}; row > 0; --row)
                field.at(row, column) = field.at(row - 1, column);
            field.at(0, column) = 0;
        }
    lines.clear();
}

