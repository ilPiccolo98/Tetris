#ifndef TETROMINO_H_INCLUDED
#define TETROMINO_H_INCLUDED
#include <string>

namespace Game
{
    class Tetromino
    {
        public:
            Tetromino(const std::string &tetromino, int current_x={0}, int current_y={0}, int current_rotation={0});
            char at_rotated(int x, int y) const;
            const char& at(int x, int y) const;
            int get_current_x() const noexcept;
            int get_current_y() const noexcept;
            void set_current_x(int current_x) noexcept;
            void set_current_y(int current_y) noexcept;
            void set_current_rotation(int rotation) noexcept;
            int get_current_rotation() const noexcept;
            static constexpr int width{ 4 };
            static constexpr int height{ 4 };
        private:
            const std::string tetromino;
            int current_x;
            int current_y;
            int current_rotation;
    };
}

#endif // TETROMINO_H_INCLUDED
