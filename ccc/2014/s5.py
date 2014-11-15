N = int(raw_input())
n = []
reach = {}

# memoize the maximum candies from a certain neighbour with a given distance remaining
mem = {}

# Returns square of the distance. Guaranteed integer.
def dist(x1, y1, x2, y2):
    dx = x1-x2
    dy = y1-y2
    return dx*dx + dy*dy

# Straightforward DFS.
def max_candies(cx, cy, last_dist, count):
    #print("At neighbor", cx, cy, ", last dist", last_dist)

    ct = str((cx, cy, last_dist))
    if ct in mem:
        return count + mem[ct]

    best_count = count
    for nx, ny in n:
        new_dist = dist(cx, cy, nx, ny)
        if new_dist > 0 and new_dist < last_dist:
            best_count = max(best_count, max_candies(nx, ny, new_dist, count+1))

    mem[ct] = best_count - count
    return best_count

for _ in xrange(N):
    x,y = map(int, raw_input().split())
    n.append((x,y))

#print(n)
print(max_candies(0, 0, 999999999, 0))
