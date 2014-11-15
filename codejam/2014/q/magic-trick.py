num_cases = int(input())

for case_num in range(num_cases):
    a1 = int(input())
    rows1 = [input().split() for _ in range(4)]
    chosen1 = set(rows1[a1-1])
    
    a2 = int(input())
    rows2 = [input().split() for _ in range(4)]
    chosen2 = set(rows2[a2-1])

    possible = list(chosen1 & chosen2)

    if len(possible) == 0:
        answer = "Volunteer cheated!"
    elif len(possible) > 1:
        answer = "Bad magician!"
    else:
        answer = str(possible[0])

    print("Case #%d: %s" % (case_num+1, answer))
