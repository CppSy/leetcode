SELECT query_name,
       ROUND(SUM(rating::numeric / position) / COUNT(result), 2)                  quality,
       ROUND(100. * COUNT(rating) FILTER ( WHERE rating < 3 ) / COUNT(rating), 2) poor_query_percentage
FROM Queries
WHERE query_name IS NOT NULL
GROUP BY query_name