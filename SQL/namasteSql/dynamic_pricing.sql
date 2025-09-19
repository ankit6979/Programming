WITH product_price AS(
SELECT
	product_id,
  	price,
    price_date AS start_price_date,
    DATE_SUB(
        IFNULL(
            (LEAD(price_date) OVER(PARTITION BY product_id ORDER BY price_date)),
            '9999-12-31'
        ), INTERVAL 1 DAY
    ) AS end_price_date
FROM products
),
order_price AS(
SELECT
	ord.order_id,
    ord.product_id,
    pp.price
FROM orders AS ord JOIN product_price AS pp
ON ord.order_date BETWEEN pp.start_price_date AND pp.end_price_date AND pp.product_id = ord.product_id
)
SELECT
	product_id,
    SUM(price) AS total_sales
FROM order_price
GROUP BY product_id
ORDER BY product_id