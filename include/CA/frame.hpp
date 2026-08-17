#pragma once
#ifndef bl_CA_frame_hpp
#define bl_CA_frame_hpp

#include <iostream>
#include <filesystem>
#include <SFML/Graphics.hpp>
#include <CA/findRes.hpp>

namespace fs = std::filesystem;

namespace ca
{
    /**
     * @brief Draws an image.
     * Taking image path from it's argument, it goes trough it pixels, getting it's rgb colors then draws them on the screen line by line.
     * 
     * @param targetPath path 
     * 
     * @returns {number} number of "lines" in an image
     *
     * @note Made by Brainy Lukas aka Brainy_Lukas aka BrainyLukas aka brainylukas
     */
    int drawFrame(fs::path targetPath)
    {
        std::array<int, 2> res = getRes();

        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);

        sf::Image image;

        if (!image.loadFromFile(targetPath))
        {
            return 0;
        }

        sf::Vector2u size = image.getSize();

        std::string frame = "";

        sf::Vector2f change = {(double)size.x/((double)res[0]/2), (double)size.y/(double)res[1]};

        int del = ((double)size.y/change.y);

        for (double y = 0; y <= (size.y-change.y); y += change.y)
        {
            std::string line = "";
            for (double x = 0; x <= (size.x-change.x); x += change.x)
            {
                sf::Color pixel = image.getPixel({(int)x, (int)y});

                line += ("\033[48;2;" + std::to_string(pixel.r) + ";" + std::to_string(pixel.g) + ";" + std::to_string(pixel.b) + "m  ");
            }
            frame += line + '\n';
        }

        std::cout << frame << "\033[0m";

        return del*2;
    }
}

#endif