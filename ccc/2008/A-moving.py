num_people = int(input())
names = {}
houses = {}
priority = {}

for _ in range(num_people):
    name, house_from, house_to = input().split()
    houses[house_from] = house_to
    names[house_from] = name

# Starting from each person in turn,
for house_from in houses:
    # Do a depth-first search
    counter = 1
    F = [house_from]
    visited = set()
    # Keep going deeper
    while True:
        house_from = F[-1]
        if house_from in houses:
            F.append(houses[house_from])
        else:
            # Bakuhatsu!
            F.pop()
            while F:
                priority[F.pop()] = counter
                counter += 1
            break

print(priority)
for h, p in sorted(list(priority.items()), key=lambda x:x[1]):
    print(names[h])
