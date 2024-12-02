with open("input", "r") as infile:
    inputs = [list(map(int, line.split())) for line in infile]

def safe(A: list) -> bool:
    monotonic = all([A[i] < A[i+1] for i in range(len(A) - 1)]) or all([A[i] > A[i+1] for i in range(len(A) - 1)])
    no_large_diffs = all([abs(A[i] - A[i+1]) <= 3 for i in range(len(A) - 1)])
    return (monotonic and no_large_diffs) 

# Bruteforcing all possible n-1 subsets:
def safe_with_removal(A: list) -> bool:
    if safe(A):
        return True
    return any([safe(sub) for sub in [A[:i] + A[i+1:] for i in range(len(A))]])

counter = sum([1 for input in inputs if safe_with_removal(input)])
print(f"{counter} safe.")