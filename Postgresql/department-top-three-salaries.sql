-- Write your PostgreSQL query statement below
WITH allInfo AS (SELECT name AS Employee,
    salary,departmentID,name FROM(
    SELECT id,name,
    salary,departmentID,
    DENSE_RANK() OVER(PARTITION BY departmentId ORDER BY salary DESC) AS count
    FROM Employee)  
WHERE count BETWEEN 1 AND 3)

SELECT d.name AS Department,
    aa.name AS Employee,
    salary FROM allInfo aa
JOIN Department d
    ON d.id =aa.departmentId  
