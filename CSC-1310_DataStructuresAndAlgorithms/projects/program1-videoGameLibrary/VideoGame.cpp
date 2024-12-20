#include "VideoGame.h"

VideoGame::VideoGame(Text *title, Text *platform, int year, Text *genre, Text *ageRating, int userRating)
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
     if (this->title != nullptr)
     {
          delete this->title;
     }
     if (this->platform != nullptr)
     {
          delete this->platform;
     }
     if (this->genre != nullptr)
     {
          delete this->genre;
     }
     if (this->ageRating != nullptr)
     {
          delete this->ageRating;
     }
}

// Print an entire game with its details
void VideoGame::printVideoGameDetails() const
{
     cout << setw(80) << setfill('-') << "" << endl;
     cout << setfill(' ');

     cout << "Title:" << endl;
     this->title->displayText();
     cout << endl
          << endl;

     cout << "Platform(s):" << endl;
     this->platform->displayText();
     cout << endl
          << endl;

     cout << "Release Year:" << endl;
     cout << this->year;
     cout << endl
          << endl;

     cout << "Genre:" << endl;
     this->genre->displayText();
     cout << endl
          << endl;

     cout << "Age Rating:" << endl;
     this->ageRating->displayText();
     cout << endl
          << endl;

     cout << "IGDB User Rating:" << endl;
     cout << this->userRating;
     cout << endl;

     cout << setw(80) << setfill('-') << "" << endl;
     cout << setfill(' ');
}

// Save to file
void VideoGame::printVideoGameDetailsToFile(ofstream &destinationFile) const
{
     if (!destinationFile.is_open())
     {
          cout << "Error opening/creating file" << endl;
          return;
     }

     // Formatted simply with line breaks so this file can be used as an input file
     destinationFile << this->title->getText() << "\n";
     destinationFile << this->platform->getText() << "\n";
     destinationFile << this->year << "\n";
     destinationFile << this->genre->getText() << "\n";
     destinationFile << this->ageRating->getText() << "\n";
     destinationFile << this->userRating << "\n";
}

Text *VideoGame::getVideoGameTitle() const
{
     return this->title;
}