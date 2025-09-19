# Write your MySQL query statement below
WITH UP_SEAT AS(
    SELECT
        ID,
        STUDENT,
        CASE
            WHEN ID % 2 = 0 THEN LAG(STUDENT) OVER(ORDER BY ID)
            ELSE STUDENT
            END AS PREV_STUDENT
    FROM SEAT
),
UPDATED_SEATING AS(
    SELECT
        ID,
        CASE
            WHEN ID % 2 = 1 THEN LEAD(STUDENT) OVER(ORDER BY ID)
            ELSE PREV_STUDENT
            END AS STUDENT,
        PREV_STUDENT
    FROM UP_SEAT
)
SELECT
    ID,
    CASE
        WHEN STUDENT IS NULL THEN PREV_STUDENT
        ELSE STUDENT
        END AS STUDENT
FROM UPDATED_SEATING

/* UPDATED */
SELECT 
    id,
    CASE
        WHEN MOD(ID, 2) = 1 and id = (select max(id) from seat) then student
        WHEN MOD(id, 2) = 0 THEN LAG(student) over (order by id)
        WHEN MOD(id,2) = 1 THEN LEAD(student) over(order by id)
    END AS student
FROM seat
ORDER BY id;

/*OPTIMIZED*/
WITH max_id_cte AS (
    SELECT MAX(id) AS max_id FROM seat
)
SELECT 
    id,
    CASE
        WHEN MOD(ID, 2) = 1 and id = (select max_id from max_id_cte) then student
        WHEN MOD(id, 2) = 0 THEN LAG(student) over (order by id)
        WHEN MOD(id,2) = 1 THEN LEAD(student) over(order by id)
    END AS student
FROM seat
ORDER BY id;