WITH rankedSalary AS (
  SELECT 
    salary,
    ROW_NUMBER() OVER(ORDER BY salary DESC) AS rn
  FROM employee
)
SELECT
  salary AS second_highest_salary
FROM rankedSalary
WHERE rn = 2

---- Using MAX ---
WITH highestSalaryCTE AS (
  SELECT 
    MAX(salary) AS highest_salary
  FROM employee
)
SELECT
  MAX(salary) AS second_highest_salary
FROM employee
WHERE salary < (
  SELECT
    highest_salary
  FROM highestSalaryCTE
)

