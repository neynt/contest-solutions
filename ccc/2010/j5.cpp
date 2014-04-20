#include <iostream>
#include <queue>
using namespace std;

bool visited[8][8];

int main ()
{
    int x1, y1, x2, y2;

    // receive input
    cin >> x1 >> y1;
    cin >> x2 >> y2;

    // due to 0-based arrays, we use 0..7
    // for the coordinates instead of 1..8
    // so we subtract 1 to convert.
    x1 -= 1; y1 -= 1;
    x2 -= 1; y2 -= 1;

    // use queues to do a breadth-first search
    queue<int> Qx;
    queue<int> Qy;
    // d: depth -- the number of turns we need to reach the corresponding
    // location.
    queue<int> Qd;

    Qx.push(x1);
    Qy.push(y1);
    Qd.push(0);

    while (!Qx.empty())
    {
        int x, y, d;

        // pop a location and depth from the queue
        x = Qx.front(); Qx.pop();
        y = Qy.front(); Qy.pop();
        d = Qd.front(); Qd.pop();

        cout << x << " " << y << " " << d << endl;

        // check for invalid position
        if (x < 0 or x >= 8 or y < 0 or y >= 8) {
            continue;
        }
        // check if we already visited this location
        if (visited[x][y]) {
            continue;
        }
        // check if we reached the goal
        if (x == x2 and y == y2) {
            // success! print the answer and break immediately
            cout << d << endl;
            break;
        }

        // mark our current position as visited
        visited[x][y] = true;

        // each line represents a possible move from
        // our current position.
        //
        // we don't have to worry
        // about invalid positions since the code at the
        // beginning of this loop handles those.
        Qx.push(x-1); Qy.push(y-2); Qd.push(d+1);
        Qx.push(x-1); Qy.push(y+2); Qd.push(d+1);
        Qx.push(x+1); Qy.push(y-2); Qd.push(d+1);
        Qx.push(x+1); Qy.push(y+2); Qd.push(d+1);
        Qx.push(x-2); Qy.push(y-1); Qd.push(d+1);
        Qx.push(x-2); Qy.push(y+1); Qd.push(d+1);
        Qx.push(x+2); Qy.push(y-1); Qd.push(d+1);
        Qx.push(x+2); Qy.push(y+1); Qd.push(d+1);
    }
    return 0;
}
