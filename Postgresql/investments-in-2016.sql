-- Write your PostgreSQL query statement below

select
round(sum(tiv_2016)::numeric,2) as tiv_2016
from insurance
where (lat,lon) not in 
    (select lat,lon 
    from insurance
    group by lat,lon
    having count(*) > 1)
and 
    tiv_2015 in 
    (select tiv_2015
    from insurance
    group by tiv_2015 
    having count(tiv_2015) > 1)