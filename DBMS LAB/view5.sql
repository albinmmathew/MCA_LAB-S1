CREATE VIEW emp_view AS
SELECT emp_id, emp_name, dept_id, salary
FROM employees;

CREATE OR REPLACE TRIGGER trg_emp_insert
INSTEAD OF INSERT ON emp_view
FOR EACH ROW
BEGIN
    INSERT INTO employees (emp_id, emp_name, dept_id, salary)
    VALUES (:NEW.emp_id, :NEW.emp_name, :NEW.dept_id, :NEW.salary);
END;
/