WITH latest_price AS (
  SELECT
    product_id,
    new_price,
    RANK() OVER(
      PARTITION BY product_id
      ORDER by change_date DESC
    ) AS rnk
  FROM playground.product_prices
  WHERE change_date <= date('2023-08-17')
),
distinctProduct AS (
  SELECT
    DISTINCT product_id
  FROM playground.product_prices
)
SELECT
    p.product_id,
    COALESCE(lp.new_price, 10) AS price
FROM (
    SELECT
        DISTINCT product_id
    FROM playground.product_prices
) p
LEFT JOIN latest_price lp
    ON p.product_id = lp.product_id AND lp.rnk = 1
ORDER BY product_id ASC