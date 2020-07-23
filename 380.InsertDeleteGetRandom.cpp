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
// #include "treeVisualizationinPreorder.h"
// #include "listNodeVisualization.h"

using namespace std;


class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m_num2Index.count(val) != 0)
            return false;
        m_nums.push_back(val);
        m_num2Index[val] = m_nums.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (m_num2Index.count(val) == 0)
            return false;
        int last = m_nums.back();
        int index = m_num2Index[val];
        m_nums[index] = last;
        m_num2Index[last] = index;
        m_nums.pop_back();
        m_num2Index.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int index = rand() % m_nums.size();
        return m_nums[index];
    }
private:
    unordered_map<int, int> m_num2Index;
    vector<int> m_nums;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */