SET SERVEROUTPUT ON;
DECLARE
	v_total_students NUMBER;
BEGIN
	SELECT COUNT(*)
	INTO v_total_students
	FROM Students
	WHERE Dept_ID = (
		SELECT Dept_ID
		FROM Departments
		WHERE Dept_Name = 'Computer Science'
	);

	DBMS_OUTPUT.PUT_LINE('Total students in Computer Science: ' || v_total_students);
END;
/