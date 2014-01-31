#include <iostream>
using namespace std;

int main ()
{
    int n;
    int temperature[30];
    int change[30];

    for(;;) {
        cin >> n;

        if (n==0) break;
        else if (n==1)
        {
            cout << "0" << endl;
        }

        // Read in temperature values
        for (int i=0; i<n; i++)
        {
            cin >> temperature[i];
        }

        // Calculate changes in temperature (first differences)
        for (int i=0; i<n-1; i++)
        {
            change[i] = temperature[i+1] - temperature[i];
        }

        // Test each possible cycle length (from 1 to n-1)
        for (int cycle_length=1; cycle_length <= n-1; cycle_length++)
        {
            // assume cycle holds...
            bool cycle_holds = true;
            for (int i=cycle_length; i < n-1; i++)
            {
                // ... until we prove that it doesn't
                if (change[i] != change[i-cycle_length])
                {
                    cycle_holds = false;
                    break;
                }
            }

            if (cycle_holds)
            {
                cout << cycle_length << endl;
                break;
            }
        }
    }
}
