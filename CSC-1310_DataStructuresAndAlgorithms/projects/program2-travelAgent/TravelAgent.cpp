/*
    Title: Program 2
    Author: Matthew Love
    Date: 2024-03-01, Fri
    Purpose: Using a linked list and input validation
*/

// NOTE TO GRADER: See README.md

#include "Destination.h"
#include "LinkedList.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
using namespace std;

// The man, the myth, the legend
void adamSavage() {
    cout << endl;
    cout << "Hello! My name is Adam Savage and I am your professional travel agent, tour director, and guide!" << endl
         << endl;
    {
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@&&&&&&&&&&&@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@&&@&&&&@&&@@@&&&&@@&&&&@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%#%#%%%&&&&&&@&&&&&&&@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%%#%%#%##((//((%%((#/#%#%%&%%##%#%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%(//((((//********////////////(###(((%&&&@&&&&&@&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%%(/////******,****,,,,..,,*********,,,,**(%&%&%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@&&%%#((/****,,,*******,,,***,,******/******,,,,.,..,(%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##(//(/*****,,,,,,,,,,,,****////////(////**,*,,.........*#%&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#(((///********,,,,,,,,,,******,,*****/////(/**,,,.....,,..,,(&&&@&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#(((//*****/********///***,,,,,,,......,,*/////******,.....,*,,,,#&&&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###(((//**//((((////***,,,,,,.............,,**////****,,....,,,,,,,(&&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%##(////(#(//**,,**,,,,,,,..................,,***/**/**,,,....,,.*,*(&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%#((/*****,,,,,,,,,,,,,.......................,******/***,.......,,**#&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%##(//***,,,,,,,................................,****,,***,,,...,,,,*(&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##((*,,,,,,,,.........,,..,,....................,***,,,,,,,,,,,.,,,*#&&@&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@#/((/*,,,,,,,..,,,,,,..,,.,,,,,,,,...........,.....,,,,,,,,,,,**,,***/&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*,/#&&@&&&&&&&&&&&&&&&&&&&&&(*(#%/*,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,.....,,,,,....,. ,.**,**,*/****/#&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#****(&&&&&&&&&&&&&&&&&%(,**,*#%%%**,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,.,,,,,,,,.,....,..,,*,,,,*/**/%&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&(/////%&&&&&&&&&&&&(,,**/((((##%&&//**,,,,,,,***,**,,,,,,,,,,,,,,,,,,,,,,,,,,,,,.....,,,,,,,**,,///%&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&/////*%&&&&&&&&&(.***/#%%%#/(%&&&#(/*,,,,,,,,,,,,,,,,,,,,,,,,,,,*,,,,,,,,,,,,,,,,,.,,,,,****,,,**/#&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#*///*#&&&&&&&***,//####(////***/((**,,,,,,,,*,**,,,,,,,,,,,,,,,,,..,,,,,,,,,,,,*,,,,,**,,**///*((#&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%**////&&&&&////(#%%%&%#(/*********/((********,,******,,,,*,,,,,,,,,,,,,,,,,,,.,**/(*(///(/*/*,*,(%&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%**///*(&&%((///(##%&####(/((/*****,*/#%##(//(////*****/*******,,,,,,,,,,,,,*(%@@@&#/*****//***(%/(&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%/*///**(((//((###&@%((%&&&@@@@&%%%&&@&&&&%%((*///(##%%%%%####(((///////%@@@@@&#/**,******/***,.((/&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&/**///*(@(*///(#&&&%%&&&@&&@&@&&&&&%###%%&&@&%%%%&@@&%%%%%%&&%%#%@@@@@@@&%/*,,,.,*******//##((**(/&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&(**////****((#####%%&&&&&&&&@@&&&&%#(/*/(##%@@@&@@@&&&%%#((/#%%%%%#&@&(/*,,,,,,,,,*/***,*/(%##*,/(&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#*,*****/*/((###%%&&&&&&&&&&&&@%&&&((/((((((@/,**#@&%%###((((###((*(@#**,,,,,,,,***///,,,/(##/***%&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#*******///((##%%%&&&&&&&&&&&&&&#%&(/**////(/,,,*/%&#%(((((/////***(@*,,,,,,,,*****/(*,,,/,.,***@&&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&(,,*****//(((#%%%%&%%%%&&%&&&&&&##%%######%(,,,,,**#%&(#(***/***,*&#****************///*,,*,,,*&&&&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%,,,****//(((###%%%%%&%##%#%&%/*/*****//(#%**,,*,,,*/(#(//(#####((/******************/(/,,*,**(@&&&&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&@*,,**//////((##%%####(((##%%**////(((##%&%(,,,,,,,,**//(#/*****,**,,,***************///*////#&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&*,,,**//**/(((######(((((##%***/(#%&&&@&#(//**//*/////**/##(/***********************////*/*/&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&(,****///**//(((#(##(((//(//*//(#%%&&&&&#//*///((#%%%%%%###((///**********************/*///*/&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&******///***/((#(#((////*(///*/(#%&&&&&&(/*///(((/(((#####((((((///////**************//(///*/&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&#,,****//**//((((((//*/*//((/((##%&&&&&&&(/*//(((#((####(((/#(((((((///////*********//(((//***&@&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&/,*****//**//((((((/***//(###(%%&&&&&&&&&&#/////((((((#((#/#/(((/////(/////////****///((///****/@@&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&@%.,,****//*///((((#/////(((#%#%%&&&&&&&&&&&&&(//(##%%%%%%&%%&&%##/#((/(/(/////////////((((///*****(@&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&%,,,,,,,***/((/######(((((##%%&&&&&&&&&&&&&@&&&@(/(#//**/(((/((((######((##(///////////((//(//*****,#&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&%/,,,,*////(((%%%%%%#%%%%%%&&&&&&&&&&&&&&&&&&&&&&%(//////(//////(/((((((/(%#(((((((///(((((///***/%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&%&#****/((#%%&%%%%#%%%%&&&&&&&&&&&&&&&&&&&&&&&&&&&&(***/((/((///((((///***(##((###((((#(((/////#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&%(((((#########&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@&**,*////(//(/*(//**,,,(%%&&&&%#####((((/%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&%#########(#%%&@@&&&&&&&&&&&&&&&&@&&&@@@@@@@@&&&/,***///(////**,*,***(#%%%%%%%%%##(((%&&&&@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&@&&&%#%&&@@@@@@@@@@&&&&&&&&@@&&@@@@@@@@&&@@@@@@@@@@@%/*////////*******/#%%%%&%%%%####%&&&&&&&&&&&&&&&&&&&&&&@&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&&&&&&&@&&&@@@@@@@@@@@@@&&&&&&&@@@@&@@@@@@@@@@@@@@@@@@@@@@@@@@%//((((((#(#((%&&&&%%%%%%%%%&&&&&&&&&&&&&&&&&&&%%&&&@&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&@@@@&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@&&&@@@&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&@@####&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%%&&&@&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "@@@@@&&&&&&&&&&&&&@&/(%&&&@@@@@@@@@@&&&&&@@&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%//(##%%%&&%&&@@@@&&&&&&&&&&&&&&&&&&%%&@&@@@&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "@@@&&&&&&&&&&&&&@&&&%#(&@&@@@@@@@@@&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@(///((((#&@@@@@@@@@&&&&&&&&&&&&&&&%%&&&@@@&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&@&&&&&@&&@@&@&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%///////@@@@@@@@@@@@@&%&&&&&&&&&&%&@&&&@@&&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&@@@@&&&&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&/////*&@@@@@@@@@@@@@@@@&%%%&&&%%&@&@@@@&&&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&@@@&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#//*/&@@@@@@@@@@@@@@@@@@@@&%%#&&@@@&@@&&&&&@&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&&&&&@&(%&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&(/(@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&@@&&&&&&@&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&&&&@@@@%(%&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%&@@@@@@@@@@@&&@@@@@@@@@&&&&&&&&&@@&&&&&&&@&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&&@@@@@@@%((@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&@@@@@&&&&&&&&&&&&&&@@&&&&&&&&@&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&&@@@@@@@@##%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&@@@&%#%@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "&&&&&&&@@@@@@@@&#&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&((%@&@@@@@@@@&&&&&&&&&&&&&&&&&&&@&&&&&&&&@&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "@@@@&&@@@@@@@@%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&@@&&&&&&&&&@&&&&&&&&&&&&&&&&&&&&&&&&@&&&&&&&&&&&&&&&&&&&&&&\n";
        cout << "@@@@@@@@@@@@&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&@&&@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@&&&&@@@@&&&&&&&&&&&&&&\n";
        cout << "@@@@@@&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&@@&&&&&&&&&&&&&&&@@@&&&&&&&&&&&&&&&&&&&&&&&@@@@&&@@@@@&&&&&&&&&&&&&&\n";
        cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&@@&&&&&&&&&&&&&&&@@&&&&&&&&&&&&&&&&&&&&&&&&@@@&&@@@@@@&&&&&&&&&&&&&&\n";
    }
    cout << endl;
}

