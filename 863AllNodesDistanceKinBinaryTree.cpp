#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <list>

// #include "nestedVectorIntVisualization.h"
// #include "nestedVectorCharVisualization.h"
 #include "treeVisualizationinPreorder.h"
// #include "listNodeVisualization.h"

using namespace std;

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if (root == nullptr)
            return {};
        vector<int> res;
        unordered_map<TreeNode*, vector<TreeNode*>> node2Neighbors;
        generateNeighbors(root, nullptr, node2Neighbors);
        unordered_set<TreeNode*> visit({ target });
        queue<TreeNode*> nodeQueue({ target });
        
        while (!nodeQueue.empty())
        {
            if (K == 0)
            {
                for (int i = nodeQueue.size(); i > 0; i--)
                {
                    TreeNode* temp = nodeQueue.front();
                    res.push_back(temp->val);
                    nodeQueue.pop();
                }
                return res;
            }
            for (int i = nodeQueue.size(); i > 0; i--)
            {
                TreeNode* node = nodeQueue.front();
                nodeQueue.pop();
                for (auto each : node2Neighbors[node])
                {
                    if (visit.count(each) != 0)
                        continue;
                    visit.insert(each);
                    nodeQueue.push(each);
                }
            }
            K--;
        }
        return res;
    }
    void generateNeighbors(TreeNode* node, TreeNode* parent, unordered_map<TreeNode*, vector<TreeNode*>>& node2Neighbors)
    {
        if (node == nullptr)
            return;
        if (node2Neighbors.count(node))
            return;
        if (parent != nullptr)
        {
            node2Neighbors[parent].push_back(node);
            node2Neighbors[node].push_back(parent);
        }
        generateNeighbors(node->left, node, node2Neighbors);
        generateNeighbors(node->right, node, node2Neighbors);
    }
};


int main()
{
    Solution sol;

    
}