#include <iostream>
#include <stack>
using namespace std;

int main ()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        int want = 1;
        stack<int> top;
        stack<int> side;
        bool possible = true;
        cin >> N;
        for (int i=0; i<N; i++) {
            int c;
            cin >> c;
            top.push(c);
        }
        while (!top.empty()) {
            int c = top.top(); top.pop();
            while (!side.empty() and side.top() == want) {
                side.pop();
                want += 1;
            }
            if (c == want) {
                want += 1;
            }
            else {
                side.push(c);
            }
        }
        while (!side.empty() and side.top() == want) {
            side.pop();
            want += 1;
        }
        if (side.empty()) cout << "Y" << endl;
        else cout << "N" << endl;
    }
}
