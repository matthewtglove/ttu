// 	C++ program using greedy algorithm to find change 
//	using minimum number of denominations of american currency (paper bills)
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std; 
  
const int SIZE = 9;  
void findMin(int deno[], int V);

int main() 
{ 
	// All denominations of American Currency (bills) 
	int deno[SIZE] = { 1, 2, 5, 10, 20, 50, 100, 500, 1000 }; 
    int amountChange; 
	cout << "\n\nWhat is the amount that you need change for?\n";
	cin >> amountChange;
    cout << "Following is minimal number of change for " << amountChange << ": "; 
	
    findMin(deno, amountChange); 
	
	cout << endl << endl;
    return 0; 
} 

void findMin(int deno[], int amountChangeLeft) 
{ 
    // Initialize result 
    vector<int> ans; 
  
    // Traverse through all denomination backwards 
    for (int i = SIZE - 1; i >= 0; i--) { 
        
		//while we still owe change & the amount is larger then current denomination
        while (amountChangeLeft >= deno[i]) 
		{ 
            amountChangeLeft -= deno[i]; 
            ans.push_back(deno[i]); 
        } 
    } 
  
    // Print result 
    for (int i = 0; i < ans.size(); i++) 
        cout << ans.at(i) << "  "; 
} 
  
