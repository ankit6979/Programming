WITH most_common_genre AS (
  SELECT
  GENRE
  FROM playground.movies
  GROUP BY GENRE
  ORDER BY COUNT(*) DESC
  LIMIT 1
),
most_liked_movies AS (
  SELECT
  *
  FROM playground.movies M
  WHERE GENRE = (SELECT GENRE FROM most_liked_genre)
)
SELECT
  A.actor,
  AA.age
FROM most_liked_movies M
LEFT JOIN playground.starring_actors A
ON M.movie = A.movie_name
LEFT JOIN playground.actor_ages AA
ON A.actor = AA.actor
ORDER BY AA.age DESC, AA.actor

-- Optimized Code --

 
SELECT
  A.actor,
  AA.age
FROM most_liked_movies M
LEFT JOIN playground.starring_actors A
    ON M.movie = A.movie_name
LEFT JOIN playground.actor_ages AA
    ON A.actor = AA.actor
ORDER BY AA.age DESC, AA.actor

-- Optimized Code --

