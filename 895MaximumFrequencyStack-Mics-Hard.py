from collections import Counter
class FreqStack:
    def __init__(self):
        self.freqs = Counter()
        self.freqDict = dict()
        self.maxFreq = 0

    def push(self, x: int) -> None:
        freq = self.freqs[x] + 1
        self.freqs[x] = freq
        self.maxFreq = max(self.maxFreq, freq)     
        if freq not in self.freqDict:
            self.freqDict[freq] = []
        self.freqDict[freq].append(x)

    def pop(self) -> int:
        curPop = self.freqDict[self.maxFreq].pop()
        if not self.freqDict[self.maxFreq]:
            self.maxFreq -= 1
        self.freqs[curPop] -= 1
        return curPop

# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(x)
# param_2 = obj.pop()

"""
https://leetcode.com/problems/maximum-frequency-stack/
Mics. Maybe can solve by heaps, but too complicated. 
"""