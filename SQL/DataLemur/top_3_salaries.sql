with rankedSalaries AS (
  SELECT
    dept.department_name,
    emp.name,
    emp.salary,
    DENSE_RANK() OVER(PARTITION BY emp.department_id ORDER BY emp.salary DESC) AS rnk
    FROM employee emp
    INNER JOIN department dept
  ON emp.department_id = dept.department_id
)
SELECT
  department_name,
  name,
  salary
FROM rankedSalaries
WHERE rnk <= 3
ORDER BY department_name ASC, salary DESC, name ASC