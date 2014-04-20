N = int(input())

f = [0]*1000
for _ in range(N):
    r = int(input())-1
    f[r] += 1

# frequency sorted
fs = sorted(list(zip(range(1,1001), f)), key=lambda x:x[1], reverse=True)

# most frequent readings
mfs = [i for i in fs if i[1] == fs[0][1]]
#print "mfs", mfs

if len(mfs) > 1:
    # more than one most frequent
    print(max(mfs)[0] - min(mfs)[0])
else:
    # exact one most frequent
    # second most frequent readings
    smfs = sorted([i for i in fs if i[1] == fs[1][1]])
    #print "smfs", smfs
    print(max(mfs[0][0]-smfs[0][0], smfs[-1][0]-mfs[0][0]))

