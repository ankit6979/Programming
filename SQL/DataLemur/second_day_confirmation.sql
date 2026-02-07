SELECT
  DISTINCT
  emails.user_id
FROM emails 
JOIN texts ON emails.email_id = texts.email_id
WHERE texts.signup_action = 'Confirmed'
AND texts.action_date = ADDDATE(emails.signup_date, INTERVAL 1 DAY)