/*

Idea:



*/

// brute force approach: nested for loop
// time O(m*n)
// space O(1)
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int sum = 0;
        for (int index1=0; index1 < arr1.size(); index1++)
        {
            bool flag = true;
            for (int index2=0; index2 < arr2.size(); index2++)
            {
                if (abs(arr1[index1] - arr2[index2]) <= d)
                {
                    flag = false;
                    continue;
                }
            }
            if (flag)
                sum++;
        }
        return sum;
    }
};


// binary search: 
// time O(n log n)
// space O(1)
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int sum = 0;
        sort(arr2.begin(), arr2.end());
        for (int i = 0; i < arr1.size(); i++)
        {
            int target = arr1[i];
            int value = getClosest(arr2, target);
            if (abs(target - value) > d)
                sum++;
        }
        return sum;
    }
    
    
    int getClosest(vector<int>& arr2, int target) 
    {
        if (target < arr2[0])
            return arr2[0];
        if (target > arr2.back())
            return arr2.back();
        int left = 0, right = arr2.size()-1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr2[mid] == target)
                return arr2[mid];
            else if (arr2[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return abs(arr2[left] - target) <= abs(arr2[right] - target) ? arr2[left] : arr2[right];
    }
};