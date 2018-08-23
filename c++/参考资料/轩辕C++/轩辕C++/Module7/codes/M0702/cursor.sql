SET SERVEROUTPUT ON;
DECLARE
  CURSOR cur_empl_info
  IS -- 定义游标
    SELECT empl_id, empl_name, salary FROM EMPLOYEE WHERE dep_depart_id = 'RND';
TYPE rec_empl_info
IS
  RECORD
  (
    v_empl_id EMPLOYEE.empl_id%TYPE,
    v_empl_name EMPLOYEE.empl_name%TYPE,
    v_salary EMPLOYEE.salary%TYPE );
  v_info rec_empl_info;
BEGIN
  OPEN cur_empl_info;
  LOOP
    FETCH cur_empl_info INTO v_info;
    EXIT WHEN cur_empl_info%NOTFOUND;
    -- 输出：fetch的行数、empl_id、empl_name、salary
    DBMS_OUTPUT.PUT_LINE('Employee #' 
      || TO_CHAR(cur_empl_info%ROWCOUNT) || ': ' 
      || v_info.v_empl_id || v_info.v_empl_name || TO_CHAR(v_info.v_salary));
  END LOOP;
  CLOSE cur_empl_info;
END;
/ 

SET SERVEROUTPUT ON;
BEGIN
    UPDATE DEPARTMENT SET location = 'Shenzhen'
    WHERE depart_id = 'PRD';
    
    IF SQL%NOTFOUND THEN  -- 或使用下面的语句
	-- IF SQL%ROWCOUNT = 0 THEN
        DBMS_OUTPUT.PUT_LINE('No such department, add it!');
        INSERT INTO DEPARTMENT 
        VALUES ('PRD', 'Public Relation', 'Shenzhen');
    END IF;
END;
/

SET SERVEROUTPUT ON;
DECLARE
    v_name  DEPARTMENT.depart_name%TYPE;
BEGIN
    SELECT depart_name INTO v_name
    FROM DEPARTMENT
    WHERE depart_id = 'ANG';
    
    IF SQL%FOUND THEN
        DELETE FROM DEPARTMENT 
        WHERE depart_id = 'ANG';
    END IF;
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('No such department');
    WHEN TOO_MANY_ROWS THEN
        DBMS_OUTPUT.PUT_LINE('Too many department matched');
END;
/


SET SERVEROUTPUT ON;
DECLARE
    v_dept  DEPARTMENT%ROWTYPE;
    TYPE cur_dept_type 
        IS REF CURSOR RETURN v_dept%TYPE;
        
    cur_dept cur_dept_type;
BEGIN
    OPEN cur_dept FOR
        SELECT * FROM DEPARTMENT WHERE depart_id = 'RND';
    
    LOOP
        FETCH cur_dept INTO v_dept;
        EXIT WHEN cur_dept%NOTFOUND;
        DBMS_OUTPUT.PUT_LINE(TO_CHAR(cur_dept%ROWCOUNT) || 
                            ' ' || v_dept.depart_name);
    END LOOP;
    CLOSE cur_dept;
    
    OPEN cur_dept FOR
        SELECT * FROM DEPARTMENT WHERE depart_id = 'ACC';
        
    LOOP
        FETCH cur_dept INTO v_dept;
        EXIT WHEN cur_dept%NOTFOUND;
        DBMS_OUTPUT.PUT_LINE(TO_CHAR(cur_dept%ROWCOUNT) || 
                             ' ' || v_dept.depart_name);
    END LOOP;
    CLOSE cur_dept;
END;
/
