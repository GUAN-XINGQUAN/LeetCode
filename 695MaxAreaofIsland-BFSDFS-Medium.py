class Solution:
    def isValidGrid(self, x, y, rows, cols):
        if x >= 0 and x <= rows - 1 and y >=0 and y <= cols - 1:
            return True
        return False
        
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        ans = 0
        if not grid or not grid[0]:
            return ans
        
        numOfRows = len(grid)
        numOfCols = len(grid[0])
        for i in range(numOfRows):
            for j in range(numOfCols):
                if grid[i][j] == 1:
                    cnt = 0
                    q = [(i, j)]
                    while q:
                        curGrid = q.pop(0)
                        if grid[curGrid[0]][curGrid[1]] == 0:
                            continue
                        
                        cnt += 1
                        grid[curGrid[0]][curGrid[1]] = 0
                        
                        leftGrid = (curGrid[0], curGrid[1] - 1)
                        rightGrid = (curGrid[0], curGrid[1] + 1)
                        upGrid = (curGrid[0] - 1, curGrid[1])
                        downGrid = (curGrid[0] + 1, curGrid[1])
                        grids = [leftGrid, rightGrid, upGrid, downGrid]
                        for g in grids:
                            if self.isValidGrid(g[0], g[1], numOfRows, numOfCols) and grid[g[0]][g[1]] == 1:
                                q.append((g[0], g[1]))
                    if cnt > ans:
                        ans = cnt
        return ans
"""
https://leetcode.com/problems/max-area-of-island/submissions/
Tree search problem. 
"""