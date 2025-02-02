#include <iostream>
#include <iomanip>

using namespace std;


int main(){
    int numberID = 1;
    double balance = 1000.00;
    string name = "Alice";
    
    
    cout << right << setw(24) << "Daily Report" << endl;  // Assuming console 40 spaces, Middle of Daily Report on 20th space.
    
    cout << left << setw(15) << "ID" << setw(15) << "Name" << "Balance" << endl;
    // section 1 is 15 spaces, with ID left-aligned. (After 'left' keyword, everything will be left-aligned). section 2 is another 15 spaces starting with Name. At the end of this, Balance is printed.
    
    cout << setw(40) << setfill('-') << "" << endl;
    
    
    cout << right << setw(5) << setfill('0') << numberID << setfill(' ') << setw(10) << "" << left << setw(15) << name << "$" << fixed << setprecision(2) << balance << endl;
    
    /*
     First, we will create 5 spaces, right-aligning our ID and padding spaces before with 0s.
     Then, we swap padding back to empty spaces, creating 10 spaces before our name, and swap alignment back to left.
     Now we create 15 spaces, left-aligning name.
     At the end of these spaces, we add a dollar sign, use fixed for decimal precision, and set_precision to limit balance to 2 decimal places.
     
     */
    
    numberID = 2;
    balance = 530.25;
    name = "Bob";
    
    cout << right << setw(5) << setfill('0') << numberID << setfill(' ') << setw(10) << "" << left << setw(15) << name << "$" << fixed << setprecision(2) << balance << endl;
    
    numberID = 3;
    balance = 2040.50;
    name = "Charlie";
    
    cout << right << setw(5) << setfill('0') << numberID << setfill(' ') << setw(10) << "" << left << setw(15) << name << "$" << fixed << setprecision(2) << balance << endl;
    
    
    return 0;
}
