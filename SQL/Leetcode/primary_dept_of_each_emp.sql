# Write your MySQL query statement below
(
    select
        employee_id,
        department_id
    from Employee
    where primary_flag = 'Y'
)
UNION
(
    SELECT
        employee_id,
        department_id
    FROM Employee
    GROUP BY employee_id
    HAVING COUNT(employee_id) = 1
)
-- SELECT 
--   employee_id, 
--   department_id 
-- FROM 
--   (
--     SELECT 
--       *, 
--       COUNT(employee_id) OVER(PARTITION BY employee_id) AS EmployeeCount
--     FROM 
--       Employee
--   ) EmployeePartition 
-- WHERE 
--   EmployeeCount = 1 
--   OR primary_flag = 'Y';