// Input validation
float requireFloatFromUser(float min = numeric_limits<float>::lowest(), float max = numeric_limits<float>::max(), string invalidInputMessage = "I have no idea what you just input.") {
    string minString = (min == numeric_limits<float>::lowest()) ? "-∞" : to_string(min);
    string maxString = (max == numeric_limits<float>::max()) ? "∞" : to_string(max);
    // Format range by removing trailing zeros and decimal point
    minString.erase(minString.find_last_not_of('0') + 1, string::npos);
    maxString.erase(maxString.find_last_not_of('0') + 1, string::npos);
    if (minString.back() == '.') {
        minString.pop_back();
    }
    if (maxString.back() == '.') {
        maxString.pop_back();
    }

    string range = " (" + minString + " to " + maxString + ")";
    // The range should only be displayed if it has a custom value
    bool displayRange = !(min == numeric_limits<float>::lowest() && max == numeric_limits<float>::max());

    float input;
    cout << "NUMBER" << (displayRange ? range : "") << ": ";
    cin >> input;
    while (!cin) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << invalidInputMessage << " ENTER A NUMBER" << (displayRange ? range : "") << ": ";
        cin >> input;
    }
    cin.ignore();

    return input;
}

// Input validation
bool requireYNFromUser(string invalidInputMessage = "I have no idea what you just input.") {
    char input;
    cout << "Y or N: ";
    cin >> input;
    bool validInput = (tolower(input) == 'y' || tolower(input) == 'n');
    while (!(cin && validInput)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << invalidInputMessage << " ENTER Y or N: ";
        cin >> input;
        validInput = (tolower(input) == 'y' || tolower(input) == 'n');
    }
    cin.ignore();

    return (tolower(input) == 'y');
}

