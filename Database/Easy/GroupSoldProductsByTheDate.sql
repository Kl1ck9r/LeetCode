# Write your MySQL query statement below

# You can replace group_concat with string_agg in postgresql 

SELECT sell_date, count( DISTINCT product ) AS num_sold ,  
GROUP_CONCAT( DISTINCT product ORDER BY product) AS products 
FROM Activities
GROUP BY sell_date
ORDER BY sell_date ASC;
