/*
SQL syntax:


*/

SELECT name, IF(travelled_distance IS NULL, 0, travelled_distance) AS travelled_distance
FROM Users LEFT JOIN
(
    SELECT user_id, SUM(distance) as travelled_distance
    FROM Rides
    GROUP BY user_id
) AS RidePerUser ON Users.id=RidePerUser.user_id
ORDER BY travelled_distance DESC, name ASC