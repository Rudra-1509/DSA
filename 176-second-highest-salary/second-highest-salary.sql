# Write your MySQL query statement below
SELECT (
    SELECT salary
    FROM (
        SELECT 
        id,salary,
        DENSE_RANK() OVER(
            ORDER BY salary DESC
        ) as rnk
        FROM Employee e
    ) AS t
    WHERE t.rnk=2
    LIMIT 1
) 
AS SecondHighestSalary