// To pace the execution of the program
void enterToContinue() {
    cout << endl
         << "(Press Enter to continue)";
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

    // Move cursor up one line
    cout << "\033[A";
    // Clear the entire line
    cout << "\033[2K";

    // Does it again
    cout << "\033[A";
    cout << "\033[2K";
}

// NOTE TO GRADER: Fixes the bad normal rand on MacOS (see README). If on Windows, comment out this function and uncomment the below srand in the main
int rand() {
    // Casts to int
    return abs((int)arc4random());
}

int main() {
    // NOTE TO GRADER: If on Windows, uncomment this
    // srand(time(0));

    LinkedList<Destination *> destinationsList;

    adamSavage();

    /// Getting from file
    string filename;
    cout << "What is the name of the file you would like to load destinations from? ";
    getline(cin, filename);
    cout << endl;

    ifstream outputFile;
    outputFile.open(filename);
    if (!outputFile.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return 1;
    }

    // The "line" separated by # delimiters instead of linebreaks
    int lineNumber = 1;
    string lineValue;

    string placeName = "";
    string description = "";
    float travelCost = 0;
    int dangerScore = 0;
    while (getline(outputFile, lineValue, '#')) {
        // Assigns each line based on where they are in the 4-line bunch
        switch (((lineNumber - 1) % 4) + 1) {
        case 1: {
            placeName = lineValue;
            break;
        }
        case 2: {
            description = lineValue;
            break;
        }
        case 3: {
            try {
                travelCost = stof(lineValue);
            } catch (...) {
                cout << "ERROR: Failed to convert string to float in " << filename << " on delimited line " << lineNumber << ". Invalid input is: " << lineValue << endl;
                cout << "Ending program" << endl;
                return 1;
            }
            break;
        }
        case 4: {
            try {
                dangerScore = stoi(lineValue);
            } catch (...) {
                cout << "ERROR: Failed to convert string to int in " << filename << " on delimited line " << lineNumber << ". Invalid input is: " << lineValue << endl;
                cout << "Ending program" << endl;
                return 1;
            }

            Destination *newDestination = new Destination(placeName, description, travelCost, dangerScore);
            destinationsList.insertNode(newDestination);

            placeName = "";
            description = "";
            travelCost = 0;
            dangerScore = 0;
            break;
        }
        }
        lineNumber++;
    }
    outputFile.close();

    /// Printing out list of destinations
    for (int i = 0; i < destinationsList.getLength(); i++) {
        cout << setfill('-') << setw(30) << "DESTINATION #" << i + 1 << setw(20) << "" << endl;
        cout << *(destinationsList.getNodeValue(i));
        cout << setfill(' ') << endl;
    }

    enterToContinue();

    /// Choosing destination
    cout << endl
         << "Answer the following four questions and I will determine the place you should travel." << endl
         << endl;

    cout << "\t1. So traveler, what's your name? ";
    string userName;
    bool validUserName = false;
    do {
        getline(cin, userName);
        validUserName = (userName != "");
        cout << (validUserName ? "" : "Username cannot be blank: ");
    } while (!validUserName);
    cout << endl;

    cout << "\t2. How much money do you make per year? ";
    float salary = requireFloatFromUser(0);
    cout << endl;

    cout << "\t3. Do you watch MythBusters? ";
    bool watchesMythBusters = requireYNFromUser();
    if (!watchesMythBusters) {
        cout << endl
             << "\tThat's a shame." << endl;
        enterToContinue();
    }
    cout << endl;

    cout << "\t4. Would dropping a penny off the Empire State Building kill someone? ";
    bool thinksDroppingAPennyOffTheEmpireStateBuildingWouldKillSomeone = requireYNFromUser(); // :D this is a joke variable name
    if (thinksDroppingAPennyOffTheEmpireStateBuildingWouldKillSomeone) {
        cout << endl
             << "\tYou're entirely wrong. You should watch " << (watchesMythBusters ? "more " : "") << "MythBusters!" << endl;
        enterToContinue();
    } else {
        cout << endl
             << "\tThat's right. Myth busted." << endl;
        enterToContinue();
    }
    cout << endl;

    cout << "Alright, " << userName;
    cout << ", based on your salary ($" << salary << "), ";
    cout << "the fact that you " << (watchesMythBusters ? "" : "do not ") << "watch MythBusters, ";
    cout << (thinksDroppingAPennyOffTheEmpireStateBuildingWouldKillSomeone ? "and because you think dropping a penny off the Empire State Building would kill someone, " : "and because you know dropping a penny off the Empire State Building would not kill someone, ");
    cout << "you are going to travel to the following destination:" << endl;

    enterToContinue();

    int magicNumber = (rand() % destinationsList.getLength());
    cout << endl;
    cout << *(destinationsList.getNodeValue(magicNumber));
    cout << endl;

    enterToContinue();

    cout << endl
         << endl
         << "HAVE FUN!!" << endl;
}