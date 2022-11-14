/*
binary search to get the number of soilders in each row.
store the pair {number of soilders, row index} into a vector
sorte the vector to retrieve the first k row indices.
*/

// m: number of rows
// n: number of columns
// time O(m log n) + O(m log mn) == O(m log mn)
// space O(m)
bool cmp(const vector<int>& v1, const vector<int>& v2)
{
    if (v1[0] < v2[0])
        return true;
    else if (v1[0] == v2[0])
        return v1[1] < v2[1];
    else
        return false;
}

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<vector<int>> soilderNumAndIndex;
        for (int i = 0; i < mat.size(); i++)
        {
            int numSoilders = getNumSoilders(mat[i]);
            soilderNumAndIndex.push_back({numSoilders, i});
        }
        sort(soilderNumAndIndex.begin(), soilderNumAndIndex.end(), cmp);
        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(soilderNumAndIndex[i][1]);
        }
        return res;
    }
    
    int getNumSoilders(vector<int>& arr)
    {
        if (arr.front() == 0)
            return 0;
        if (arr.back() == 1)
            return arr.size();
        int left = 0, right = arr.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] == 0)
                right = mid;
            else if (arr[mid] > 0)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};


/*


    0   1   2   3   4

0   1   1   0   0   0
1   1   1   1   1   0
2   1   0   0   0   0
3   1   1   0   0   0
4   1   1   1   1   1


res = [2   0   3]


binary search:
    smallest soilders
    

    0   1   2   3   4   5
    1   1   1   0   0   null
    L       M           R
    L   M   R
            L|R

    RETURN 3
    
    0   1   2   3   4   5
    1   1   1   1   1   NULL
    L       M           R
                L   M   R
                        L|R
                    
    RETURN 4
    
    
    0   1   2   3   4
    0   0   0   0   0
    L       M       R
    L   M   R
    L   R
    L|R
    
    RETURN 0
    
    0   1   2   3   4   5
    1   1   1   1   0   null
    
    L       M           R
                L   M   R
                L   R
                    L|R
                    
    RETURN 4

*/