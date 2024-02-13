#include <iostream>
#include "VideoGame.h"
#include "utils.h"

class VideoGameLibrary
{
private:
    VideoGame **videoGamesArray;
    int maxGames;
    int numGames;

public:
    VideoGameLibrary(int maxGames)
    {
        videoGamesArray = new VideoGame *[maxGames];
        // this->maxGames = maxGames;
        numGames = 0;
    }

    ~VideoGameLibrary()
    {
        for (int i = 0; i < numGames; i++)
        {
            delete videoGamesArray[i];
        }
        delete[] videoGamesArray;
    }

    void resizeVideoGameArray()
    {
        // This function called by addVideoGameToArray
        // When array is not big enough for new video game, create a new array double the size and move all the old items to this new array
        this->maxGames *= 2;
        VideoGame **resizedVideoGamesArray = new VideoGame *[this->maxGames];
        for (int i = 0; i < this->numGames; i++)
        {
            resizedVideoGamesArray[i] = videoGamesArray[i];
        }

        // resizedVideoGamesArray is pointing to the same VideoGames in memory, so we don't want to delete the video games, just the old videoGamesArray
        delete[] videoGamesArray;

        // Now we make the empty videoGamesArray into the new array
        videoGamesArray = resizedVideoGamesArray;
    }

    void addVideoGameToArray()
    {
        int maxInputLength = 200;

        cout << "New video game:\n"
             << endl;

        cout << "TITLE: ";
        char inputTitle[maxInputLength];
        cin.getline(inputTitle, maxInputLength);
        Text *title = new Text(inputTitle);

        cout << "PLATFORM(S): ";
        char inputPlatform[maxInputLength];
        cin.getline(inputPlatform, maxInputLength);
        Text *platform = new Text(inputPlatform);

        cout << "RELEASE YEAR: ";
        int year;
        cin >> year;
        cin.ignore();

        cout << "GENRE: ";
        char inputGenre[maxInputLength];
        cin.getline(inputGenre, maxInputLength);
        Text *genre = new Text(inputGenre);

        cout << "AGE RATING: ";
        char inputAge[maxInputLength];
        cin.getline(inputAge, maxInputLength);
        Text *ageRating = new Text(inputAge);

        cout << "IGDB USER RATING (1-100): ";
        double userRating;
        requireFloatInput(0, 100);

        cout << endl;

        VideoGame *newGame = new VideoGame(title, platform, year, genre, ageRating, userRating);
        if (this->numGames == this->maxGames)
        {
            resizeVideoGameArray();
        }
        videoGamesArray[this->numGames] = newGame;
        this->numGames++;
    }

    void displayVideoGames()
    {
        // call each VideoGame's printVideoGameDetails function
    }

    void displayVideoGameTitles()
    {
        cout << "Video Game Library:\n"
             << endl;
        for (int i = 0; i < this->numGames; i++)
        {
            Text *text = this->videoGamesArray[i]->getVideoGameTitle();
            cout << "- " << text->getText() << endl;
        }
        cout << endl;
    }

    void loadVideoGamesFromFile(char *filename[10000])
    {
        // Read in the contents of the file
    }
};