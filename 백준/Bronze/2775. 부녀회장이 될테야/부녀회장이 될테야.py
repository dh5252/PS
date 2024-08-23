
arr = [[0 for _ in range(15)] for _ in range(15)]

for i in range(0, 15):
    for j in range(0, 15):
        if i == 0:
            arr[i][j] = j
        else:
            for k in range(1, j + 1):
                arr[i][j] += arr[i - 1][k]

T = int(input())

for i in range(T):
    k = int(input())
    n = int(input())
    print(arr[k][n])
