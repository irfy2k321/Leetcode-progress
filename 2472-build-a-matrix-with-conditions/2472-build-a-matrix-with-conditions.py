class Solution:
    def buildMatrix(self, k: int, rowConditions: List[List[int]], colConditions: List[List[int]]) -> List[List[int]]:
        def topologicalSort(k: int, conditions: List[List[int]]) -> List[int]:
            inDegree = [0] * (k + 1)
            graph = defaultdict(list)
            
            for u, v in conditions:
                graph[u].append(v)
                inDegree[v] += 1
            
            queue = deque([i for i in range(1, k + 1) if inDegree[i] == 0])
            order = []
            
            while queue:
                node = queue.popleft()
                order.append(node)
                for neighbor in graph[node]:
                    inDegree[neighbor] -= 1
                    if inDegree[neighbor] == 0:
                        queue.append(neighbor)
            
            return order if len(order) == k else []
        
        rowOrder = topologicalSort(k, rowConditions)
        colOrder = topologicalSort(k, colConditions)
        
        if not rowOrder or not colOrder:
            return []
        
        rowPos = {num: i for i, num in enumerate(rowOrder)}
        colPos = {num: i for i, num in enumerate(colOrder)}
        
        matrix = [[0] * k for _ in range(k)]
        
        for num in range(1, k + 1):
            matrix[rowPos[num]][colPos[num]] = num
        
        return matrix
