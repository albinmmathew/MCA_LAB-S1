SET SERVEROUTPUT ON;
DECLARE
v_course_id Courses.Course_ID%TYPE;
v_student_count NUMBER;
BEGIN
v_course_id := '&course_id';
SELECT COUNT(*)
INTO v_student_count
FROM Enrollments
WHERE Course_ID = v_course_id;
DBMS_OUTPUT.PUT_LINE('Number of students enrolled in ' || v_course_id || ': ' || v_student_count);
END;
/