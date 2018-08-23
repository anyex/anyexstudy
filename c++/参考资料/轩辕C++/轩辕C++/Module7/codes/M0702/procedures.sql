
SET SERVEROUTPUT ON;
CREATE OR REPLACE PROCEDURE test_proc (
	arg1	IN OUT	EMPLOYEE.dep_depart_id%TYPE,
	arg2	IN		EMPLOYEE.empl_name%TYPE,
	arg3	OUT		INTEGER) AS
	-- 过程内部的变量在 AS 和 BEGIN之间定义
	v_sal	EMPLOYEE.salary%TYPE;
BEGIN
	SELECT salary INTO v_sal FROM EMPLOYEE
	WHERE dep_depart_id = arg1 AND empl_name = arg2;
	
	arg3 := 0; -- Success
EXCEPTION
	WHEN NO_DATA_FOUND THEN
		arg3 := 1;
	WHEN TOO_MANY_ROWS THEN
		arg3 := 2;
	WHEN OTHERS THEN
		arg3 := 3;
END test_proc;
/

SET SERVEROUTPUT ON;
DECLARE
	v_did	EMPLOYEE.dep_depart_id%TYPE;
	v_ename	EMPLOYEE.empl_name%TYPE;
	v_res	INTEGER;
BEGIN
	v_did := 'ACG';
	v_ename := 'Luo jin';
	
	test_proc(v_did, v_ename, v_res); -- 调用存储过程
	DBMS_OUTPUT.PUT_LINE('Result is: ' || to_char(v_res));
END;
/

SET SERVEROUTPUT ON;
DECLARE
	v_did	EMPLOYEE.dep_depart_id%TYPE;
	v_ename	EMPLOYEE.empl_name%TYPE;
	v_res	INTEGER;
BEGIN
	v_did := 'ACC';
	v_ename := 'Luo jin';

	/* 注意以下传参的语法：将实参与test_proc的形参关联起来，
                  这样就不必按存储过程声明时的参数顺序传参*/
	test_proc(arg1=>v_did, arg3=>v_res, arg2=>v_ename); 
	DBMS_OUTPUT.PUT_LINE('Result is: ' || to_char(v_res));
END;
/

CREATE OR REPLACE PROCEDURE proc1 (
    arg1 INTEGER, -- 参数形式没指定，则默认为IN
    arg2 VARCHAR2) AS
BEGIN
    FOR n IN 0..arg1 LOOP
        DBMS_OUTPUT.PUT_LINE(TO_CHAR(n) || ': ' || arg2);
    END LOOP;
END proc1;
/
SET SERVEROUTPUT ON;
call proc1 (10, 'hello');
-- 或
SET SERVEROUTPUT ON;
exec proc1 (10, 'hello');

CREATE OR REPLACE FUNCTION calc_level (
	arg_eid	EMPLOYEE.empl_id%TYPE)
	RETURN INTEGER AS
	v_lev	INTEGER;
	v_sal	EMPLOYEE.salary%TYPE;
BEGIN
	SELECT salary INTO v_sal
	FROM EMPLOYEE WHERE empl_id = arg_eid;
	
	CASE
		WHEN v_sal < 3000 THEN v_lev := 1;
		WHEN v_sal BETWEEN 3000 AND 3999 THEN v_lev := 2;
		WHEN v_sal BETWEEN 4000 AND 4999 THEN v_lev := 3;
		ELSE v_lev := 4;
	END CASE;
  
	RETURN v_lev;
	
EXCEPTION
	WHEN NO_DATA_FOUND THEN
		RETURN 0;
	WHEN OTHERS THEN
		RETURN -1;
END calc_level;
/

SET SERVEROUTPUT ON;
DECLARE
	v_lev	INTEGER;
BEGIN
	v_lev := calc_level('ACC0001');
	DBMS_OUTPUT.PUT_LINE('Salary level of ACC0001 is: ' || TO_CHAR(v_lev));
END;
/

CREATE OR REPLACE TRIGGER trigger_empl 
    AFTER INSERT OR UPDATE OR DELETE ON EMPLOYEE
    FOR EACH ROW
BEGIN
    IF INSERTING THEN
        INSERT INTO op_log
        VALUES (seq_op_log.NEXTVAL, USER, 
				'insert', :NEW.empl_id, SYSDATE);
    ELSIF UPDATING THEN
        INSERT INTO op_log
        VALUES (seq_op_log.NEXTVAL, USER, 
				'update', :NEW.empl_id, SYSDATE);
    ELSIF DELETING THEN
        INSERT INTO op_log
        VALUES (seq_op_log.NEXTVAL, USER, 
				'delete', :OLD.empl_id, SYSDATE);
    END IF;  
END;
/

select * from op_log;