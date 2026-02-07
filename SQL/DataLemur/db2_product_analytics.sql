WITH queryExecutedByEmployee AS (
  SELECT
    emp.employee_id AS employee_id,
    COUNT(DISTINCT query_id) AS unique_queries
  FROM employees emp
  LEFT JOIN (
    SELECT
      employee_id,
      query_id
    FROM queries
    WHERE EXTRACT (MONTH FROM query_starttime) IN (7,8,9)
  ) q
  ON emp.employee_id = q.employee_id
  GROUP BY 1
)
SELECT
  unique_queries,
  COUNT(employee_id) AS employee_count
FROM queryExecutedByEmployee
GROUP BY 1
ORDER BY unique_queries ASC 
