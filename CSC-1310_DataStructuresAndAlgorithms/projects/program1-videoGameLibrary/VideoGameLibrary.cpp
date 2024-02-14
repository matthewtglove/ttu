#include "VideoGameLibrary.h"

VideoGameLibrary::VideoGameLibrary(int maxGames)
{
    this->maxGames = maxGames;
    this->videoGamesArray = new VideoGame *[this->maxGames];
    this->numGames = 0;
}

VideoGameLibrary::~VideoGameLibrary()
{
    for (int i = 0; i < this->numGames; i++)
    {
        if (this->videoGamesArray[i] != nullptr)
        {
            delete this->videoGamesArray[i];
        }
    }
    if (this->videoGamesArray != nullptr)
    {
        delete[] this->videoGamesArray;
    }
}

void VideoGameLibrary::resizeVideoGameArray()
{
    this->maxGames *= 2;
    VideoGame **resizedVideoGamesArray = new VideoGame *[this->maxGames];
    for (int i = 0; i < this->numGames; i++)
    {
        resizedVideoGamesArray[i] = this->videoGamesArray[i];
    }

    // Only delete the array, not the items
    delete[] this->videoGamesArray;

    // Now we make the empty videoGamesArray into the new and improved array
    this->videoGamesArray = resizedVideoGamesArray;
}

void VideoGameLibrary::addVideoGameToArray()
{
    int maxInputLength = 10000;

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

    // Handles a number differently
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

    // ...
    cout << "IGDB USER RATING (1-100): ";
    int userRating;
    cin >> userRating;
    cin.ignore();

    cout << endl;

    VideoGame *newGame = new VideoGame(title, platform, year, genre, ageRating, userRating);
    if (this->numGames == this->maxGames)
    {
        resizeVideoGameArray();
    }
    this->videoGamesArray[this->numGames] = newGame;
    this->numGames++;
}

void VideoGameLibrary::displayVideoGames() const
{
    if (this->numGames < 1)
    {
        cout << "You have no video games :(" << endl;
        return;
    }
    for (int i = 0; i < this->numGames; i++)
    {
        this->videoGamesArray[i]->printVideoGameDetails();
    }
}

void VideoGameLibrary::displayVideoGameTitles() const
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
        cout << i + 1 << ". ";
        this->videoGamesArray[i]->getVideoGameTitle()->displayText();
        cout << endl;
    }
    cout << endl;
}

// TODO: This is broken
void VideoGameLibrary::loadVideoGamesFromFile(const char *filename)
{
    ifstream inputFile;

    inputFile.open(filename);
    if (!inputFile.is_open())
    {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    int maxInputLength = 10000;

    int lineNumber = 1;
    char inputLine[maxInputLength];
    while (inputFile.getline(inputLine, maxInputLength))
    {
        // The provided text files sabatoge Unix users - getline includes the carraige return which breaks cout
        // This manually removes the carraige return
        int i = 0;
        char c = inputLine[i];

        while (c != '\0')
        {
            if (c == '\r')
            {
                inputLine[i] = c = '\0';
                break;
            }
            i++;
            c = inputLine[i];
        }

        Text *title;
        Text *platform;
        int year;
        Text *genre;
        Text *ageRating;
        int userRating;

        // Assigns values based on where they are in their 6-line bunch
        switch (((lineNumber - 1) % 6) + 1)
        {
        case 1:
            title = new Text(inputLine);
            break;

        case 2:
            platform = new Text(inputLine);
            break;

        case 3:
            year = atoi(inputLine);
            break;

        case 4:
            genre = new Text(inputLine);
            break;

        case 5:
            ageRating = new Text(inputLine);
            break;

        case 6:
            userRating = atoi(inputLine);

            VideoGame *newGame = new VideoGame(title, platform, year, genre, ageRating, userRating);

            if (this->numGames == this->maxGames)
            {
                resizeVideoGameArray();
            }
            this->videoGamesArray[this->numGames] = newGame;
            cout << "✅ ";
            newGame->getVideoGameTitle()->displayText();
            cout << " was added to the video game library!" << endl;
            this->numGames++;

            break;
        }

        lineNumber++;
    }
    inputFile.close();
}

void VideoGameLibrary::removeVideoGameFromArray()
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
    int userDeletedVideoGame;
    cin >> userDeletedVideoGame;
    int iDeletedVideoGame = userDeletedVideoGame - 1;

    cout << "Are you sure you want to remove \"";
    this->videoGamesArray[iDeletedVideoGame]->getVideoGameTitle()->displayText();
    cout << "\"? (y/n)" << endl;
    cout << "CONFIRM REMOVE? ";
    char userConfirmDelete;
    cin >> userConfirmDelete;
    bool confirmDelete = (userConfirmDelete == 'y');

    if (!confirmDelete)
    {
        cout << "✔️";
        this->videoGamesArray[iDeletedVideoGame]->getVideoGameTitle()->displayText();
        cout << " was not removed." << endl;
        return;
    }

    this->numGames--;
    delete this->videoGamesArray[iDeletedVideoGame];
    for (int i = iDeletedVideoGame; i < this->numGames; i++)
    {
        this->videoGamesArray[i] = this->videoGamesArray[i + 1];
    }
    // The above will leave two duplicates of each other at the end of the array, so...
    this->videoGamesArray[this->numGames] = nullptr;

    cout << "✔️ ";
    this->videoGamesArray[iDeletedVideoGame]->getVideoGameTitle()->displayText();
    cout << " has successfully been removed." << endl;
}

void VideoGameLibrary::saveToFile(char *filename) const
{
    ofstream outputFile;
    // Opens and closes the file outside of the printVideoGameDetailsToFile function
    outputFile.open(filename);
    for (int i = 0; i < this->numGames; i++)
    {
        videoGamesArray[i]->printVideoGameDetailsToFile(outputFile);
    }

    outputFile.close();

    cout << "All the video games have successfully been printed to " << filename << endl;
}