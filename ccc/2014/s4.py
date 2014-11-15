N = int(raw_input())
T = int(raw_input())

# Dict of columns, each of which contains a dict of rows
# e.g. starts[340][500] = 5 -> there's 5 tint added at&below 340,500
starts = {}

xss = set()
yss = set()
rects = []

# Read in each rect
for _ in xrange(N):
    x1, y1, x2, y2, t = map(int, raw_input().split())
    rects.append((x1, y1, x2, y2, t))
    xss.add(x1)
    xss.add(x2)
    yss.add(y1)
    yss.add(y2)

for x in xss:
    starts[x] = {}
    for y in yss:
        starts[x][y] = 0

xs = list(xss)
ys = list(yss)
xs.sort()
ys.sort()

for x1, y1, x2, y2, t in rects:
    for x in xs:
        if x1 <= x < x2:
            starts[x][y1] += t
            starts[x][y2] -= t

total_area = 0

#print(xs)
#print(ys)

for i in xrange(len(xs)-1):
    xt = xs[i+1] - xs[i]
    cur_tint = 0
    for j in xrange(len(ys)-1):
        yt = ys[j+1] - ys[j]
        cur_tint += starts[xs[i]][ys[j]]
        #print("tint at %d %d is %d" % (x, y, cur_tint))
        if cur_tint >= T:
            total_area += xt*yt
            #print("Adding %d!" % (xt*yt))

print total_area

# LIKE AN ANGEL IN DISGUISE
