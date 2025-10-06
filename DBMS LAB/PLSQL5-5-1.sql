-- Trigger -- before insert
SET SERVEROUTPUT ON;

CREATE OR REPLACE TRIGGER trg_check_marks
BEFORE INSERT ON Std
FOR EACH ROW
BEGIN
    IF :NEW.marks < 35 THEN
        RAISE_APPLICATION_ERROR(-20001, 'Marks must be atleast 35.');
    END IF;
END;
/