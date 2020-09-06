class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        sums = {0:1, }
        s = 0
        cnt = 0
        for n in nums:
            s += n
            if s - k in sums:
                cnt += sums[s-k]
            if s in sums:
                sums[s] += 1
            else:
                sums[s] = 1
        return cnt

"""
https://leetcode.com/problems/subarray-sum-equals-k/

The key idea is actually at hint3 and hint 4 - 
"What about storing sum frequencies in a hash table? Will it be useful?"
and
"sum(i,j)=sum(0,j)-sum(0,i), where sum(i,j) represents the sum of all the 
elements from index i to j-1. Can we use this property to optimize it."

One more hint about hash table:
"Apply hash when we need to search in a collection. "

"""