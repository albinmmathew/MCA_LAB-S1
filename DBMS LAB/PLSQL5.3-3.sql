SET SERVEROUTPUT ON;
CREATE TABLE Course_Log (
Course_ID VARCHAR2(6),
Old_Credits NUMBER(1),
New_Credits NUMBER(1),
Update_Date DATE
);
CREATE OR REPLACE PROCEDURE update_course_credits(
p_course_id IN VARCHAR2,
p_new_credits IN NUMBER
) AS
v_old NUMBER;
BEGIN
SELECT Credits INTO v_old FROM Courses WHERE Course_ID = p_course_id;
UPDATE Courses
SET Credits = p_new_credits
WHERE Course_ID = p_course_id;
INSERT INTO Course_Log VALUES (p_course_id, v_old, p_new_credits, SYSDATE);
DBMS_OUTPUT.PUT_LINE('Credits updated and logged for ' || p_course_id);
END;
/
BEGIN
update_course_credits('ME101', 4);
END;
/
