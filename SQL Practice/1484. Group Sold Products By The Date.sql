/*
SQL syntax:
    GROUP_CONCAT([DISTINCT] col_name [ORDER BY] col_name [SEPARATOR] string_value): concat values in multiple rows into the same cell
*/

SELECT sell_date, COUNT(DISTINCT product) AS num_sold,
GROUP_CONCAT(DISTINCT product ORDER BY product) AS products
FROM Activities
GROUP BY sell_date
ORDER BY sell_date