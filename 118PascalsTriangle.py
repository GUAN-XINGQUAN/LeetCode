class Solution:
    def generate(self, numRows):
        """

        :param numRows: int
        :return: List[List[int]]
        """
        triangle = []
        for row_num in range(numRows):
            row = [0 for _ in range(row_num+1)]
            row[0] = 1
            row[-1] = 1

            for col_num in range(1, len(row)-1):
                row[col_num] = triangle[row_num-1][col_num-1] + triangle[row_num-1][col_num]
            triangle.append(row)
        return triangle



# Expected "11"
N = 1
s = Solution()
print(s.generate(N))
