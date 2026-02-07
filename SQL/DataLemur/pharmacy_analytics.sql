SELECT
  manufacturer,
  COUNT(*) AS drug_count,
  SUM (ABS (total_sales - cogs)) AS total_loss
FROM pharmacy_sales
WHERE (total_sales - cogs) < 0
GROUP BY 1
ORDER BY total_loss DESC