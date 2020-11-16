from collections import deque
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        dependencies = dict()
        ins = [0 for _ in range(numCourses)]
        queue = deque()
        ans = []
        for relation in prerequisites:
            first = relation[1]
            second = relation[0]
            if first in dependencies:
                dependencies[first].add(second)
            else:
                dependencies[first] = {second, }
            ins[second] += 1
        
        for idx in range(numCourses):
            if ins[idx] == 0:
                queue.append(idx)
        
        while queue:
            course = queue.popleft()
            ans.append(course)
            if len(ans) == numCourses:
                return True
            if course not in dependencies:
                continue
            for second in dependencies[course]:
                ins[second] -= 1
                if ins[second] == 0:
                    queue.append(second)
        return False
"""
https://leetcode.com/problems/course-schedule/
Topological Sort. Indegree matters. firstCourse -> secondCourse, indegree(secondCourse) = 1, indegree(firstCourse) = 0.
Everytime a new course whose indegree is zero, then the course is selectable. 
Remove the corresponding post-course's indegree by -1.
"""