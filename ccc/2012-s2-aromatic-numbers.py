#!/usr/bin/env python3
R = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}

value = 0
number = input()
last = 0
for a,r in reversed(list(zip(number[::2], number[1::2]))):
    v = int(a) * R[r]
    if R[r] >= last:
        value += v
    else:
        value -= v
    last = R[r]

print(value)
