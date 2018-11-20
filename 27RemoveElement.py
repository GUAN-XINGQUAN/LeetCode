# Optimized method
class Solution:
    def removeElement(self, nums, val):
        """

        :param nums: List[int]
        :param val: int
        :return: int
        """
        index = 0
        length = len(nums)
        while index <= length-1:
            if nums[index] == val:
                nums[index] = nums[length - 1]
                length = length - 1
            else:
                index = index + 1
        return index


# Test the program
nums = [0,1,2,2,3,0,4,2]
val = 2
s = Solution()
print(s.removeElement(nums, val))
print(nums)
