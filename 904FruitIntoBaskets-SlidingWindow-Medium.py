class Solution:
    def totalFruit(self, tree: List[int]) -> int:
        leftIdx = 0
        baskets = dict()
        maxNum = 0
        for rightIdx in range(len(tree)):
            rightType = tree[rightIdx]
            baskets[rightType] = baskets.setdefault(rightType, 0) + 1
            
            # judge if leftIdx needs to be moved
            while len(baskets) > 2:
                leftType = tree[leftIdx]
                baskets[leftType] -= 1
                if baskets[leftType] < 1:
                    del baskets[leftType]
                leftIdx += 1
            
            # count
            maxNum = max(maxNum, self.addDict(baskets))
        return maxNum    
    
    def addDict(self, myDict):
        s = 0
        for key in myDict:
            s += myDict[key]
        return s
    
"""
https://leetcode.com/problems/fruit-into-baskets/
A sliding window problem. 
"""