WITH WinnerTeam AS (
  SELECT
    match_id,
    first_team_score,
    second_team_score,
    match_host,
    CASE
      WHEN first_team_score > second_team_score THEN 1
      WHEN first_team_score = second_team_score THEN 0
      ELSE 2 
    END AS winning_team
  FROM playground.scores
),
final AS (
    select 
    match_id,
    first_team_score,
    second_team_score,
    match_host,
    winning_team,
    CASE
        WHEN winning_team = 1 THEN first_team_score - second_team_score
        WHEN winning_team = 2 THEN second_team_score - first_team_score
        ELSE 0
        END AS goal_diff,
    CASE
        WHEN winning_team = 1 AND match_host = 2 THEN 1
        WHEN winning_team = 2 AND match_host = 1 THEN 1
        ELSE 0
        END AS away_win
    FROM WinnerTeam
),
Aggregated AS (
  SELECT
    winning_team,
    COUNT(1) AS total_wins,
    SUM(goal_diff) AS overall_goal_diff,
    SUM(away_win) AS away_wins
  FROM final
  GROUP BY 1
  ORDER BY total_wins DESC, overall_goal_diff DESC, away_wins DESC
)
SELECT
  winning_team AS winner
FROM Aggregated
LIMIT 1
  