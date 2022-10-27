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

class LRUCache {
public:
    LRUCache(int capacity) {
        m_capacity = capacity;
    }

    int get(int key) {
        unordered_map<int, list<pair<int, int>>::iterator>::iterator it = m_num2ListIterator.find(key);
        if (it == m_num2ListIterator.end())
            return -1;
        m_list.splice(m_list.begin(), m_list, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        unordered_map<int, list<pair<int, int>>::iterator>::iterator it = m_num2ListIterator.find(key);
        if (it != m_num2ListIterator.end())
            m_list.erase(it->second);
        m_list.push_front(make_pair(key, value));
        m_num2ListIterator[key] = m_list.begin();
        if (m_list.size() > m_capacity)
        {
            int tempKey = m_list.rbegin()->first;
            m_list.pop_back();
            m_num2ListIterator.erase(tempKey);
        }
    }
private:
    int m_capacity;
    list<pair<int, int>> m_list;
    unordered_map<int, list<pair<int, int>>::iterator> m_num2ListIterator;
}; 

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
*/