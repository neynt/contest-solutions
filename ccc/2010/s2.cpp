#include <iostream>
#include <string>
#include <map>
using namespace std;

int main ()
{
    int k;
    string seq, chr, line;

    // Get input
    cin >> k;
    map<string, string> code;
    for (int i=0; i<k; i++)
    {
        cin >> chr >> seq;
        code[seq] = chr;
    }
    cin >> line;

    // Greedily match the sequences
    seq.clear();
    for (int i=0; i<line.length(); i++)
    {
        seq += line[i];
        if (code.count(seq)) {
            cout << code[seq];
            seq.clear();
        }
    }
    cout << endl;
    return 0;
}
