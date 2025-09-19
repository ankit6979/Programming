SELECT
	dept.department_name,
    ROUND(AVG(emp.salary), 2) AS average_salary
FROM
	Employees AS emp JOIN Departments AS dept
    ON emp.department_id = dept.department_id
GROUP BY dept.department_name
HAVING COUNT(emp.employee_id) > 2
ORDER BY average_salary DESC