WITH projectDuration AS (
	SELECT
		ID,
		TIMESTAMPDIFF(DAY, start_date, end_date) AS days
	FROM projects
),
salariesPaid AS (
	SELECT
		pd.ID,
		SUM((pd.days * emp.salary)/365) AS salaryPaid
	FROM projectDuration pd
	LEFT JOIN project_employees pe
	ON pd.id = pe.project_id 
	LEFT JOIN employees emp
	ON emp.id = pe.employee_id
	GROUP BY pd.ID
)
SELECT
	prj.title,
	prj.budget,
	CASE
		WHEN prj.budget < sp.salaryPaid THEN 'overbudget'
		ELSE 'within budget'
	END AS label
FROM projects prj
LEFT JOIN salariesPaid sp
ON prj.id = sp.id
ORDER BY prj.title