-- Write your PostgreSQL query statement below
with prod as 
(
    select distinct product_id from Products
), 
cte as 
(
    select product_id, new_price, dense_rank() over(partition by product_id order by change_date desc) as rnk
    from Products where change_date<='2019-08-16'
)

select p.product_id, COALESCE(cte.new_price,10) as price from prod p left join cte on p.product_id = cte.product_id where rnk=1 or rnk is null