WITH extremes AS (
  SELECT
    MIN(first_criterion) AS min_first,
    MAX(first_criterion) AS max_first,
    MIN(second_criterion) AS min_second,
    MAX(second_criterion) AS max_second,
    MIN(third_criterion) AS min_third,
    MAX(third_criterion) AS max_third
  FROM playground.dance_scores
)
SELECT ds.arbiter_id, ds.first_criterion, ds.second_criterion, ds.third_criterion
FROM playground.dance_scores ds, extremes e
WHERE (
  (CASE WHEN ds.first_criterion = e.min_first OR ds.first_criterion = e.max_first THEN 1 ELSE 0 END) +
  (CASE WHEN ds.second_criterion = e.min_second OR ds.second_criterion = e.max_second THEN 1 ELSE 0 END) +
  (CASE WHEN ds.third_criterion = e.min_third OR ds.third_criterion = e.max_third THEN 1 ELSE 0 END)
) < 2
ORDER BY ds.arbiter_id;
