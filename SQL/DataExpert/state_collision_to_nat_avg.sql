/* Bad as it calculates the avg for each row*/
SELECT
  state,
  fatal_collisions_per_billion_miles,
  CASE
    WHEN fatal_collisions_per_billion_miles > (
      SELECT AVG(FATAL_COLLISIONS_PER_BILLION_MILES)
      FROM playground.bad_drivers
    )  THEN 'Above Average'
    ELSE 'Below Average'
    END AS comparison_to_national_avg 
FROM playground.bad_drivers
ORDER BY state ASC


/* Optimized */
WITH national_avg AS (
  SELECT AVG(fatal_collisions_per_billion_miles) AS avg_fatal
  FROM playground.bad_drivers
)
SELECT
  bd.state,
  bd.fatal_collisions_per_billion_miles,
  CASE
    WHEN bd.fatal_collisions_per_billion_miles > na.avg_fatal THEN 'Above Average'
    ELSE 'Below Average'
  END AS comparison_to_national_avg 
FROM playground.bad_drivers bd
CROSS JOIN national_avg na
ORDER BY bd.state ASC;


/**/
SELECT
  bd.state,
  bd.fatal_collisions_per_billion_miles,
  CASE
    WHEN bd.fatal_collisions_per_billion_miles > avg_stats.avg_fatal THEN 'Above Average'
    ELSE 'Below Average'
  END AS comparison_to_national_avg 
FROM playground.bad_drivers bd,
     (SELECT AVG(fatal_collisions_per_billion_miles) AS avg_fatal FROM playground.bad_drivers) avg_stats -- same as cross join
ORDER BY bd.state ASC;
-- This query compares the fatal collisions per billion miles in each state to the national average.
-- It selects the state, the number of fatal collisions per billion miles, and a comparison to the national average.