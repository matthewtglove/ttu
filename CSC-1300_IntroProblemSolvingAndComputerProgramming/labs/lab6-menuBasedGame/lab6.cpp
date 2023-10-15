/*
    Title: lab6.cpp
    Author: Matthew Love
    Date: 2023-10-14, Sat
    Purpose: Creating a menu-based program
*/

#include <iostream>
#include <string>
using namespace std;

int GetIntInRange(int minRange, int maxRange, string invalidInputMessage);

int DisplayMenuGetChoice();

void GoblinSickDays();

void DisplayCoolMessages(int &countTimesDisplayed);

int main()
{
    cout << "\nSplendid. Yet another day at Gringott's bank." << endl;
    int countDisplayCoolMessage = 0;

    // To keep the program running till the user chooses to end it
    bool runAgain = true;
    while (runAgain)
    {
        switch (DisplayMenuGetChoice())
        {
        case 1:
        {
            GoblinSickDays();
            break;
        }

        case 2:
        {
            DisplayCoolMessages(countDisplayCoolMessage);
            break;
        }

        case 3:
        {
            cout << "\n";

            // Differing message depending on number of times the user displayed the COOL MESSAGE
            if (countDisplayCoolMessage == 0)
            {
                cout << "You didn't even display the cool message. How unfortunate." << endl;
            }
            else if (countDisplayCoolMessage < 4)
            {
                cout << "You chose to display the cool message " << countDisplayCoolMessage << " times. You should have displayed it more..." << endl;
            }
            else
            {
                cout << "You chose to display the cool message " << countDisplayCoolMessage << " times. How cool was that?!" << endl;
            }
            cout << endl;

            runAgain = false;
        }
        }
    }

    return 0;
}

// To validate user input (integer min-max)
int GetIntInRange(int minRange, int maxRange, string invalidInputMessage = "Absolutely unnacceptable input.")
{
    int choice;

    bool validChoice = false;
    do
    {
        cout << "INPUT: ";
        cin >> choice;

        validChoice = (choice >= minRange && choice <= maxRange);

        if (!validChoice)
        {
            cout << invalidInputMessage << " Please choose " << minRange << "-" << maxRange << endl;
        }
    } while (!validChoice);

    return choice;
}

int DisplayMenuGetChoice()
{
    cout << endl;
    cout << "What would you like to do?\n";
    cout << "\t1 - Enter Goblin Sick Days\n";
    cout << "\t2 - Display Something Cool (Need a big window)\n";
    cout << "\t3 - End the Program\n\n";

    int menuChoice;

    // To validate user input (integer 1-3)
    menuChoice = GetIntInRange(1, 3);

    return menuChoice;
}

void GoblinSickDays()
{
    cout << "How many Goblin tellers worked at Gringotts during each of the last three years?\n";

    int numGoblins;

    // To validate user input (positive integer)
    numGoblins = GetIntInRange(0, INT_MAX, "What? We don't have negative goblins!");
    cout << endl;

    int totalSickDays = 0;

    for (int i = 1; i <= numGoblins; i++)
    {
        // Last 3 years, so only iterate a set 3 times per goblin
        for (int j = 1; j <= 3; j++)
        {
            cout << "How many sick days was Goblin " << i << " out for, during year " << j << "?\n";
            totalSickDays += GetIntInRange(0, 366, "You uncultered swine. There are not that many days in a year!");
            cout << "\n";
        }
    }

    // Differing message depening on number of goblins
    if (numGoblins == 0)
    {
        cout << "You should really start hiring." << endl;
    }
    else if (numGoblins == 1)
    {
        cout << "The " << numGoblins << " Goblin was out sick for a total of " << totalSickDays << " days during the last 3 years." << endl;
    }
    else
    {
        cout << "The " << numGoblins << " Goblins were out sick for a total of " << totalSickDays << " days during the last 3 years." << endl;
    }
}

