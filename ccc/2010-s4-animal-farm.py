#!/usr/bin/env python3

# a solution in four parts.
# 1. read in pens one by one
# 2. construct a graph from the pens
# 3. prim's on graph without outside
# 4. prim's on graph considering outside as one huge pen

from collections import defaultdict
from queue import PriorityQueue

num_pens = int(input())

fence_cost = {}
fence_pens = {}

for cur_pen in range(num_pens):
    vals = list(map(int, input().split()))
    p = vals[0]
    posts = vals[1:p+1]
    costs = vals[p+1:]
    for i in range(p):
        edge = tuple(sorted([posts[i], posts[(i+1)%p]]))
        cost = costs[i]
        if edge in fence_pens:
            fence_pens[edge].append(cur_pen)
        else:
            fence_pens[edge] = [(cur_pen)]
        fence_cost[edge] = cost

# use 1001 as the "outside" pen
G = {}

#print(fence_pens)
#print(fence_cost)

# build the weighted graph
for edge in fence_pens:
    pens = fence_pens[edge]
    if len(pens) == 1:
        pen1 = pens[0]
        pen2 = 1001
    else:
        pen1 = pens[0]
        pen2 = pens[1]

    cost = fence_cost[edge]
    if pen1 not in G:
        G[pen1] = []
    if pen2 not in G:
        G[pen2] = []
    G[pen1].append((cost, pen2))
    G[pen2].append((cost, pen1))

#print(set(G.keys()))
#print(G)

# Prim's (taking the outside into account)
next_pens = PriorityQueue()
remaining_pens = set(G.keys())
total_cost = 0
next_pens.put((0, list(G.keys())[0]))
while remaining_pens and next_pens:
    cost, pen = next_pens.get()
    if pen in remaining_pens:
        remaining_pens.remove(pen)
        total_cost += cost
        for next_cost, next_pen in G[pen]:
            next_pens.put((next_cost, next_pen))

answer = total_cost
#print("Considering outside: %d" % total_cost)

# Remove outside pen
del(G[1001])
#print(G)
for p in G:
    for cost, target in G[p]:
        if target == 1001:
            G[p].remove((cost, target))

#print("yolo", G)

# More Prim's (without outside)
#next_pens = PriorityQueue()
#remaining_pens = set(G.keys())
#total_cost = 0
#next_pens.put((0, list(G.keys())[0]))
##print(next_pens)
#while remaining_pens and next_pens.qsize():
#    #print(remaining_pens)
#    cost, pen = next_pens.get()
#    #print("kore wa ", cost,pen)
#    if pen in remaining_pens:
#        remaining_pens.remove(pen)
#        total_cost += cost
#        for next_cost, next_pen in G[pen]:
#            next_pens.put((next_cost, next_pen))

#answer = min(answer, total_cost)
#print("Not considering outside: %d" % total_cost)
print(total_cost)
