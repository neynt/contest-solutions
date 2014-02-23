num_obs, num_queries = map(int, input().split())

group = {}
theory = {}
G = {}
for _ in range(num_obs):
    l = input().split()
    street_a = l[0]
    street_b = l[1]
    weight = {'parallel':0, 'intersect':1}[l[2]]
    if street_a not in G:
        G[street_a] = []
    if street_b not in G:
        G[street_b] = []
    G[street_a].append((street_b, weight))
    G[street_b].append((street_a, weight))

# Do a depth-first search from each node,
# assigning theories and collecting groups.


