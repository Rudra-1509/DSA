# Write your MySQL query statement below
DELETE p
FROM Person p
INNER JOIN (
    SELECT 
        email,
        MIN(id) as first_id
    FROM Person
    GROUP BY email
) AS t
ON t.email=p.email
WHERE t.first_id<>p.id