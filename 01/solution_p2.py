with open("input", "r") as infile:
    left, right = zip(*[map(int, line.split()) for line in infile])

diff = sum([x * sum([1 for y in right if y == x]) for x in left])
print(f"Total difference: {diff}")