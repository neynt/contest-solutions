from collections import deque
from copy import deepcopy

while True:
    n = input()
    if n == 0: break

    coins = [[x] for x in map(int, raw_input().split())]
    goal = sorted(coins)
    visited = set()
    answer = -1
    
    Q = deque()
    Q.append((coins, 0))
    while Q:
        c,d = Q.popleft()
        if c == goal:
            answer = d
            break
        if str(c) in visited:
            continue
        visited.add(str(c))

        #print c, d

        # Create new moves
        for i in range(n):
            if c[i]:
                if i > 0:
                    new = deepcopy(c)
                    if (not new[i-1]) or new[i-1][-1] > new[i][-1]:
                        new[i-1].append(new[i].pop())
                        Q.append((new, d+1))
                if i < n-1:
                    new = deepcopy(c)
                    if (not new[i+1]) or new[i+1][-1] > new[i][-1]:
                        new[i+1].append(new[i].pop())
                        Q.append((new, d+1))
    if answer >= 0:
        print answer
    else:
        print "IMPOSSIBLE"
