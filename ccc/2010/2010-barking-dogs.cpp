#include <iostream>
#include <vector>
#include <queue>
#include <map>

int main ()
{
    int num_dogs;
    int num_hearers;
    int total_time;
    int wait[1000];
    int barktime[1000];
    map<int, vector<int> > hearers;

    cin >> num_dogs;

    for (int i=0; i<num_dogs; i++) {
        cin >> wait[i];
        barktime[i] = 0;
    }

    cin >> num_hearers;

    for (int i=0; i<num_hearers; i++) {
        int dogi, dogj;
        cin >> dogi >> dogj;
        hearers[dogi].push_back(dogj);
    }

    cin >> total_time;
}
