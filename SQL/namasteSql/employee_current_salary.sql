with RECURSIVE orderedPromotions AS (
	SELECT
		emp.id,
		emp.name,
		emp.joining_salary as joining_salary,
		p.promotion_date,
		p.percent_increase,
		ROW_NUMBER() OVER (PARTITION BY emp.id ORDER BY p.promotion_date) AS rn
	from employees as emp
	left join promotions as p
	on emp.id = p.emp_id
),
recursiveSalary AS (
	select
		id,
		name,
		joining_salary,
        CAST(joining_salary AS DECIMAL(10,1)) AS current_salary,
        promotion_date,
		percent_increase,
		0 as rn
	from orderedPromotions
	where rn = 1

	union all

	select
		op.id,
		op.name,
		op.joining_salary,
        CAST(current_salary AS DECIMAL(10,1)) * (1 + (op.percent_increase / 100.0)) AS current_salary,
        op.promotion_date,
		op.percent_increase,
		op.rn
	from recursiveSalary rs
	join orderedPromotions op
	ON rs.id = op.id AND rs.rn + 1 = op.rn
),
aggregated_data as (
	SELECT
		id,
		name,
		joining_salary as initial_salary,
		MAX(current_salary) AS current_salary
	FROM recursiveSalary
	GROUP BY id, name, joining_salary
	order by id
)
select
	id,
	name,
	initial_salary,
	TRIM(TRAILING '.0' FROM TRIM(TRAILING '.0' FROM current_salary)) AS current_salary
from aggregated_data