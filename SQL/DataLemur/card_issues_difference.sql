WITH monthly_cards_issued AS (
  SELECT
    issue_month,
    card_name,
    SUM(issued_amount) AS issued_amount
  FROM monthly_cards_issued
  GROUP BY 1, 2
)
SELECT
  card_name,
  MAX (issued_amount) - MIN (issued_amount) AS difference
FROM monthly_cards_issued
GROUP BY card_name
ORDER BY difference DESC
