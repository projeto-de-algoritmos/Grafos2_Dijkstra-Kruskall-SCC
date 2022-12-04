import sys

class Graph:
    def __init__(self):
        self.graph = dict()
        self.nodes = set()

    def addEdge(self, node1, node2, cost):
        if node1 not in self.graph:
            self.graph[node1] = []
        if node2 not in self.graph:
            self.graph[node2] = []

        self.graph[node1].append((node2, int(cost)))

    def dijkstra_algorithm(self, start_node):
        unvisited_nodes = list(self.nodes)
    
        # We'll use this dict to save the cost of visiting each node and update it as we move along the graph   
        shortest_path = {}
    
        # We'll use this dict to save the shortest known path to a node found so far
        previous_nodes = {}
    
        # We'll use max_value to initialize the "infinity" value of the unvisited nodes   
        max_value = sys.maxsize
        for node in unvisited_nodes:
            shortest_path[node] = max_value
        # However, we initialize the starting node's value with 0   
        shortest_path[start_node] = 0
        
        # The algorithm executes until we visit all nodes
        while unvisited_nodes:
            # The code block below finds the node with the lowest score
            current_min_node = None
            for node in unvisited_nodes: # Iterate over the nodes
                if current_min_node == None:
                    current_min_node = node
                elif shortest_path[node] < shortest_path[current_min_node]:
                    current_min_node = node
            
            
            # The code block below retrieves the current node's neighbors and updates their distances
            neighbors = self.get_outgoing_edges(current_min_node)
            for neighbor in neighbors:
                distance = self.get_distance(current_min_node, neighbor)
                tentative_value = shortest_path[current_min_node] + distance
                if tentative_value < shortest_path[neighbor]:
                    shortest_path[neighbor] = tentative_value
                    # We also update the best path to the current node
                    previous_nodes[neighbor] = current_min_node
    
            # After visiting its neighbors, we mark the node as "visited"
            unvisited_nodes.remove(current_min_node)
        
        return shortest_path

    def get_outgoing_edges(self, current_min_node):
        neighbors = [n[0] for n in self.graph[current_min_node]]
        return neighbors

    def get_distance(self, node1, node2):
        for n in self.graph[node1]:
            if n[0] == node2:
                return n[1]


T = int(input())

for _ in range(T):
    N, M, source_node, final_node, money = input().split()
    
    g = Graph()
    rg = Graph()
    nodes = set()
    edges = []
    
    for _ in range(int(M)):
        node1, node2, cost = input().split()
        
        g.addEdge(node1, node2, int(cost))
        rg.addEdge(node2, node1, int(cost))
        
        edges.append((node1, node2, cost))
        
        nodes.add(node1)
        nodes.add(node2)
    
    g.nodes = nodes
    rg.nodes = nodes
        
    shortest_path = g.dijkstra_algorithm(source_node)
    shortest_path_rg = rg.dijkstra_algorithm(final_node)

    best_toll = -1
    while(edges != []):
        edge_tuple = edges.pop()
        totalCost = shortest_path[edge_tuple[0]] + int(edge_tuple[2]) + shortest_path_rg[edge_tuple[1]]
        if totalCost <= int(money):
            best_toll = max(best_toll, int(edge_tuple[2]))

    print(best_toll)
