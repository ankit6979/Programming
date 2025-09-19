SELECT
	cat.category_name,
    SUM(COALESCE(sls.amount, 0)) AS total_sales
FROM Categories AS cat LEFT JOIN sales AS sls
ON cat.category_id = sls.category_id
GROUP BY cat.category_name
ORDER BY total_sales ASC