/*
SQL syntax:
    DELETE column_name FROM table_name WHERE condition;
SQL syntax: self-join
    SELECT column_name(s)
    FROM table1 T1, table1 T2
    WHERE condition;
*/

DELETE p1 FROM Person p1,
    Person p2
WHERE
    p1.Email = p2.Email AND p1.Id > p2.Id