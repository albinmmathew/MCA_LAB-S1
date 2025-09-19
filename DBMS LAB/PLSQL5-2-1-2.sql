--SET SERVEROUTPUT ON;
DECLARE
  v_no NUMBER := 1;
  v_name VARCHAR2(10);
BEGIN
  WHILE v_no <= 10 LOOP
    SELECT sNAME INTO v_name FROM S WHERE NO = v_no;
    DBMS_OUTPUT.PUT_LINE('NO: ' || v_no || ' NAME: ' || v_name);
    v_no := v_no + 1;
  END LOOP;
END;
/