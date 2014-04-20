#!/usr/bin/env python3
print({False:'French',True:'English'}[(lambda s:sum(1 for c in s if c=='t') > sum(1 for c in s if c=='s'))(''.join(input().lower() for _ in range(int(input()))))])
