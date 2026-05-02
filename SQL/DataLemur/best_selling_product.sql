WITH rankedData AS (
  SELECT
    products.product_name,
    products.category_name,
    product_sales.sales_quantity,
    product_sales.rating,
    ROW_NUMBER() OVER(PARTITION BY products.category_name ORDER BY sales_quantity DESC, rating DESC) AS rn
  FROM products
  JOIN product_sales
  ON products.product_id = product_sales.product_id
)
SELECT
  category_name,
  product_name
FROM rankedData
WHERE rn = 1
ORDER BY category_name ASC
