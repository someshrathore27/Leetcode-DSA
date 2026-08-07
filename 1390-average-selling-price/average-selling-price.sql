# Write your MySQL query statement below
-- select p1.product_id , ifnull(ROUND(SUM(p2.units * p1.price) / SUM(p2.units), 2),0) AS average_price from Prices p1 left join 
-- UnitsSold p2 on p1.product_id=p2.product_id AND p2.purchase_date BETWEEN p1.start_date AND p1.end_date group by p1.product_id;


select p.product_id , ifnull(round(sum(p.price*u.units)/sum(u.units),2),0) as average_price  from Prices p left join UnitsSold u 
on p.product_id = u.product_id and u.purchase_date between p.start_date and p.end_date 
group by p.product_id