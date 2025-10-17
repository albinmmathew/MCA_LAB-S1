SET SERVEROUTPUT ON;
CREATE OR REPLACE PROCEDURE add_course(
p_course_id IN VARCHAR2,
p_course_name IN VARCHAR2,
p_dept_id IN VARCHAR2,
p_prof_id IN VARCHAR2,
p_credits IN NUMBER
) AS
v_dept NUMBER;
v_prof NUMBER;
BEGIN
-- Check if department exists
SELECT COUNT(*) INTO v_dept FROM Departments WHERE Dept_ID = p_dept_id;
-- Check if professor exists
SELECT COUNT(*) INTO v_prof FROM Professors WHERE Prof_ID = p_prof_id;
IF v_dept > 0 AND v_prof > 0 THEN
INSERT INTO Courses (Course_ID, Course_Name, Dept_ID, Prof_ID, Credits, Total_Students)
VALUES (p_course_id, p_course_name, p_dept_id, p_prof_id, p_credits, 0);
DBMS_OUTPUT.PUT_LINE('Course ' || p_course_name || ' added successfully.');
ELSE
DBMS_OUTPUT.PUT_LINE('Department or Professor not found. Cannot add course.');	
END IF;
END;
/
BEGIN
add_course('CIV102', 'Concrete Design', 'D04', 'P1004', 3);
END;
/
