-- Write your PostgreSQL query statement below
SELECT
COALESCE((SELECT num
FROM MyNumbers
GROUP BY 1
HAVING count(num) = 1
ORDER BY num DESC
LIMIT 1),NULL) num