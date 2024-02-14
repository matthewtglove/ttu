#include "VideoGame.h"

class VideoGameLibrary
{
private:
    VideoGame **videoGamesArray;
    int maxGames;
    int numGames;

public:
    VideoGameLibrary(int maxGames);
    ~VideoGameLibrary();
    void resizeVideoGameArray();
    void addVideoGameToArray();
    void displayVideoGames() const;
    void displayVideoGameTitles() const;
    void loadVideoGamesFromFile(const char *filename);
    void removeVideoGameFromArray();
    void saveToFile(char *filename) const;
};
