/*
Algorithm:
    order the salary from the highest to the lowest using ORDER BY <col_name> DESC
    then select the 2nd one using LIMIT 1 OFFSET 1
    be cautious that if the 2nd one does not exist, it should return null. In this case, use another SELECT as the outmost query.

*/

SELECT (
    SELECT DISTINCT salary
    FROM Employee
    ORDER BY salary DESC
    LIMIT 1 OFFSET 1
) AS SecondHighestSalary