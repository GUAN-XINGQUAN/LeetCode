/*
SQL syntax:
    CONCAT(string1, string2): concat two strings together

SQL syntax:
    UPPER(string): convert all characters in the string to capital letters
    LOWER(string): convert all characters in the string to lower letters
    LEFT(string, number): return the number of characters from the left
    SUBSTRING(string_name, start, num_characters): return the string_name[start, start+num_characters-1]
*/


SELECT user_id,  CONCAT(UPPER(LEFT(name, 1)), LOWER(SUBSTRING(name, 2, LENGTH(name))))  as name
FROM Users
ORDER BY user_id 