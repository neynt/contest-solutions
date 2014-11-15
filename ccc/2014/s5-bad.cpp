#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int N;
int x[2000], y[2000];
map<pair<int, int>, int> mem[2000];

// A straightforward DFS.
int max_candies (int cx, int cy, int last_dist, int count) {
    int best_count = count;
    for (int i=0; i<N; i++) {
        int dx = cx-x[i];
        int dy = cy-y[i];
        int new_dist = (dx*dx + dy*dy);
        if (new_dist != 0 and new_dist < last_dist) {
            best_count = max(best_count, max_candies(x[i], y[i], new_dist, count+1));
        }
    }
    return best_count;
}

int main ()
{
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> x[i] >> y[i];
    }
    cout << max_candies(0, 0, INT_MAX, 0)-1 << endl;
}
