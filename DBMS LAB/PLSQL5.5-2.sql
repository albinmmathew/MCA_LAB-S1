SET SERVEROUTPUT ON;
CREATE TABLE Enrollments_Log (
Student_ID VARCHAR2(6),
Course_ID VARCHAR2(6),
Old_Marks NUMBER(5,2),
New_Marks NUMBER(5,2),
Update_Date DATE
);
set serveroutput on;
CREATE OR REPLACE TRIGGER trg_log_marks_update
AFTER UPDATE OF Marks ON Enrollments
FOR EACH ROW
BEGIN
INSERT INTO Enrollments_Log
VALUES (:OLD.Student_ID, :OLD.Course_ID, :OLD.Marks, :NEW.Marks, SYSDATE);
END;
/