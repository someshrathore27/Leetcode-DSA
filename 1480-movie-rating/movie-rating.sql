# Write your MySQL query statement below
with t1 as(
    select user_id , count(user_id) as cnt from MovieRating group by user_id
),
r1 as(
     select u.name as results from Users u join t1 on u.user_id=t1.user_id order by t1.cnt desc,u.name asc limit 1 
),
t3 as(
    select * from MovieRating where year(created_at)=2020 and month(created_at)=02
),
t4 as(
    select movie_id, avg(rating) ag from t3 group by movie_id
),
r2 as(
    select m.title as results from Movies m join t4 on m.movie_id=t4.movie_id order by t4.ag desc, m.title asc limit 1
)
select r1.results from r1 
union all
select r2.results from r2 
