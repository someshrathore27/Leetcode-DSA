# Write your MySQL query statement below
SELECT customer_id, COUNT(*) AS count_no_trans
FROM Visits
WHERE visit_id NOT IN (SELECT distinct visit_id FROM Transactions) GROUP BY customer_id;