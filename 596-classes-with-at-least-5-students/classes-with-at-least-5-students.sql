# Write your MySQL query statement below
with t as(
    select class , count(class) as cnt from Courses group by class
)
select class from t where t.cnt>=5;