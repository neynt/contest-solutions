#!/usr/bin/env python3

# Counts the number of ways to reach the final hotel from
# a certain starting hotel using recursion.
def count_ways(start):
    # We are already at the ending hotel!
    if start == 7000:
        return 1

    # We are not already at the ending hotel.
    # Travel to all hotels possible and add up.
    way_counter = 0
    min_dist = start + min_travel
    max_dist = start + max_travel
    for m in motels:
        if min_dist <= m <= max_dist:
            way_counter += count_ways(m)
    return way_counter

# Initial motels
motels = [990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000]

# Get input
min_travel = int(input())
max_travel = int(input())
for i in range(int(input())):
    motels.append(int(input()))

# Give answer
print(count_ways(0))
