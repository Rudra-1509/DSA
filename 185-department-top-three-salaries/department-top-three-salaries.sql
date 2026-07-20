# Write your MySQL query statement below
SELECT 
    Department,Employee,Salary
FROM (
    SELECT 
        d.name AS Department,
        e.name AS Employee,
        e.salary AS Salary,
        DENSE_RANK() OVER(
            PARTITION BY d.name
            ORDER BY SALARY DESC
        ) AS rank_num
    FROM Employee e
    INNER JOIN Department d
    ON e.departmentId=d.id
) as t
WHERE t.rank_num<=3;