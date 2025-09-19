WITH prdtRating AS(
  SELECT
      prdt.id AS id,
      prdt.category AS category,
      prdt.price AS price,
      purch.stars AS stars
  FROM products AS prdt LEFT JOIN purchases AS purch
  ON prdt.id = purch.product_id AND purch.stars in (4, 5)
)
SELECT
	category,
    COALESCE(MIN(CASE WHEN stars IS NOT NULL THEN price END), 0) AS price
FROM prdtRating
GROUP BY category
ORDER BY category