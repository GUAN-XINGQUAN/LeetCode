class Solution:
    def isValidGrid(self, x, y, rows, cols):
        if x >= 0 and x <= rows - 1 and y >=0 and y <= cols - 1:
            return True
        return False
    
    def dfs(self, x, y, grid):
        ans = 1
        grid[x][y] = 0
        
        leftGrid = (x, y - 1)
        rightGrid = (x, y + 1)
        upGrid = (x - 1, y)
        downGrid = (x + 1, y)
        numOfRows = len(grid)
        numOfCols = len(grid[0])
        grids = [leftGrid, rightGrid, upGrid, downGrid]
        
        for g in grids:
            if self.isValidGrid(g[0], g[1], numOfRows, numOfCols) and grid[g[0]][g[1]] == 1:
                ans += self.dfs(g[0], g[1], grid)
        return ans
    
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        ans = 0
        if not grid or not grid[0]:
            return ans
        
        numOfRows = len(grid)
        numOfCols = len(grid[0])
        for i in range(numOfRows):
            for j in range(numOfCols):
                if grid[i][j] == 1:
                    cnt = self.dfs(i, j, grid)
                    if cnt > ans:
                        ans = cnt
        return ans
"""
https://leetcode.com/problems/max-area-of-island/submissions/
Tree search problem. 
But in BFS, take care to avoid dups.
In our experiment, DFS is faster (156 ms vs 160 ms) while BFS consumes less memory(14.2MB vs 16.9MB).
"""