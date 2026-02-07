WITH views AS (
  SELECT
    CASE
      WHEN device_type = 'laptop'
      THEN 1
      ELSE 0
    END AS laptop_views,
    CASE
      WHEN device_type = 'tablet' OR device_type = 'phone'
      THEN 1
      ELSE 0
    END AS mobile_views
  FROM viewership
)
SELECT
  SUM(laptop_views) AS laptop_views,
  SUM(mobile_views) AS mobile_views
FROM views

---------------------------------------------------------------------------
---------------------------------------------------------------------------
SELECT
  SUM( CASE WHEN device_type = 'laptop' THEN 1 ELSE 0 END) AS laptop_views,
  SUM( CASE WHEN device_type IN ('tablet', 'phone') THEN 1 ELSE 0 END) AS mobile_views
FROM viewership


---------------------------------------------------------------------------
Postgre specific
---------------------------------------------------------------------------
SELECT 
  COUNT(*) FILTER (WHERE device_type = 'laptop') AS laptop_views,
  COUNT(*) FILTER (WHERE device_type IN ('tablet', 'phone'))  AS mobile_views 
FROM viewership;