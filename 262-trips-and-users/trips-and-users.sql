# Write your MySQL query statement below
SELECT 
    request_at AS `Day`,
    ROUND(
        SUM(status IN ('cancelled_by_driver','cancelled_by_client')) / COUNT(*),
        2
    ) AS `Cancellation Rate`
FROM Trips t
WHERE 
client_id IN (
    SELECT users_id AS client_id
    FROM Users
    WHERE role='client'
    AND banned='No'
)
AND driver_id IN
(
    SELECT users_id AS users_id
    FROM Users
    WHERE role='driver' 
    AND banned='No'
)
AND request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY request_at;