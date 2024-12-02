with open("input", "r") as infile:
    left, right = zip(*[map(int, line.split()) for line in infile])

left = sorted(left)
right = sorted(right)

sum([abs(l - r) for l, r in zip(left, right)])

