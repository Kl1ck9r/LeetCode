
/*
Write an SQL query to find the employees who earn more than their managers.
Return the result table in any order.
*/

SELECT s2.name AS 'Employee' FROM Employee s1
JOIN Employee s2 ON s2.managerId = s1.id
WHERE s1.salary < s2.salary