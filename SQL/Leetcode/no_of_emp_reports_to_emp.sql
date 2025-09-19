# Write your MySQL query statement below
WITH managers AS (
    SELECT
        reports_to AS employee_id,
        AVG(age) as average_age,
        COUNT(employee_id) as reports_count
    FROM Employees
    GROUP BY reports_to
)
SELECT
    mgr.employee_id AS employee_id,
    emp.name AS name,
    mgr.reports_count AS reports_count,
    ROUND(mgr.average_age) AS average_age
FROM managers AS mgr
INNER JOIN Employees AS emp
ON mgr.employee_id = emp.employee_id
ORDER BY employee_id
