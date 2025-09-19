WITH monthly_sales AS (
  SELECT
     id,
     month,
     SUM(sales) AS total_sales,
     RANK() OVER(PARTITION BY month ORDER BY sum(sales) DESC) AS rank
FROM playground.sales
GROUP BY id, month 
)
SELECT 
  *
FROM monthly_sales  
WHERE rank <= 2
ORDER BY id, rank, month ASC