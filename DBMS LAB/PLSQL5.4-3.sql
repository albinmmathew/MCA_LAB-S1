SET SERVEROUTPUT ON;
CREATE OR REPLACE FUNCTION teaches_more_than_two(p_prof_id IN VARCHAR2)
RETURN VARCHAR2
AS
v_count NUMBER;
BEGIN
SELECT COUNT(*)
INTO v_count
FROM Courses
WHERE Prof_ID = p_prof_id;
IF v_count > 2 THEN
RETURN 'YES';
ELSE
RETURN 'NO';
END IF;
END;
/
BEGIN
DBMS_OUTPUT.PUT_LINE('Does professor teach >2 courses? ' || teaches_more_than_two('&pid'));
END;
/
