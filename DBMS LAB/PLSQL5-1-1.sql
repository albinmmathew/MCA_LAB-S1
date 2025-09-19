--SET SERVEROUTPUT ON;

DECLARE
    v_course_id Courses.Course_ID%TYPE := 'CSE101'; --example input
    v_count NUMBER;
BEGIN
    SELECT COUNT(*)
    INTO v_count
    FROM Enrollments
    WHERE Course_ID = v_course_id;

    DBMS_OUTPUT.PUT_LINE('Course ' || v_course_id || ' has ' || v_count || ' students enrollments.');

END;
/