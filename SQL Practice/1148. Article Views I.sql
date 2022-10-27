/*
Solution:
    keep the rows where the author and viewer is the same
    then select the unique authors from the author_id column
*/

SELECT DISTINCT author_id AS id
FROM Views
WHERE author_id=viewer_id
ORDER BY id ASC