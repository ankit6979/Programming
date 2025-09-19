WITH loan_paid_date AS(
  SELECT
      loan_id,
      SUM(amount_paid) AS total_paid_amount,
      MAX(payment_date) AS last_paid_date
  FROM payments
  GROUP BY loan_id
)
SELECT
	loans.loan_id,
    loans.loan_amount,
    loans.due_date,
    CASE
    	WHEN lpd.total_paid_amount = loans.loan_amount
        THEN 1
        ELSE 0
        END AS fully_paid_flag,
   CASE
    	WHEN lpd.last_paid_date <= loans.due_date
        THEN 1
        ELSE 0
        END AS on_time_flag
FROM loans JOIN loan_paid_date AS lpd
ON loans.loan_id = lpd.loan_id