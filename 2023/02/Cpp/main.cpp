#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <unordered_map>
#include "main.h"

int FirstPart(bool &retFlag)
{
    retFlag = true;
    auto filename = "input.txt";
    auto file = std::ifstream(filename);

    if (!file.is_open())
    {
        std::cout << "File not found" << std::endl;
        return 1;
    }

    char buffer[1024];

    std::unordered_map<std::string, int> limits;

    limits["red"] = 12;
    limits["blue"] = 14;
    limits["green"] = 13;

    int res = 0;

    while (file.getline(buffer, 1024, '\n'))
    {
        std::string line = buffer;

        int game = 0;
        char sets[1024];

        sscanf(line.c_str(), "Game %d: %[^\n]s", &game, &sets);

        std::cout << "Game: " << game << " Sets: " << sets << std::endl;

        std::stringstream ss(sets);

        char gameBuffer[256];
        bool count = true;
        while (ss.getline(gameBuffer, 256, ';'))
        {
            std::string set = gameBuffer;

            // std::cout << "GameBuffer: " << set << std::endl;

            std::stringstream gameStream(set);
            char moveBuffer[128];

            std::unordered_map<std::string, int> counts;

            while (gameStream.getline(moveBuffer, 1024, ','))
            {
                int count;
                char type[256];

                std::string move = moveBuffer;

                // std::cout << "Move: " << move << std::endl;

                sscanf(move.c_str(), "%d %[^\0]", &count, &type);

                std::string typeStr = type;

                counts[typeStr] = count;
                // std::cout << "Count: " << count << " Type: " << type << std::endl;
            }

            for (auto i = counts.begin(); i != counts.end(); i++)
            {
                if (limits[i->first] < i->second)
                {
                    count = false;
                    break;
                }
            }
        }

        if (count)
        {
            res += game;
        }
    }

    std::cout << "Result: " << res << std::endl;
    file.close();
    retFlag = false;
    return {};
}

int SecondPart(bool &retFlag)
{
    retFlag = true;
    auto filename = "input.txt";
    auto file = std::ifstream(filename);

    if (!file.is_open())
    {
        std::cout << "File not found" << std::endl;
        return 1;
    }

    char buffer[1024];


    int res = 0;

    while (file.getline(buffer, 1024, '\n'))
    {
        std::string line = buffer;

        int game = 0;
        char sets[1024];

        sscanf(line.c_str(), "Game %d: %[^\n]s", &game, &sets);

        std::cout << "Game: " << game << " Sets: " << sets << std::endl;

        std::unordered_map<std::string, int> limits;

        std::stringstream ss(sets);

        char gameBuffer[256];
        bool count = true;
        while (ss.getline(gameBuffer, 256, ';'))
        {
            std::string set = gameBuffer;

            // std::cout << "GameBuffer: " << set << std::endl;

            std::stringstream gameStream(set);
            char moveBuffer[128];

            std::unordered_map<std::string, int> counts;

            while (gameStream.getline(moveBuffer, 1024, ','))
            {
                int count;
                char type[256];

                std::string move = moveBuffer;

                // std::cout << "Move: " << move << std::endl;

                sscanf(move.c_str(), "%d %[^\0]", &count, &type);

                std::string typeStr = type;

                counts[typeStr] = count;
                // std::cout << "Count: " << count << " Type: " << type << std::endl;
            }

            for (auto i = counts.begin(); i != counts.end(); i++)
            {
                if (limits[i->first] < i->second)
                {
                    limits[i->first] = i->second;
                }
            }
        }

        int power = 1;
        for (auto i = limits.begin(); i != limits.end(); i++)
        {
            power *= i->second ;
        }
        res += power;
        
    }

    std::cout << "Result: " << res << std::endl;
    file.close();
    retFlag = false;
    return {};
}

int main(){
    bool retFlag;
    int retVal = FirstPart(retFlag);
    SecondPart(retFlag);
    if (retFlag)
        return retVal;
}