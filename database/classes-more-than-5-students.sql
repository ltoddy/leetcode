SELECT class
FROM (SELECT DISTINCT *
      FROM courses) as c
GROUP BY c.class
HAVING COUNT(student) >= 5;
