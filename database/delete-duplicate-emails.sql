DELETE FROM Person
WHERE Id NOT IN
      (SELECT Id
       FROM (SELECT MIN(Id) Id
             FROM Person
             GROUP BY Email) p);
