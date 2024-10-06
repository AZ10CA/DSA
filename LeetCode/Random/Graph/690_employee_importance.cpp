/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        // Time: O(n), Space: O(n)
        unordered_map<int, Employee*> id_to_emp;

        for(auto emp: employees)
            id_to_emp[emp->id] = emp;


        queue<Employee*> to_visit;
        to_visit.push(id_to_emp[id]);

        int sum = 0;
        while(!to_visit.empty()){
            auto top = to_visit.front();
            to_visit.pop();
            sum += top->importance;

            for(auto id: top->subordinates)
                to_visit.push(id_to_emp[id]);
        }

        return sum;
    }
};