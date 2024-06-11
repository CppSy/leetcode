WITH managers AS(
    SELECT reports_to AS employee_id,
            COUNT(reports_to) AS reports_count,
            ROUND(AVG(age)) AS average_age
    FROM Employees
    WHERE reports_to IS NOT NULL
    GROUP BY reports_to
)

SELECT employee_id,
        name,
        reports_count,
        average_age
FROM managers AS m
INNER JOIN Employees AS e
USING(employee_id)
ORDER BY employee_id;