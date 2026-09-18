# Write your MySQL query statement below
select * , case
                when (x+y)>z && (x+z)>y && (y+z)>x then 'Yes'
                else 'No'
            end as triangle
from Triangle;