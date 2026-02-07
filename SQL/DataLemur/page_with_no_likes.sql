SELECT
  pages.page_id
FROM pages
LEFT JOIN page_likes
ON pages.page_id = page_likes.page_id
WHERE page_likes.user_id IS NULL
ORDER BY pages.page_id ASC

/* Using Except */

SELECT page_id
FROM pages
EXCEPT
SELECT page_id
FROM page_likes
order by page_id;