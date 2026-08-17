#include <iostream>
#include <string>
#include <Windows.h>
#include <filesystem>
#include <fstream>
#include <cstdlib>

#include <array>

#include <qol/mvup.hpp>
#include <CA/frame.hpp>

namespace fs = std::filesystem;

unsigned int getVideoFrames(fs::path path)
{
    unsigned int count = 0;
    for (const auto& entry : fs::directory_iterator(path))
        ++count;

    return count;
}

//test: ./clianimator.exe "D:\Lukas\Windows Downloads\badapple.mp4" 1
int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    char exeDir[MAX_PATH]; // exe path
    DWORD gmflResult = GetModuleFileNameA(NULL, exeDir, MAX_PATH);

    if (gmflResult == 0)
        throw "Could not get exe path.";

    char* lastBackslash = strrchr(exeDir, '\\');
    if (lastBackslash != nullptr)
        *lastBackslash = '\0';

    fs::path tempPath = fs::path(exeDir) / ".." / "temp";

    fs::remove_all(tempPath);
    fs::create_directory(tempPath);

    if (argc == 3)
    {
        std::string videoPath = argv[1];
        float speed = std::stof(argv[2]);

        fs::path videoOutputFrameNameTemplate = tempPath / "output%010d-frame.png";
        //fs::path videoOutputAudioNameTemplate = tempPath / "output%010d-audio.mp3";

        std::string ffmpegFrameSplitCommand = // ffmpeg -i "D:\VideoLibrary\coolVideo.mp4" -r 6.7 "C:\CLI-Animator\temp"
        "ffmpeg" 
        " -i "  "\"" + fs::path(videoPath).string() + "\""
        " -fps_mode passthrough" + 
        " \"" + videoOutputFrameNameTemplate.string() + "\"" ;

        /*std::string ffmpegAudioCommand = "ffmpeg"
        " -i " "\"" + fs::path(videoPath).string() + "\""
        "-vn -acodec copy" + 
        " \"" + videoOutputAudioNameTemplate.string() + "\"";*/

        std::cout << "Running Command: " + ffmpegFrameSplitCommand << "\n\n";
        system(ffmpegFrameSplitCommand.c_str());

        std::cout << "\n\n";

        /*std::cout << "Running Command: " + ffmpegAudioCommand << "\n";
        system(ffmpegAudioCommand.c_str());*/

        unsigned int frames = getVideoFrames(tempPath);

        double frameDelay = 1.l/frames;

        system("pause");

        int n = 0;
        for (const auto &entry : fs::directory_iterator(tempPath))
        {
            qol::mvup(n);
            n = ca::drawFrame(entry.path());

            //Sleep(50);
        }
    }
    else
        throw "Command does not accept this number of arguments!";

    fs::remove_all(tempPath);

    return 2;
}