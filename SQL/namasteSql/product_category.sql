WITH ProductCategory AS (
  SELECT
  	product_id,
  	CASE
  		WHEN price < 100 THEN "Low Price"
  		WHEN price <= 500 THEN "Medium Price"
  		ELSE "High Price"
  	END AS category
  FROM Products
 )
SELECT
 	category,
    COUNT(*) AS no_of_products
FROM ProductCategory
GROUP BY category
ORDER BY no_of_products DESC