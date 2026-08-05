# Write your MySQL query statement below
SELECT 
    name 
FROM
(
    SELECT
        COUNT(e1.id) as cnt,
        e2.name AS name
    FROM Employee e1
    INNER JOIN Employee e2
    ON e1.managerId=e2.id
    GROUP BY e1.managerId
    HAVING cnt>=5
) t;

