/* Write a solution to find the average selling price for each product. average_price should be rounded to 2 decimal places.
Return the result table in any order.
The result format is in the following example. */


SELECT p.product_id, COALESCE(ROUND(SUM(u.units*p.price)/SUM(u.units)::decimal, 2), 0)average_price
FROM Prices p
LEFT JOIN UnitsSold u
ON u.product_id = p.product_id AND u.purchase_date BETWEEN p.start_date AND p.end_date
GROUP BY p.product_id