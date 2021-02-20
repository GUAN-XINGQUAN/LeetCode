class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        left = 0
        right = len(nums) - 1
        while left <= right:
            mid = (left + right) // 2
            leftVal = nums[left]
            rightVal = nums[right]
            midVal = nums[mid]
            
            if midVal == target or rightVal == target or leftVal == target:
                return True
            while leftVal == midVal == rightVal:
                left += 1
                right -= 1
                if left > right:
                    return False
                leftVal = nums[left]
                rightVal = nums[right]
            
            # When pivot idx > mid, left-side is sorted
            if leftVal <= midVal:
                if target > midVal:
                    left = mid + 1
                elif target < midVal:
                    if target >= leftVal:
                        right = mid - 1
                    elif target < leftVal:
                        left = mid + 1                
            
            # When pivot idx < mid, right-side is sorted
            elif midVal <= rightVal:
                if target > midVal:
                    if target > rightVal:
                        right = mid - 1
                    elif target <= rightVal:
                        left = mid + 1
                elif target < midVal:
                    right = mid - 1      
        return False
"""
https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
Binary Search. 
"""