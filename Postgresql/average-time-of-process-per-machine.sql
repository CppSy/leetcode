-- Write your PostgreSQL query statement below
SELECT al.machine_id, ROUND(AVG(ar.timestamp - al.timestamp)::numeric,3) AS processing_time
FROM 
    Activity al  
JOIN 
    Activity ar 
ON al.process_id = ar.process_id AND al.machine_id = ar.machine_id AND al.activity_type = 'start' AND ar.activity_type = 'end'
GROUP BY al.machine_id;
