WITH groupedData AS (
  SELECT
    customer_id,
    COUNT(DISTINCT products.product_category) AS cnt1
  FROM customer_contracts
  JOIN products
  ON customer_contracts.product_id = products.product_id
  GROUP BY 1
),
cte AS (
  SELECT
  customer_id,
  cnt1,
  total_product_category AS cnt2
  FROM groupedData
  CROSS JOIN
  (
    SELECT COUNT(DISTINCT product_category) AS total_product_category
    FROM products
  ) inr
)
SELECT 
customer_id
FROM cte
WHERE cnt1 = cnt2


WITH supercloud_cust AS (
  SELECT 
    customers.customer_id, 
    COUNT(DISTINCT products.product_category) AS product_count
  FROM customer_contracts AS customers
  INNER JOIN products 
    ON customers.product_id = products.product_id
  GROUP BY customers.customer_id
)

SELECT customer_id
FROM supercloud_cust
WHERE product_count = (
  SELECT COUNT(DISTINCT product_category) FROM products
);