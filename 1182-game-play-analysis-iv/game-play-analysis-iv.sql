with t1 as(
    select player_id,
    min(event_date) as event_date from Activity 
    group by player_id   
)

select 
round(sum(if(datediff(a.event_date,t1.event_date)=1 ,1,0))/(select count(*)from t1 as total_players),2) as fraction
from t1 join Activity a on t1.player_id=a.player_id;