#!/usr/bin/python2

n = int(raw_input())
computers = []
for i in range(n):
    name, r, s, d = raw_input().split()
    computers.append((name, 2*int(r) + 3*int(s) + int(d)))
computers.sort(reverse=True)
computers.sort(key=lambda c:c[1])
if computers:
    print('\n'.join(c[0] for c in computers[-1:-3:-1]))
