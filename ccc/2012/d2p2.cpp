#include <iostream>
#include <set>
#include <math.h>
using namespace std;

/* CCC 2012 Stage 2 Day 2 Problem 2: Sample Size
 * 
 * Notice that 100 is guaranteed to work.
 * We simply try all possible sample sizes from 1 to 100. */

int main ()
{
    int M;
    set<int> percentages;

    cin >> M;
    for (int i=0; i<M; i++)
    {
        int x;
        cin >> x;
        percentages.insert(x);
    }

    // N=100 is guaranteed to work.
    for (int N=1; N<=100; N++)
    {
        set<int> p; // permissible percentages.
        for (int i=0; i<=N; i++)
        {
            p.insert(round((double)i*100.0/N));
        }

        bool works = true;
        for (set<int>::iterator it = percentages.begin(); it != percentages.end(); it++)
        {
            if (!p.count(*it))
            {
                works = false;
                break;
            }
        }

        if (works)
        {
            cout << N << endl;
            break;
        }
    }
    return 0;
}
