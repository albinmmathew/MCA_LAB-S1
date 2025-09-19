--SET SERVEROUTPUT ON;

DECLARE
    v_count NUMBER;
BEGIN
    SELECT COUNT(*)
    INTO v_count
    FROM Departments
    WHERE Dept_Name = 'Biotech';

    if v_count = 0 THEN
        INSERT INTO Departments(Dept_ID, Dept_Name, Building, Number_of_classrooms)
        VALUES('D05', 'Biotech', 'Bio Block', 1);
        DBMS_OUTPUT.PUT_LINE('Department biotech inserted');
    ELSE
        DBMS_OUTPUT.PUT_LINE('Department already exits.');
    END IF;
END;
/