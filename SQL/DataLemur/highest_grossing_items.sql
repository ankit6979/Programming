WITH totalSales AS (
SELECT 
  category,
  product,
  SUM(spend) AS gross_sales
  FROM product_spend
WHERE EXTRACT(YEAR FROM transaction_date) = '2022'
GROUP BY 1, 2
),
rankedSales AS (
SELECT
  category,
  product,
  gross_sales,
  RANK() OVER(PARTITION BY category ORDER BY gross_sales DESC) AS rn
FROM totalSales
)
SELECT
  category,
  product,
  gross_sales AS total_spend
FROM rankedSales
WHERE rn <= 2
