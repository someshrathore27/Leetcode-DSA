with t1 as (
    select distinct employee_id from Employees
)
select employee_id from Employees where manager_id not in (select employee_id from t1) and 
salary<30000 order by employee_id;