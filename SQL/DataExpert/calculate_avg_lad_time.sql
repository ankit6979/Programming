SELECT
  ship_mode,
  COUNT(ORDER_ID) AS total_shipping_service,
  ROUND(AVG(DATE_DIFF('day', ORDER_DATE, SHIP_DATE)), 2) AS avg_lead_time
FROM playground.superstore
GROUP BY ship_mode
ORDER BY ship_mode DESC