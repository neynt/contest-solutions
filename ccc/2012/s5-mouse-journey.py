#!/usr/bin/env python2
from collections import deque

R, C = map(int, raw_input().split())

dp = [[0 for _ in range(C)] for _ in range(R)]
cage = [[False for _ in range(C)] for _ in range(R)]

K = int(raw_input())
for _ in range(K):
    r,c = map(int, raw_input().split())
    cage[r-1][c-1] = True

for r in range(R):
    for c in range(C):
        if cage[r][c]:
            dp[r][c] = 0
        elif r == 0 and c == 0:
            dp[r][c] = 1
        elif r == 0:
            dp[r][c] = dp[r][c-1]
        elif c == 0:
            dp[r][c] = dp[r-1][c]
        else:
            dp[r][c] = dp[r-1][c] + dp[r][c-1]

print dp[R-1][C-1]
