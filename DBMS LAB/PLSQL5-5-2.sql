-- Trigger -- after insert
SET SERVEROUTPUT ON;

CREATE TABLE student_log (
    SID NUMBER,
    action_date DATE
);

CREATE OR REPLACE TRIGGER trg_log_insert
AFTER INSERT ON Std
FOR EACH ROW
BEGIN
    INSERT INTO student_log VALUES (:NEW.SID, SYSDATE);
END;
/