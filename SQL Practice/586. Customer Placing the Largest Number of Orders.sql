/*
SQL syntax:

*/

SELECT customer_number FROM 
(
    SELECT customer_number, COUNT(customer_number) AS customer_count
    FROM Orders
    GROUP BY customer_number
    ORDER BY customer_count DESC
    LIMIT 1
) temp