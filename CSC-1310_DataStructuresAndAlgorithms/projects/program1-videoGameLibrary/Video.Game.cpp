#include "VideoGame.h"

VideoGame::VideoGame(Text *title, Text *platform, int year, Text *genre, Text *ageRating, double userRating)
{
    this->title = title;
    this->platform = platform;
    this->year = year;
    this->genre = genre;
    this->ageRating = ageRating;
    this->userRating = userRating;
}

VideoGame::~VideoGame()
{
    delete this->title;
    delete this->platform;
    delete this->genre;
    delete this->ageRating;
}

void VideoGame::printVideoGameDetails()
{
    // Some cool video game listing
    // Remember to use displayText()
}

void VideoGame::printVideoGameDetailsToFile(ifstream destinationFile)
{
    // Print to the file
    // Remember to use getText()
}

Text *VideoGame::getVideoGameTitle()
{
    return title;
}