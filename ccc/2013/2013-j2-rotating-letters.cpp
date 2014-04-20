#include <iostream>
#include <set>
#include <string>
using namespace std;

int main ()
{
    const char allowed_chars[] = "IOSHZXN";
    set<char> allowed(allowed_chars, allowed_chars+7);

    string word;
    cin >> word;
    bool possible = true;
    for (int i=0; i<word.length(); i++)
    {
        char c = word[i];
        if (allowed.count(c) == 0)
        {
            possible = false;
        }
    }
    if (possible)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
