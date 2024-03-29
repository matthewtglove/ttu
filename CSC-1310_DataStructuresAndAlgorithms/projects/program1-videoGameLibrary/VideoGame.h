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
    int userRating;

public:
    VideoGame(Text *title, Text *platform, int year, Text *genre, Text *ageRating, int userRating);
    ~VideoGame();
    void printVideoGameDetails() const;
    void printVideoGameDetailsToFile(ofstream &destinationFile) const;
    Text *getVideoGameTitle() const;
};

#endif