# Read input
code = {}
for i in range(int(input())):
    char, sequence = input().split()
    code[sequence] = char
line = input()

# Greedily match the sequences
sequence = ""
output = ""
for c in line:
    sequence += c
    if sequence in code:
        output += code[sequence]
        sequence = ""

print(output)
