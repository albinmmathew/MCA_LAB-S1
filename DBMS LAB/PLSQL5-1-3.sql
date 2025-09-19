--SET SERVEROUTPUT ON;

DECLARE
    v_total NUMBER;
BEGIN
    SELECT COUNT(*)
    INTO v_total
    FROM Students
    WHERE Dept_ID = (SELECT Dept_ID FROM Departments WHERE Dept_Name = 'Computer Science');
    DBMS_OUTPUT.PUT_LINE('Total Students in Computer Science: ' || v_total);
END;
/
/