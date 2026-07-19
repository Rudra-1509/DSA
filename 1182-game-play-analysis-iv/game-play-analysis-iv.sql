# Write your MySQL query statement below


SELECT 
    ROUND(COUNT(*)/(
        SELECT COUNT(DISTINCT player_id) FROM Activity
    ),2)  AS fraction
FROM Activity a1
INNER JOIN (
    SELECT
        player_id,MIN(event_date) as init_login
    FROM Activity
    GROUP BY player_id
)   AS a
ON a.player_id=a1.player_id
WHERE DATEDIFF(a1.event_date,a.init_login)=1