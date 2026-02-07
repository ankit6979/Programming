WITH DepartmentSalary AS (
  SELECT * 
  FROM playground.emp AS emp
  JOIN playground.dept AS dept
  ON emp.department = dept.ID
),
GroupedSalary AS (
  SELECT
    MAX(NAME) AS dep_name,
    MAX(department) AS dept_id,
    COUNT(full_name) AS emp_number,
    SUM(SALARY) AS total_salary 
  FROM DepartmentSalary
  GROUP BY department
),
filteredSalary AS (
  SELECT
    *
  FROM GroupedSalary
  WHERE emp_number <= 5
),
final AS (
    SELECT
        *,
    ROW_NUMBER() OVER(ORDER BY total_salary DESC, emp_number DESC, dept_id ASC) AS rn
    FROM filteredSalary
)
SELECT
    dep_name,
    emp_number,
    total_salary
FROM final
WHERE MOD(rn, 2) = 1