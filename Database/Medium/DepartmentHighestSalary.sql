
/*
Write an SQL query to find employees who have 
the highest salary in each of the departments.
Return the result table in any order.
*/

SELECT s1.name AS 'Department',
       s2.name  AS 'Employee',
       s2.salary
FROM Employee s2,Department s1
WHERE s2.departmentId=s1.id and 
s2.Salary = (SELECT max(salary) FROM Employee s3 WHERE s1.id = s3.departmentId )