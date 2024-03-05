Watch MythBusters

## Using arc4rand() instead of rand()
On MacOS, the normal rand() seeded with the current time will always result in a factor of 7 (on the first random number call). This is because of the bad default randomizer the system has (which just multiplies the given random value by a specific factor). 
See more information on this issue here: https://stackoverflow.com/questions/7866754/why-does-rand-7-always-return-0