# BFS algorithm in Python


import collections
# BFS algorithm
def bfsearch(graphs, roots):

    visited, queue = set(), collections.deque([roots])
    visited.add(roots)

    while queue:

        # Dequeue a vertex from queue
        vertex = queue.popleft()
        print(str(vertex) + " ", end="")

        # If not visited, mark it as visited, and
        # enqueue it
        for neighbour in graphs[vertex]:
            if neighbour not in visited:
                visited.add(neighbour)
                queue.append(neighbour)


if __name__ == '__main__':
    graphs = {0: [1, 2], 1: [2], 2: [3], 3: [1, 2]}
    print("Following is Breadth First Traversal: ")
    bfsearch(graphs, 0)
