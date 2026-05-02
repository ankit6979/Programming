WITH recent_transaction_date AS (
  SELECT
    user_id,
    transaction_date,
    product_id,
    RANK() OVER(PARTITION BY user_id ORDER BY transaction_date DESC) AS rn
  FROM user_transactions
)
SELECT
  transaction_date,
  user_id,
  COUNT(product_id) AS purchase_count
FROM recent_transaction_date
WHERE rn = 1
GROUP BY 1, 2
ORDER BY transaction_date ASC