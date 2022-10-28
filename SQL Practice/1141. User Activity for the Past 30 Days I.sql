/*
SQL syntax:
    DATEDIFF(date1, date2): returns date1 - date2
*/

SELECT activity_date AS day, COUNT(DISTINCT user_id) AS active_users
FROM Activity
WHERE DATEDIFF('2019-07-27', activity_date)<=29 AND DATEDIFF('2019-07-27', activity_date)>=0
GROUP BY activity_date