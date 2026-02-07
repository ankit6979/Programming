WITH possiblePackages AS (
    SELECT
        gift.id,
        package.package_type,
        package.length * package.width * package.height AS volume
    FROM playground.gifts AS gift
    JOIN playground.packages AS package
    ON (
        gift.length <= package.length
        AND gift.width <= package.width
        AND gift.height <= package.height
    )
),
minPossiblePackage AS (
    SELECT
        id,
        package_type,
        ROW_NUMBER() OVER(PARTITION BY id ORDER BY volume ASC) AS rn
    FROM possiblePackages
)
SELECT
    package_type,
    COUNT(id) AS number
FROM minPossiblePackage
WHERE rn = 1
GROUP BY 1
ORDER BY package_type ASC


/* Optimized */
WITH possiblePackages AS (
    SELECT
        gift.id,
        package.package_type,
        package.length * package.width * package.height AS volume
    FROM playground.gifts AS gift
    JOIN playground.packages AS package
    ON (
        gift.length <= package.length
        AND gift.width <= package.width
        AND gift.height <= package.height
    )
),
minVolume AS (
    SELECT
        id,
        MIN(volume) AS min_volume
    FROM possiblePackages
    GROUP BY id
)
SELECT
    p.package_type,
    COUNT(*) AS number
FROM possiblePackages p
JOIN minVolume mv
    ON p.id = mv.id AND p.volume = mv.min_volume
GROUP BY p.package_type
ORDER BY p.package_type;
