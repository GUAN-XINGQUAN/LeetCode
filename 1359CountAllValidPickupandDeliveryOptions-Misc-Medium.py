class Solution:
    def countOrders(self, n: int) -> int:
        if n == 1:
            return 1
        base = 1
        for i in range(2, n + 1):
            base = base * (2 * i - 1) * i
        return base % (10 ** 9 + 7)

        
"""
https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/
https://leetcode-cn.com/problems/count-all-valid-pickup-and-delivery-options/solution/you-xiao-de-kuai-di-xu-lie-shu-mu-by-leetcode-solu/
"""