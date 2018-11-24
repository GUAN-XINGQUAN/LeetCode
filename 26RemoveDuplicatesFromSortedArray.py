class Solution:
    def removeDuplicates(self, nums):
        """
        :param nums: List[int]
        :return: int
        """
        if len(nums) == 0:
            return 0
        index = 1
        starting = 1
        length = len(nums)
        current_element = nums[0]
        count = 1
        while index <= length - 1:
            if nums[index] != current_element:
                nums[starting] = nums[index]
                current_element = nums[index]
                starting += 1
                count += 1
            else:
                pass
            index += 1
        return count




# Expected "11"
nums = []
s = Solution()
result = s.removeDuplicates(nums)
print(nums)
print(result)
