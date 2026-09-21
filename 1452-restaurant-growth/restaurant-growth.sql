# Write your MySQL query statement below
with t1 as(
    select visited_on , sum(amount) as amount from Customer group by visited_on
)
select visited_on , 
sum(t1.amount) over(
    order by visited_on
    rows between 6 preceding and current row
) as amount , 
round(avg(t1.amount) over(
    order by visited_on
    rows between 6 preceding and current row
),2) as average_amount from t1 limit 10000 offset 6;