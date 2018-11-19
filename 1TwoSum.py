# Optimized method
class Solution:
    def twoSum(self, nums, target):
        """
        :param nums: List[int]
        :param target: int
        :return: List[int]
        """
        hashTable = dict()
        for index, value in enumerate(nums):
            print(index, value)
            if (target-value) in hashTable.keys():
                return [hashTable[target-value], index]
            hashTable[value] = index


# Test the program
nums = [2, 7, 11, 15]
target = 9;
s = Solution()
print(s.twoSum(nums, target))
