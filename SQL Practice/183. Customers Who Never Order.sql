/*
SQL syntax:
    NOT IN: a field is not in the values of another field
*/

select name as Customers
from Customers
where id not in (select customerId from Orders)