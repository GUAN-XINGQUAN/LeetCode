#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>

// #include "NestedVectorVisualization.h"

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;
        unordered_map<Node*, Node*> nodeMap;
        queue<Node*> nodeQueue({ node });
        Node* clone = new Node(node->val);
        nodeMap[node] = clone;
        while (!nodeQueue.empty())
        {
            Node* temp = nodeQueue.front();
            nodeQueue.pop();
            for (Node* eachNeighbor : temp->neighbors)
            {
                if (nodeMap.count(eachNeighbor) == 0)
                {
                    nodeMap[eachNeighbor] = new Node(eachNeighbor->val);
                    nodeQueue.push(eachNeighbor);
                }
                nodeMap[temp]->neighbors.push_back(nodeMap[eachNeighbor]);
            }
        }
        return clone;
    }
};


int main()
{

}