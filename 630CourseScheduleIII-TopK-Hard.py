import heapq
class Solution:
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        courses.sort(key=lambda x: x[1])
        heap = []
        heapq.heapify(heap)
        time = 0
        for item in courses:
            duration = item[0]
            deadline = item[1]
            if time + duration <= deadline:
                heapq.heappush(heap, duration * (-1))
                time += duration
            elif heap and heap[0] * (-1) > duration:
                time = time - heapq.heappop(heap) * (-1) + duration
                heapq.heappush(heap, duration * (-1))
        return len(heap)
"""
https://leetcode.com/problems/course-schedule-iii/solution/
TopK. Note that courses[1] is deadline, and you can finish it ahead of time.
"""