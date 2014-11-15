#include <iostream>
using namespace std;

int main ()
{
    int money_left = 100+500+1000+5000+10000+25000+50000+100000+500000+1000000;
    int num_cases;
    int cur_case;
    int offer;
    int expected;

    cin >> num_cases;
    for (int i=0; i<num_cases; i++)
    {
        cin >> cur_case;
        switch (cur_case)
        {
            case 1:  money_left -= 100; break;
            case 2:  money_left -= 500; break;
            case 3:  money_left -= 1000; break;
            case 4:  money_left -= 5000; break;
            case 5:  money_left -= 10000; break;
            case 6:  money_left -= 25000; break;
            case 7:  money_left -= 50000; break;
            case 8:  money_left -= 100000; break;
            case 9:  money_left -= 500000; break;
            case 10: money_left -= 1000000; break;
        }
    }
    cin >> offer;

    expected = money_left / (10-num_cases);
    if (offer > expected)
        cout << "deal" << endl;
    else
        cout << "no deal" << endl;
    return 0;
}
