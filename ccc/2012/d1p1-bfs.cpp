#include <iostream>
#include <set>
#include <queue>
#include <vector>
using namespace std;

vector<int> digits;
set<pair<int, int> > reached;
set<int> possibru;
queue<int> Qn;
queue<int> Qd;

int main ()
{
    int W; // Number of operations to use. 0 <= W <= 6
    int D; // Number of working digit keys.
    int V; // Number of target values.
    cin >> W;
    cin >> D;
    for (int i=0; i<D; i++)
    {
        int d;
        cin >> d;
        digits.push_back(d);
    }
    cin >> V;

    for (int i=0; i<D; i++)
    {
        Qn.push(digits[i]);
        Qd.push(0);
    }


    while (!Qd.empty())
    {
        int n = Qn.front(); Qn.pop();
        int d = Qd.front(); Qd.pop();

        // More ops than allowed
        if (d > W) continue;
        // Already visited
        if (reached.count(pair<int, int>(n, d))) continue;
        reached.insert(pair<int, int>(n, d));

        //if (d < 4) {
        //    cout << "Works " << d << ": " << n << endl;
        //}

        // Insert possible numbers to reach
        if (d == W)
        {
            possibru.insert(n);
        }
        
        // Addition of each digit
        for (int i=0; i<D; i++)
        {
            Qn.push(n + digits[i]);
            Qd.push(d+1);
        }
        // Multiplication by each digit
        for (int i=0; i<D; i++)
        {
            Qn.push(n * digits[i]);
            Qd.push(d+1);
        }
    }

    for (int i=0; i<V; i++)
    {
        int v;
        cin >> v;
        if (possibru.count(v))
            cout << "Y" << endl;
        else
            cout << "N" << endl;
    }
    return 0;
}
