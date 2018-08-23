call attendance_sys.simpleproc(@x);
select @x;

select count(*) from Employee;

select hello('bill');

show create procedure attendance_sys.simpleproc;

select count(*) into @n from Employee;
select @n;

delimiter $$
CREATE PROCEDURE test_cursor()
BEGIN
  DECLARE done INT DEFAULT 0;
  DECLARE dept_id VARCHAR(6);
  DECLARE max_sal INT;
  DECLARE cur1 CURSOR FOR 
    SELECT depart_id, max(salary) FROM Employee
    GROUP BY depart_id;
  DECLARE CONTINUE HANDLER FOR SQLSTATE '02000' SET done = 1;

  OPEN cur1;
  REPEAT
    FETCH cur1 INTO dept_id, max_sal;
    IF NOT done THEN
       SELECT dept_id, max_sal;
    END IF;
  UNTIL done END REPEAT;

  CLOSE cur1;
END$$

 delimiter ;

call attendance_sys.test_cursor();

DELIMITER $$
DROP PROCEDURE IF EXISTS calc_level2$$
CREATE PROCEDURE calc_level2(IN eid varchar(8))
BEGIN
    DECLARE sal, level INT;
    SELECT salary INTO sal
    FROM Employee WHERE empl_id = eid;
    
    IF sal < 3000 THEN
        SET level = 1;
    ELSEIF sal > 3000 AND sal < 4000 THEN
        SET level = 2;
    ELSE
        SET level = 3;
    END IF;

    SELECT CONCAT('Level of ',eid,' is: ',level) result;
END$$
DELIMITER ;

call        calc_level2('ACC0001');
                                                                                         
select * from Employee where empl_id =  'ACC0001';


DELIMITER $$
DROP PROCEDURE IF EXISTS guess_num$$

CREATE PROCEDURE guess_num(IN num INT)
BEGIN    
    CASE num
        WHEN 12 THEN
            SELECT 'Good luck!';
        WHEN 64 THEN
            SELECT 'Good luck too!';
        ELSE
            SELECT 'Try again!';
    END CASE;
END$$
DELIMITER ;

call guess_num(64);


     DELIMITER $$
DROP PROCEDURE IF EXISTS calc_level3$$
CREATE PROCEDURE calc_level3(IN eid varchar(8))
BEGIN
    DECLARE sal, level INT;
    SELECT salary INTO sal
    FROM Employee WHERE empl_id = eid;
    
    CASE
        WHEN sal < 3000 THEN
            SET level = 1;
        WHEN sal > 3000 AND sal < 4000 THEN
            SET level = 2;
        ELSE
            SET level = 3;
    END CASE;

    SELECT CONCAT('Level of ',eid,' is: ',level) result;
END$$
DELIMITER ;

call             calc_level3('ACC0001');


DELIMITER $$
DROP PROCEDURE IF EXISTS loop_test1$$
CREATE PROCEDURE loop_test1()
BEGIN
    DECLARE i INT;
    SET i = 0;
    lp: LOOP
        IF i > 20 THEN
            LEAVE lp;
        ELSEIF MOD(i, 3) = 0 THEN
            SET i = i + 2;
            ITERATE lp;
        ELSE
           SET i = i + 1;
        END IF;
    END LOOP lp;        
END$$
DELIMITER ;

call loop_test1();

DELIMITER $$
DROP PROCEDURE IF EXISTS repeat_test1$$
CREATE PROCEDURE repeat_test1()
BEGIN
    DECLARE i INT;
    SET i = 0;
    REPEAT
        SET i = i + 1;
    UNTIL i > 10
    END REPEAT;
END$$
DELIMITER ;

DELIMITER $$
DROP PROCEDURE IF EXISTS while_test1$$
CREATE PROCEDURE while_test1()
BEGIN
    DECLARE i  INT;
    SET i = 0;
    WHILE i <= 10 DO
        SET i = i + 1;
    END WHILE;
END$$

DELIMITER ;


