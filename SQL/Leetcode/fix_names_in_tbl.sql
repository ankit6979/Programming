# Write your MySQL query statement below
select
    user_id,
    concat(upper(left(name, 1)), lower(right(name, length(name) - 1))) as name
from
users
order by user_id

SELECT
    user_id,
    CONCAT(UPPER(SUBSTRING(name, 1, 1)), LOWER(SUBSTRING(name, 2))) AS name
FROM
    users
ORDER BY
    user_id;