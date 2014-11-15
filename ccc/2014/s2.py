input()
partners = list(zip(input().split(), input().split()))
pd = {}
for p1, p2 in partners:
    pd[p1] = p2
print("good" if all(p == pd[pd[p]] and p != pd[p] for p in pd) else "bad")

