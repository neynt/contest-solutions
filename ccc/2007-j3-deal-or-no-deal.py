#!/usr/bin/env python3
briefcases = [100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 500000, 1000000]

money_left = sum(briefcases)
num_briefcases = int(input())
for i in range(num_briefcases):
    money_left -= briefcases[int(input())-1]
offer = int(input())

expectation = money_left / (10-num_briefcases)

if offer > expectation:
    print("deal")
else:
    print("no deal")
