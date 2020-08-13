import time
from array import array

MATRIX_SIZE = 200
NUM_OF_RUNS = 1

def print_array(a, a_len = 1000):
    for i in a[:a_len]:
        print(i)

def floyd_warshall(a):
    for k in range(len(a)):
            for i in range(len(a)):
                for j in range(len(a)):
                    if a[i][j] > a[i][k] + a[k][j]:
                        a[i][j] = a[i][k] + a[k][j]
    return a


"""
test_arr = [
    [0, 1, 5, 2],
    [1, 0, 8, 4],
    [5, 8, 0, 2],
    [2, 4, 2, 0]
]
"""

arr = [0]*MATRIX_SIZE
with open("day_4/input") as file:
    for i, line in enumerate(file):
        if i == MATRIX_SIZE:
            break
        arr[i] = array("I", [int(x) for x in line.split()[:MATRIX_SIZE]])

#print_array(arr)

est_time = 0
for i in range(NUM_OF_RUNS):
    t1 = time.time_ns()
    arr = floyd_warshall(arr)
    t2 = time.time_ns()
    est_time += (t2 - t1)

delta = str(est_time / (10 ** 9 * NUM_OF_RUNS))
print(f"Execution took {delta} seconds")
input("Press any key to exit...")


