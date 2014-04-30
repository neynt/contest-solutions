#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int V, T, R1, R2, W;
map<char, vector<string> > rules;
map<char, map<string, bool> > writable;
char start;

bool can_write(string word, char var)
{
    // Check directly for a memoized result
    if (writable[var].count(word))
        return writable[var][word];
    // Try every way of splitting the word in two
    for (int i=1; i<word.length(); i++)
    {
        string w1, w2;
        w1 = word.substr(0, i);
        w2 = word.substr(i, -1);

        // ... and every way of assigning each half to two variables
        for (int j=0; j<rules[var].size(); j++)
        {
            string new_vars = rules[var][j];
            if (can_write(w1, new_vars[0]) and can_write(w2, new_vars[1]))
            {
                // SUCCESS!!!
                writable[var][word] = true;
                return true;
            }
        }
    }
    writable[var][word] = false;
    return false;
}

int main ()
{
    cin >> V >> T;
    for (int i=0; i<V; i++)
    {
        string v;
        cin >> v;
        if (i==0)
            start = v[0];
    }
    for (int i=0; i<T; i++)
    {
        string t;
        cin >> t;
    }
    cin >> R1;
    for (int i=0; i<R1; i++)
    {
        string a, b;
        cin >> a >> b;
        writable[a[0]][b] = true;
    }
    cin >> R2;
    for (int i=0; i<R2; i++)
    {
        string a, b, c;
        cin >> a >> b >> c;
        rules[a[0]].push_back(b+c);
    }
    cin >> W;
    for (int i=0; i<W; i++)
    {
        string word;
        cin >> word;
        if (can_write(word, start))
        {
            cout << "1" << endl;
        }
        else
        {
            cout << "0" << endl;
        }
    }
}
