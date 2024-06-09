-- Write your PostgreSQL query statement below
WITH rankedOrders as (
    select
        *,
        ROW_NUMBER() over (partition by customer_id order by order_date asc) as order_number
        from Delivery
)
select
    round(sum(
        case
            when order_number = 1 and order_date::date = customer_pref_delivery_date::date then 1
        else 0
    end
    )::numeric * 100 / sum(
        case
            when order_number = 1 then 1
            else 0
        end
    ), 2) as immediate_percentage
from rankedOrders