SET SERVEROUTPUT ON;
CREATE OR REPLACE FUNCTION get_student_age(p_student_id IN VARCHAR2)
RETURN NUMBER
AS
v_age NUMBER;
v_dob DATE;
BEGIN
-- Get DOB from table
SELECT DOB INTO v_dob
FROM Students
WHERE Student_ID = p_student_id;
-- Calculate age
v_age := TRUNC(MONTHS_BETWEEN(SYSDATE, v_dob)/12);
RETURN v_age;
END;
/
BEGIN
DBMS_OUTPUT.PUT_LINE('Age: ' || get_student_age('&student_id'));
END;
/
