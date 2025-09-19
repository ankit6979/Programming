WITH salesDay AS (
  SELECT
  	category,
  	amount
  FROM sales
  WHERE WEEKDAY(order_date) < 5 AND MONTH(order_date) = 2 AND YEAR(order_date) = 2022
)
SELECT
	category AS category,
    SUM(amount) AS total_sales
FROM salesDay
GROUP BY category
ORDER BY total_sales ASC