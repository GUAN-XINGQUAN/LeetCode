class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        if not letters:
            return None
        leftIdx = 0
        rightIdx = len(letters) - 1
        midIdx = None
        while leftIdx <= rightIdx:
            midIdx = (leftIdx + rightIdx) // 2
            midVal = letters[midIdx]
            if leftIdx == rightIdx:
                break
            if midVal < target:
                leftIdx = midIdx + 1
            elif midVal == target:
                break
            else:
                # No need to subtract 1, i.e. rightIdx = midIdx - 1
                # In this set of settings {midIdx = (leftIdx + rightIdx) // 2, leftIdx = midIdx + 1, rightIdx = midIdx}
                # There's the possibility that rightIdx == leftIdx.
                rightIdx = midIdx 
        if target < letters[midIdx]:
            return letters[midIdx]
        elif target > letters[midIdx]:
            return letters[0]
        
        # target == letters[midIdx]
        while target == letters[midIdx]:
            if midIdx == len(letters) - 1:
                break
            elif letters[midIdx] != letters[midIdx + 1]:
                break
            # letters[midIdx] == letters[midIdx + 1]
            else:
                midIdx += 1
                
        if midIdx == len(letters) - 1:
            return letters[0]
        else:
            return letters[midIdx + 1]
"""
https://leetcode.com/problems/find-smallest-letter-greater-than-target/
Binary Search.
Remind to know the meaning of midIdx. 
"""