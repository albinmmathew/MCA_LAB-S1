SET SERVEROUTPUT ON;
CREATE OR REPLACE PROCEDURE student_course_count(
	p_student_id IN VARCHAR2
) AS
	v_count NUMBER;
BEGIN
	SELECT COUNT(*)
	INTO v_count
	FROM Enrollments
	WHERE Student_ID = p_student_id;

	DBMS_OUTPUT.PUT_LINE('Student ' || p_student_id || ' is enrolled in ' || v_count || ' courses.');
END;
/
BEGIN
	student_course_count('&student_id');
END;
/
