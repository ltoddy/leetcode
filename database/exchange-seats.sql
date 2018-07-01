SELECT
  IF(IF(id % 2, id + 1, id - 1) > (SELECT COUNT(*)
                                   FROM seat),
     id,
     IF(id % 2, id + 1, id - 1)) AS `id`,
  student
FROM seat
ORDER BY id ASC;
