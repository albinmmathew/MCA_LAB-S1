SET SERVEROUTPUT ON;

CREATE OR REPLACE VIEW emp_readonly AS
SELECT * FROM employees
WITH READ ONLY;

BEGIN
    UPDATE emp_readonly
    SET salary = 60000
    WHERE emp_id = 2;
EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Cannot update read-only view');
END;
/