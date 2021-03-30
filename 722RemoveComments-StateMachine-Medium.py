class Solution:   
    def removeComments(self, source: List[str]) -> List[str]:
        inComment = None
        ans = []
        curLine = []
        for line in source:
            idx = 0
            while idx < len(line):
                if not inComment:
                    if idx == len(line) - 1:
                        curLine.append(line[idx])
                        ans.append("".join(curLine))
                        curLine = []
                        idx += 1
                    else:
                        symbol = line[idx:idx + 2]
                        if symbol == "//" or symbol == "/*":
                            idx += 2
                            inComment = symbol
                        else:
                            curLine.append(line[idx])
                            idx += 1
                else:
                    if idx == len(line) - 1:
                        if inComment == "//":
                            inComment = None
                            if len(curLine) > 0:                                
                                ans.append("".join(curLine))
                                curLine = []
                        elif inComment == "/*" and len(line) > 1 and line[-2:] == "*/":
                            inComment = None
                            if len(curLine) > 0:
                                ans.append("".join(curLine))
                                curLine = []
                        idx += 1
                    else:
                        symbol = line[idx:idx + 2]
                        if symbol == "*/" and inComment == "/*":
                            if idx == len(line) - 2 and len(curLine) > 0:
                                ans.append("".join(curLine))
                                curLine = []
                            inComment = None
                            idx += 2
                        else:
                            idx += 1
        return ans  
"""
https://leetcode.com/problems/remove-comments/
State Machine.
"""