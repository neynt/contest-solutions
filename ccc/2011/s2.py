#!/usr/bin/env python3
N = int(input())
print(sum(1 for q,a in zip([input() for _ in range(N)], [input() for _ in range(N)]) if q==a))
