#!/usr/bin/env python3
while True:
    # Read input.
    nums = list(map(int, input().split()))
    n = nums[0]
    temperatures = nums[1:]

    # Break out if the first number is 0
    if n == 0: break

    # Calculate changes in temperature
    changes = [b-a for a,b in zip(temperatures[:-1], temperatures[1:])]
    # this also works:
    #changes = [temperatures[i+1] - temperatures[i] for i in range(len(temperatures)-1)]

    # Test each possible cycle length
    for cycle_length in range(1, n):
        # As soon as a proper one is found...
        if all(changes[i] == changes[i-cycle_length] for i in range(cycle_length, len(changes))):
            # print it and break out
            print(cycle_length)
            break
