# Write your MySQL query statement below
WITH managedEmployees AS (
    SELECT *
    FROM Employees
    WHERE manager_id IS NOT NULL
)
SELECT
    mgemp.employee_id
FROM managedEmployees AS mgemp
LEFT JOIN Employees AS emp
ON mgemp.manager_id = emp.employee_id
WHERE mgemp.salary < 30000 AND emp.name IS NULL
ORDER BY employee_id