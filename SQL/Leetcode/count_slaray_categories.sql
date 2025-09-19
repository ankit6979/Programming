WITH AccountGroup AS (
    SELECT
        CASE
            WHEN income < 20000 THEN "Low Salary"
            WHEN income <= 50000 THEN "Average Salary"
            ELSE "High Salary"
        END AS "category"
    FROM Accounts
),
DummyGroup AS(
    (SELECT "Low Salary" AS category)
    UNION
    (SELECT "Average Salary" AS category)
    UNION
    (SELECT "High Salary" AS category)
),
CategoryCount AS (
    SELECT
        COALESCE(acc.category, dg.category) AS category,
        CASE
            WHEN acc.category IS NULL THEN 0
            ELSE 1
        END AS category_cnt
    FROM AccountGroup AS acc
    RIGHT JOIN DummyGroup AS dg
    ON acc.category = dg.category
)
SELECT
    category,
    sum(category_cnt) AS accounts_count
FROM CategoryCount
GROUP BY category


/*OPTIMIZED*/
SELECT
    "Low Salary" AS category,
    COUNT(CASE WHEN income < 20000 THEN 1 END) AS accounts_count
    FROM Accounts
UNION ALL
SELECT
    "Average Salary" AS category,
    COUNT(CASE WHEN income >=20000 AND income <= 50000 THEN 1 END) AS accounts_count
    FROM Accounts
UNION ALL
SELECT
    "High Salary" AS category,
    COUNT(CASE WHEN income > 50000 THEN 1 END) AS accounts_count
    FROM Accounts

/*Further Optimized*/
SELECT
    "Low Salary" AS category,
    COUNT(income) AS accounts_count
    FROM Accounts
    WHERE income < 20000
UNION ALL
SELECT
    "Average Salary" AS category,
    COUNT(income) AS accounts_count
    FROM Accounts
    WHERE income BETWEEN 20000 AND 50000
UNION ALL
SELECT
    "High Salary" AS category,
    COUNT(income) AS accounts_count
    FROM Accounts
    WHERE income > 50000