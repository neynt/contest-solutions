#!/usr/bin/env python3

# Get input
num_houses = int(input())
houses = [int(input()) for i in range(num_houses)]
num_hydrants = int(input())

# Sort the houses
houses.sort()

# Takes the indices of two houses
# and returns the distance between them
def distance(h1, h2):
    h1 %= num_houses
    h2 %= num_houses
    return min((houses[h1]-houses[h2]) % 1000000,
               (houses[h2]-houses[h1]) % 1000000)

# Keep track of the best hose length by far
ultimate_answer = 500000
# Using each of the houses one by one as a "starting house"...
for starting_house in range(len(houses)):
    # Do a binary search on the length of the hose
    min_length = 0
    max_length = 500000
    while max_length - min_length > 0:
        cur_length = (min_length + max_length) // 2
        possible = True
        cur_hose_house = starting_house
        num_hoses = 1
        for cur_house in range(starting_house, starting_house + num_houses):
            if distance(cur_house, cur_hose_house) > 2*cur_length:
                # cur_house cannot be reached by a hose half-way between it and cur_hose_house;
                # start a new hose at cur_house
                num_hoses += 1
                cur_hose_house = cur_house
                if num_hoses > num_hydrants:
                    possible = False;
                    break;
        if possible:
            max_length = cur_length
        else:
            min_length = cur_length + 1

    # Update the answer if we get a better one starting from the current starting house
    ultimate_answer = min(min_length, ultimate_answer)
    
# Finally, just output the answer!
print(ultimate_answer)
