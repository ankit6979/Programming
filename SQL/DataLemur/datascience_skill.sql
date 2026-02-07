SELECT
  candidate_id
FROM candidates
WHERE UPPER(skill) in ('PYTHON', 'TABLEAU', 'POSTGRESQL')
GROUP BY 1
HAVING COUNT(DISTINCT skill) >= 3
ORDER BY candidate_id ASC

/*
UPPER(skill)
Using UPPER():
Prevents index usage on skill
Adds unnecessary function overhead
*/