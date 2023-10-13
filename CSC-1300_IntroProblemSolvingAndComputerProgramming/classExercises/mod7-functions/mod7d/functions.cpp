
srand(time(0));

bool luckyGuess(int guess)
{
    int randomNumber = (rand() % 100) + 1;
    unsigned int difference = randomNumber - guess;

    if (difference <= 25)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void getUserData(string &userName, string &userFavoriteFood, int &userFavoriteNumber)
{
    cout << "Name: ";
    getline(cin, userName);
    cout << "Favorite food: ";
    getline(cin, userFavoriteFood);
    cout << "Favorite number: ";
    cin >> userFavoriteNumber;
    cout << endl;
}