SELECT
  age_breakdown.age_bucket,
  ROUND((SUM(CASE WHEN activity_type = 'send' THEN time_spent ELSE 0 END) / SUM(time_spent)) * 100.0, 2) AS send_perc,
  ROUND((SUM(CASE WHEN activity_type = 'open' THEN time_spent ELSE 0 END) / SUM(time_spent)) * 100.0, 2) AS open_perc
FROM activities
LEFt JOIN age_breakdown
ON activities.user_id = age_breakdown.user_id
WHERE activity_type IN ('open', 'send')
GROUP BY 1