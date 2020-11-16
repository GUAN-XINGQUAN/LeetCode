# DFS, Iterative solution. 
class Solution:
    def isValidGrid(self, x, y, rows, cols):
        if x >= 0 and x <= rows - 1 and y >=0 and y <= cols - 1:
            return True
        return False
    
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        ans = 0
        if not grid or not grid[0]:
            return ans
        callStack = list()
        numOfRows = len(grid)
        numOfCols = len(grid[0])
        for i in range(numOfRows):
            for j in range(numOfCols):
                if grid[i][j] == 1:
                    curCnt = 0
                    callStack.append((i, j))
                    while callStack:
                        topPos = callStack.pop(-1);
                        x = topPos[0]
                        y = topPos[1]
                        if grid[x][y] == 1:
                            grid[x][y] = 0
                            curCnt += 1
                            leftGrid = (x, y - 1)
                            rightGrid = (x, y + 1)
                            upGrid = (x - 1, y)
                            downGrid = (x + 1, y)
                            grids = [leftGrid, rightGrid, upGrid, downGrid]
                            for g in grids:
                                if self.isValidGrid(g[0], g[1], numOfRows, numOfCols) and grid[g[0]][g[1]] == 1:
                                    callStack.append((g[0], g[1]))
                    if curCnt > ans:
                        ans = curCnt
        return ans
"""
https://leetcode.com/problems/max-area-of-island/submissions/
Tree search problem. 
But in BFS, take care to avoid dups.
In our experiment, DFS (recursion) is faster (156 ms vs 160 ms) while BFS consumes less memory(14.2MB vs 16.9MB).
However, DFS(iterative) seems to be faster (144ms) and consumes less memory(14.2MB) in call cases. More experiments needs to be finished to confirm this point. 
"""