SET SERVEROUTPUT ON;
DECLARE
	v_rows NUMBER;
BEGIN
	UPDATE Enrollments
	SET Marks = Marks + 2
	WHERE Semester = 'Sem1';
	v_rows := SQL%ROWCOUNT;
	DBMS_OUTPUT.PUT_LINE('Marks updated for ' || v_rows || ' students.');
END;
/