/*
SQL syntax:
    IS NULL: evaluate whether a field is null value
*/

SELECT NAME
FROM Customer
WHERE referee_id<>2 OR referee_id IS NULL