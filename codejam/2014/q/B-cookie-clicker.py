from queue import PriorityQueue

# Dijkstra's.

num_cases = int(input())
for case in range(1, num_cases+1):
    C, F, X = map(float, input().split())
    Q = PriorityQueue()

    # (time, production, winning)
    answer = None
    Q.put((0.0, 2.0, False))
    while True:
        time, prod, win = Q.get(False)
        
        if win:
            answer = time
            break

        time_to_farm = C/prod
        time_to_win = X/prod

        # Get a farm
        Q.put((time+time_to_farm, prod+F, False))
        # Wait for win
        Q.put((time+time_to_win, prod, True))

    print("Case #%d: %.7f" % (case, answer))
