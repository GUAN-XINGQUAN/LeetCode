/*
SQL syntax:
    UPDATE table_name
    SET column1 = value1, column2 = value2, ...
    WHERE condition;
*/

UPDATE Salary
SET sex=(
    CASE
        WHEN sex='f' THEN 'm'
        ELSE 'f'
    END
)
