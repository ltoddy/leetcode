SELECT w1.Id
FROM Weather w1
  JOIN Weather w2 ON w1.Temperature > w2.Temperature AND DATEDIFF(w1.RecordDate, w2.RecordDate) = 1;
