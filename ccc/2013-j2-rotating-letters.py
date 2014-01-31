#!/usr/bin/env python3
print({True:'YES',False:'NO'}[all(c in 'IOSHZXN' for c in input())])
