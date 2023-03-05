def hanoi(n):
    if n == 0:
        return 0
    return 2 * hanoi(n-1) + 1

for i in range(10):
    print(f"Tower of hanoi with {i} disk(s) needs {hanoi(i)} move(s).")