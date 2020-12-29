def solution(arr):
    newArr = []
    for emp in arr:
        for t in emp:
            newArr.append(t)
    newArr.sort()
    if not newArr:
        return []
    ans = []
    maxEnd = newArr[0][1]
    for interval in newArr:
        startTime = interval[0]
        endTime = interval[1]
        if startTime > maxEnd:
            ans.append([maxEnd, startTime])
            maxEnd = endTime
        elif startTime <= maxEnd and endTime <= maxEnd:
            pass
        elif startTime <= maxEnd and endTime > maxEnd:
            maxEnd = endTime
    return ans


if __name__ == "__main__":
    print(solution([[[1, 3], [6, 7]], [[2, 4]], [[2, 5], [9, 12]]]))
    print(solution([[[1,2],[5,6]],[[1,3]],[[4,10]]]))

"""
http://shibaili.blogspot.com/2019/02/759-employee-free-time.html
Merging Intervals.
Using a scanning line (maxEnd) to make virtual merging. 
"""
