WITH inventory_summary AS (
    SELECT 
        item_type,
        COUNT(*) AS available_count
    FROM playground.inventory
    GROUP BY item_type
),
limits AS (
    SELECT
        MAX(CASE WHEN item_type = 'prime_eligible' THEN available_count ELSE 0 END) AS prime_available,
        MAX(CASE WHEN item_type = 'not_prime' THEN available_count ELSE 0 END) AS nonprime_available
    FROM inventory_summary
)
SELECT 
    'prime_eligible' AS item_type,
    LEAST(prime_available, nonprime_available, 250000) AS item_count
FROM limits
UNION ALL
SELECT 
    'not_prime' AS item_type,
    LEAST(prime_available, nonprime_available, 250000) AS item_count
FROM limits
ORDER BY CASE WHEN item_type = 'prime_eligible' THEN 1 ELSE 2 END;
