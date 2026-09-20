with t1 as (
    select distinct product_id from Products
),
t2 as(
    select * from Products where change_date<='2019-08-16' 
),
t3 as(
    select t.product_id , t.new_price from(
        select * , row_number() over (
            partition by product_id 
            order by change_date desc
        ) as rn
        from t2
    )t 
    where rn=1
)

select t1.product_id,
case
    when t3.new_price is null then 10
    else t3.new_price
end
as price from t1  left join t3 
on t1.product_id=t3.product_id;