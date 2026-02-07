-- SELECT 
--     country,
--     SUM(CASE WHEN leisure_activity_type = 'Adventure park' THEN number_of_places ELSE 0 END) AS adventure_park,
--     SUM(CASE WHEN leisure_activity_type = 'Golf' THEN number_of_places ELSE 0 END) AS golf,
--     SUM(CASE WHEN leisure_activity_type = 'River cruise' THEN number_of_places ELSE 0 END) AS river_cruise,
--     SUM(CASE WHEN leisure_activity_type = 'Kart racing' THEN number_of_places ELSE 0 END) AS kart_racing
-- FROM 
--     playground.country_activities
-- GROUP BY 
--     country
-- ORDER BY 
--     country; 

SELECT
    country,
    ['Adventure park'] AS adventure_park,
    ['Golf'] AS golf,
    ['River cruise'] AS river_cruise,
    ['Kart racing'] AS kart_racing
FROM (
    SELECT
        country,
        leisure_activity_type
    FROM playground.country_activities
)
PIVOT (
    COUNT(1)
    FOR activity IN (['Adventure park'], ['Golf'], ['River cruise'], ['Kart racing'])
) AS pivotedData

