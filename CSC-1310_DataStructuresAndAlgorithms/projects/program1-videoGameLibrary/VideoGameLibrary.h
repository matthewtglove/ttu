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
        this->videoGamesArray = new VideoGame *[this->maxGames];
        this->maxGames = maxGames;
        this->numGames = 0;
    }

    ~VideoGameLibrary()
    {
        for (int i = 0; i < this->numGames; i++)
        {
            delete this->videoGamesArray[i];
        }
        delete[] this->videoGamesArray;
    }

    void resizeVideoGameArray() // TODO: I'm not sure if this is right
    {
        this->maxGames *= 2;
        VideoGame **resizedVideoGamesArray = new VideoGame *[this->maxGames];
        for (int i = 0; i < this->numGames; i++)
        {
            resizedVideoGamesArray[i] = this->videoGamesArray[i];
        }

        // resizedVideoGamesArray is pointing to the same VideoGames in memory, so we don't want to delete the video games, just the old videoGamesArray
        delete[] this->videoGamesArray;

        // Now we make the empty videoGamesArray into the new array
        this->videoGamesArray = resizedVideoGamesArray;
    }

    void addVideoGameToArray()
    {
        int maxInputLength = 1000;

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
        this->videoGamesArray[this->numGames] = newGame;
        this->numGames++;
    }

    void displayVideoGames() const
    {
        for (int i = 0; i < this->numGames; i++)
        {
            this->videoGamesArray[i]->printVideoGameDetails();
        }
    }

    void displayVideoGameTitles() const
    {
        if (this->numGames < 1)
        {
            cout << "You have no video games :(" << endl;
            return;
        }

        cout << "Video Game Library:\n"
             << endl;
        for (int i = 0; i < this->numGames; i++)
        {
            Text *text = this->videoGamesArray[i]->getVideoGameTitle();
            cout << i + 1 << ". " << text->getText() << endl;
        }
        cout << endl;
    }

    void loadVideoGamesFromFile(const char *filename)
    {
        ifstream inputFile;

        inputFile.open(filename);
        if (!inputFile.is_open())
        {
            cout << "Error opening file: " << filename << endl;
            return;
        }

        int maxInputLength = 1000;

        char inputTitle[maxInputLength];
        while (inputFile.getline(inputTitle, maxInputLength, '\n'))
        {

            Text *title = new Text(inputTitle);

            char inputPlatform[maxInputLength];
            inputFile.getline(inputPlatform, maxInputLength, '\n');
            Text *platform = new Text(inputPlatform);

            char inputCharYear[maxInputLength];
            inputFile.getline(inputCharYear, maxInputLength, '\n');
            int year = atoi(inputCharYear);

            char inputGenre[maxInputLength];
            inputFile.getline(inputGenre, maxInputLength, '\n');
            Text *genre = new Text(inputGenre);

            char inputAge[maxInputLength];
            inputFile.getline(inputAge, maxInputLength, '\n');
            Text *ageRating = new Text(inputAge);

            char inputCharUserRating[maxInputLength];
            inputFile.getline(inputCharUserRating, maxInputLength, '\n');
            double userRating = strtod(inputCharUserRating, nullptr);

            VideoGame *newGame = new VideoGame(title, platform, year, genre, ageRating, userRating);

            // TEST
            cout << "numGames is " << this->numGames << endl;
            cout << "maxGames is " << this->maxGames << endl;

            if (this->numGames == this->maxGames)
            {
                resizeVideoGameArray();
            }
            this->videoGamesArray[this->numGames] = newGame;
            this->numGames++;

            cout << newGame->getVideoGameTitle() << " was added to the video game library!" << endl;
        }
    }

    void removeVideoGameFromArray()
    {
        if (this->numGames < 1)
        {
            cout << "You have no video games :(\nThere must be 1 or more video games in your library to remove video games." << endl;
            return;
        }

        cout << "Which video game would you like to remove?"
             << " Choose 1-" << this->numGames << endl;
        displayVideoGameTitles();

        cout << "SELECT: ";
        int iDeletedVideoGame = requireIntInput(1, this->numGames) - 1;

        cout << "Are you sure you want to remove \"" << this->videoGamesArray[iDeletedVideoGame]->getVideoGameTitle() << "\"? (y/n)" << endl;
        cout << "CONFIRM REMOVE? ";
        char userConfirmDelete;
        cin >> userConfirmDelete;
        bool confirmDelete = (userConfirmDelete == 'y');

        if (!confirmDelete)
        {
            cout << this->videoGamesArray[iDeletedVideoGame]->getVideoGameTitle() << " was not removed." << endl;
            return;
        }

        this->numGames--;
        delete this->videoGamesArray[iDeletedVideoGame];
        for (int i = iDeletedVideoGame; i < this->numGames; i++)
        {
            this->videoGamesArray[i] = this->videoGamesArray[i + 1];
        }
        // This will leave two duplicates of each other at the end of the array, but the second will not affect the library as it is outside of what numGames would call

        cout << this->videoGamesArray[iDeletedVideoGame]->getVideoGameTitle() << " has successfully been removed." << endl;
    }

    void saveToFile(char *filename) const
    {
        // Open file
        // call printVideoGameDetailsToFile()
        // Format everything with new lines (no extra linebreaks between games). That way the output file can be read in again, it's just a line break separated file
    }
};
