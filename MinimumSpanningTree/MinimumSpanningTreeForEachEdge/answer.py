from sys import stdout

def modified_kruskal(graph, n, results):
    graph_sorted = sorted(graph)

    node_list = [i for i in range(n)]
    mst = []
    remaining_weight = 0

    for weight, u, v in graph_sorted:
        
        while node_list[u] != u:
            mst.append(u)
            u = node_list[u]
        
        while node_list[v] != v:
            mst.append(v)
            v = node_list[v]
        
        if u != v:
            remaining_weight += weight
            if len(nodes_set[u]) < len(nodes_set[v]):
                u, v = v, u
            node_list[v] = u
            for j in nodes_set[v] & nodes_set[u]:
                results[j] -= weight
            nodes_set[u] ^= nodes_set[v]
        
        for x in mst:
            node_list[x] = u
        
        del mst[:]

    for i in range(m):
        results[i] += remaining_weight
    
    return results

graph = []

n, m =  map(int, input().split())
nodes_set = [set() for _ in range(n)]
results = [0] * m

for i in range(int(m)):
    node1, node2, weight = map(int, input().split())
    graph.append((weight, node1-1, node2-1))
    nodes_set[node1-1].add(i)
    nodes_set[node2-1].add(i)
    results[i] = weight

results = modified_kruskal(graph, n, results)

stdout.write('\n'.join(map(str, results)))
