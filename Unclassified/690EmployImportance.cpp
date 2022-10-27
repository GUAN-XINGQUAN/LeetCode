#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>

// #include "NestedVectorCharVisualization.h"

using namespace std;

// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

// BFS
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int sumImport = 0;
        unordered_map<int, Employee*> idEmploy;
        for (Employee* eachEmpoly : employees)
            idEmploy[eachEmpoly->id] = eachEmpoly;
        queue<int> employID({ id });
        while (!employID.empty())
        {
            int tempID = employID.front();
            employID.pop();
            sumImport += idEmploy[tempID]->importance;
            for (int eachSub : idEmploy[tempID]->subordinates)
                employID.push(eachSub);
        }
        return sumImport;
    }
};