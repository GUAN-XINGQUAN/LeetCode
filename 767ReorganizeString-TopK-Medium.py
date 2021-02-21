import heapq
class Solution:
    def reorganizeString(self, S: str) -> str:
        di = dict()
        for char in S:
            di[char] = di[char] + 1 if char in di else 1
            
        li = list()
        heapq.heapify(li)
        for char in di:
            heapq.heappush(li, (-1 * di[char], char))
        
        prevMax = None
        ans = []
        while li:
            curMax = heapq.heappop(li)
            if prevMax and prevMax[0] < 0:
                heapq.heappush(li, (prevMax[0], prevMax[1]))
            ans.append(curMax[1])
            curMax = (curMax[0] + 1, curMax[1])
            prevMax = curMax
        ans = "".join(ans)
        if len(ans) != len(S):
            return ""
        return ans
"""
https://leetcode.com/problems/reorganize-string/
TopK(heap)
Always to use the 1st frequent or 2nd frequent to append the ans. 
"""