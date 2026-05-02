WITH dateDiff AS (
SELECT
  user_id,
  transaction_date,
  CASE
    WHEN (transaction_date - LAG(transaction_date) OVER(PARTITION BY user_id ORDER BY transaction_date ASC)) =  INTERVAL '1 day' THEN 1
    ELSE 0
    END AS shopping_spree
FROM transactions
),
agg as (
SELECT
  user_id,
  SUM(CASE WHEN shopping_spree = 0 THEN 1 ELSE 0 END) OVER (PARTITION BY user_id ORDER BY transaction_date ASC) AS running_sum
FROM dateDiff
)
select
DISTINCT user_id
FROM agg
WHERE running_sum >= 2
ORDER BY user_id ASC

-- using self join
SELECT DISTINCT T1.user_id
FROM transactions AS T1
INNER JOIN transactions AS T2
  ON DATE(T2.transaction_date) = DATE(T1.transaction_date) + 1
INNER JOIN transactions AS T3
  ON DATE(T3.transaction_date) = DATE(T1.transaction_date) + 2
ORDER BY T1.user_id;

-- Most optimized solution using window function
WITH t AS (
  SELECT
    user_id,
    transaction_date,
    transaction_date 
      - ROW_NUMBER() OVER (
          PARTITION BY user_id 
          ORDER BY transaction_date
        ) * INTERVAL '1 day' AS grp
  FROM transactions
)
SELECT user_id
FROM t
GROUP BY user_id, grp
HAVING COUNT(*) >= 3
ORDER BY user_id;