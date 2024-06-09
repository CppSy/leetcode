
select round (count(*)::numeric / (select count (distinct player_id) from activity) , 2) fraction
from activity
where (player_id , event_date) in (
        select player_id , min(event_date) + 1 firstLog 
        from activity 
        group by 1 )

