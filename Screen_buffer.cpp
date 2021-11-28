#include "Screen_buffer.h"

//PUBLIC METHODS
Game::Screen_buffer::Screen_buffer() : dwBytesWritten{0}, hConsole{ CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL) }
{
    SetConsoleActiveScreenBuffer(hConsole);
}

void Game::Screen_buffer::write_characters(const char *screen, int width, int height)
{
    WriteConsoleOutputCharacter(hConsole, screen, width * height, { 0,0 }, &dwBytesWritten);
}

void Game::Screen_buffer::close()
{
    CloseHandle(hConsole);
}
