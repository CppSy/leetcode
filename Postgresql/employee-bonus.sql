/* Write a solution to report the name and bonus amount of each employee with a bonus less than 1000.
Return the result table in any order. */

SELECT e.name, b.bonus
FROM Employee as e
LEFT JOIN Bonus as b
ON e.empId = b.empId
WHERE b.Bonus < 1000 OR b.bonus IS NULL;