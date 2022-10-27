/*
SQL syntax:

*/

(SELECT e.employee_id
FROM Employees e LEFT JOIN Salaries s ON e.employee_id=s.employee_id
WHERE s.salary IS NULL)
UNION
(SELECT s.employee_id
FROM Salaries s LEFT JOIN Employees e ON s.employee_id=e.employee_id
WHERE e.name IS NULL)
ORDER BY employee_id