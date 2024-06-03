/* Write a solution to find the number of times each student attended each exam.
Return the result table ordered by student_id and subject_name.
The result format is in the following example. */

-- Write your PostgreSQL query statement below
SELECT 
    st.student_id, 
    st.student_name, 
    su.subject_name, 
    COUNT(e.subject_name) AS attended_exams
FROM 
    Students st
CROSS JOIN 
    Subjects su
LEFT JOIN 
    Examinations e ON st.student_id = e.student_id AND su.subject_name = e.subject_name
GROUP BY 
    st.student_id, 
    st.student_name, 
    su.subject_name
ORDER BY 
    st.student_id, 
    su.subject_name;