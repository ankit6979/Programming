# Write your MySQL query statement below
WITH PersonRnk AS (
    SELECT
        *,
        RANK() OVER(PARTITION BY email ORDER BY id) AS rnk
    FROM Person
),
Ranks AS(
    SELECT id FROM PersonRnk
    WHERE rnk <> 1
)
DELETE FROM Person WHERE id in (SELECT * FROM Ranks)

/* optimized */

DELETE FROM Person
WHERE id IN (
    SELECT id
    FROM (
        SELECT id, 
               RANK() OVER (PARTITION BY email ORDER BY id) AS rnk
        FROM Person
    ) AS ranked
    WHERE rnk <> 1
);