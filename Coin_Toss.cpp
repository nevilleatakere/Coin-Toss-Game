// Program Name: Coin Toss
// Purpose: To determine the coins position on the tosses made
// Description: Write program that uses a function named coinToss that simulates the tossing of a coin. When you call the function, it should generate a random number in the range of 1 through 2. If the random number is 1, the function should display “heads”. 
// Author: Neville Atakere
// Date Last Modified: 06/28/2020
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void coinToss();
int inputValidate(int);
int main()
{
    int choice;
    unsigned seed = time(0);
    srand(seed);
    cout << "How many tosses should I make?";
    choice = inputValidate(choice);
    for (int i = 0; i < choice; i++)
    coinToss();
    return 0;
}
int inputValidate(int num)
{
    while(!(cin >> num) || num < 0)
    {
        cout << " Incorrect, Enter a number above 0: ";
        cin.clear();
        cin.ignore(123, '\n');
    }
    return num;
}
void coinToss()
{
    const int MinimumValue = 1;
    const int MaximumValue = 2;
    int coin;
    coin = (rand() % (MaximumValue - MinimumValue + 1)) + MinimumValue;
    cout << (coin == MinimumValue ? "Heads" : "Tails") << endl;
}