void DisplayCoolMessages(int &countTimesDisplayed)
{
    switch (countTimesDisplayed % 4)
    {
    case 0:
    {
        cout << "TTTTTTTTTTTTTTTTTTTTTTThhhhhhh                                                                                                                                                                                   tttt                                                   \n";
        cout << "T:::::::::::::::::::::Th:::::h                                                                                                                                                                                ttt:::t                                                   \n";
        cout << "T:::::::::::::::::::::Th:::::h                                                                                                                                                                                t:::::t                                                   \n";
        cout << "T:::::TT:::::::TT:::::Th:::::h                                                                                                                                                                                t:::::t                                                   \n";
        cout << "TTTTTT  T:::::T  TTTTTT h::::h hhhhh           eeeeeeeeeeee           aaaaaaaaaaaaa  nnnn  nnnnnnnn        sssssssssswwwwwww           wwwww           wwwwwww eeeeeeeeeeee    rrrrr   rrrrrrrrr        ttttttt:::::ttttttt       ooooooooooo                           \n";
        cout << "        T:::::T         h::::hh:::::hhh      ee::::::::::::ee         a::::::::::::a n:::nn::::::::nn    ss::::::::::sw:::::w         w:::::w         w:::::wee::::::::::::ee  r::::rrr:::::::::r       t:::::::::::::::::t     oo:::::::::::oo                         \n";
        cout << "        T:::::T         h::::::::::::::hh   e::::::eeeee:::::ee       aaaaaaaaa:::::an::::::::::::::nn ss:::::::::::::sw:::::w       w:::::::w       w:::::we::::::eeeee:::::eer:::::::::::::::::r      t:::::::::::::::::t    o:::::::::::::::o                        \n";
        cout << "        T:::::T         h:::::::hhh::::::h e::::::e     e:::::e                a::::ann:::::::::::::::ns::::::ssss:::::sw:::::w     w:::::::::w     w:::::we::::::e     e:::::err::::::rrrrr::::::r     tttttt:::::::tttttt    o:::::ooooo:::::o                        \n";
        cout << "        T:::::T         h::::::h   h::::::he:::::::eeeee::::::e         aaaaaaa:::::a  n:::::nnnn:::::n s:::::s  ssssss  w:::::w   w:::::w:::::w   w:::::w e:::::::eeeee::::::e r:::::r     r:::::r           t:::::t          o::::o     o::::o                        \n";
        cout << "        T:::::T         h:::::h     h:::::he:::::::::::::::::e        aa::::::::::::a  n::::n    n::::n   s::::::s        w:::::w w:::::w w:::::w w:::::w  e:::::::::::::::::e  r:::::r     rrrrrrr           t:::::t          o::::o     o::::o                        \n";
        cout << "        T:::::T         h:::::h     h:::::he::::::eeeeeeeeeee        a::::aaaa::::::a  n::::n    n::::n      s::::::s      w:::::w:::::w   w:::::w:::::w   e::::::eeeeeeeeeee   r:::::r                       t:::::t          o::::o     o::::o                        \n";
        cout << "        T:::::T         h:::::h     h:::::he:::::::e                a::::a    a:::::a  n::::n    n::::nssssss   s:::::s     w:::::::::w     w:::::::::w    e:::::::e            r:::::r                       t:::::t    tttttto::::o     o::::o                        \n";
        cout << "      TT:::::::TT       h:::::h     h:::::he::::::::e               a::::a    a:::::a  n::::n    n::::ns:::::ssss::::::s     w:::::::w       w:::::::w     e::::::::e           r:::::r                       t::::::tttt:::::to:::::ooooo:::::o                        \n";
        cout << "      T:::::::::T       h:::::h     h:::::h e::::::::eeeeeeee       a:::::aaaa::::::a  n::::n    n::::ns::::::::::::::s       w:::::w         w:::::w       e::::::::eeeeeeee   r:::::r                       tt::::::::::::::to:::::::::::::::o ......  ......  ...... \n";
        cout << "      T:::::::::T       h:::::h     h:::::h  ee:::::::::::::e        a::::::::::aa:::a n::::n    n::::n s:::::::::::ss         w:::w           w:::w         ee:::::::::::::e   r:::::r                         tt:::::::::::tt oo:::::::::::oo  .::::.  .::::.  .::::. \n";
        cout << "      TTTTTTTTTTT       hhhhhhh     hhhhhhh    eeeeeeeeeeeeee         aaaaaaaaaa  aaaa nnnnnn    nnnnnn  sssssssssss            www             www            eeeeeeeeeeeeee   rrrrrrr                           ttttttttttt     ooooooooooo    ......  ......  ...... \n";
        break;
    }

    case 1:
    {
        cout << "lllllll   iiii     ffffffffffffffff                                       tttt         hhhhhhh                                                                          iiii                                                                                                                            \n";
        cout << "l:::::l  i::::i   f::::::::::::::::f                                   ttt:::t         h:::::h                                                                         i::::i                                                                                                                           \n";
        cout << "l:::::l   iiii   f::::::::::::::::::f                                  t:::::t         h:::::h                                                                          iiii                                                                                                                            \n";
        cout << "l:::::l          f::::::fffffff:::::f                                  t:::::t         h:::::h                                                                                                                                                                                                          \n";
        cout << " l::::l iiiiiii  f:::::f       ffffffeeeeeeeeeeee                ttttttt:::::ttttttt    h::::h hhhhh           eeeeeeeeeeee         uuuuuu    uuuuuunnnn  nnnnnnnn    iiiiiiivvvvvvv           vvvvvvv eeeeeeeeeeee    rrrrr   rrrrrrrrr       ssssssssss       eeeeeeeeeeee                            \n";
        cout << " l::::l i:::::i  f:::::f           ee::::::::::::ee              t:::::::::::::::::t    h::::hh:::::hhh      ee::::::::::::ee       u::::u    u::::un:::nn::::::::nn  i:::::i v:::::v         v:::::vee::::::::::::ee  r::::rrr:::::::::r    ss::::::::::s    ee::::::::::::ee                          \n";
        cout << " l::::l  i::::i f:::::::ffffff    e::::::eeeee:::::ee            t:::::::::::::::::t    h::::::::::::::hh   e::::::eeeee:::::ee     u::::u    u::::un::::::::::::::nn  i::::i  v:::::v       v:::::ve::::::eeeee:::::eer:::::::::::::::::r ss:::::::::::::s  e::::::eeeee:::::ee                        \n";
        cout << " l::::l  i::::i f::::::::::::f   e::::::e     e:::::e            tttttt:::::::tttttt    h:::::::hhh::::::h e::::::e     e:::::e     u::::u    u::::unn:::::::::::::::n i::::i   v:::::v     v:::::ve::::::e     e:::::err::::::rrrrr::::::rs::::::ssss:::::se::::::e     e:::::e                        \n";
        cout << " l::::l  i::::i f::::::::::::f   e:::::::eeeee::::::e                  t:::::t          h::::::h   h::::::he:::::::eeeee::::::e     u::::u    u::::u  n:::::nnnn:::::n i::::i    v:::::v   v:::::v e:::::::eeeee::::::e r:::::r     r:::::r s:::::s  ssssss e:::::::eeeee::::::e                        \n";
        cout << " l::::l  i::::i f:::::::ffffff   e:::::::::::::::::e                   t:::::t          h:::::h     h:::::he:::::::::::::::::e      u::::u    u::::u  n::::n    n::::n i::::i     v:::::v v:::::v  e:::::::::::::::::e  r:::::r     rrrrrrr   s::::::s      e:::::::::::::::::e                         \n";
        cout << " l::::l  i::::i  f:::::f         e::::::eeeeeeeeeee                    t:::::t          h:::::h     h:::::he::::::eeeeeeeeeee       u::::u    u::::u  n::::n    n::::n i::::i      v:::::v:::::v   e::::::eeeeeeeeeee   r:::::r                  s::::::s   e::::::eeeeeeeeeee                          \n";
        cout << " l::::l  i::::i  f:::::f         e:::::::e                             t:::::t    tttttth:::::h     h:::::he:::::::e                u:::::uuuu:::::u  n::::n    n::::n i::::i       v:::::::::v    e:::::::e            r:::::r            ssssss   s:::::s e:::::::e                                   \n";
        cout << "l::::::li::::::if:::::::f        e::::::::e           ,,,,,,           t::::::tttt:::::th:::::h     h:::::he::::::::e               u:::::::::::::::uun::::n    n::::ni::::::i       v:::::::v     e::::::::e           r:::::r            s:::::ssss::::::se::::::::e                                  \n";
        cout << "l::::::li::::::if:::::::f         e::::::::eeeeeeee   ,::::,           tt::::::::::::::th:::::h     h:::::h e::::::::eeeeeeee        u:::::::::::::::un::::n    n::::ni::::::i        v:::::v       e::::::::eeeeeeee   r:::::r            s::::::::::::::s  e::::::::eeeeeeee   ......  ......  ...... \n";
        cout << "l::::::li::::::if:::::::f          ee:::::::::::::e   ,::::,             tt:::::::::::tth:::::h     h:::::h  ee:::::::::::::e         uu::::::::uu:::un::::n    n::::ni::::::i         v:::v         ee:::::::::::::e   r:::::r             s:::::::::::ss    ee:::::::::::::e   .::::.  .::::.  .::::. \n";
        cout << "lllllllliiiiiiiifffffffff            eeeeeeeeeeeeee   ,:::,,               ttttttttttt  hhhhhhh     hhhhhhh    eeeeeeeeeeeeee           uuuuuuuu  uuuunnnnnn    nnnnnniiiiiiii          vvv            eeeeeeeeeeeeee   rrrrrrr              sssssssssss        eeeeeeeeeeeeee   ......  ......  ...... \n";
        cout << "                                                     ,:::,                                                                                                                                                                                                                                              \n";
        cout << "                                                     ,,,,                                                                                                                                                                                                                                               \n";
        break;
    }

    case 2:
    {
        cout << "                                               dddddddd                                                                                                                                                                                                                                                                                                                         \n";
        cout << "                                               d::::::d                                                                                                                    tttt         hhhhhhh               iiii                                              iiii                          iiii          tttt                 iiii                                           \n";
        cout << "                                               d::::::d                                                                                                                 ttt:::t         h:::::h              i::::i                                            i::::i                        i::::i      ttt:::t                i::::i                                          \n";
        cout << "                                               d::::::d                                                                                                                 t:::::t         h:::::h               iiii                                              iiii                          iiii       t:::::t                 iiii                                           \n";
        cout << "                                               d:::::d                                                                                                                  t:::::t         h:::::h                                                                                                          t:::::t                                                                \n";
        cout << "  aaaaaaaaaaaaa  nnnn  nnnnnnnn        ddddddddd:::::d          eeeeeeeeeeee  vvvvvvv           vvvvvvv eeeeeeeeeeee    rrrrr   rrrrrrrrryyyyyyy           yyyyyyyttttttt:::::ttttttt    h::::h hhhhh       iiiiiiinnnn  nnnnnnnn       ggggggggg   ggggg     iiiiiiinnnn  nnnnnnnn         iiiiiiittttttt:::::ttttttt         iiiiiii     ssssssssss                           \n";
        cout << "  a::::::::::::a n:::nn::::::::nn    dd::::::::::::::d        ee::::::::::::ee v:::::v         v:::::vee::::::::::::ee  r::::rrr:::::::::ry:::::y         y:::::y t:::::::::::::::::t    h::::hh:::::hhh    i:::::in:::nn::::::::nn    g:::::::::ggg::::g     i:::::in:::nn::::::::nn       i:::::it:::::::::::::::::t         i:::::i   ss::::::::::s                          \n";
        cout << "  aaaaaaaaa:::::an::::::::::::::nn  d::::::::::::::::d       e::::::eeeee:::::eev:::::v       v:::::ve::::::eeeee:::::eer:::::::::::::::::ry:::::y       y:::::y  t:::::::::::::::::t    h::::::::::::::hh   i::::in::::::::::::::nn  g:::::::::::::::::g      i::::in::::::::::::::nn       i::::it:::::::::::::::::t          i::::i ss:::::::::::::s                         \n";
        cout << "           a::::ann:::::::::::::::nd:::::::ddddd:::::d      e::::::e     e:::::e v:::::v     v:::::ve::::::e     e:::::err::::::rrrrr::::::ry:::::y     y:::::y   tttttt:::::::tttttt    h:::::::hhh::::::h  i::::inn:::::::::::::::ng::::::ggggg::::::gg      i::::inn:::::::::::::::n      i::::itttttt:::::::tttttt          i::::i s::::::ssss:::::s                        \n";
        cout << "    aaaaaaa:::::a  n:::::nnnn:::::nd::::::d    d:::::d      e:::::::eeeee::::::e  v:::::v   v:::::v e:::::::eeeee::::::e r:::::r     r:::::r y:::::y   y:::::y          t:::::t          h::::::h   h::::::h i::::i  n:::::nnnn:::::ng:::::g     g:::::g       i::::i  n:::::nnnn:::::n      i::::i      t:::::t                i::::i  s:::::s  ssssss                         \n";
        cout << "  aa::::::::::::a  n::::n    n::::nd:::::d     d:::::d      e:::::::::::::::::e    v:::::v v:::::v  e:::::::::::::::::e  r:::::r     rrrrrrr  y:::::y y:::::y           t:::::t          h:::::h     h:::::h i::::i  n::::n    n::::ng:::::g     g:::::g       i::::i  n::::n    n::::n      i::::i      t:::::t                i::::i    s::::::s                              \n";
        cout << " a::::aaaa::::::a  n::::n    n::::nd:::::d     d:::::d      e::::::eeeeeeeeeee      v:::::v:::::v   e::::::eeeeeeeeeee   r:::::r               y:::::y:::::y            t:::::t          h:::::h     h:::::h i::::i  n::::n    n::::ng:::::g     g:::::g       i::::i  n::::n    n::::n      i::::i      t:::::t                i::::i       s::::::s                           \n";
        cout << "a::::a    a:::::a  n::::n    n::::nd:::::d     d:::::d      e:::::::e                v:::::::::v    e:::::::e            r:::::r                y:::::::::y             t:::::t    tttttth:::::h     h:::::h i::::i  n::::n    n::::ng::::::g    g:::::g       i::::i  n::::n    n::::n      i::::i      t:::::t    tttttt      i::::i ssssss   s:::::s                         \n";
        cout << "a::::a    a:::::a  n::::n    n::::nd::::::ddddd::::::dd     e::::::::e                v:::::::v     e::::::::e           r:::::r                 y:::::::y              t::::::tttt:::::th:::::h     h:::::hi::::::i n::::n    n::::ng:::::::ggggg:::::g      i::::::i n::::n    n::::n     i::::::i     t::::::tttt:::::t     i::::::is:::::ssss::::::s                        \n";
        cout << "a:::::aaaa::::::a  n::::n    n::::n d:::::::::::::::::d      e::::::::eeeeeeee         v:::::v       e::::::::eeeeeeee   r:::::r                  y:::::y               tt::::::::::::::th:::::h     h:::::hi::::::i n::::n    n::::n g::::::::::::::::g      i::::::i n::::n    n::::n     i::::::i     tt::::::::::::::t     i::::::is::::::::::::::s  ......  ......  ...... \n";
        cout << " a::::::::::aa:::a n::::n    n::::n  d:::::::::ddd::::d       ee:::::::::::::e          v:::v         ee:::::::::::::e   r:::::r                 y:::::y                  tt:::::::::::tth:::::h     h:::::hi::::::i n::::n    n::::n  gg::::::::::::::g      i::::::i n::::n    n::::n     i::::::i       tt:::::::::::tt     i::::::i s:::::::::::ss   .::::.  .::::.  .::::. \n";
        cout << "  aaaaaaaaaa  aaaa nnnnnn    nnnnnn   ddddddddd   ddddd         eeeeeeeeeeeeee           vvv            eeeeeeeeeeeeee   rrrrrrr                y:::::y                     ttttttttttt  hhhhhhh     hhhhhhhiiiiiiii nnnnnn    nnnnnn    gggggggg::::::g      iiiiiiii nnnnnn    nnnnnn     iiiiiiii         ttttttttttt       iiiiiiii  sssssssssss     ......  ......  ...... \n";
        cout << "                                                                                                                                               y:::::y                                                                                           g:::::g                                                                                                                        \n";
        cout << "                                                                                                                                              y:::::y                                                                                gggggg      g:::::g                                                                                                                        \n";
        cout << "                                                                                                                                             y:::::y                                                                                 g:::::gg   gg:::::g                                                                                                                        \n";
        cout << "                                                                                                                                            y:::::y                                                                                   g::::::ggg:::::::g                                                                                                                        \n";
        cout << "                                                                                                                                           yyyyyyy                                                                                     gg:::::::::::::g                                                                                                                         \n";
        cout << "                                                                                                                                                                                                                                         ggg::::::ggg                                                                                                                           \n";
        cout << "                                                                                                                                                                                                                                            gggggg                                                                                                                              \n";
        break;
    }

    case 3:
    {
        cout << "       444444444   222222222222222            \n";
        cout << "      4::::::::4  2:::::::::::::::22          \n";
        cout << "     4:::::::::4  2::::::222222:::::2         \n";
        cout << "    4::::44::::4  2222222     2:::::2         \n";
        cout << "   4::::4 4::::4              2:::::2         \n";
        cout << "  4::::4  4::::4              2:::::2         \n";
        cout << " 4::::4   4::::4           2222::::2          \n";
        cout << "4::::444444::::444    22222::::::22           \n";
        cout << "4::::::::::::::::4  22::::::::222             \n";
        cout << "4444444444:::::444 2:::::22222                \n";
        cout << "          4::::4  2:::::2                     \n";
        cout << "          4::::4  2:::::2                     \n";
        cout << "          4::::4  2:::::2       222222        \n";
        cout << "        44::::::442::::::2222222:::::2 ...... \n";
        cout << "        4::::::::42::::::::::::::::::2 .::::. \n";
        cout << "        444444444422222222222222222222 ...... \n";
        break;
    }
    }

    countTimesDisplayed += 1;
}
