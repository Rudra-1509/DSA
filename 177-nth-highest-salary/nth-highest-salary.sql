-- CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
-- BEGIN
--   RETURN (
--       # Write your MySQL query statement below.
--             SELECT salary
--             FROM(
--                 SELECT 
--                 salary,
--                 DENSE_RANK() OVER(
--                     ORDER BY salary DESC
--                 ) AS rnk
--                 FROM Employee e
--             ) AS t
--             WHERE t.rnk=N
--             LIMIT 1
--   );
-- END



CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  SET N=N-1;
  RETURN (
    SELECT DISTINCT salary
    FROM Employee
    ORDER BY salary DESC
    LIMIT 1
    OFFSET N
  );
END
