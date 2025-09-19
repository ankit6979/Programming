WITH region_category_purchase AS (
  SELECT
  region,
  sub_category,
  COUNT(1) AS purchase_count
  FROM playground.superstore
  GROUP BY region, sub_category
)
SELECT
  region,
  sub_category,
  purchase_count
FROM (
  SELECT
    region,
    sub_category,
    purchase_count,
    RANK() OVER(PARTITION BY region ORDER BY purchase_count DESC) AS rnk
  FROM region_category_purchase
)
WHERE rnk = 1
ORDER BY region ASC
  
/* OPTIMIZED */
WITH counts AS (
  SELECT
    region,
    sub_category,
    COUNT(*) AS purchase_count,
    ROW_NUMBER() OVER (
      PARTITION BY region
      ORDER BY COUNT(*) DESC, sub_category ASC
    ) AS rn
  FROM playground.superstore
  GROUP BY region, sub_category
)
SELECT region, sub_category, purchase_count
FROM counts
WHERE rn = 1
ORDER BY region;