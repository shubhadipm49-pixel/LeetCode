# Write your MySQL query statement below
SELECT 
    s1.student_id,
    s1.subject,
    s2.score AS first_score,
    s3.score AS latest_score
FROM (
    SELECT 
        student_id,
        subject,
        MIN(exam_date) AS first_exam,
        MAX(exam_date) AS latest_exam
    FROM Scores
    GROUP BY student_id, subject
    HAVING COUNT(*) >= 2
) AS s1 
LEFT JOIN Scores s2 
    ON s1.student_id = s2.student_id 
    AND s1.subject = s2.subject 
    AND s1.first_exam = s2.exam_date
LEFT JOIN Scores s3 
    ON s1.student_id = s3.student_id 
    AND s1.subject = s3.subject 
    AND s1.latest_exam = s3.exam_date
WHERE s2.score < s3.score
ORDER BY s1.student_id, s1.subject;