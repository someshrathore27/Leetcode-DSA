-- # Write your MySQL query statement below
-- with m1 as(
--     select managerId , count(managerId) as cnt from Employee group by(managerId)
-- )
-- select name from Employee inner join m1 on Employee.id=m1.managerId where m1.cnt>=5;

with t1 as (
    select managerId , count(managerId) as cnt from Employee group by managerId
)
select name from Employee e inner join t1 on e.id=t1.managerId and t1.cnt>=5;