WITH emailTexts AS (
  SELECT
    emails.user_id,
    emails.email_id,
    texts.signup_action
  FROM emails
  LEFT JOIN texts
  ON emails.email_id = texts.email_id
)
SELECT
  ROUND(SUM(CASE WHEN signup_action = 'Confirmed' THEN 1 ELSE 0 END) * 1.0 /COUNT(DISTINCT user_id), 2) AS confirm_rate
FROM emailTexts