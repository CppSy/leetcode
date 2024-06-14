-- Write your PostgreSQL query statement below
WITH last_6_days AS (
    SELECT DISTINCT visited_on
    FROM Customer
    ORDER BY visited_on ASC
    OFFSET 6
)

SELECT c1.visited_on,
        SUM(c2.amount) AS amount,
        ROUND(SUM(c2.amount) / 7., 2)  AS average_amount
FROM last_6_days AS c1
INNER JOIN Customer AS c2
ON c2.visited_on BETWEEN c1.visited_on - 6 AND c1.visited_on
GROUP BY c1.visited_on;