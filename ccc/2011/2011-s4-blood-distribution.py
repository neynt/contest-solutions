#!/usr/bin/env python3
donors = {}
receiv = {}
types = 'O- O+ A- A+ B- B+ AB- AB+'.split()

def give(t1, t2):
    global donors, receiv
    amt = min(donors[t1], receiv[t2])
    donors[t1] -= amt
    receiv[t2] -= amt
    return amt

for t,q in zip(types, map(int, input().split())):
    donors[t] = q
for t,q in zip(types, map(int, input().split())):
    receiv[t] = q

# It's all greedy
dsum = 0
dsum += give('O-', 'O-')
dsum += give('O+', 'O+')
dsum += give('A-', 'A-')
dsum += give('A+', 'A+')
dsum += give('A+', 'AB+')
dsum += give('B-', 'B-')
dsum += give('B+', 'B+')
dsum += give('B+', 'AB+')
dsum += give('AB-', 'AB-')
dsum += give('AB+', 'AB+')
dsum += give('O-', 'A-')
dsum += give('O-', 'B-')
dsum += give('O-', 'AB-')
dsum += give('A-', 'A+')
dsum += give('A-', 'AB-')
dsum += give('A-', 'AB+')
dsum += give('B-', 'B+')
dsum += give('B-', 'AB-')
dsum += give('B-', 'AB+')
dsum += give('O-', 'A+')
dsum += give('O-', 'B+')
dsum += give('O-', 'AB+')
dsum += give('O+', 'A+')
dsum += give('O+', 'B+')
dsum += give('O+', 'AB+')
dsum += give('', '')
dsum += give('', '')
dsum += give('', '')
dsum += give('', '')
dsum += give('', '')
dsum += give('', '')
dsum += give('', '')
