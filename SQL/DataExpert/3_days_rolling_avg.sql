SELECT
  user_id,
  post_date,
  ROUND(AVG(post_count) OVER(
    PARTITION BY user_id 
    ORDER BY post_date
    ROWS BETWEEN 2 PRECEDING AND CURRENT ROW
  ), 2) AS third_rolling_avg 
FROM playground.posts
ORDER BY POST_DATE ASC
-- This query calculates a 3-day rolling average of post counts per user
-- The ROWS BETWEEN 2 PRECEDING AND CURRENT ROW creates a window of 3 days
-- including the current day and 2 preceding days