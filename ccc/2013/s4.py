from collections import deque

N, M = map(int, raw_input().split())
people = [[] for _ in xrange(N)]
for _ in xrange(M):
    p, q = map(int, raw_input().split())
    people[p-1].append(q-1)

a, b = map(int, raw_input().split())
a -= 1
b -= 1

def taller(a, b):
    visited = set()
    Q = deque()
    Q.append(a)
    while Q:
        c = Q.popleft()
        if c in visited:
            continue
        visited.add(c)
        if c == b:
            return True
        for p in people[c]:
            Q.append(p)
    return False

if taller(a,b):
    print "yes"
elif taller(b,a):
    print "no"
else:
    print "unknown"
