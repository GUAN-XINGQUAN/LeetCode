# # Method 1:
# class Solution:
#     def maxSubArray(self, nums):
#         """
#
#         :param nums: List[int]
#         :return: int
#         """
#         if len(nums) == 0:
#             return 0
#         currentMax = nums[0]
#         for i in range(0, len(nums)):
#             for j in range(i, len(nums)):
#                 currentSum = 0
#                 for k in range(i, j+1):
#                     currentSum += nums[k]
#                 if currentSum > currentMax:
#                     currentMax = currentSum
#         return currentMax

# # Method 2:
# class Solution:
#     def maxSubArray(self, nums):
#         if len(nums) == 0:
#             return 0
#         for i in range(1, len(nums)):
#             curr_num = max(nums[i]+nums[i-1], nums[i])
#             nums[i] = curr_num
#         return max(nums)

# # Method 3:
# class Solution:
#     def maxSubArray(self, nums):
#         current = nums[0]
#         sum = nums[0]
#         for i in range(1, len(nums)):
#             if current < 0:
#                 current = nums[i]
#             else:
#                 current += nums[i]
#             if current > sum:
#                 sum = current
#         return sum

# Method 4
class Solution:
    def maxSubArray(self, nums):
        sum = nums[0]
        n = nums[0]
        for i in range(1, len(nums)):
            if (n > 0):
                n += nums[i]
            else:
                n = nums[i]
            if (sum < n):
                sum = n
        return sum

s1 = Solution()
numsList = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
print(s1.maxSubArray(numsList))