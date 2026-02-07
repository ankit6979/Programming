WITH YearwiseProduct AS (
  SELECT
    YEAR(transaction_date) AS year,
    spend,
    product_id
  FROM playground.dates
),
YearwiseProductSales AS (
  SELECT
    product_id,
    year,
    SUM(spend) AS spends
  FROM YearwiseProduct
  GROUP BY product_id, year
),
YearOnYearSales AS (
    SELECT
    YEAR,
    PRODUCT_ID,
    spends AS current_year_spend,
    LAG(spends) OVER(PARTITION BY PRODUCT_ID ORDER BY YEAR ASC) AS previous_year_spend
    FROM YearwiseProductSales
)
SELECT
    year,
    product_id,
    current_year_spend,
    previous_year_spend,
    ROUND(((current_year_spend - previous_year_spend) / previous_year_spend) * 100, 2) AS yoy_rate
FROM YearOnYearSales
limit 1