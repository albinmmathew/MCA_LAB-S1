SET SERVEROUTPUT ON;
CREATE OR REPLACE TRIGGER trg_no_weekend_changes
BEFORE UPDATE OR DELETE ON Courses
FOR EACH ROW
BEGIN
-- Check if today is Saturday or Sunday
IF TO_CHAR(SYSDATE,'D') IN ('7','1') THEN
RAISE_APPLICATION_ERROR(-20003, 'Updates or deletes not allowed on weekends.');
END IF;
END;
/