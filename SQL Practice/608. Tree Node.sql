/*
algorithm:
    if p_id is null, this node is the root node.
    if id does not show up i nthe p_id, this node is the leaf.
    all the rest nodes are inner nodes.
*/

SELECT id, 
CASE 
    WHEN p_id IS NULL THEN 'Root'
    WHEN id NOT IN (SELECT p_id FROM Tree WHERE p_id IS NOT NULL) THEN 'Leaf'
    ELSE 'Inner'
END
AS type
FROM Tree
ORDER BY id ASC