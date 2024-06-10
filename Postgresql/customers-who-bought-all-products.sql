-- Write your PostgreSQL query statement below
SELECT
    customer_id
FROM
    customer
GROUP BY customer_id
HAVING
    COUNT(DISTINCT product_key) = (SELECT COUNT(DISTINCT product_key) FROM product)