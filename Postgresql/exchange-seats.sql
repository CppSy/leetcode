-- Write your PostgreSQL query statement below
select id, 
case 
when id%2 = 1 and lead(student) over(order by id) is null then student
when id%2 = 0 then lag(student) over (order by id)
else lead(student) over (order by id)
end as student
from Seat