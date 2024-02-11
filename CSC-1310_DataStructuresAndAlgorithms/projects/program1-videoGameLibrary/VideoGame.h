#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "Text.h"
#include <iostream>
#include <fstream>

class VideoGame
{
private:
    Text *title;
    Text *platform;
    int year;
    Text *genre;
    Text *ageRating;
    double userRating;

public:
    VideoGame(Text *title, Text *platform, int year, Text *genre, Text *ageRating, double userRating);
    ~VideoGame();
    void printVideoGameDetails();
    void printVideoGameDetailsToFile(ifstream destinationFile);
    Text *getVideoGameTitle();
};

#endif