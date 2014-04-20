#!/usr/bin/env python

def crystal(x,y,m):
    w = 5**(m-1)
    ax = x//w
    ay = y//w
    if (ax,ay) in [(1,0), (2,0), (3,0), (2,1)]:
        return True
    elif (ax,ay) in [(1,1), (2,2), (3,1)]:
        return crystal(x%w, y%w, m-1)
    else:
        return False

for _ in range(int(input())):
    m, x, y = map(int, input().split())
    print('crystal' if crystal(x, y, m) else 'empty')
