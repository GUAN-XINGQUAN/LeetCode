class Solution:
    def swap(self, arr, i, j):
        temp = arr[i]
        arr[i] = arr[j]
        arr[j] = temp
            
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        ans = []
        i = 0
        while i <= len(nums) - 1:
            curElem = nums[i]
            if curElem != i + 1 and curElem != nums[curElem - 1]:
                self.swap(nums, i, curElem - 1)
            else:
                i += 1
        for i in range(len(nums)):
            if i + 1 != nums[i]:
                ans.append(i + 1)
        return ans
"""
https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
Cyclic Sort. 
"""