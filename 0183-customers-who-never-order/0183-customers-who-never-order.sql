# Write your MySQL query statement below
SELECT e.name AS Customers 
FROM Customers e
LEFT JOIN Orders o
ON e.id = o.customerId
WHERE customerId is NULL;

