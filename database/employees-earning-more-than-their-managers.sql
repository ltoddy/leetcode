SELECT E1.Name `Employee`
FROM Employee as `E1`, Employee as `E2`
WHERE E1.Salary > E2.Salary AND E1.ManagerId = E2.Id;
