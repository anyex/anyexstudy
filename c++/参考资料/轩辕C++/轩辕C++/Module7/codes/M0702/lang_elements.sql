SET SERVEROUTPUT ON;
DECLARE
  v_name EMPLOYEE.empl_name%TYPE;
BEGIN
  SELECT empl_name INTO v_name FROM EMPLOYEE WHERE empl_id = 'ACC0001';
  DBMS_OUTPUT.PUT_LINE(v_name);
END;
/
SET SERVEROUTPUT ON;
<<blk_outer>>
DECLARE
  v_dept_id DEPARTMENT.depart_id%TYPE;
  v_dname DEPARTMENT.depart_name%TYPE;
BEGIN
  <<blk_inner>>
  BEGIN
    SELECT dep_depart_id
    INTO v_dept_id
    FROM EMPLOYEE
    WHERE lower(empl_name)=lower('&name');
  END blk_inner;
  SELECT depart_name INTO v_dname FROM DEPARTMENT WHERE depart_id=v_dept_id;
  DBMS_OUTPUT.PUT_LINE('Department name：'||v_dname);
END blk_outer;
/
SET SERVEROUTPUT ON;
DECLARE
  v_email EMPLOYEE.email%TYPE;
BEGIN
  SELECT email INTO v_email FROM EMPLOYEE WHERE empl_id = 'ACC0001';
  IF v_email IS NOT NULL THEN
    DBMS_OUTPUT.PUT_LINE(v_email);
  END IF;
END;
/
SET SERVEROUTPUT ON;
DECLARE
  v_salary EMPLOYEE.salary%TYPE;
  v_sal_level NUMBER(1);
BEGIN
  SELECT salary INTO v_salary FROM EMPLOYEE WHERE empl_id = 'ACC0001';
  IF v_salary     < 3000 THEN
    v_sal_level  := 1;
  ELSIF v_salary >= 3000 AND v_salary < 5000 THEN
    v_sal_level  := 2;
  ELSE
    v_sal_level := 3;
  END IF;
  DBMS_OUTPUT.PUT_LINE(v_sal_level);
END;
/
SET SERVEROUTPUT ON;
DECLARE
  v_location DEPARTMENT.location%TYPE;
BEGIN
  SELECT location INTO v_location FROM DEPARTMENT WHERE depart_id = 'RND';
  CASE v_location
  WHEN 'Beijing' THEN
    DBMS_OUTPUT.PUT_LINE('Northern China.');
  WHEN 'Shanghai' THEN
    DBMS_OUTPUT.PUT_LINE('Eastern China.');
  ELSE
    DBMS_OUTPUT.PUT_LINE('Unknown.');
  END CASE;
END;
/
SET SERVEROUTPUT ON;
DECLARE
  v_salary EMPLOYEE.salary%TYPE;
  v_sal_level NUMBER(1);
BEGIN
  SELECT salary INTO v_salary FROM EMPLOYEE WHERE empl_id = 'ACC0001';
  CASE
  WHEN v_salary  < 3000 THEN
    v_sal_level := 1;
  WHEN v_salary >= 3000 AND v_salary < 5000 THEN
    v_sal_level := 2;
  ELSE
    v_sal_level := 3;
  END CASE;
  DBMS_OUTPUT.PUT_LINE(v_sal_level);
END;
/
SET SERVEROUTPUT ON;
DECLARE
  n NUMBER(2) := 0;
BEGIN
  LOOP
    DBMS_OUTPUT.PUT_LINE('Round #' || TO_CHAR(n));
    EXIT
  WHEN n = 10;
    n   := n + 1;
  END LOOP;
END;
/
SET SERVEROUTPUT ON;
DECLARE
  n NUMBER(2) := 0;
BEGIN
  WHILE n <= 10
  LOOP
    DBMS_OUTPUT.PUT_LINE('Round #' || TO_CHAR(n));
    n := n + 1;
  END LOOP;
END;
/
SET SERVEROUTPUT ON;
BEGIN
  FOR n IN 0 .. 10
  LOOP
    DBMS_OUTPUT.PUT_LINE('Round #' || TO_CHAR(n));
  END LOOP;
END;
/
