class Solution:
    def dfs(self, board, visited, row, col, word, startIdx):
        if word[startIdx] != board[row][col] or visited[row][col]:
            return False        
        if startIdx == len(word) - 1:
            return True
        visited[row][col] = True
        m = len(board)
        n = len(board[0])
        ifExist = False
        for axis1, axis2 in [(-1, 0), (1, 0), (0, 1), (0, -1)]:
            idx1 = row + axis1
            idx2 = col + axis2
            if 0 <= idx1 < m and 0 <= idx2 < n:
                ifExist = self.dfs(board, visited, idx1, idx2, word, startIdx + 1) 
                if ifExist:
                    return True
        visited[row][col] = False
        return False  
        
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        ans = set()
        m = len(board)
        n = len(board[0])
        for word in words:
            ifExist = False
            visited = [[False for _ in range(n)] for _ in range(m)]
            for row in range(m):
                for col in range(n):
                    ifExist = self.dfs(board, visited, row, col, word, 0)
                    if ifExist:
                        ans.add(word)
                        break
                if ifExist:
                    break
        return ans
"""
https://leetcode.com/problems/word-search-ii/
DFS. Take care to line 5-6: when to return True. It's nota good practice to return true at startIdx == len(word), since we may not be able to access that step (when all units are visited, for instance. )
"""  