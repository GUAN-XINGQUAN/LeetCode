/*
SQL syntax:
    string function: LIKE
    example: find the name starting with letter "M": name LIKE 'M%'

    SQL syntax:
    IF (CONDITION, VALUE_IF_TRUE, VALUE_IF_FALSE)

    SQL syntax:
    CASE
        WHEN condition1 THEN result1
        WHEN condition2 THEN result2
        WHEN conditionN THEN resultN
        ELSE result
    END;
*/


--Approach 1--
select employee_id, 
(case when employee_id%2=1 and name not like 'M%' then salary
else 0
end) as bonus
from Employees
order by employee_id 


--Approach 2--
select employee_id, 
if (employee_id%2=1 and name not like 'M%', salary, 0) as bonus
from Employees
order by employee_id 