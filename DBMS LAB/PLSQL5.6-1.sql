SET SERVEROUTPUT ON;
CREATE OR REPLACE VIEW Students_Course_Count AS
SELECT s.Student_ID,
s.Student_Name,
(SELECT COUNT(*)
FROM Enrollments e
WHERE e.Student_ID = s.Student_ID) AS Courses_Enrolled
FROM Students s;
SELECT * FROM Students_Course_Count;