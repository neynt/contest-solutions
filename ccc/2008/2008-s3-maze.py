#!/usr/bin/env python3

# This solution is a breadth-first search using a Python deque as a queue.

from collections import deque

t = int(input())

for _ in range(t):
    R, C = int(input()), int(input())
    grid = [input() for _ in range(R)]
    visited = set()
    answer = -1

    # Q contains (r, c, d) triples
    # r: row, c: column, d: depth i.e. number of moves to get to (r,c)
    Q = deque()
    Q.append((0, 0, 1))

    while Q:
        r, c, d = Q.popleft()

        # out of bounds
        if r < 0 or r >= R or c < 0 or c >= C: continue
        # impassable terrain
        if grid[r][c] == '*': continue
        # already visited
        if (r,c) in visited: continue

        # reached goal
        if (r,c) == (R-1,C-1):
            answer = d
            break

        # otherwise, keep on BFSing
        if grid[r][c] in '-+':
            Q.append((r, c+1, d+1))
            Q.append((r, c-1, d+1))
        if grid[r][c] in '|+':
            Q.append((r+1, c, d+1))
            Q.append((r-1, c, d+1))
        
        # mark as visited
        visited.add((r,c))

    print(answer)
