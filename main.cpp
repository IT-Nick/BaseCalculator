#include <iostream>
#include <cmath>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <cassert>
#include <exception>
using namespace std;

#include "converter.h"
#include "saver.h"
#include "calculations.h"
#include "tests.h"
#include "calculator.h"
//TODO:  Дописать тесты и обработать крайние случаи
/*
void reverse(char str[], int length) {
    int start = 0;
    int end = length -1;
    while (start < end) {
        swap(*(str+start), *(str+end));
        start++;
        end--;
    }
}
double Ostatoc(double a, double b) {
    int z = a / b;
    return a - z * b;
}
char* MyItoa(int num, char* str, int base) {
    int i = 0;
    bool isNegative = false;
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
    if (num < 0 && base == 10) {
        isNegative = true;
        num = -num;
    }
    while (num != 0) {
        int rem = Ostatoc(num, base);
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }
    if (isNegative)
        str[i++] = '-';
    str[i] = '\0';
    reverse(str, i);
    return str;
}
*/
enum class RequestConsole {
    CALCULATE,
    SETBASE,
    SAVE,
    SELECT,
    DETACHSAVEDVALUE,
    CONVERTBASE
};

void Interface(RequestConsole& request_t, Converter& c, Saver& s, const string& select, const string& saved, string& value) {
    cout << "Enter the command: CALCULATE - 0, SETBASE - 1, SAVE - 2, SELECT - 3, DETACHSAVEDVALUE - 4, CONVERTBASE - 5" << endl;
    int request_num;
    cin >> request_num;
    if(request_num >=0 && request_num < 6) {
        request_t = static_cast<RequestConsole>(request_num);
    } else {
        cerr <<  "Wrong! Enter the number from 0 to 5!" << endl;
        return;
    }
    switch (request_t) {
        case RequestConsole::CALCULATE: {
            cout << "What do you want to count?\ncommands: BASIC - 0, TRIGONOMETRIC - 1, BINARY - 2, NOD - 3, NOK - 4, FACTORIAl - 5,\n "
                    "POW - 6, LOG - 7, SQRT - 8, RAND - 9, TRIANGLE - 10, EQUATION - 11" << endl;
            int request_code;
            cin >> request_code;
            auto request = static_cast<RequestType>(request_code);
            Calculator(c, request, value, s);
            cout << "OK" << endl;
            break;
        }
        case RequestConsole::SETBASE: {
            cout << "What system do you want to input?\n example: 16 10 8 2 ..." << endl;
            int isystem;
            cin >> isystem;
            if(isystem < 2 || isystem > 36) throw runtime_error("Enter only: 2 <= base =< 36");
            cout << "What system do you want to output?\n example: 16 10 8 2 ..." << endl;
            int osystem;
            cin >> osystem;
            if(osystem < 2 || osystem > 36) throw runtime_error("Enter only: 2 <= base =< 36");
            c.SetO(osystem);
            c.SetI(isystem);
            cout << "OK" << endl;
            break;
        }
        case RequestConsole::SELECT: {
            cout << "Choose the storage: 0, 1, 2 or 3" << endl;
            int choice = 0;
            cin >> choice;
            if(choice <= 3) {
                cout << s.GetSave(choice) << endl;
                value = s.GetSave(choice);
            } else {
                throw runtime_error("You have 0, 1, 2, 3 storages");
            }
            cout << "OK" << endl;
            break;
        }
        case RequestConsole::SAVE: {
            cout << "You will save this: " << s.GetLastExpr() << endl;
            cout << "Please, select the storage: 0, 1, 2 or 3?" << endl;
            int choice = 0;
            cin >> choice;
            if(choice <= 3) {
                s.Insert(choice);
            } else {
                throw runtime_error("You have 0, 1, 2, 3 storages");
            }
            cout << "OK" << endl;
            break;
        }
        case RequestConsole::DETACHSAVEDVALUE: {
            cout << "You has detached your saved value" << endl;
            value = "";
            break;
        }
        case RequestConsole::CONVERTBASE: {
            cout << "From:" << endl;
            int from;
            cin >> from;
            if(from < 2 || from > 36) throw runtime_error("Invalid base! Enter only 2 >= base <= 36");
            cout << "To:" << endl;
            int to;
            cin >> to;
            if(to < 2 || to > 36) throw runtime_error("Invalid base! Enter only 2 >= base <= 36");
            string number;
            if(value.empty()) {
                cout << "Number:" << endl;
                cin >> number;
            } else {
                number = value;
            }
            //From
            char *endptr;
            const char *cstr = number.c_str();
            int fromResult = (int)strtol(cstr, &endptr, from);
            //To
            char buffer[33];
            string toResult = (string)itoa(fromResult, buffer, to);
            cout << toResult << endl;
            s.SetSave(toResult);
            break;
        }
    }
}

int main() {
    //TESTS
    TestAll();
    //INTERFACE
    RequestConsole request_t = RequestConsole::CALCULATE;
    Converter c;
    Saver s;
    string select;
    string saved;
    string value;
    cout << "How many commands do you want?" << endl;
    int count_of_calcs = 0;
    cin >> count_of_calcs;
    if(count_of_calcs <= 0) {
        cerr << "Enter a number > 0!" << endl;
        cin >> count_of_calcs;
    }
    while (count_of_calcs > 0) {
        try {
            Interface(request_t, c, s, select, saved, value);
            count_of_calcs--;
        } catch (exception& e) {
            cerr << e.what() << endl;
        }
    }
    return 0;
}