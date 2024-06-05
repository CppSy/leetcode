with reports as (
    select managerId, count(*) as cnt from employee
    group by managerId
    having count(*) >= 5
)
select name from employee
join reports on employee.id = reports.managerId;