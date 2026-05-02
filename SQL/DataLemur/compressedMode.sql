WITH rankedTransaction AS (
  SELECT
    item_count,
    order_occurrences,
    RANK() OVER(ORDER BY order_occurrences DESC) AS rnk
  FROM items_per_order
)
SELECT
  item_count AS mode
FROM rankedTransaction
WHERE rnk = 1
ORDER BY item_count ASC