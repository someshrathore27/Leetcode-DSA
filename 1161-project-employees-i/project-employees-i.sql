# Write your MySQL query statement below
with t1 as (
    select p.project_id,e.experience_years from Project p inner join Employee e on
    p.employee_id = e.employee_id
)
select t1.project_id as project_id , round(avg(t1.experience_years),2) as average_years from t1 group by t1.project_id;