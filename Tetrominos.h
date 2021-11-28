#ifndef TETROMINOS_H_INCLUDED
#define TETROMINOS_H_INCLUDED
#include <string>

namespace Game
{
    static constexpr int number_of_tetrominos{ 7 };

    std::string get_tetromino_1() noexcept;
    std::string get_tetromino_2() noexcept;
    std::string get_tetromino_3() noexcept;
    std::string get_tetromino_4() noexcept;
    std::string get_tetromino_5() noexcept;
    std::string get_tetromino_6() noexcept;
    std::string get_tetromino_7() noexcept;
}

#endif // TETROMINOS_H_INCLUDED
