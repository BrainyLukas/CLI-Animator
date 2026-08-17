#pragma once
#ifndef bl_mvup_hpp
#define bl_mvup_hpp

#include <iostream>

namespace qol
{
    /**
     * @brief moves cursor n lines from terminal.
     * Moves cursor n number of lines up from current line.
     * 
     * @param {number} n - number of lines to go up
     *
     * @note Made by Brainy Lukas aka Brainy_Lukas aka BrainyLukas aka brainylukas
     */
    void mvup(int n)
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        
        if (!(n <= 0))
        {
            /*std::cout << "\x1b[2K";*/

            for (int i = 1; i < n; ++i)
            {
                std::cout << "\x1b[1A" /*<< "\x1b[2K"*/;
            }

            std::cout << std::flush;
        }
    }
}

#endif