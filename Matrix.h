#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#include <vector>

namespace Game
{
    template<typename T>
    class Matrix
    {
        public:
            Matrix(int rows, int columns, const T &default_value={});
            Matrix(const Matrix &copy) =default;
            Matrix(Matrix &&move) =default;
            ~Matrix() =default;
            T& at(int row, int column);
            const T& at(int row, int column) const;
            int get_rows() const noexcept;
            int get_columns() const noexcept;
            T* data() noexcept;
            const T* data() const noexcept;
        private:
            const int rows;
            const int columns;
            std::vector<T> matrix;
    };
}

//PUBLIC METHODS
template<typename T>
Game::Matrix<T>::Matrix(int rows, int columns, const T &default_value)
    : rows{ rows }, columns{ columns }, matrix(rows * columns, default_value)
{

}

template<typename T>
T& Game::Matrix<T>::at(int row, int column)
{
    return matrix[row * columns + column];
}

template<typename T>
const T& Game::Matrix<T>::at(int row, int column) const
{
    return matrix[row * columns + column];
}

template<typename T>
int Game::Matrix<T>::get_rows() const noexcept
{
    return rows;
}

template<typename T>
int Game::Matrix<T>::get_columns() const noexcept
{
    return columns;
}

template<typename T>
T* Game::Matrix<T>::data() noexcept
{
    return matrix.data();
}

template<typename T>
const T* Game::Matrix<T>::data() const noexcept
{
    return matrix.data();
}

#endif // MATRIX_H_INCLUDED
