-- Trigger -- before UPDATION
SET SERVEROUTPUT ON;

CREATE OR REPLACE TRIGGER trg_no_mark_decrease
BEFORE UPDATE OF marks ON Std
FOR EACH ROW
BEGIN
    IF :NEW.marks < :OLD.marks THEN
        RAISE_APPLICATION_ERROR(-20001, 'Marks Cannot be reduced');
    END IF;
END;
/