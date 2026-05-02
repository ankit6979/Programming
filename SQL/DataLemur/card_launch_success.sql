-- select * from monthly_cards_issued
WITH ranked_cards AS (
  SELECT
    card_name,
    issued_amount,
    ROW_NUMBER() OVER(PARTITION BY card_name ORDER BY issue_year ASC, issue_month ASC) AS rn
  FROM monthly_cards_issued
)
SELECT
  card_name,
  issued_amount
FROM ranked_cards
WHERE rn = 1
ORDER BY issued_amount DESC