SET SERVEROUTPUT ON;
CREATE OR REPLACE VIEW Courses_Avg_Marks AS
SELECT c.Course_ID,
c.Course_Name,
AVG(e.Marks) AS Avg_Marks,
COUNT(e.Student_ID) AS Student_Count
FROM Courses c
JOIN Enrollments e ON c.Course_ID = e.Course_ID
GROUP BY c.Course_ID, c.Course_Name
HAVING COUNT(e.Student_ID) > 1;
SELECT * FROM Courses_Avg_Marks;