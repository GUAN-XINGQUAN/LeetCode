class Solution:
    def countAndSay(self, n):
        """

        :param n: int
        :return: str
        """
        # For case n = 1
        if (n == 1):
            return "1"
        # For case n >= 2
        previous_list = self.countAndSay(n-1)
        count = 0
        current_item = previous_list[0]
        total_str = ''
        for index in range(len(previous_list)):
            if (previous_list[index] == current_item):
                count += 1
            else:
                total_str += str(count) + str(current_item)
                current_item = previous_list[index]
                count = 1
            if (index == len(previous_list)-1):
                total_str += str(count) + str(current_item)
        return total_str


"""
# Test the program: Expected "1"
N = 1
s = Solution()
print(s.countAndSay(N))
"""

# Expected "11"
N = 2
s = Solution()
print(s.countAndSay(N))