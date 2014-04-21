#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <limits.h>
using namespace std;

/* 2012 CCC Stage 2 Day 1 Problem 2: The Hungary Games
 * 
 * We use a modified Dijkstra's that keeps track of both the
 * shortest and second shortest path to each node. */

typedef pair<int, int> pack;

// Graph of Budapest
map<int, vector<pack> > G; 

// Determine which vertices to explore next (like Dijkstra's)
priority_queue<pack, vector<pack>, greater<pack> > PQ; 

int S[30000][2]; // Two shortest distances to S

int main ()
{
    // Number of nodes
    int N;

    // Number of edges
    int M;

    cin >> N >> M;

    // Clear S
    for (int i=0; i<N; i++)
    {
        S[i][0] = INT_MAX;
        S[i][1] = INT_MAX;
    }

    for (int i=0; i<M; i++)
    {
        int a, b, l;
        cin >> a >> b >> l;
        G[a-1].push_back(pack(b-1, l));
    }

    PQ.push(pack(0, 0));
    while (!PQ.empty())
    {
        pack cur = PQ.top(); PQ.pop();
        int depth = cur.first;
        int n = cur.second;

        // We've already determined the second shortest path
        // to the current node
        if (S[n][1] < INT_MAX) continue;

        //cout << "Visiting " << n << " at depth " << depth << endl;

        bool yolo = false;

        // Update two-shortest-distances array
        if (depth < S[n][0])
        {
            S[n][1] = S[n][0];
            S[n][0] = depth;
            yolo = true;
        }
        else if (depth != S[n][0] and depth <= S[n][1])
        {
            S[n][1] = depth;
            yolo = true;
        }

        // Branch out
        if (yolo)
        {
            for (int i=0; i<G[n].size(); i++)
            {
                pack nxt = G[n][i];
                int t = nxt.first;
                int dist = nxt.second;
                PQ.push(pack(depth+dist, t));
                //cout << "Pushing " << t << " at depth " << depth+dist << endl;
            }
        }
    }

    int ans = S[N-1][1];
    if (ans == INT_MAX) cout << -1 << endl;
    else cout << S[N-1][1] << endl;
    return 0;
}
