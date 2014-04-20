#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* High-level overview of solution
 *
 * Note that we do not need to figure out exactly where the hydrants are.
 * Instead, we assume that each hose starts at a house and can go a distance
 * twice its length in one direction.
 *
 * Then, we can place the hydrant in the middle of the hose's range.
 *
 * 1. Get all input. Store the house numbers in a vector<int>
 * 2. Sort the houses
 * 3. Going through each house as a "starting house"...
 *    - determine the length of hose required to connect all the houses...
 *    - using binary search on the length of the hose (!!!)
 * 4. Take the smallest of those to get the answer
 *
 * The crux of this solution is the binary search.
 *
 * In order to check whether a certain length of hose works or not,
 * we start a length of hose at the "starting house" and greedily cover
 * as many houses as possible with that one hose.
 *
 * Then we start the next hose at the next house, and so on.
 *
 * If we end up using too many hoses, we know the current length doesn't work.
 * Otherwise, it does.
 *
 * tl;dr binary search on length of hose
 *
 * */

int num_houses;
int num_hydrants;
int min_length;
int max_length;
int cur_length;
vector<int> houses;

int dist_between(int house1, int house2)
{
    return min((houses[house1%num_houses] - houses[house2%num_houses] + 1000000) % 1000000,
               (houses[house2%num_houses] - houses[house1%num_houses] + 1000000) % 1000000);
}

int main ()
{
    // Get input
    cin >> num_houses;
    for (int i=0; i<num_houses; i++)
    {
        int new_house;
        cin >> new_house;
        houses.push_back(new_house);
    }
    cin >> num_hydrants;

    // Sort the houses
    sort(houses.begin(), houses.end());

    // Keep track of the lowest length we find
    int ultimate_answer = 1000000;

    // Try starting from each house...
    for (int start_house=0; start_house < num_houses; start_house++)
    {
        // Binary search on the length of the hose
        min_length = 0;
        max_length = 1000000;
        //cout << "Starting at house " << houses[start_house] << endl;
        while (max_length - min_length > 0) {
            cur_length = (max_length + min_length) / 2;

            // Test if it's possible to cover all houses with current hose length
            bool possible = true;
            int num_hoses = 1;
            int cur_hose_house = start_house;
            for (int cur_house = start_house; cur_house < start_house + num_houses; cur_house++)
            {
                // If we can't reach the current house from the last house we started a hose at,
                // then we start a new hose at the current house.
                if (dist_between(cur_hose_house, cur_house) > cur_length*2) {
                    num_hoses += 1;
                    cur_hose_house = cur_house;

                    // If we've exceeded the number of hoses, the cover isn't possible.
                    if (num_hoses > num_hydrants) { 
                        possible = false;
                        break;
                    }
                }
            }

            // Adjust binary search accordingly
            if (possible)
                max_length = cur_length;
            else
                // +1 because cur_length is not itself possible
                min_length = cur_length+1;
        }
        //cout << "Optimal is " << min_length << endl;

        // If the length we got starting from the current start_house
        // is the best we've ever seen, then keep it.
        if (min_length < ultimate_answer)
            ultimate_answer = min_length;
    }

    // Finally, output the answer.
    cout << ultimate_answer << endl;

    return 0;
}
