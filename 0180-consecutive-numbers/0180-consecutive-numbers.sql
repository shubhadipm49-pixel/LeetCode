# Write your MySQL query statement below

#SELECT COUNT(*) ON num as ConsecutiveNums FROM Logs WHERE num > 2;
#select  num " ConsecutiveNums" from Logs group by id having count(*)>2  
SELECT DISTINCT l1.num AS ConsecutiveNums
FROM Logs l1
JOIN Logs l2 ON l2.id = l1.id + 1
JOIN Logs l3 ON l3.id = l1.id + 2
WHERE l1.num = l2.num
  AND l2.num = l3.num; 