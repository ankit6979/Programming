WITH ordered AS (
    SELECT 
        searches,
        num_users,
        ROW_NUMBER() OVER (ORDER BY searches ASC) AS rn,
        COUNT(*) OVER() AS cnt
    FROM playground.search_freq
),
middle_values AS (
    SELECT
        MAX(CASE WHEN rn = cnt/2 THEN num_users END) AS first_mid,
        MAX(CASE WHEN rn = cnt/2 + 1 THEN num_users END) AS second_mid,
        MAX(CASE WHEN rn = (cnt+1)/2 THEN num_users END) AS odd_mid,
        MAX(cnt) AS cnt
    FROM ordered
)
SELECT 
    CASE 
        WHEN cnt % 2 = 0 
            THEN ROUND(CAST((first_mid + second_mid) / 2.0 AS DOUBLE), 1)
        ELSE odd_mid
    END AS median
FROM middle_values;
