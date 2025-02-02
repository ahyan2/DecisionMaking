#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;


int main() {
    const double USD_TO_EUR = 0.9650;   // cannot use const_cast on const variables (unchangeable)
    const double USD_TO_GBP = 0.8071;
    const double USD_TO_JPY = 155.17;
    const double EUR_TO_USD = 1.0363;
    const double GBP_TO_USD = 1.2390;
    const double JPY_TO_USD = 0.0064;
    
    double modUSD_TO_EUR = USD_TO_EUR;  // able to refer to these modifiable copies with const_cast
    double modUSD_TO_GBP = USD_TO_GBP;
    double modUSD_TO_JPY = USD_TO_JPY;
    double modEUR_TO_USD = EUR_TO_USD;
    double modGBP_TO_USD = GBP_TO_USD;
    double modJPY_TO_USD = JPY_TO_USD;
    
    while (true){       // loop to ensure user input is valid
        char promoChoice;
            cout << setw(100) << setfill('-') << "" << setfill(' ') << endl;    // including lines between initial outputs
            cout << "Do you want to apply the promotional rate? (y/n):" << endl;
            cin >> promoChoice;

            if (promoChoice == 'y') {
                double* pointUSD_TO_EUR = const_cast<double*>(&modUSD_TO_EUR);   // const_cast temporarily adjusts the rates. only non-const value modified, not original const value
                double* pointUSD_TO_GBP = const_cast<double*>(&modUSD_TO_GBP);
                double* pointUSD_TO_JPY = const_cast<double*>(&modUSD_TO_JPY);
                double* pointEUR_TO_USD = const_cast<double*>(&modEUR_TO_USD);
                double* pointGBP_TO_USD = const_cast<double*>(&modGBP_TO_USD);
                double* pointJPY_TO_USD = const_cast<double*>(&modJPY_TO_USD);

                *pointUSD_TO_EUR *= 1.10;   // Increase rates by 10% from promotional offer
                *pointUSD_TO_GBP *= 1.10;
                *pointUSD_TO_JPY *= 1.10;
                *pointEUR_TO_USD *= 1.10;
                *pointGBP_TO_USD *= 1.10;
                *pointJPY_TO_USD *= 1.10;

                cout << "Promotional rates applied, the conversion rates have been increased by 10%." << endl;
            }
        
        if (cin.fail() || (promoChoice != 'y' && promoChoice != 'n')) {   // if invalid input, not a char or not 'y' or 'n', then loop through again.
                        cout << "Invalid input! Please enter 'y' or 'n'." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    } else {
                        break;
                    }
    }
    
    
    
    int currencyType;
    while (true){   // looping for proper user input (integer between 1 and 4)
        cout << setw(100) << setfill('-') << "" << setfill(' ') << endl;
        cout << "What currency do you have? Enter the corresponding number: (1 - USD, 2 - EUR, 3 - GBP, 4 - JPY)" << endl;
        cin >> currencyType;
        
        if (cin.fail() || currencyType < 1 || currencyType > 4) {   // cin.fail() returns true if user input not an integer
                    cout << "Invalid input! Please enter a number between 1 and 4." << endl;
                    cin.clear();  // Clear cin error
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
                } else {
                    break;  // Valid input, exit loop
                }
    }
    
    double currencyValue;
    while (true) {
        cout << setw(100) << setfill('-') << "" << setfill(' ') << endl;
        cout << "Enter the numerical value of your currency:" << endl;
        cin >> currencyValue;
            
        if (cin.fail()) {   // ensuring user input is a double
            cout << "Invalid input! Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    
    int convertingType;
    while (true) {
        cout << setw(100) << setfill('-') << "" << setfill(' ') << endl;
        cout << "What currency would you like to convert to? Enter the corresponding number: (1 - USD, 2 - EUR, 3 - GBP, 4 - JPY)" << endl;
        cin >> convertingType;

        if (cin.fail() || convertingType < 1 || convertingType > 4) {       // ensuring user input is integer between 1 and 4
            cout << "Invalid input! Please enter a number between 1 and 4." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    
    cout << setw(100) << setfill('-') << "" << setfill(' ') << endl;
    
    string currencySymbol;
    switch (currencyType) {
        case 1:  // Starting USD
            if (convertingType == 1) {  // to USD
                currencySymbol = "$";
                break;
            } else if (convertingType == 2) {  // to EUR
                currencyValue *= modUSD_TO_EUR;
                currencySymbol = "€";   // symbol too large for char, needs to be in string var
            } else if (convertingType == 3) {  // to GBP
                currencyValue *= modUSD_TO_GBP;
                currencySymbol = "£";
            } else {  // to JPY
                currencyValue *= modUSD_TO_JPY;
                currencySymbol = "¥";
            }
            break;

        case 2:  // Starting EUR
            if (convertingType == 1) {  // to USD
                currencyValue *= modEUR_TO_USD;
                currencySymbol = "$";
            } else if (convertingType == 2) {  // to EUR
                currencySymbol = "€";
                break;
            } else if (convertingType == 3) {  // to GBP
                currencyValue *= (modUSD_TO_GBP / modUSD_TO_EUR);
                currencySymbol = "£";
            } else {  // to JPY
                currencyValue *= (modUSD_TO_JPY / modUSD_TO_EUR);
                currencySymbol = "¥";
            }
            break;

        case 3:  // Starting GBP
            if (convertingType == 1) {  // to USD
                currencyValue *= modGBP_TO_USD;
                currencySymbol = "$";
            } else if (convertingType == 2) {  // to EUR
                currencyValue *= (modUSD_TO_EUR / modUSD_TO_GBP);
                currencySymbol = "€";
            } else if (convertingType == 3) {  // to GBP
                currencySymbol = "£";
                break;
            } else {  // to JPY
                currencyValue *= (modUSD_TO_JPY / modUSD_TO_GBP);
                currencySymbol = "¥";
            }
            break;

        case 4:  // Starting JPY
            if (convertingType == 1) {  // to USD
                currencyValue *= modJPY_TO_USD;
                currencySymbol = "$";
            } else if (convertingType == 2) {  // to EUR
                currencyValue *= (modUSD_TO_EUR / modUSD_TO_JPY);
                currencySymbol = "€";
            } else if (convertingType == 3) {  // to GBP
                currencyValue *= (modUSD_TO_GBP / modUSD_TO_JPY);
                currencySymbol = "£";
            } else {  // to JPY
                currencySymbol = "¥";
                break;
            }
            break;
    }  // don't need default since inputs are looped to be correct
        
    
    cout << "Your converted currency is: " << currencySymbol << fixed << setprecision(2) << currencyValue << endl; // value to 2 decimals
    
    return 0;
}

