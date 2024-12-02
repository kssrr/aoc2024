with open("input", "r") as infile:
    inputs = [list(map(int, line.split())) for line in infile]

def safe(A: list) -> bool:
    monotonic = all([A[i] < A[i+1] for i in range(len(A) - 1)]) or all([A[i] > A[i+1] for i in range(len(A) - 1)])
    no_large_diffs = all([abs(A[i] - A[i+1]) <= 3 for i in range(len(A) - 1)])
    return (monotonic and no_large_diffs)

counter = sum([1 for input in inputs if safe(input)])
print(f"{counter} safe.")