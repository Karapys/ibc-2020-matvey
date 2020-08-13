import time

def print_array(a):
    for i in a[:2]:
        print(i)

def floyd_warshall(a):
    for k in range(len(a)):
            for i in range(len(a)):
                for j in range(len(a)):
                    if a[i][j] > a[i][k] + a[k][j]:
                        a[i][j] = a[i][k] + a[k][j]
    return a


"""
arr = [
    [0, 1, 5, 2],
    [1, 0, 8, 4],
    [5, 8, 0, 2],
    [2, 4, 2, 0]
]
"""

arr = []
with open("day_4/input") as file:
    for line in file:
        arr.append([int(x) for x in line.split()])

#print_array(arr)
t1 = time.time_ns()
arr = floyd_warshall(arr)
t2 = time.time_ns()

delta = str(t2 - t1)
print(f"Execution took {delta} nanoseconds")
input("Press any key to exit...")


