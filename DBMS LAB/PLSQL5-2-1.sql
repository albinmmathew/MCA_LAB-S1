--SET SERVEROUTPUT ON;

BEGIN
    FOR i IN 1..5 LOOP
        DBMS_OUTPUT.PUT_LINE('Square of ' || i || ' = ' || i*i );
    END LOOP;
END;
/
