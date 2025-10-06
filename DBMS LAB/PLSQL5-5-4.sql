-- Trigger -- after deletion
SET SERVEROUTPUT ON;

CREATE TABLE student_delete_log (
    SID NUMBER,
    deleted_date DATE
);

CREATE OR REPLACE TRIGGER trg_log_delete
AFTER DELETE ON Std
FOR EACH ROW
BEGIN
    INSERT INTO student_delete_log VALUES (:OLD.SID, SYSDATE);
END;
/