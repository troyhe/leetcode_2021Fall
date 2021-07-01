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
    void helper(const vector<Employee*>& employees, unordered_map<int, int>& idDic, int target, int& importance){
        importance += employees[idDic[target]]->importance;
        for (int i = 0; i < employees[idDic[target]]->subordinates.size(); i++){
            helper(employees, idDic, employees[idDic[target]]->subordinates[i], importance);
        }
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        // Find the employee with id
        unordered_map<int, int> idDic;// <id, idx>
        for (int i = 0; i < employees.size(); i++){
            idDic[employees[i]->id] = i;
        }
        int sum = 0;
        helper(employees, idDic, id, sum);
        return sum;
    }
};
