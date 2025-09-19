# Write your MySQL query statement below
WITH consecutive AS(
    SELECT
        id,
        num,
        LAG(num) OVER () AS prev_num,
        LAG(num, 2) OVER () AS prev_prev_num
    FROM logs
)
SELECT
    distinct num AS ConsecutiveNums
FROM consecutive
WHERE num = prev_num AND num = prev_prev_num