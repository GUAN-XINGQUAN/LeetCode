class Solution:
    def swap(self, arr, i, j):
        tmp = arr[i]
        arr[i] = arr[j]
        arr[j] = tmp
        
    def findDuplicates(self, nums: List[int]) -> List[int]:
        ans = []
        i = 0
        maxCnt = 0
        while i < len(nums):
            curElem = nums[i]
            if curElem < len(nums) and curElem != i + 1 and curElem != nums[curElem - 1]:
                self.swap(nums, i, curElem - 1)
            else:
                i += 1
        for i in range(len(nums)):
            if nums[i] == len(nums):
                maxCnt += 1
            if nums[i] != i + 1 and nums[i] != len(nums):
                ans.append(nums[i])
        if maxCnt > 1:
            ans.append(len(nums))
        return ans
"""
https://leetcode.com/problems/find-all-duplicates-in-an-array/
Cyclic Sort. It's always important to care for the range of nums[i] in such problems. 
"""