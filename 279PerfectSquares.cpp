#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>

// #include "nestedVectorIntVisualization.h"
// #include "nestedVectorCharVisualization.h"
// #include "treeVisualizationinPreorder.h"
// #include "listNodeVisualization.h"

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        // n is alwasy positive

        // BFS
        queue<int> numQueue({ n });
        vector<int> squares = generateSquares(n);
        //for (int i = 0; i < squares.size(); i++)
        //    cout << squares[i] << endl;
        int res = 0;
        while (!numQueue.empty())
        {
            res++;
            for (int i = numQueue.size(); i > 0; i--)
            {
                int temp = numQueue.front();
                numQueue.pop();
                //cout << temp << endl;
                for (auto eachSquare : squares)
                {
                    //cout << eachSquare << endl;
                    int newTarget = temp - eachSquare;
                    if (newTarget < 0)
                        break;
                    if (newTarget == 0)
                        return res;
                    numQueue.push(newTarget);
                }
            }
        }
        return res;
    }
    vector<int> generateSquares(int n)
    {
        vector<int> res;
        int upper = sqrt(n);
        for (int i = 1; i <= upper; ++i)
            res.push_back(i * i);
        return res;
    }
};


int main()
{
    Solution sol;

    int res = sol.numSquares(5);

    cout << res << endl;
}