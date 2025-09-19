WITH UniqueProducts AS(
    SELECT
        DISTINCT product_id AS product_id
    FROM Products
),
RankedPrice AS(
    SELECT
        product_id,
        new_price,
        change_date,
        RANK() OVER(PARTITION BY product_id ORDER BY change_date DESC) AS rnk
    FROM Products
    WHERE change_date <= "2019-08-16"
)
SELECT
    DISTINCT up.product_id,
    COALESCE(rp.new_price, 10) AS price
FROM RankedPrice AS rp
RIGHT JOIN UniqueProducts AS up
ON rp.product_id = up.product_id AND rp.rnk = 1