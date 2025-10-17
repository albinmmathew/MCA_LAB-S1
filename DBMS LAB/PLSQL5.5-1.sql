SET SERVEROUTPUT ON;
CREATE OR REPLACE TRIGGER trg_prevent_delete_course
BEFORE DELETE ON Courses
FOR EACH ROW
BEGIN
IF :OLD.Credits > 2 THEN
RAISE_APPLICATION_ERROR(-20001, 'Cannot delete course with more than 2 credits.');
END IF;
END;
/
BEGIN
DELETE from Courses where Credits>2;
END;
/