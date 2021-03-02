from collections import deque
class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n == 1:
            return [0]
        graph = dict()
        passed = set()
        leaves = deque()
        ins = [0 for _ in range(n)]
        for node1, node2 in edges:
            if node1 in graph:                
                graph[node1].add(node2)
            else:
                graph[node1] = set([node2])
            if node2 in graph:                
                graph[node2].add(node1)
            else:
                graph[node2] = set([node1])
            ins[node1] += 1
            ins[node2] += 1
        
        for i in range(n):
            if ins[i] == 1: # This node is currently a leaf. 
                leaves.append(i)
                
        while len(leaves) + len(passed) < n:
            for _ in range(len(leaves)):
                curNode = leaves.popleft()
                passed.add(curNode)
                for nextNode in graph[curNode]:
                    ins[nextNode] -= 1
                    if ins[nextNode] == 1: # This node is currently a leaf. 
                        leaves.append(nextNode)
        return leaves
"""
https://leetcode.com/problems/minimum-height-trees/
Topological Sort. Exclude level by level (use anonymous loop as bfs)
"""