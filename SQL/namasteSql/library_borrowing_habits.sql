WITH BorrowedBook AS(
	SELECT
    	borrower.BorrowerName AS BorrowerName,
    	book.BookName AS BookName
	FROM
		Books AS book JOIN Borrowers AS borrower
    	ON book.BookID = borrower.BookID
)
SELECT
	BorrowerName,
    GROUP_CONCAT(BookName ORDER BY BookName SEPARATOR ',') AS BorrowedBooks
FROM BorrowedBook
GROUP BY BorrowerName
ORDER BY BorrowerName