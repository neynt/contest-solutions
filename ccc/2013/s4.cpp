#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int N, M;
vector<int> people[1000001];

bool taller(int a, int b)
{
    set<int> visited;
    queue<int> Q;

    Q.push(a);
    while (!Q.empty()) {
        int c = Q.back(); Q.pop();
        if (c == b) {
            return true;
        }
        if (visited.count(c)) {
            continue;
        }
        visited.insert(c);
        for (int i=0; i<people[c].size(); i++) {
            Q.push(people[c][i]);
        }
    }
    return false;
}

int main ()
{
    int a, b;
    int p, q;
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        cin >> a >> b;
        people[a].push_back(b);
    }
    cin >> p >> q;
    
    if (taller(p, q)) {
        cout << "yes" << endl;
    }
    else if (taller(q, p)) {
        cout << "no" << endl;
    }
    else {
        cout << "unknown" << endl;
    }
    return 0;
}
