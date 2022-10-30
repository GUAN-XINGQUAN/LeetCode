/*
SQL syntax:

person --> star
1 --> 0
0 --> 1
0 --> 2
1 --> 2 


*/

SELECT user_id, COUNT(DISTINCT follower_id) AS followers_count
FROM Followers
GROUP BY user_id