#include "Tetrominos.h"

std::string Game::get_tetromino_1() noexcept
{
    std::string tetromino_skin_1{};
    tetromino_skin_1.append("..X.");
    tetromino_skin_1.append("..X.");
    tetromino_skin_1.append("..X.");
    tetromino_skin_1.append("..X.");
    return tetromino_skin_1;
}

std::string Game::get_tetromino_2() noexcept
{
    std::string tetromino_skin_2{};
    tetromino_skin_2.append("..X.");
    tetromino_skin_2.append(".XX.");
    tetromino_skin_2.append(".X..");
    tetromino_skin_2.append("....");
    return tetromino_skin_2;
}

std::string Game::get_tetromino_3() noexcept
{
    std::string tetromino_skin_3{};
    tetromino_skin_3.append(".X..");
    tetromino_skin_3.append(".XX.");
    tetromino_skin_3.append("..X.");
    tetromino_skin_3.append("....");
    return tetromino_skin_3;
}

std::string Game::get_tetromino_4() noexcept
{
    std::string tetromino_skin_4{};
    tetromino_skin_4.append("....");
    tetromino_skin_4.append(".XX.");
    tetromino_skin_4.append(".XX.");
    tetromino_skin_4.append("....");
    return tetromino_skin_4;
}

std::string Game::get_tetromino_5() noexcept
{
    std::string tetromino_skin_5{};
    tetromino_skin_5.append("..X.");
    tetromino_skin_5.append(".XX.");
    tetromino_skin_5.append("..X.");
    tetromino_skin_5.append("....");
    return tetromino_skin_5;
}

std::string Game::get_tetromino_6() noexcept
{
    std::string tetromino_skin_6{};
    tetromino_skin_6.append("....");
    tetromino_skin_6.append(".XX.");
    tetromino_skin_6.append("..X.");
    tetromino_skin_6.append("..X.");
    return tetromino_skin_6;
}

std::string Game::get_tetromino_7() noexcept
{
    std::string tetromino_skin_7{};
    tetromino_skin_7.append("....");
    tetromino_skin_7.append(".XX.");
    tetromino_skin_7.append(".X..");
    tetromino_skin_7.append(".X..");
    return tetromino_skin_7;
}
