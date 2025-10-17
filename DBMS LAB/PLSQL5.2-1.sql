SET SERVEROUTPUT ON;
DECLARE
	v_rows NUMBER;
BEGIN
	INSERT INTO Students (Student_ID, Student_Name, Dept_ID, DOB)
	VALUES ('S0005', 'Rahul Dev', 'D02', DATE '2003-09-15');
	v_rows := SQL%ROWCOUNT;
	DBMS_OUTPUT.PUT_LINE('Rows inserted: ' || v_rows);
END;
/