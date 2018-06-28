SELECT *
FROM cinema
WHERE description <> 'boring' AND id % 2 <> 0
ORDER BY rating DESC;
