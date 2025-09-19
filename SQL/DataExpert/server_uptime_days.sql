SELECT
  SUM(uptime_days) AS total_uptime_days
  FROM (
    SELECT
      DATE_DIFF('DAY', session_time, LEAD(session_time) OVER(PARTITION BY session_id ORDER BY session_time ASC)) AS uptime_days
    FROM playground.sessions
)
WHERE uptime_days IS NOT NULL


/* OPTIMIZED */
WITH ordered AS (
  SELECT
    session_id,
    array_agg(session_time ORDER BY session_time) AS ts
  FROM playground.sessions
  GROUP BY session_id
),
pairs AS (
  SELECT
    date_diff('day', ts[i], ts[i+1]) AS d
  FROM ordered
  CROSS JOIN UNNEST(sequence(1, cardinality(ts) - 1)) AS u(i)
)
SELECT COALESCE(SUM(d), 0) AS total_uptime_days
FROM pairs;
