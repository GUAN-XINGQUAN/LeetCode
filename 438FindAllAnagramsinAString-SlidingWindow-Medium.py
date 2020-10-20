class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        if len(p) > len(s):
            return []
        ans = []
        cnt = 0
        myDict = dict()
        for char in p:
            myDict[char] = myDict.setdefault(char, 0) + 1        
        
        for rightIdx in range(len(s)):
            rightChar = s[rightIdx]
            myDict[rightChar] = myDict.setdefault(rightChar, 0) - 1
            if myDict[rightChar] >= 0:
                cnt += 1
            if rightIdx >= len(p):
                prevLeftIdx = rightIdx - len(p)
                prevLeftChar = s[prevLeftIdx]
                myDict[prevLeftChar] = myDict[prevLeftChar] + 1
                if myDict[prevLeftChar] > 0:
                    cnt -= 1
            if cnt == len(p):
                ans.append(rightIdx - len(p) + 1)
        return ans
            
        
        
"""
https://leetcode.com/problems/find-all-anagrams-in-a-string/

Classic sliding window problem. 
Window size as len(p)
Apply a counter to count valid chars. Once counter == len(p), got valid idx. 

* Values of myDict at line 10 represents the max values for each char. 
* Values of myDict greater than 0 represents "valid" char in p.
"""