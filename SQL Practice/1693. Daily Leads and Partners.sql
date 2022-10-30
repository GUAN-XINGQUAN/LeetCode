/*
SQL syntax:
    

SQL syntax:
   
Idea:
    count the unique lead_id and unique partner_id_id, then group by the date_id and make_name
*/

SELECT date_id, make_name, COUNT(DISTINCT lead_id) AS unique_leads, COUNT(DISTINCT partner_id) AS unique_partners 
FROM DailySales
GROUP BY date_id, make_name