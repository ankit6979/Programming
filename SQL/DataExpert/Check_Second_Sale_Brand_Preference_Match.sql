WITH combinedOrders AS (
  SELECT
    o.order_date,
    o.item_id,
    i.item_brand,
    o.seller_id,
    u.preferred_brand,
    ROW_NUMBER() OVER (PARTITION BY o.seller_id ORDER BY o.order_date ASC) AS rn
  FROM playground.orders AS o
  LEFT JOIN playground.items AS i
    ON o.item_id = i.item_id
  LEFT JOIN playground.users AS u
    ON o.seller_id = u.user_id
),
sellerWithPreferredBrand AS (
  SELECT
    seller_id,
    CASE
      WHEN item_brand = preferred_brand THEN 'yes'
      ELSE 'no'
    END AS has_pref_brand
  FROM combinedOrders
  WHERE rn = 2
)
SELECT
  u.user_id AS seller_id,
  COALESCE(s.has_pref_brand, 'no') AS has_pref_brand
FROM playground.users AS u
LEFT JOIN sellerWithPreferredBrand AS s
  ON u.user_id = s.seller_id
ORDER BY seller_id ASC;
