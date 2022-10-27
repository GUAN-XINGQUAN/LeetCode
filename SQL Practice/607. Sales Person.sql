/*
Solution:
    select the sales who did a business with company 'RED' --> list
    then select the sales who is not in the list
*/

SELECT s.name
FROM SalesPerson s
WHERE s.sales_id NOT IN
    (
    SELECT sales_id   
    FROM Orders o LEFT JOIN Company c ON o.com_id=c.com_id
    WHERE c.name='RED'
    )