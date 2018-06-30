SELECT
  D.Name    AS `Department`,
  E1.Name   AS `Employee`,
  E1.Salary AS `Salary`
FROM Employee AS `E1`
  JOIN Department AS `D` ON E1.DepartmentId = D.Id
WHERE E1.Salary IN (SELECT MAX(E2.Salary)
                    FROM Employee AS `E2`
                    WHERE E1.DepartmentId = E2.DepartmentId);