DELIMITER $$
DROP PROCEDURE  IF EXISTS add_department1$$
CREATE PROCEDURE add_department1 (
		dept_id VARCHAR(6),
		dept_name VARCHAR(32),
		dept_location VARCHAR(45))
	MODIFIES SQL DATA  -- 存储过程的特征(characteristic)
BEGIN
	DECLARE duplicate_key INT DEFAULT 0;
	BEGIN -- 遇到1062错误则退出该语句块，而不是退出子程序
		-- Code 1062: Duplicate key
		DECLARE EXIT HANDLER FOR 1062 SET duplicate_key = 1;

		INSERT INTO Department (depart_id, name, location)
		VALUES (dept_id,dept_name,dept_location);
		SELECT CONCAT('Department ',dept_id,' created') Result;
	END;
	IF duplicate_key = 1 THEN
		SELECT CONCAT('Failed to insert ',dept_id,
                      ': duplicate key') Result;
        END IF;
END$$   
DELIMITER ;

call   add_department1 ('ACC', 'acc department', 'Beijing');


DELIMITER $$
DROP PROCEDURE  IF EXISTS add_department1$$

CREATE PROCEDURE add_department2 (
		dept_id VARCHAR(6),
		dept_name VARCHAR(32),
		dept_location VARCHAR(45))
	MODIFIES SQL DATA -- 存储过程的特征(characteristic)
BEGIN
	DECLARE duplicate_key INT DEFAULT 0;	
	-- Code 1062: Duplicate key 
	DECLARE CONTINUE HANDLER FOR 1062 SET duplicate_key = 1;

	INSERT INTO Department (depart_id, name, location)
	VALUES (dept_id,dept_name,dept_location);
	
    -- 如果遇到1062错误，则会转到此处，继续执行以下代码
	IF duplicate_key = 1 THEN
		SELECT CONCAT('Failed to insert ',dept_id,
                      ': duplicate key') Result;
    ELSE
    	SELECT CONCAT('Department ',dept_id,' created') Result;
    END IF;
END$$
 DELIMITER ;

call   add_department2 ('ACM', 'acc department', 'Beijing');

 DELIMITER $$
DROP PROCEDURE  IF EXISTS transfer$$
CREATE PROCEDURE transfer (
		account_from INT, 
		account_to INT,
		amount NUMERIC(6,2))
BEGIN
	DECLARE has_error INT DEFAULT 0;
	DECLARE CONTINUE HANDLER 
		FOR SQLEXCEPTION SET has_error = 1;
    SET AUTOCOMMIT = 0; -- 禁止自动提交事务，同：START TRANSACTION;
    UPDATE ACCOUNT
       SET balance = balance - amount
	WHERE account_id = account_from;
    UPDATE ACCOUNT
       SET balance = balance + amount
	WHERE account_id = account_to;	
	IF has_error = 1 THEN
		ROLLBACK;  -- 如果有任何错误，须回滚事务
	ELSE
		COMMIT; -- 只有所有操作都成功执行，才提交事务
	END IF;
END$$
 DELIMITER ;


                                   -- 操作日志表
DROP TABLE IF EXISTS op_log;
CREATE TABLE op_log (
    log_seq     INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    who         VARCHAR(32)    NOT NULL,
    operation   VARCHAR(16)    NOT NULL,
    rec_id      VARCHAR(32)    NOT NULL,
    op_time     DATE           NOT NULL
);


DELIMITER $$
drop TRIGGER  if exists trigger_empl_insert$$
CREATE TRIGGER trigger_empl_insert 
    AFTER INSERT ON Employee
    FOR EACH ROW
BEGIN
    INSERT INTO op_log
    VALUES (NULL, USER(), 'insert', NEW.empl_id, SYSDATE());
END$$

drop TRIGGER  if exists trigger_empl_update$$
CREATE TRIGGER trigger_empl_update
    AFTER UPDATE ON Employee
    FOR EACH ROW
BEGIN
    INSERT INTO op_log
    VALUES (NULL, USER(), 'update', OLD.empl_id, SYSDATE());
END $$
 DELIMITER ;

