/*
algorithm:
    Join the Person table with Address table. 
    All rows in Person table should be kept and their associated records in Address table (if exists) is appended to the right.
    Such an operation is LEFT JOIN in SQL.
*/

SELECT firstName, lastName, city, state
FROM Person p LEFT JOIN Address a ON p.personId=a.personId