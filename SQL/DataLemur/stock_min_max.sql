WITH rankedPrice AS
(
  SELECT
    ticker,
    date,
    open,
    ROW_NUMBER() OVER(PARTITION BY ticker ORDER BY OPEN DESC) AS descRank,
    ROW_NUMBER() OVER(PARTITION BY ticker ORDER BY OPEN ASC) AS ascRank
  FROM stock_prices
),
openPrice AS (
  SELECT
    ticker,
    CONCAT(TO_CHAR(date, 'Mon-YYYY')) AS date,
    open
  FROM rankedPrice
  WHERE descRank = 1
),
closePrice AS (
  SELECT
    ticker,
    CONCAT(TO_CHAR(date, 'Mon-YYYY')) AS date,
    open
  FROM rankedPrice
  WHERE ascRank = 1
)
SELECT
  R1.ticker,
  R1.date AS highest_mth,
  R1.open AS highest_open,
  R2.date AS lowest_mth,
  R2.open AS lowest_open
FROM openPrice R1
JOIN closePrice R2
ON R1.ticker = R2.ticker