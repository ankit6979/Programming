WITH ReqUsers AS(
    SELECT requester_id AS user_id
    FROM RequestAccepted 
),
AccUsers AS(
    SELECT accepter_id AS user_id
    FROM RequestAccepted 
),
TotalUsers AS(
    (
        SELECT user_id
        FROM ReqUsers
    )
    UNION ALL
    (
        SELECT user_id
        FROM AccUsers
    )
)
SELECT
    user_id AS id,
    COUNT(user_id) AS num
FROM TotalUsers
GROUP BY user_id
ORDER BY num DESC
LIMIT 1