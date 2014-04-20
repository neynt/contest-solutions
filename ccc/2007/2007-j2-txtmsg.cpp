#include <iostream>
#include <map>
using namespace std;

int main ()
{
    /* Declare a map from string to string.
     *
     * A map (a.k.a. associative array, dictionary) is a data structure
     * where you can "look up" any object given another object. The lookup is
     * usually very fast -- about log(n) time. */
    map<string, string> translation;

    string input;

    /* Populate our map with the given translations. */
    translation["CU"] = "see you";
    translation[":-)"] = "I'm happy";
    translation[":-("] = "I'm unhappy";
    translation[";-)"] = "wink";
    translation[":-P"] = "stick out my tongue";
    translation["(~.~)"] = "sleepy";
    translation["TA"] = "totally awesome";
    translation["CCC"] = "Canadian Computing Competition";
    translation["CUZ"] = "because";
    translation["TY"] = "thank-you";
    translation["YW"] = "you're welcome";
    translation["TTYL"] = "talk to you later";

    /* Continue to get input and either translate it,
     * or echo it (if there is no translation) ... as long as
     * the input is not "TTYL". */
    do {
        cout << "Enter phrase> ";
        cin >> input;

        if (translation.count(input))
            cout << translation[input] << endl;
        else 
            cout << input << endl;
    } while (input != "TTYL");

    // That is all.
    return 0;
}
