WITH weekData AS (
  SELECT
      emp_id,
      login,
      logout,
      TIMESTAMPDIFF(minute, login, logout) AS minutes
  FROM employees
),
aggData AS (
  SELECT
  	emp_id,
  	SUM(CASE WHEN minutes > 480 THEN 1 ELSE 0 END) AS criteria1,
  	SUM(CASE WHEN minutes > 600 THEN 1 ELSE 0 END) AS criteria2
  FROM weekData
  GROUP BY 1
)
SELECT
	emp_id,
    CASE
    	WHEN criteria1 >= 3 AND criteria2 >= 2 THEN 'both'
        WHEN criteria1 >= 3 THEN '1'
        ELSE '2'
    END AS criteria
FROM aggData
