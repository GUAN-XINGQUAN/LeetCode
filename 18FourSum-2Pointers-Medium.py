class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        ans = []
        nums.sort()
        visited = set()
        if len(nums) < 4:
            return ans
        for idx1 in range(len(nums) - 3):
            val1 = nums[idx1]
            for idx2 in range(idx1 + 1, len(nums) - 2):
                val2 = nums[idx2]
                idx3 = idx2 + 1
                idx4 = len(nums) - 1
                while idx3 < idx4:
                    val3 = nums[idx3]
                    val4 = nums[idx4]
                    s = val1 + val2 + val3 + val4
                    if s > target:
                        idx4 -= 1
                    elif s < target:
                        idx3 += 1
                    else:
                        a = [val1, val2, val3, val4]
                        astr = str(a)[1:-1]
                        if astr not in visited:
                            ans.append(a)
                            visited.add(astr)
                        idx3 += 1
                        idx4 -= 1
        return ans
"""
https://leetcode.com/problems/4sum/submissions/
It's nothing special with 3Sum...
2 Pointers problem. 
"""