# Write your MySQL query statement below
with m1 as
(select a1.machine_id,a1.process_id, (a2.timestamp-a1.timestamp) as diff from Activity a1 join  Activity a2 on 
    a1.machine_id=a2.machine_id && a1.process_id=a2.process_id &&
    a1.activity_type='start' && a2.activity_type='end'
)
select m1.machine_id,round(avg(diff),3) as processing_time from m1 group by m1.machine_id; 
