N, M = map(int, input().split())
arr = list(map(int, input().split()))
result = 0

for i in range(N):
    for j in range(i + 1, N):
        for k in range(j + 1, N):
            print
            if arr[i] + arr[j] + arr[k] > M:
                continue
            result = max(result, arr[i] + arr[j] + arr[k])

print(result)
