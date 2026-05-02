WITH unionedData AS (
  SELECT
    user_id,
    song_id,
    1 as song_plays
  FROM songs_weekly
  WHERE EXTRACT(DAY FROM songs_weekly.listen_time) <= '04'
  UNION ALL
  SELECT
    user_id,
    song_id,
    song_plays
  FROM songs_history
)
SELECT
  user_id,
  song_id,
  SUM(song_plays) AS song_plays
FROM unionedData
GROUP BY 1, 2
ORDER BY song_plays DESC