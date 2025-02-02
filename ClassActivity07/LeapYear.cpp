#include <iostream>

using namespace std;


int main(){
    int year = 4;
    bool leapYear = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
    
    
    cout << year << " is " << (leapYear ? "a leap year" : "not a leap year") << endl;
    
    return 0;
}
