-- Write your PostgreSQL query statement below
WITH countOfNumber AS (
SELECT user_id,
COUNT(*) AS count FROM  MovieRating 
GROUP BY user_id),

userIdMAX AS (SELECT user_id FROM MovieRating 
GROUP BY user_id    
HAVING COUNT(*)=(SELECT MAX(count) FROM countOfNumber)),

avgMovie AS (SELECT title ,AVG(rating) AS raiting FROM Movies m
JOIN MovieRating mr
    ON mr.movie_id=m.movie_id
WHERE created_at::text LIKE '2020-02-%'
GROUP BY mr.movie_id ,title )

(SELECT title AS results FROM avgMovie
WHERE raiting=(SELECT MAX(raiting) FROM avgMovie)
ORDER BY title LIMIT 1
)
    UNION ALL
(SELECT name AS results FROM userIdMAX u 
JOIN Users uu
    ON uu.user_id=u.user_id
ORDER BY name LIMIT 1)
