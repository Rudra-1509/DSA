# Write your MySQL query statement below
SELECT 
    Email
FROM
(
    SELECT
        email AS Email,
        COUNT(id) AS cnt
    FROM Person
    GROUP BY email
    HAVING cnt>1
) t;