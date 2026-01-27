SELECT 
    LEFT(trans_date, 7) AS month,
    country, 
    COUNT(id) AS trans_count,
    SUM(case when state = 'approved' then 1 else 0 end) AS approved_count,
    SUM(amount) AS trans_total_amount,
    SUM((case when state = 'approved' then 1 else 0 end) * amount) AS approved_total_amount
FROM 
    Transactions
GROUP BY month, country;