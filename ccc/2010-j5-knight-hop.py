from queue import Queue

# Get input
x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())

visited = set()

# Queue of (x, y, d) tuples
# where x,y is a coordinate and
# d is the depth (how many steps it takes to
# get to x,y from x1,y1)
Q = Queue()
Q.put((x1, y1, 0))

while not Q.empty():
    x, y, d = Q.get()
    # Check if out of bounds
    if x < 1 or x > 8 or y < 1 or y > 8:
        continue
    # Check if already visited
    if (x,y) in visited:
        continue
    # Check if this is our goal
    if x == x2 and y == y2:
        print(d)
        break
    
    # Branch out!
    visited.add((x,y))
    Q.put((x-1,y-2,d+1))
    Q.put((x-1,y+2,d+1))
    Q.put((x+1,y-2,d+1))
    Q.put((x+1,y+2,d+1))
    Q.put((x-2,y-1,d+1))
    Q.put((x-2,y+1,d+1))
    Q.put((x+2,y-1,d+1))
    Q.put((x+2,y+1,d+1))
