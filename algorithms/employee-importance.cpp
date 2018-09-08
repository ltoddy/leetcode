/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution
{
private:
    int MAX_EMPLOYEES = 2010;
    vector<Employee> company = vector<Employee>(this->MAX_EMPLOYEES);

    int getImportance(Employee boss)
    {
        if (boss.subordinates.empty()) return boss.importance;

        int res = 0;
        for (int subordinateId : boss.subordinates)
            res += getImportance(this->company[subordinateId]);
        return res + boss.importance;
    }

public:
    int getImportance(vector<Employee*> employees, int id)
    {
        for (Employee* employee : employees)
            this->company[employee->id] = *employee;
        Employee boss = this->company[id];
        return this->getImportance(boss);
    }
};
