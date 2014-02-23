#!/usr/bin/env python3

STREET_LEN = 1000000

# Get input
h = int(input())
houses = [int(input()) for i in range(h)]
k = int(input())

houses.sort()

def distance(h1, h2):
    h1 %= h
    h2 %= h
    return min((houses[h1]-houses[h2]) % STREET_LEN,
               (houses[h2]-houses[h1]) % STREET_LEN)

# Keep track of the best hose length by far
best = 500000
# Using each of the houses one by one as a "starting house"...
for starting_house in range(len(houses)):
    # Do a binary search on the length of the hose
    lo = 0
    hi = 500000
    while hi > lo:
        mid = (lo + hi) // 2
        possible = True

        # i is the current starting house
        i = starting_house
        count = 1

        # cur is the index of our current house
        for cur in range(starting_house, starting_house + h):
            if distance(cur, i) > 2*mid:
                # cur_house cannot be reached by a hose half-way between it and cur_hose_house;
                # start a new hose at cur_house
                count += 1
                i = cur
                if count > k:
                    possible = False;
                    break;
        if possible:
            hi = mid
        else:
            lo = mid + 1

    best = min(lo, best)
    
# Finally, just output the answer!
print(best)
