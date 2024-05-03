/* 
	Fractional knapsack problem using greedy programming.\

	While a greedy solution to the 0-1 knapsack problem is 
	not usually optimal, a greedy solution to the fractional 
	knapsack problem is optimal. 	

*/
#include<iostream>
using namespace std;

int main()
{
	/*
		itemArray stores info on each item.  
		first row is item weight & 
		2nd row is item profit
	*/
    int itemArray[2][100]; 
	int numberOfItems; 	//number of possible items
	int maxWeight;		//maximum weight of knapsack
	int currentWeight;	//current weight of knapsack
	int used[100];
	int maxi;				//index of item with maximum unit profit (maximum value)
	int totalprofit = 0;	//accumulator for profit of entire knapsack
	
    //input number of items
    cout << "\n\nEnter number of items you hope to fit in your knapsack: ";
    cin >> numberOfItems;
	
    //input max weight of knapsack
    cout << "Enter the maximum weight the knapsack can hold: ";
    cin >> maxWeight;
	
    // itemArray's first row is to store weights second row is to store profits 
    for (int i = 0; i < numberOfItems; i++)
    {
		cout << "\nEnter the weight & profit of item " << i+1 << ", seperated by a space.\n";
        cin >> itemArray[0][i] >> itemArray[1][i];
    }
    for (int i = 0; i < numberOfItems; i++)
    {
        used[i] = 0;
    }
    currentWeight = maxWeight;
	cout << endl << endl << "-------------------------------------------------------------------------------\n";
	
    //loop until knapsack is full
    while (currentWeight >= 0)
    {

        maxi = -1;
        //loop to find maximum value object
        for (int i = 0; i < numberOfItems; i++)
        {
			//value of item = weight / profit
			float tempItemUnitProfit = static_cast<float>(itemArray[1][i]) / itemArray[0][i]; //value of current item
			float tempMaxiUnitProfit = static_cast<float>(itemArray[1][maxi]) / itemArray[0][maxi]; //value of already established maximum value item
            if ((used[i] == 0) && (tempItemUnitProfit > tempMaxiUnitProfit))
            {
				//this means that we haven't already used this item in the knapsack AND this item has a higher value
                maxi = i;
            }
        }
        used[maxi] = 1; //we now set the maximum value item to used

        //decrease current wight of knapsack by weight of this maximum value item
        currentWeight -= itemArray[0][maxi];
		
        //increase total profit of knapsack by profit of this maximum value item
        totalprofit += itemArray[1][maxi];
		
        if (currentWeight >= 0)  //we have space for this whole item
        {
            cout << "\n\nItem " 	<< maxi + 1 << " was completely added to knapsack.";;
			cout << "\n\tWeight: "			<< itemArray[0][maxi];
			cout << "\n\tProfit: " 		<< itemArray[1][maxi];
			cout << "\n\tSpace left: " << currentWeight;
        }
        else //whole item doesn't fit - take fractional item if possible
        {
            cout << "\n\nItem " 	<< maxi + 1 << " did not completely fit in knapsack.";
			cout << "\n\tWeight added: "			<< (itemArray[0][maxi] + currentWeight);
			cout << "\n\tProfit added: "			<< (static_cast<float>(itemArray[1][maxi]) / itemArray[0][maxi]) * (itemArray[0][maxi] + currentWeight);
			cout << "\n\tSpace left: 0";

			
            totalprofit -= itemArray[1][maxi];
            totalprofit += ((static_cast<float>(itemArray[1][maxi]) / itemArray[0][maxi]) * (itemArray[0][maxi] + currentWeight));
        }
    }
	
    //print total worth of objects filled in knapsack
    cout << "\n\nBags filled with objects worth: " << totalprofit;
	cout << "\n\n";
    return 0;
}