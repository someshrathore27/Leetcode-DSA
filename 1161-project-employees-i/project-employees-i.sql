# Write your MySQL query statement below
select p.project_id as project_id,CAST(AVG(e.experience_years) AS DECIMAL(10,2)) as average_years from Project p inner join Employee e on
p.employee_id = e.employee_id group by p.project_id;
