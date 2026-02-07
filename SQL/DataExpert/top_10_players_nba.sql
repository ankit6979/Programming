WITH eligible AS (
    SELECT
        player_name,
        season,
        pts,
        ROW_NUMBER() OVER (PARTITION BY player_name ORDER BY season) AS rn
    FROM bootcamp.nba_player_seasons
    WHERE pts >= 20
),
groups AS (
    SELECT
        player_name,
        season,
        pts,
        (season - rn) AS grp
    FROM eligible
),
streaks AS (
    SELECT
        player_name,
        COUNT(*) AS consecutive_seasons
    FROM groups
    GROUP BY player_name, grp
),
longest AS (
    SELECT
        player_name,
        MAX(consecutive_seasons) AS consecutive_seasons
    FROM streaks
    GROUP BY player_name
),
ranked AS (
    SELECT
        player_name,
        consecutive_seasons,
        RANK() OVER (ORDER BY consecutive_seasons DESC) AS rnk
    FROM longest
)
SELECT player_name, consecutive_seasons
FROM ranked
WHERE rnk <= 10
ORDER BY consecutive_seasons DESC, player_name ASC;
