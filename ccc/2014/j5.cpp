#include <iostream>
#include <string>
#include <map>
using namespace std;

int main ()
{
    int N;
    map<string, string> G;
    string A[1000];
    string B[1000];
    bool consistent = true;

    // Getting input
    cin >> N;

    for (int i=0; i<N; i++) {
        cin >> A[i];
    }
    for (int i=0; i<N; i++) {
        cin >> B[i];
    }

    for (int i=0; i<N; i++) {
        G[A[i]] = B[i];
    }

    // Check for consistency
    for (int i=0; i<N; i++) {
        if (A[i] == G[G[A[i]]] and A[i] != G[A[i]]) {
            continue;
        }
        else {
            consistent = false;
            break;
        }
    }

    // Output
    if (consistent) {
        cout << "good" << endl;
    }
    else {
        cout << "bad" << endl;
    }
    return 0;
}
