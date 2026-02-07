WITH monthly_reviews AS (
  SELECT
    EXTRACT(MONTH FROM submit_date) AS mth,
    product_id AS product,
    stars
  FROM reviews
)
SELECT
  mth,
  product,
  ROUND(AVG(stars), 2) AS avg_stars
FROM monthly_reviews
GROUP BY 1, 2
ORDER BY mth, product