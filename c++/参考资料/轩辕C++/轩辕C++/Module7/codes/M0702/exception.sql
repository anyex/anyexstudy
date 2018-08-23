SET SERVEROUTPUT ON;
DECLARE
  v_salary         INTEGER;
  e_invalid_salary EXCEPTION;
BEGIN
  SELECT salary INTO v_salary FROM EMPLOYEE WHERE empl_id = 'ACC0001';
  IF v_salary < 5000 THEN
    RAISE e_invalid_salary;
  END IF;
EXCEPTION
WHEN e_invalid_salary THEN
  DBMS_OUTPUT.PUT_LINE('Catch e_invalid_salary');
  UPDATE EMPLOYEE SET salary = 5000 WHERE empl_id = 'ACC0001';
END;
/
