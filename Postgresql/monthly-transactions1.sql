-- Write your PostgreSQL query statement below

select to_char(trans_date, 'YYYY-MM') as month
, country
, count(id) as trans_count
, sum(case when state = 'approved' then 1 else 0 end) as approved_count
, sum(amount) as trans_total_amount
, sum(case when state = 'approved' then amount else 0 end) as approved_total_amount
from transactions
group by 1,2