WITH student_grade AS (
SELECT
  student_id,
  course_id,
  grade,
  RANK() OVER(PARTITION BY student_id ORDER BY grade DESC, course_id ASC) AS rnk
FROM playground.student_grades
)
SELECT
  student_id,
  course_id,
  grade
FROM student_grade
WHERE rnk = 1
ORDER BY student_id ASC

/* QUALIFY RANK*/
SELECT
  student_id,
  course_id,
  grade
FROM playground.student_grades
QUALIFY RANK() OVER (PARTITION BY student_id ORDER BY grade DESC, course_id ASC) = 1
ORDER BY student_id asc