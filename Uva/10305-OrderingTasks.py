import sys

def kahns(adj, n):
    ans = []
    
    vertices = []
    indegree = [0] * (n + 1)

    for v in adj:
        for e in v:
            indegree[e] = indegree[e] + 1

    for v in range(1, n + 1):
        if indegree[v] == 0:
            vertices.append(v)

    while len(vertices) > 0:
        u = vertices[-1]
        vertices.pop()

        ans.append(u)

        for v in adj[u]:
            indegree[v] = indegree[v] - 1
            if indegree[v] == 0:
                vertices.append(v)

    return ans

while True:
    n, m = [int(x) for x in input().split()]

    if n == 0 and m == 0:
        break

    adj = []

    for i in range(n+1):
        adj.append([])

    for i in range(m):
        u, v = [int(x) for x in input().split()]

        adj[u].append(v)

    ans = kahns(adj, n)

    for x in ans:
        print(str(x) + " ", end = "")
    
    print()
    
