SET SERVEROUTPUT ON;
DECLARE
	CURSOR c1 IS
	SELECT s.Student_Name, e.Marks
	FROM Students s, Enrollments e
	WHERE s.Student_ID = e.Student_ID
	AND e.Marks > 80;
BEGIN
	FOR rec IN c1
	LOOP
		DBMS_OUTPUT.PUT_LINE(rec.Student_Name || ' scored ' || rec.Marks);
	END LOOP;
END;
/