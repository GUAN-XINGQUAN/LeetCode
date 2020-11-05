class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        windowElem = dict()
        windowMaxCnt = 0 # Global 
        leftIdx = 0
        result = 0
        for rightIdx in range(len(s)):
            rightElem = s[rightIdx]
            windowElem[rightElem] = windowElem.setdefault(rightElem, 0) + 1
            windowMaxCnt = max(windowMaxCnt, windowElem[rightElem])
            
            while rightIdx - leftIdx + 1 - windowMaxCnt > k:
                leftElem = s[leftIdx]
                windowElem[leftElem] = windowElem[leftElem] - 1
                leftIdx += 1
                
            result = max(result, rightIdx - leftIdx + 1)
        return result
    
"""
https://leetcode.com/problems/longest-repeating-character-replacement/
Also a sliding window problem. 
Set a "global" var windowMaxCnt, representing the highest number of elements in a window in the history. 
"""