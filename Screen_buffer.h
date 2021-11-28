#ifndef SCREEN_BUFFER_H_INCLUDED
#define SCREEN_BUFFER_H_INCLUDED
#include <windows.h>

namespace Game
{
    class Screen_buffer
    {
        public:
            Screen_buffer();
            void write_characters(const char *screen, int width, int height);
            void close();
        private:
            DWORD dwBytesWritten;
            HANDLE hConsole;
    };
}

#endif // SCREEN_BUFFER_H_INCLUDED
