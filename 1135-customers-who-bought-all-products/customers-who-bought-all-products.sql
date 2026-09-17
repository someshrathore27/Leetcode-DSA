WITH t AS 
(
    SELECT customer_id, COUNT(DISTINCT product_key) AS cnt
    FROM Customer
    GROUP BY customer_id
    HAVING cnt = (SELECT COUNT(*) FROM Product)
)
SELECT customer_id
FROM t;