/*
* Tristan Lea
* Cs212 Irvene
* 4/21/22
* Description: Excepetion handling practice program
*/

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
using namespace std;

int main() {
    stringstream ss;
    string userInput;
    int value;

    // Failed conversion throws ios_base::failure
    ss.exceptions(ios::failbit);

    cout << "Enter a divisor of 60\n"; // simple user prompt
    getline(cin, userInput);

    while (userInput != "end") {
        try {
            ss.str("");
            ss.clear();
            ss << userInput;
            ss >> value;

            if (isdigit(value)) {
                // Division by zero throws runtime_error
                if (value == 0) {
                    throw runtime_error("Cannot divide by Zero!");

                }
                // checks if its within the range of an int
                if (-2147483647 < value < 2147483647) {
                    throw runtime_error("Too may digits.");

                }
            }

            cout << 60 / value << endl;
        }
        catch (ios_base::failure& excpt) {
            cout << "Not an acceptable input." << endl;
        }
        catch (runtime_error& excpt) {
            cout << excpt.what() << endl;
        }
        getline(cin, userInput);
        ss.clear();
    }
    cout << "OK" << endl;

    return 0;
}