SET SERVEROUTPUT ON;
DECLARE
	v_count NUMBER;
BEGIN
	SELECT COUNT(*)
	INTO v_count
	FROM Departments
	WHERE Dept_Name = 'Biotech';

	IF v_count = 0 THEN
		INSERT INTO Departments (Dept_ID, Dept_Name, Building, Number_of_Classrooms)
		VALUES ('D05', 'Biotech', 'Bio Block', 5);
		DBMS_OUTPUT.PUT_LINE('Department Biotech inserted.');
	ELSE
		DBMS_OUTPUT.PUT_LINE('Department Biotech already exists.');
	END IF;
END;
/