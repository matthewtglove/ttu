// 
/*
	C++ program for activity selection problem. 
	
	The activity selection problem is a problem where 1 or more 
	activities are available, each with a start and finish time, 
	and the goal is to build the largest possible set of activities 
	without time conflicts. 
	Ex: When on vacation, various activities such as museum tours 
	or mountain hikes may be available. Since vacation time is limited, 
	the desire is often to engage in the maximum possible number of 
	activities per day.

	In this algorithm, the first step is that activities are sorted in 
	ascending order by finish time.  This implementation already
	assumes that the activities are already sorted.

*/
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

void printMaxActivities(string [], int s[], int f[], int n);

int main() 
{ 
    int startTime[] =  {1, 3, 0, 5, 8, 5};  //start time of all activities
    int finishTime[] =  {2, 4, 6, 7, 9, 9}; //finish times of activities - already sorted in ascending order
	string activityDescription[] = 
						{ 	"Getting Started with Game Dev", 
							"How to Build a Card Game",
							"Sid Meier talk: Civilization",
							"Todd Howard talk: Elder Scrolls",
							"Creating a Game in Unity",
							"Designing Assets for your Game"
						};
    int arraySize = sizeof(startTime)/sizeof(startTime[0]); 
	
	cout << "\n\nThe following activities are available:\n\n";
	cout << setw(33) << "Activity" << setw(12) << "Start Time" << setw(12) << "End Time" << endl;
	for(int i=0; i<arraySize; i++)
	{
		cout << setw(33) << activityDescription[i] << setw(12) << startTime[i] << setw(12) << finishTime[i] << endl;
	}
	
    printMaxActivities(activityDescription, startTime, finishTime, arraySize); 
	
	cout << endl << endl;
    return 0; 
} 
  
// Prints a maximum set of activities that can be done by a single 
// person, one at a time. 
//  n   -->  Total number of activities 
//  s[] -->  An array that contains start time of all activities 
//  f[] -->  An array that contains finish time of all activities 
void printMaxActivities(string desc[], int s[], int f[], int n) 
{ 
    int i, j; 
  
    cout << "\n\nThe following activities are selected:\n\n"; 
  
    // The first activity always gets selected
    i = 0; 
    cout << desc[i] << endl; 
  
    // Consider rest of the activities 
    for (j = 1; j < n; j++) 
    { 
      // If this activity has start time greater than or 
      // equal to the finish time of previously selected 
      // activity, then select it 
      if (s[j] >= f[i]) 
      { 
          cout << desc[j] << endl; 
          i = j; 
      } 
    } 
} 
  
