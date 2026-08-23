# Write your MySQL query statement below
SELECT 
    CASE
        WHEN id % 2 = 1 AND id + 1 IN(SELECT id FROM Seat) Then id + 1
        WHEN id % 2 = 0 then id -1
        ELSE id
    END AS id,
    student 
FROM Seat
ORDER BY id;