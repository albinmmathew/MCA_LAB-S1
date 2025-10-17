SET SERVEROUTPUT ON;
CREATE OR REPLACE TRIGGER trg_prevent_duplicate_enroll
BEFORE INSERT ON Enrollments
FOR EACH ROW
DECLARE
v_count NUMBER;
BEGIN
SELECT COUNT(*) INTO v_count
FROM Enrollments
WHERE Student_ID = :NEW.Student_ID
AND Course_ID = :NEW.Course_ID;
IF v_count > 0 THEN
RAISE_APPLICATION_ERROR(-20002, 'Student already enrolled in this course.');
END IF;
END;
/
BEGIN
INSERT INTO Enrollments (Student_ID, Course_ID, Semester, Marks)
VALUES ('S0001', 'CSE101', 'Sem1', 90);
END;
/