#include <iostream>
#include <vector>
using namespace std;

int min_travel, max_travel;
vector<int> motels;

/* Uses recursion to compute the number of ways in which
 * you can reach the final hotel from a given location. */
int num_ways(int start)
{
    // If we have already reached the goal, count it.
    if (start == 7000) return 1;

    // Otherwise, try to reach all the possible motels from the
    // current motel.
    int ways = 0;
    int min_dist = start + min_travel;
    int max_dist = start + max_travel;
    for (int i=0; i<motels.size(); i++)
    {
        if (motels[i] >= min_dist and motels[i] <= max_dist) {
            ways += num_ways(motels[i]);
        }
    }

    return ways;
}

int main ()
{
    int num_additional_motels;
    int new_motel;

    // Populate motel vector with given motels
    motels.push_back(990);
    motels.push_back(1010);
    motels.push_back(1970);
    motels.push_back(2030);
    motels.push_back(2940);
    motels.push_back(3060);
    motels.push_back(3930);
    motels.push_back(4060);
    motels.push_back(4970);
    motels.push_back(5030);
    motels.push_back(5990);
    motels.push_back(6010);
    motels.push_back(7000);

    // Get input
    cin >> min_travel;
    cin >> max_travel;
    cin >> num_additional_motels;
    for (int i=0; i<num_additional_motels; i++) {
        cin >> new_motel;
        motels.push_back(new_motel);
    }

    // Give answer
    cout << num_ways(0) << endl;
    return 0;
}
