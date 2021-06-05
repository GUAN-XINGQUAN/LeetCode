class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        N = len(nums)
        ans = [10 ** 5 + 1, 3 * 10 ** 5 + 3]
        listDict = dict()    
        sortedList = list()      
        for listIdx in range(len(nums)):
            for num in nums[listIdx]:
                sortedList.append((num, listIdx))
        sortedList.sort()  
        
        leftIdx = 0
        for rightIdx in range(len(sortedList)):
            leftElem = sortedList[leftIdx]
            rightElem = sortedList[rightIdx]
            listDict[rightElem[1]] = listDict[rightElem[1]] + 1 if rightElem[1] in listDict else 1
            while len(listDict) == N and listDict[leftElem[1]] > 1 and leftIdx < rightIdx:
                listDict[leftElem[1]] -= 1
                leftIdx += 1
                leftElem = sortedList[leftIdx]
            if len(listDict) == N:
                leftRange = leftElem[0]
                rightRange = rightElem[0]
                if rightRange - leftRange < ans[1] - ans[0]:
                    ans = [leftRange, rightRange]
        return ans
            
"""
https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
KWay Merge. Heap is not applied. sortedList & sliding window.
"""