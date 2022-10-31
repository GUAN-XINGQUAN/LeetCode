/*
SQL syntax:

*/


-- Approach 1: use subquery
SELECT name, balance 
FROM Users INNER JOIN
(
SELECT account, SUM(amount) AS balance
FROM Transactions
GROUP BY account
HAVING SUM(amount)>10000
) AS TransactionAccount
ON Users.account=TransactionAccount.account


-- Approach 2: inner join and then filter
SELECT u.name, SUM(amount) AS balance    
FROM Users u INNER JOIN Transactions t ON u.account=t.account
GROUP BY t.account
HAVING SUM(amount)>10000