CREATE FUNCTION getNthHighestSalary(N INT)
  RETURNS INT
  BEGIN
    DECLARE n1 INT;
    SET n1 = N - 1;
    RETURN (
      SELECT Salary
      FROM (SELECT DISTINCT Salary
            FROM Employee) AS t
      ORDER BY Salary DESC
      LIMIT n1, 1
    );
  END
