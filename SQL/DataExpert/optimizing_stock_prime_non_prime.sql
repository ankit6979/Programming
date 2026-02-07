WITH stats AS (
  SELECT
    AVG(CASE WHEN item_type = 'prime_eligible' THEN square_footage END) AS avg_prime,
    AVG(CASE WHEN item_type = 'not_prime' THEN square_footage END) AS avg_nonprime
  FROM playground.inventory
),
candidates AS (
  SELECT
    p,
    (500000.0 - p * s.avg_prime) AS remaining_area,
    GREATEST(FLOOR((500000.0 - p * s.avg_prime) / s.avg_nonprime), 0) AS nonprime_count
  FROM stats s
  CROSS JOIN UNNEST(SEQUENCE(1, CAST(FLOOR(500000.0 / s.avg_prime) AS INTEGER), 1)) AS t(p)
  WHERE (500000.0 - p * s.avg_prime) >= 0
),
filtered AS (
  SELECT *
  FROM candidates
  WHERE nonprime_count > 0
),
best AS (
  SELECT
    p,
    nonprime_count,
    ROW_NUMBER() OVER (ORDER BY p DESC, nonprime_count DESC) AS rn
  FROM filtered
)
SELECT 'prime_eligible' AS item_type, p AS item_count
FROM best
WHERE rn = 3
UNION ALL
SELECT 'not_prime', nonprime_count
FROM best
WHERE rn = 3;
