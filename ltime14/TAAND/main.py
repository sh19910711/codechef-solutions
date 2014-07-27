n = int(input())
A = [0] * n
for i in range(n):
    A[i] = int(input())

res = 0
for i in range(n):
    for j in range(i + 1, n):
        res = max(res, A[i] & A[j])

print(res)