#include <iostream>
using namespace std;

int main()
{
    int numGuests;

    cout << "Hello, welcome to The Royal Solwezi. How many are in your party today?" << endl;
    cin >> numGuests;

    if(numGuests <= 2)
    {
        cout << "You may be seated at a small table. We will be with you shortly!" << endl;
    } else {
        cout << "You may be seated at a large table. We will be with you shortly!" << endl;
    }
    
    return 0;
}