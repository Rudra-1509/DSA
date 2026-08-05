
SELECT 
    ROUND(COUNT(DISTINCT a.player_id)/
    (SELECT COUNT(DISTINCT player_id) from Activity),2) AS fraction
FROM Activity AS a
INNER JOIN (
    SELECT 
        player_id,
        MIN(event_date) AS first_login
    FROM Activity
    GROUP BY player_id
) AS t
ON a.player_id=t.player_id 
AND DATEDIFF(a.event_date,t.first_login)=1
