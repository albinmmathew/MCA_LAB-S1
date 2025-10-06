SET SERVEROUTPUT ON;
/*
CREATE TABLE employees (
    emp_id NUMBER ,
    emp_name VARCHAR2(20),
    dept_id NUMBER,
    salary NUMBER
);

INSERT INTO employees VALUES (1, 'Alice', 10, 40000);
INSERT INTO employees VALUES (2, 'Bob', 20, 50000);
INSERT INTO employees VALUES (3, 'Charlie', 10, 45000);
COMMIT; */

CREATE VIEW dept10_view AS
SELECT emp_id, emp_name, salary
FROM employees
WHERE dept_id = 10;

BEGIN
    FOR rec IN (SELECT * FROM dept10_view ) LOOP
        DBMS_OUTPUT.PUT_LINE(rec.emp_name || ' earns ' || rec.salary);
    END LOOP;
END;
/