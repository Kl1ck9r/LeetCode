/*
Write an SQL query to report the names of all the salespersons
who did not have any orders related to the company with the name "RED".
Return the result table in any order.
*/

SELECT s1.name FROM SalesPerson s1
WHERE s1.name NOT IN(
    SELECT s1.name FROM SalesPerson s1
    LEFT JOIN Orders or1 ON or1.sales_id = s1.sales_id 
    LEFT JOIN Company cm1 ON cm1.com_id = or1.com_id
    WHERE cm1.name = 'RED'
)
  