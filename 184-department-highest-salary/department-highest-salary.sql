# Write your MySQL query statement below


SELECT 
    Department,
    Employee,
    Salary
FROM (
    SELECT
    d.name AS Department,
    e.name AS Employee,
    e.salary AS Salary,
    RANK() OVER(
        PARTITION BY d.id
        ORDER BY e.salary DESC
    ) as rnk
    FROM Employee e
    INNER JOIN Department d
    ON e.departmentId=d.id
) AS t
WHERE rnk=1;