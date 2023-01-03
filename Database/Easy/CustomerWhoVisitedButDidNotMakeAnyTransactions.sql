
/*
Write an SQL query to find the IDs of the users who visited without making 
any transactions and the number of times they made these types of visits.
Return the result table sorted in any order.
*/


SELECT customer_id,COUNT(v.visit_id) AS count_no_trans
FROM Visits v
WHERE v.visit_id not in (select t.visit_id from Transactions t)
GROUP BY customer_id
ORDER BY count_no_trans DESC 