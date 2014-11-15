#include <iostream>
using namespace std;

// CCC 2014 J3: Double Dice
int main ()
{
    int n;
    int a, d;
    int a_score, d_score;
    a_score = d_score = 100;

    cin >> n;
    // Simulates each turn of the game
    for (int i=0; i<n; i++) {
        cin >> a >> d;
        if (a > d) {
            d_score -= a;
        }
        else if (d > a) {
            a_score -= d;
        }
    }

    cout << a_score << endl;
    cout << d_score << endl;
    return 0;
}
