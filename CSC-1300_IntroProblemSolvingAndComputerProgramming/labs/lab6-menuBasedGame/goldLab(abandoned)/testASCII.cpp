

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    cout << "$$$$$$$$\\ $$\\ $$\\ $$\\ $$\\ $$\\     \n\\__$$ __ | $$ |      \\__ |                \\__ | $$ | $$ |    \n $$ | $$$$$$$\\ $$\\ $$$$$$$\\ $$\\ $$$$$$$\\ $$$$$$\\ $$$$$$\\ $$$$$$\\ $$$$$$$\\ $$$$$$\\   \n $$ | $$ __$$\\ $$ | $$ _____ | $$ | $$ _____ |       \\____$$\\       \\_$$ _ | $$ __$$\\ $$ _____ |\\_$$ _ |  \n $$ | $$ | $$ | $$ |\\$$$$$$\\ $$ |\\$$$$$$\\ $$$$$$$ | $$ | $$$$$$$$ |\\$$$$$$\\ $$ |    \n $$ | $$ | $$ | $$ | \\____$$\\ $$ | \\____$$\\ $$ __$$ | $$ | $$\\ $$ ____ | \\____$$\\ $$ | $$\\ \n $$ | $$ | $$ | $$ | $$$$$$$ | $$ | $$$$$$$ |      \\$$$$$$$ |        \\$$$$ |\\$$$$$$$\\ $$$$$$$ |  \\$$$$ |\n   \\__ |   \\__ |  \\__ |\\__ |\\_______ /       \\__ |\\_______ /        \\_______ |         \\____ /  \\_______ |\\_______ /    \\____ / \n";
}

// Failed

// Expected output
/*
$$$$$$$$\ $$\       $$\                 $$\                                   $$\                           $$\
\__$$  __|$$ |      \__|                \__|                                  $$ |                          $$ |
   $$ |   $$$$$$$\  $$\  $$$$$$$\       $$\  $$$$$$$\        $$$$$$\        $$$$$$\    $$$$$$\   $$$$$$$\ $$$$$$\
   $$ |   $$  __$$\ $$ |$$  _____|      $$ |$$  _____|       \____$$\       \_$$  _|  $$  __$$\ $$  _____|\_$$  _|
   $$ |   $$ |  $$ |$$ |\$$$$$$\        $$ |\$$$$$$\         $$$$$$$ |        $$ |    $$$$$$$$ |\$$$$$$\    $$ |
   $$ |   $$ |  $$ |$$ | \____$$\       $$ | \____$$\       $$  __$$ |        $$ |$$\ $$   ____| \____$$\   $$ |$$\
   $$ |   $$ |  $$ |$$ |$$$$$$$  |      $$ |$$$$$$$  |      \$$$$$$$ |        \$$$$  |\$$$$$$$\ $$$$$$$  |  \$$$$  |
   \__|   \__|  \__|\__|\_______/       \__|\_______/        \_______|         \____/  \_______|\_______/    \____/

*/

// Correct way to do it:
// Used find and replace to replace one backlash with two backslashes
void asciiTest()
{
    cout << "$$$$$$$$\\ $$\\       $$\\                 $$\\                                   $$\\                           $$\\     \n";
    cout << "\\__$$  __|$$ |      \\__|                \\__|                                  $$ |                          $$ |    \n";
    cout << "   $$ |   $$$$$$$\\  $$\\  $$$$$$$\\       $$\\  $$$$$$$\\        $$$$$$\\        $$$$$$\\    $$$$$$\\   $$$$$$$\\ $$$$$$\\   \n";
    cout << "   $$ |   $$  __$$\\ $$ |$$  _____|      $$ |$$  _____|       \\____$$\\       \\_$$  _|  $$  __$$\\ $$  _____|\\_$$  _|  \n";
    cout << "   $$ |   $$ |  $$ |$$ |\\$$$$$$\\        $$ |\\$$$$$$\\         $$$$$$$ |        $$ |    $$$$$$$$ |\\$$$$$$\\    $$ |    \n";
    cout << "   $$ |   $$ |  $$ |$$ | \\____$$\\       $$ | \\____$$\\       $$  __$$ |        $$ |$$\\ $$   ____| \\____$$\\   $$ |$$\\ \n";
    cout << "   $$ |   $$ |  $$ |$$ |$$$$$$$  |      $$ |$$$$$$$  |      \\$$$$$$$ |        \\$$$$  |\\$$$$$$$\\ $$$$$$$  |  \\$$$$  |\n";
    cout << "   \\__|   \\__|  \\__|\\__|\\_______/       \\__|\\_______/        \\_______|         \\____/  \\_______|\\_______/    \\____/ \n";
}