SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL';

DROP SCHEMA IF EXISTS `attendance_sys` ;
CREATE SCHEMA IF NOT EXISTS `attendance_sys` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci ;

-- -----------------------------------------------------
-- Table `attendance_sys`.`Department`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `attendance_sys`.`Department` ;

CREATE  TABLE IF NOT EXISTS `attendance_sys`.`Department` (
  `depart_id` VARCHAR(6) NOT NULL ,
  `name` VARCHAR(32) NOT NULL ,
  `location` VARCHAR(45) NOT NULL ,
  PRIMARY KEY (`depart_id`) ,
  UNIQUE INDEX `department_id_UNIQUE` (`depart_id` ASC) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8
COLLATE = utf8_general_ci;


-- -----------------------------------------------------
-- Table `attendance_sys`.`Employee`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `attendance_sys`.`Employee` ;

CREATE  TABLE IF NOT EXISTS `attendance_sys`.`Employee` (
  `empl_id` VARCHAR(8) NOT NULL ,
  `name` VARCHAR(12) NOT NULL ,
  `depart_id` VARCHAR(6) NOT NULL ,
  `salary` INT NOT NULL ,
  `hire_date` DATE NOT NULL ,
  `email` VARCHAR(64) NULL ,
  PRIMARY KEY (`empl_id`) ,
  UNIQUE INDEX `employee_id_UNIQUE` (`empl_id` ASC) ,
  INDEX `fk_Employee_Department` (`depart_id` ASC) ,
  CONSTRAINT `fk_Employee_Department`
    FOREIGN KEY (`depart_id` )
    REFERENCES `attendance_sys`.`Department` (`depart_id` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8
COLLATE = utf8_general_ci;


-- -----------------------------------------------------
-- Table `attendance_sys`.`Attendance_Sheet`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `attendance_sys`.`Attendance_Sheet` ;

CREATE  TABLE IF NOT EXISTS `attendance_sys`.`Attendance_Sheet` (
  `attendance_date` DATE NOT NULL ,
  `empl_id` VARCHAR(8) NOT NULL ,
  `begin_time` TIME NULL ,
  `leave_time` TIME NULL ,
  PRIMARY KEY (`attendance_date`, `empl_id`) ,
  INDEX `fk_Attendance_Sheet_Employee1` (`empl_id` ASC) ,
  CONSTRAINT `fk_Attendance_Sheet_Employee1`
    FOREIGN KEY (`empl_id` )
    REFERENCES `attendance_sys`.`Employee` (`empl_id` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8
COLLATE = utf8_general_ci;


-- -----------------------------------------------------
-- Table `attendance_sys`.`attendance_Plan`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `attendance_sys`.`Attendance_Plan` ;

CREATE  TABLE IF NOT EXISTS `attendance_sys`.`Attendance_Plan` (
  `plan_id` INT NOT NULL ,
  `weekday` TINYINT NOT NULL ,
  `begin_time` TIME NULL ,
  `over_time` TIME NULL ,
  PRIMARY KEY (`plan_id`, `weekday`) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8
COLLATE = utf8_general_ci;


-- -----------------------------------------------------
-- Table `attendance_sys`.`Empl_attendance_Plan`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `attendance_sys`.`Empl_Attendance_Plan` ;

CREATE  TABLE IF NOT EXISTS `attendance_sys`.`Empl_Attendance_Plan` (
  `empl_id` VARCHAR(8) NOT NULL ,
  `plan_id` INT NOT NULL ,
  INDEX `fk_Empl_attendance_Plan_Employee1` (`empl_id` ASC) ,
  INDEX `fk_Empl_attendance_Plan_attendance_Plan1` (`plan_id` ASC) ,
  PRIMARY KEY (`empl_id`, `plan_id`) ,
  CONSTRAINT `fk_Empl_attendance_Plan_Employee1`
    FOREIGN KEY (`empl_id` )
    REFERENCES `attendance_sys`.`Employee` (`empl_id` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Empl_attendance_Plan_attendance_Plan1`
    FOREIGN KEY (`plan_id` )
    REFERENCES `attendance_sys`.`attendance_Plan` (`plan_id` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8
COLLATE = utf8_general_ci;



SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;

