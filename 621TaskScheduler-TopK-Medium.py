from collections import deque
import heapq
class Solution:
    def emptyWaitingList(self, waitingList):
        for elem in waitingList:
            if elem:
                return False
        return True
    
    def leastInterval(self, tasks: List[str], n: int) -> int:
        ans = []
        waitingList = deque()
        di = dict()
        for task in tasks:
            di[task] = di[task] + 1 if task in di else 1
        heap = list()
        heapq.heapify(heap)
        for task in di:
            heapq.heappush(heap, (-1 * di[task], task))
        while True:
            curTask = None
            while len(waitingList) > n:
                backup = waitingList.popleft()
                if backup != None and backup[0] < 0:
                    heapq.heappush(heap, backup)
            
            if not heap and self.emptyWaitingList(waitingList):
                break
            if heap:
                curTask = heapq.heappop(heap)
            
            ans.append(curTask)
            if curTask != None:
                curTask = (curTask[0] + 1, curTask[1])
                if curTask[0] > -1:
                    curTask = None
            waitingList.append(curTask)
        return len(ans)
"""
https://leetcode.com/problems/task-scheduler/
TopK(heap). By holding a waitingList whose length is n,
and pushing even None values into the waitingList,
we can decently handle the CD time. 
"""