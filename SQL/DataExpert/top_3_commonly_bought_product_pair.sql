WITH purchasedProduct AS (
    SELECT
        transaction1.transaction_id AS transaction_id,
        transaction1.product_name AS product_name1,
        transaction2.product_name AS product_name2
    FROM playground.product_transactions transaction1
    CROSS JOIN playground.product_transactions transaction2
    WHERE transaction1.transaction_id = transaction2.transaction_id
    AND transaction1.product_name <> transaction2.product_name
)
SELECT
    product_name1 AS product1,
    product_name2 AS product2,
    COUNT(transaction_id) AS freq
FROM purchasedProduct
GROUP BY 1, 2
ORDER BY freq DESC, product_name1 ASC, product_name2 ASC
LIMIT 1


----------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------

WITH purchasedProduct AS (
  SELECT
      transaction1.transaction_id AS transaction_id,
      LEAST(transaction1.product_name, transaction2.product_name) AS product_name1, -- LEAST() and GREATEST() make sure that the pair order is consistent (so (Pen, Pencil) and (Pencil, Pen) count together).
      GREATEST(transaction1.product_name, transaction2.product_name) AS product_name2
  FROM playground.product_transactions transaction1
  CROSS JOIN playground.product_transactions transaction2
  WHERE transaction1.transaction_id = transaction2.transaction_id
    AND transaction1.product_name <> transaction2.product_name
)
SELECT
    product_name1 AS product1,
    product_name2 AS product2,
    COUNT(DISTINCT transaction_id) AS freq
FROM purchasedProduct
GROUP BY 1, 2
ORDER BY freq DESC, product_name1 ASC, product_name2 ASC
LIMIT 1;