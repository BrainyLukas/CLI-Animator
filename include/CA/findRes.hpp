#pragma once
#ifndef bl_CA_findRes_hpp
#define bl_CA_findRes_hpp

#include <Windows.h>
#include <array>

std::array<int, 2> getRes()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;
  
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    return {columns, rows};
}

#endif