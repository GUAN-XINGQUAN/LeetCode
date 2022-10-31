/*
SQL syntax:
    SELECT column_name(s)
    FROM table_name
    WHERE condition
    GROUP BY column_name(s)
    HAVING condition
    ORDER BY column_name(s);
*/

-- Approach 1: use subquery
SELECT email AS Email
FROM
(
    SELECT email, COUNT(email) AS email_count
    FROM Person GROUP BY email
) AS EmailCount
WHERE email_count>1

-- Approach 2: use HAVING
SELECT email AS Email
FROM Person
GROUP BY Email
HAVING COUNT(Email)>1