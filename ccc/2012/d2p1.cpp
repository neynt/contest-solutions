#include <iostream>
#include <queue>
#include <limits.h>
#include <algorithm>
using namespace std;

int main ()
{
    int N, Rs, Cs, Rf, Cf;
    int len[100000];
    int *dp[100000];
    queue<int> Qr, Qc, Qd;

    cin >> N;
    for (int i=0; i<N; i++)
    {
        cin >> len[i];
        dp[i] = new int[len[i]];
        for (int j=0; j<len[i]; j++)
        {
            dp[i][j] = INT_MAX;
        }
    }
    cin >> Rs >> Cs;
    cin >> Rf >> Cf;

    Qr.push(Rs-1);
    Qc.push(Cs-1);
    Qd.push(0);

    while (!Qd.empty())
    {
        int r, c, d;
        r = Qr.front(); Qr.pop();
        c = Qc.front(); Qc.pop();
        d = Qd.front(); Qd.pop();

        // Check
        if (d < dp[r][c])
        {
            dp[r][c] = d;
            if (r == Rf-1 and c == Cf-1)
            {
                break;
            }
        }
        else
        {
            continue;
        }

        // Up
        if (r > 0) {
            Qr.push(r-1); Qc.push(min(c, len[r-1]-1)); Qd.push(d+1);
        }

        // Down
        if (r < N-1) {
            Qr.push(r+1); Qc.push(min(c, len[r+1]-1)); Qd.push(d+1);
        }

        // Left
        if (c > 0) {
            Qr.push(r); Qc.push(c-1); Qd.push(d+1);
        }
        else if (r > 0) {
            Qr.push(r-1); Qc.push(len[r-1]-1); Qd.push(d+1);
        }

        // Right
        if (c < len[r]-1) {
            Qr.push(r); Qc.push(c+1); Qd.push(d+1);
        }
        else if (r < N-1) {
            Qr.push(r+1); Qc.push(0); Qd.push(d+1);
        }
    }

    cout << dp[Rf-1][Cf-1] << endl;
    return 0;
}
