#include <iostream>

using namespace std;


int main(){
    int age;
    cout << "What is your age?" << endl;
    cin >> age;
    
    if (age >= 12){
        if (age >= 20){
            if (age >= 65){
                cout << "Senior" << endl;
            } else {
                cout << "Adult" << endl;
            }
        } else {
            cout << "Teen" << endl;
        }
    } else {
        cout << "Child" << endl;
    }
    
    
    
    return 0;
}
