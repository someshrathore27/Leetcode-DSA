WITH t1 AS (
    SELECT
        person_name,
        turn,
        weight,
        SUM(weight) OVER (
            ORDER BY turn
        ) AS total_weight
    FROM Queue
)
SELECT person_name
FROM t1
WHERE total_weight <= 1000
ORDER BY turn DESC
LIMIT 1;