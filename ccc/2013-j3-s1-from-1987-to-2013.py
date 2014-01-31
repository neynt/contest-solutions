#!/usr/bin/env python3
Y = int(input()) + 1
while len(set(str(Y))) != len(str(Y)):
    Y += 1
print(Y)
