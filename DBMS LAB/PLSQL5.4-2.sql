SET SERVEROUTPUT ON;
CREATE OR REPLACE FUNCTION count_courses_by_dept(p_dept_id IN VARCHAR2)
RETURN NUMBER
AS
v_count NUMBER;
BEGIN
SELECT COUNT(*)
INTO v_count
FROM Courses
WHERE Dept_ID = p_dept_id;
RETURN v_count;
END;
/
BEGIN
DBMS_OUTPUT.PUT_LINE('Total courses in department: ' || count_courses_by_dept('&dept_id'));
END;
/