#ifndef LOGIC_H_INCLUDED
#define LOGIC_H_INCLUDED
#include <string>
#include "Tetromino.h"
#include "Tetrominos.h"
#include "Matrix.h"
#include <array>
#include <vector>

namespace Game
{
    std::array<Tetromino, number_of_tetrominos> get_tetrominos() noexcept;
    void add_border(Matrix<int> &field) noexcept;
    void draw_field(Matrix<char> &buffer, const Matrix<int> &field, int margin_left={0}, int margin_top={0}) noexcept;
    void draw_tetromino(Matrix<char> &buffer, const Tetromino &tetromino, int current_tetromino, int margin_left={0}, int margin_top={0}) noexcept;
    bool does_piece_fit(const Tetromino &tetromino, const Matrix<int> &field, int new_x, int new_y) noexcept;
    void lock_piece(const Tetromino &tetromino, Matrix<int> &field, int current_tetromino) noexcept;
    void check_lines(const Matrix<int> &field, int first_row, std::vector<int>& lines) noexcept;
    void draw_lines(Matrix<int> &field, const std::vector<int> &lines) noexcept;
    void remove_lines(Matrix<int> &field, std::vector<int> &lines);
}

#endif // LOGIC_H_INCLUDED
