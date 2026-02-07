SELECT
  account_id,
  SUM(
    CASE
      WHEN transaction_type = 'Withdrawal'
      THEN (-1 * amount)
      ELSE amount
    END
  ) AS final_balance
FROM transactions
GROUP BY account_id