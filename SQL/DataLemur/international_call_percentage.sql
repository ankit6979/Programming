WITH user_mapped_contry AS (
  SELECT
    CASE
      WHEN caller_phone_info.country_id <> receiver_phone_info.country_id THEN 1 ELSE 0
    END AS different_country_call
  FROM phone_calls
  JOIN phone_info AS caller_phone_info
  ON phone_calls.caller_id = caller_phone_info.caller_id
  JOIN phone_info AS receiver_phone_info
  ON phone_calls.receiver_id = receiver_phone_info.caller_id
)
SELECT
  ROUND(((SUM(different_country_call) * 1.0) / (COUNT(*) * 1.0)) * 100, 1) AS international_calls_pct
FROM user_mapped_contry

