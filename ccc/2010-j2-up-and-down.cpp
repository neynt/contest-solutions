#include <iostream>
using namespace std;

int main ()
{
    int a, b, c, d, s;
    cin >> a >> b >> c >> d >> s;

    int nikki, byron;
    
    for (int i=0; i<s; i++) {
        // Does Nikki go forward or back?
        // For i%(a+b) from 0 to a-1, Nikki goes forward
        // For i%(a+b) from a to a+b-1, Nikki goes backward
        // For i%(a+b) from 0 to a-1, Nikki goes forward
        // For i%(a+b) from a to a+b-1, Nikki goes backward
        // etc. etc.
        if (i%(a+b) < a) {
            nikki += 1; // nikki = nikki + 1;
        }
        else {
            nikki -= 1;
        }
        if (i%(c+d) < c) {
            byron += 1;
        }
        else {
            byron -= 1;
        }
    }
    if (byron > nikki) {
        cout << "Byron" << endl;
    }
    else if (nikki > byron) {
        cout << "Nikky" << endl;
    }
    else {
        cout << "Tied" << endl;
    }
    return 0;
}
