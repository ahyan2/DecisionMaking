#include <iostream>

using namespace std;


int main(){
    int score;
    cout << "What score did you recieve? (0 - 100)" << endl;
    cin >> score;
    
    if (score >= 90){
        cout << "Excellent" << endl;
    } else if (score >= 70){
        cout << "Good" << endl;
    } else if (score >= 60){
        cout << "Pass" << endl;
    } else{
        cout << "Fail" << endl;
    }
    

    
    return 0;
}
