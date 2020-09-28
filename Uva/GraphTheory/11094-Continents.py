import sys


def dfs(grid, s, visited, n, m, x, y, land):
    stack = []
    stack.append(s)
    flag = True
    ans = 0
    while len(stack) > 0:
        u = stack[-1]
        stack.pop()

        if u not in visited:
            visited.add(u)
            ans = ans + 1

            if u[0] == x and u[1] == y:
                flag = False
            
            #left
            if u[1] - 1 == -1:
                if grid[u[0]][m-1] == land:
                    stack.append((u[0], m - 1))
            elif grid[u[0]][u[1] -1] == land:
                stack.append((u[0], u[1] - 1))
            #right
            if u[1] + 1 == m:
                if grid[u[0]][0] == land:
                    stack.append((u[0], 0))
            elif grid[u[0]][u[1] + 1] == land:
                stack.append((u[0], u[1] + 1))
            #down
            if u[0] + 1 < n and grid[u[0] + 1][u[1]] == land:
                stack.append((u[0] + 1, u[1]))
            #up
            if u[0] - 1 >= 0 and grid[u[0] - 1][u[1]] == land:
                stack.append((u[0] - 1, u[1]))
    
    if not flag:
        ans = 0
    return ans
            

for line in sys.stdin:
    if len(line.strip()) == 0:
        continue
    n, m = [int(x) for x in line.split()]

    grid = [[]]

    for i in range(n):
        row = input()
        grid.append([])
        for c in row:
            grid[i].append(c)

    x, y = [int(x) for x in input().split()]

    land = grid[x][y]

    visited = set()

    ans = 0
    for i in range(n):
        for j in range(m):
            cell = (i, j)
            if grid[i][j] == land and cell not in visited:
                val = dfs(grid, cell, visited, n, m, x, y, land)
                ans = max(ans, val)
    
    print(ans)

    
