/*
SQL syntax:
    YEAR(time): return the year segment of the time
    MONTH(time): return the month segment of the time
    DAY(time): return the date segment of the time
*/

SELECT user_id, MAX(time_stamp) AS last_stamp
FROM Logins
WHERE YEAR(time_stamp)='2020'
GROUP BY user_id