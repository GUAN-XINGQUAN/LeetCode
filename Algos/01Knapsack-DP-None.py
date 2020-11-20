def topDownHelper(dp, idx, cap, p, w):
    if idx >= len(p):
        return 0
    if dp[idx][cap] != 0:
        return dp[idx][cap]

    profit = p[idx]
    weight = w[idx]

    # Profit1 will include the current item's profit, while profit2 won't.
    profit1, profit2 = 0, 0
    if cap >= weight:
        profit1 = topDownHelper(dp, idx + 1, cap - weight, p, w) + profit
    profit2 = topDownHelper(dp, idx + 1, cap, p, w)
    dp[idx][cap] = max(profit1, profit2)
    return dp[idx][cap]


def topDown(p, w, c):
    # We'll apply a recursive method for the solution.
    # Maybe not so recursive.
    # Corner cases are not considered. i.e. invalid cap, null profits, etc.
    cap = [0 for _ in range(c + 1)]
    dp = [list(cap) for _ in range(len(p))]
    # dp[idx][cap],
    # Where idx represents "from the current idx, all the following idx will
    # be considered".
    # cap represents the current available capacity.
    return topDownHelper(dp, 0, c, p, w)


def bottomUp(p, w, c):
    cap = [0 for _ in range(c + 1)]
    dp = [list(cap) for _ in range(len(p))]
    # dp[idx][cap],
    # Where idx represents "to the current idx, all the previous idx will
    # be considered".
    # cap represents the current available capacity.
    for idx in range(len(p)):
        for cap in range(c + 1):
            if cap == 0:
                dp[idx][cap] = 0
            else:
                profit, weight = p[idx], w[idx]
                # Profit1 will include the current item's profit,
                # while profit2 won't.
                profit1, profit2 = 0, 0
                if idx == 0:
                    if cap >= weight:
                        dp[idx][cap] = profit
                    else:
                        dp[idx][cap] = 0
                else:
                    if cap >= weight:
                        profit1 = dp[idx - 1][cap - weight] + profit
                    profit2 = dp[idx - 1][cap]
                    dp[idx][cap] = max(profit1, profit2)
    return dp[len(p) - 1][c]


if __name__ == "__main__":
    profits = [1, 6, 10, 16, 3, 4, 8]
    weights = [1, 2, 3, 5, 2, 1, 4]
    cap = 15
    print(topDown(profits, weights, cap))
    print(bottomUp(profits, weights, cap))
