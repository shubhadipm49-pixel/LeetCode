# Write your MySQL query statement below

SELECT E.employee_id 
FROM Employees E
LEFT JOIN Salaries S
ON E.employee_id = S.employee_id
WHERE S.employee_id IS NULL

UNION

SELECT S.employee_id
FROM Salaries S
LEFT JOIN Employees E
ON S.employee_id = E.employee_id
WHERE E.employee_id IS NULL
ORDER BY employee_id;