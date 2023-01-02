
/*
Write an SQL query to report the IDs of all the employees with missing information. The information of an employee is missing if:

The employee's name is missing, or
The employee's salary is missing.
Return the result table ordered by employee_id in ascending order.

The query result format is in the following example.
*/
 
SELECT employee_id FROM Employees WHERE employee_id NOT IN(SELECT employee_id FROM Salaries)
UNION 
SELECT employee_id FROM Salaries WHERE employee_id NOT IN (SELECT employee_id FROM Employees)
ORDER BY employee_id ASC

-- -----------------------------------
-- OR Alternatively you can write so --

SELECT e.employee_id FROM Employees e
LEFT JOIN Salaries s ON s.employee_id = e.employee_id
WHERE s.salary IS NULL

UNION 

SELECT s1.employee_id FROM Employees e1
RIGHT JOIN Salaries s1 ON s1.employee_id = e1.employee_id
WHERE e1.name IS NULL 
ORDER BY employee_id ASC 

