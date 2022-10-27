/*
SQL syntax:
    IS NULL: evaluate whether a field is null value
*/

select name
from Customer
where referee_id<>2 or referee_id is NULL