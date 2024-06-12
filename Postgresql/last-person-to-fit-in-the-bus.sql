-- Write your PostgreSQL query statement below
SELECT person_name
FROM (
    SELECT person_id, 
           person_name, 
           SUM(weight) OVER (ORDER BY turn) AS cum_sum
     FROM Queue
     ORDER BY turn DESC
)
WHERE cum_sum <= 1000
LIMIT 1