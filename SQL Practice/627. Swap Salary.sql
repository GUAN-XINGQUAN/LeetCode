/*
SQL syntax:
    UPDATE table_name
    SET column1 = value1, column2 = value2, ...
    WHERE condition;
*/

update Salary
set sex=(
    case
        when sex='f' then 'm'
        else 'f'
    end
)
