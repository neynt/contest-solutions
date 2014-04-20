T = int(input())
C = int(input())
chores = [int(input()) for _ in range(C)]
chores.sort()
n = 0
for c in chores:
    T -= c
    if T < 0: break
    n += 1
print(n)
