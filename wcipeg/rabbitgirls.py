N = int(input())
K = int(input())
if N >= K:
    print(min(N%K, (-N)%K))
else:
    print(K-N)
