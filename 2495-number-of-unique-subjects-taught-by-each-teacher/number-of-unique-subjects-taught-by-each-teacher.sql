# Write your MySQL query statement below
with t as(
    select teacher_id,subject_id
    from Teacher t group by teacher_id , subject_id
)

select teacher_id , 
count(teacher_id) as cnt from t group by teacher_id;