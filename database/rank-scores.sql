SELECT
  Score,
  (SELECT COUNT(DISTINCT Score)
   FROM Scores
   WHERE Score >= s.Score) AS `RANK`
FROM Scores AS s
ORDER BY Score DESC;
