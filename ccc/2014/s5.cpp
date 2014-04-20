#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main ()
{
    int N;
    vector<int> xs;
    vector<int> ys;
    vector<int> best;
    vector<int> pbest;
    vector<int> pdist;
    vector<pair<int, pair<int, int> > > pts;

    xs.push_back(0);
    ys.push_back(0);
    best.push_back(0);
    pbest.push_back(0);
    pdist.push_back(0);

    cin >> N;
    for (int i=0; i<N; i++)
    {
        int a, b;
        cin >> a >> b;
        xs.push_back(a);
        ys.push_back(b);
        best.push_back(0);
        pbest.push_back(0);
        pdist.push_back(0);
    }
    
    for (int i=0; i<N+1; i++)
    {
        for (int j=0; j<N+1; j++)
        {
            if (i >= j) continue;
            int dx = xs[i] - xs[j];
            int dy = ys[i] - ys[j];
            pair<int, pair<int, int> > meister;
            meister.first = dx*dx + dy*dy;
            meister.second.first = i;
            meister.second.second = j;
            pts.push_back(meister);
        }
    }

    sort(pts.begin(), pts.end());

    for (int i=0; i<pts.size(); i++)
    {
        int dist, a, b;
        pair<int, pair<int, int> > n;
        n = pts[i];
        dist = n.first;
        a = n.second.first;
        b = n.second.second;

        if (dist > pdist[a])
        {
            pdist[a] = dist;
            pbest[a] = best[a];
        }
        if (dist > pdist[b])
        {
            pdist[b] = dist;
            pbest[b] = best[b];
        }
        if (a == 0)
        {
            best[a] = max(best[a], pbest[b]);
        }
        else
        {
            best[a] = max(best[a], pbest[b] + 1);
            best[b] = max(best[b], pbest[a] + 1);
        }
    }

    cout << best[0] + 1 << endl;
    return 0;
}
