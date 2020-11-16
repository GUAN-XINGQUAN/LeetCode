class BrowserHistory:

    def __init__(self, homepage: str):
        self.curIdx = 0
        self.lastIdx = 0
        self.hist = [homepage]        

    def visit(self, url: str) -> None:
        # Danger
        if self.curIdx < self.lastIdx or self.lastIdx + 1 < len(self.hist): # Dead here last time: missing "or self.lastIdx + 1 < len(self.hist)"
            self.curIdx += 1
            self.lastIdx = self.curIdx
            self.hist[self.curIdx] = url
        else:
            self.curIdx += 1
            self.lastIdx += 1
            self.hist.append(url)        

    def back(self, steps: int) -> str:
        if self.curIdx == -1:
            return None
        else: 
            while steps > 0:
                steps -= 1
                self.curIdx -= 1
                if self.curIdx <= -1:
                    if self.hist:
                        self.curIdx = 0
                        return self.hist[self.curIdx]
                    else:
                        self.curIdx = -1
                        return None
            return self.hist[self.curIdx]          
        

    def forward(self, steps: int) -> str:
        while steps > 0:
            steps -= 1
            if self.curIdx + 1 > self.lastIdx:
                return self.hist[self.curIdx] # + str(self.curIdx) + str(self.lastIdx)
            self.curIdx += 1
        return self.hist[self.curIdx]
        


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)

"""
https://leetcode.com/problems/design-browser-history/submissions/
"""