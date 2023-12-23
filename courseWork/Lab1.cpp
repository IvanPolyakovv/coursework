#include <iostream>
using namespace std;
int main() {
    cout << "1.\n";
    cout << "size of int: " << sizeof(int) << '\n';
    cout << "size of long int: " << sizeof(long int) << '\n';
    cout << "size of float: " << sizeof(float) << '\n';
    cout << "size of double: " << sizeof(double) << '\n';
    cout << "size of long double: " << sizeof(long double) << '\n';
    cout << "size of char: " << sizeof(char) << '\n';
    cout << "size of bool: " << sizeof(bool) << '\n';

    cout << "2.\n";
    int number;
    cout << "Enter the integer number: ";
    cin >> number;
    unsigned int order = 32;
    unsigned int mask = 1 << (order - 1);
    for (int i = 1; i <= order; i++)
    {
        cout << (number & mask ? '1' : '0');
        number = number << 1;
        if (i % 8 == 0 || i % order - 1 == 0)
        {
            cout << ' ';
        }
    }
    cout << '\n';

    cout << "3.\n";
    union
    {
        int intNumber;
        float floatNumber;
    };
    cout << "Enter the float number: ";
    cin >> floatNumber;
    for (int i = 1; i <= order; i++)
    {
        cout << (intNumber & mask ? '1' : '0');
        intNumber = intNumber << 1;
        if (i % 8 == 0 || i % order - 1 == 0)
        {
            cout << ' ';
        }
    }
    cout << '\n\n';
    
    cout << "IDZ:\nEnter the integer number: ";
    cin >> number;
    if (number >= 0)
    {
        for (int i = 1; i <= order; i++)
        {
            if (i % 2 == 0)
            {
                cout << '0';
                number = number << 1;
                if (i % 8 == 0 || i % order - 1 == 0)
                {
                    cout << ' ';
                }
            }
            else
            {
                cout << (number & mask ? '1' : '0');
                number = number << 1;
                if (i % 8 == 0 || i % order - 1 == 0)
                {
                    cout << ' ';
                }
            }
        }
    }
    else
    {
        for (int i = 1; i <= order; i++)
        {
            if (i % 2 != 0)
            {
                cout << '1';
                number = number << 1;
                if (i % 8 == 0 || i % order - 1 == 0)
                {
                    cout << ' ';
                }
            }
            else
            {
                cout << (number & mask ? '1' : '0');
                number = number << 1;
                if (i % 8 == 0 || i % order - 1 == 0)
                {
                    cout << ' ';
                }
            }
        }
    }
    return 0;
}




