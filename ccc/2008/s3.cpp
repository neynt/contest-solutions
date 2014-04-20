#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

typedef pair<int, int> coord;

int main ()
{
    int num_cases;
    cin >> num_cases;
    for (int i=0; i<num_cases; i++)
    {
        int R, C;
        cin >> R;
        cin >> C;
        vector<string> grid;
        for (int j=0; j<R; j++) {
            string new_row;
            cin >> new_row;
            grid.push_back(new_row);
        }

        int answer = -1;
        queue<int> Qr, Qc, Qd;
        set<coord> visited;
        Qr.push(0); Qc.push(0); Qd.push(1);
        while (!Qd.empty())
        {
            int r, c, d;
            r = Qr.front(); Qr.pop();
            c = Qc.front(); Qc.pop();
            d = Qd.front(); Qd.pop();
            if (r<0 or c<0 or r>=R or c>=C) continue;
            if (grid[r][c] == '*') continue;
            if (visited.count(coord(r,c))) continue;

            if (r==R-1 and c==C-1) {
                answer = d;
                break;
            }

            if (grid[r][c] == '+' or grid[r][c] == '-') {
                Qr.push(r); Qc.push(c-1); Qd.push(d+1);
                Qr.push(r); Qc.push(c+1); Qd.push(d+1);
            }
            if (grid[r][c] == '+' or grid[r][c] == '|') {
                Qr.push(r-1); Qc.push(c); Qd.push(d+1);
                Qr.push(r+1); Qc.push(c); Qd.push(d+1);
            }

            visited.insert(coord(r,c));
        }

        cout << answer << endl;
    }
}
