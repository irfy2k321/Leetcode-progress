SELECT author_id AS ID 
FROM Views
WHERE author_id = viewer_id
GROUP BY author_id
ORDER BY ID ASC;
