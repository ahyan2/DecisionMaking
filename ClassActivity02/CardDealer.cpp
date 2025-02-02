#include <iostream>
#include <cstdlib>  // import for rand()
#include <iomanip>  // input output manipulation import.

using namespace std;


int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    
    int randomSuit = rand() % 4;    // 0 - 3
    int randomRank = rand() % 13;   // 0 - 12
    
    string suits[4] = {"Spades", "Hearts", "Diamonds", "Clubs"};
    string ranks[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    
    string card = ranks[randomRank] + " of " + suits[randomSuit];
    
    
    cout << setfill('*') << setw(40) << "" <<  endl;
    cout << setfill(' ') << setw(40) << "" << endl;
    
    cout << setfill('-') << left << setw(20) << "Casino Card:" << setw(20) << right << card << endl;
    
    cout << setfill(' ') << setw(40) << "" << endl;
    cout << setfill('*') << setw(40) << "" <<  endl;

    
    
    
    
    return 0;
}
