#include <iostream>
using namespace std;

// CCC 2014 J1: Triangle Times
int main ()
{
    int a, b, c;
    cin >> a >> b >> c;

    if (a+b+c != 180) {
        cout << "Error" << endl;
    }
    else if (a == b and a == c) {
        cout << "Equilateral" << endl;
    }
    else if (a == b or a == c or a == c) {
        cout << "Isosceles" << endl;
    }
    else {
        cout << "Scalene" << endl;
    }
    return 0;
}
