k = int(input())
code = {}
for i in range(k):
    char, sequence = input().split()
    code[sequence] = char
line = input()

sequence = ""
output = ""
for c in line:
    sequence += c
    if sequence in code:
        output += code[sequence]
        sequence = ""

print(output)
