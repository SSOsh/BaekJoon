import sys
sys.setrecursionlimit(10000)

def dfs(x, y):
  dx = [1, -1, 0, 0]
  dy = [0, 0, 1, -1]
  visit[x][y] = 1
  
  for i in range(4):
    moveX = x + dx[i]
    moveY = y + dy[i]
    if (0 <= moveX < m) and (0 <= moveY < n) and visit[moveX][moveY] != 1 and arr[moveX][moveY] == 1:
      dfs(moveX, moveY)


T = int(input())
for _ in range(T):
  m, n, k = map(int, input().split())
  arr = [[0]*n for _ in range(m)]
  visit = [[0]*n for _ in range(m)]
  result = 0
  for _ in range(k):
    x, y = map(int, input().split())
    arr[x][y] = 1

  for i in range(m):
    for j in range(n):
      if arr[i][j] > 0 and visit[i][j] != 1:
        dfs(i, j)
        result += 1
  print(result)