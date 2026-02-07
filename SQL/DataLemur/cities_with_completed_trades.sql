SELECT
  u.city AS city,
  COUNT(DISTINCT t.order_id) AS trades
FROM trades t
INNER JOIN users u
ON t.user_id = u.user_id
WHERE t.status = 'Completed'
GROUP BY city
ORDER BY trades DESC
LIMIT 3