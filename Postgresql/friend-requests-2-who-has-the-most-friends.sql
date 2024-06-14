-- Write your PostgreSQL query statement below
WITH CountOfFriends AS
(
    SELECT requester_id as id
    FROM RequestAccepted
    UNION ALL
    SELECT accepter_id as id
    FROM RequestAccepted
)

SELECT id, COUNT(id) as num
FROM CountOfFriends
GROUP BY id
ORDER BY num DESC
LIMIT 1