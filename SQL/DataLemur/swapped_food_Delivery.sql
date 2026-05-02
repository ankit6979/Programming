SELECT
order_id AS corrected_order_id,
COALESCE(
  CASE
    WHEN MOD(order_id, 2) = 0 THEN LAG(item) OVER(ORDER BY order_id)
    WHEN MOD(order_id, 2) = 1 THEN LEAD(item) OVER(ORDER BY order_id)
  END,
    item
  ) AS item
FROM orders 
ORDER BY order_id
