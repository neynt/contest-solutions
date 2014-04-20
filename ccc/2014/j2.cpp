#include <iostream>
using namespace std;

// CCC 2014 J2: Vote Count
int main ()
{
    int n;
    char votes[80];
    cin >> n;
    cin >> votes;

    int a, b;

    // Counts the votes
    for (int i=0; i<n; i++) {
        if (votes[i] == 'A') {
            a += 1;
        }
        else {
            b += 1;
        }
    }

    if (a > b) {
        cout << "A" << endl;
    }
    else if (b > a) {
        cout << "B" << endl;
    }
    else {
        cout << "Tie" << endl;
    }
    return 0;
}
