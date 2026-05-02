WITH rankedData AS (
  SELECT
    measurement_id,
    measurement_value,
    measurement_time,
    ROW_NUMBER() OVER(PARTITION BY DATE(measurement_time) ORDER BY measurement_time ASC) AS rn
  FROM measurements
)
SELECT
  DATE(measurement_time) AS measurement_day,
  SUM(
    CASE
      WHEN MOD(RN, 2) = 0 THEN measurement_value ELSE 0 
    END
  ) AS even_sum,
  SUM(
    CASE
      WHEN MOD(RN, 2) = 1 THEN measurement_value ELSE 0 
    END
  ) AS odd_sum
FROM rankedData
GROUP BY 1
ORDER BY measurement_day ASC