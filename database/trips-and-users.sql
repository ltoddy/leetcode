SELECT
  t.Request_at                         AS `Day`,
  ROUND(SUM(CASE WHEN Status = 'completed'
    THEN 0
            ELSE 1 END) / COUNT(*), 2) AS `Cancellation Rate`
FROM Trips AS `t`
  INNER JOIN Users AS `u` ON u.Users_Id = t.Client_Id AND u.Banned = 'No'
WHERE t.Request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY t.Request_at;
