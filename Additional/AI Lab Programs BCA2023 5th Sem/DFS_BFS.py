from queue import Queue

def dfs(graph, node, visited):
    if visited[node]:
        return
    else:
        print(f"Visiting node {node}")
        visited[node] = 1
        for neighbour in graph[node]:
            if not visited[neighbour]:
                dfs(graph, neighbour, visited)

def bfs(graph, start):
    visited = [0] * len(graph)
    queue = Queue()
    queue.put(start)

    while not queue.empty():
        curr_node = queue.get()
        visited[curr_node] = True
        print(f"Visiting node {curr_node}")
        for neighbour in graph[curr_node]:
            if not visited[neighbour]:
                queue.put(neighbour)
        

graph = {
    0: [1, 2],
    1: [0, 3],
    2: [0],
    3: [1]
}

visited = [0] * len(graph)
print("Running DFS:")
dfs(graph, 0, visited)

print("\nRunning BFS:")
bfs(graph, 0)