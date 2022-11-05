/*
SQL syntax:
    NOT IN: a field is not in the values of another field
*/

SELECT NAME AS Customers
FROM Customers
WHERE id NOT IN (SELECT customerId FROM Orders)