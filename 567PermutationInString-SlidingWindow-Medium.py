class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        freqs = dict()
        for char in s1:
            freqs[char] = freqs.setdefault(char, 0) + 1
        leftIdx = 0
        cnt = 0
        for rightIdx in range(len(s2)):
            rightChar = s2[rightIdx]
            leftChar = s2[leftIdx]
            freqs[rightChar] = freqs.setdefault(rightChar, 0) - 1
            if freqs[rightChar] >= 0:
                cnt += 1
            
            # Move left
            if rightIdx - leftIdx + 1 > len(s1):
                freqs[leftChar] += 1
                if freqs[leftChar] > 0:
                    cnt -= 1                
                leftIdx += 1
            
            # count
            if cnt == len(s1):
                return True
        return False
    
"""
https://leetcode.com/problems/permutation-in-string/
A sliding window problem. 
"""