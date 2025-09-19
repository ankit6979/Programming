SELECT
	review_id,
    product_id,
    review_text
FROM product_reviews
WHERE (
	lower(review_text) regexp 'excellent|amazing' AND
    lower(review_text) NOT REGEXP 'not excellent|not amazing'
ORDER BY review_id