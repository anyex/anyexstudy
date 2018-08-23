DROP TABLE countries;
CREATE TABLE countries(
    country_id      char(2)    not NULL,
    country_name    VARCHAR2(40),
    region_id       number(8)
);

insert into  countries values ('CA','Canada',2);
insert into  countries values ('DE','Germany',1);
insert into  countries values ('UK','United Kingdom',1);
insert into  countries values ('US','United States of America',2);

DROP TABLE departments;
CREATE TABLE departments(
    department_id      number(4)    not NULL,
    department_name    VARCHAR2(30) not null,
    manager_id     number(6),
    location_id    number(4)
);

insert into departments values (10,'Administration',200,1700);
insert into departments values (20,'Marketing',201,1800);
insert into departments values (50,'Shipping',124,1500);
insert into departments values (60,'IT',103,1400);
insert into departments values (80,'Sales',149,2500);
insert into departments values (90,'Executive',100,1700);
insert into departments values (110,'Accounting',205,1700);
insert into departments values (190,'Contracting',null,1700);

DROP TABLE employees;
CREATE TABLE employees(
    employee_id    number(6)    not NULL,
    first_name     VARCHAR2(20) ,
    last_name      VARCHAR2(25) not null,
    email          VARCHAR2(25) not null,
    phone_number   VARCHAR2(20) ,
    hire_date      date   not null,
    job_id         VARCHAR2(10)  not null,
    salary          number(8,2),
    commission_pct  number(2,2),
    manager_id     number(6),
    department_id    number(4)
);

insert into  employees values (100,'Steven','King','SKING','5151234567','17-Jun-87','AD_PRES',24000,null,null,90);
insert into  employees values (101,'Neena','Kochhar','SNKOCHHAR','5151234568','21-Sep-89','AD_VP',17000,null,100,90);
insert into  employees values (102,'lex','De Haan','LDEHAAN','5151234569','13-Jan-93','AD_VP',17000,null,100,90);
insert into  employees values (103,'Alexander','Hunold','AHUNOLD','5904234567','03-Jan-90','IT_PROG',9000,null,102,60);
insert into  employees values (104,'Bruce','Ernst','BERNST','5904234568','21-May-91','IT_PROG',6000,null,103,60);
insert into  employees values (107,'Diana','Lorentz','DLORENTZ','5904235567','07-Feb-99','IT_PROG',4200,null,103,60);
insert into  employees values (124,'Kevin','Mourgos','KMOURGES','5501235234','16-Nov-99','ST_MAN',5800,null,100,50);
insert into  employees values (141,'Trenna','Rajs','TRAJS','6501218009','17-Oct-99','ST_CLERK',3500,null,124,50);
insert into  employees values (142,'Curtis','Davies','CDAVIES','6501212994','29-Jan-99','ST_CLERK',3100,null,124,50);
insert into  employees values (143,'Randall','Matos','RMATOS','6501212874','15-Mar-98','ST_CLERK',2600,null,124,50);
insert into  employees values (144,'Peter','Vargas','PVARGAS','6501212004','09-Jul-99','ST_CLERK',2500,null,124,50);
insert into  employees values (149,'Eleni','Zlotkey','EZLOTKEY','011441344429018','29-Jan-00','SA_MAN',10500,0.2,100,80);
insert into  employees values (174,'Ellen','Abel','EABEL','011441644429267','11-May-96','SA_REP',11000,0.3,149,80);
insert into  employees values (176,'Jonathon','Taylor','JTAYLOR','011441644429265','24-Mar-98','SA_REP',8600,0.2,149,80);
insert into  employees values (178,'Kimberely','Grant','KGRANT','011441644429263','24-May-99','SA_REP',7000,0.15,149,null);
insert into  employees values (200,'Jennifer','Whalen','JWHALEN','5151234444','17-Sep-87','AD_ASST',4400,null,101,10);
insert into  employees values (201,'Michael','Hartstein','MHARTSTE','5151235555','17-Feb-96','MK_MAN',13000,null,100,20);
insert into  employees values (205,'Shelley','Higgins','SHIGGINS','5151238080','07-Jun-94','AC_MGR',12000,null,101,110);
insert into  employees values (202,'Pat','Fay','PFAY','6031236666','17-Aug-97','MK_REP',6000,null,201,20);
insert into  employees values (206,'William','Gietz','WGIETZ','5151238181','07-Jun-94','AC_ACCOUNT',8300,null,205,110);


DROP TABLE jobs;
CREATE TABLE jobs(
    job_id         VARCHAR2(10)  not null,
    job_title      VARCHAR2(35)  not null,
    max_salary          number(6),
    min_salary          number(6)
);

insert into jobs values ('AD_PRES' ,'President',20000,40000);
insert into jobs values ('AD_VP' ,'Administration Vice President',15000,30000);
insert into jobs values ('AD_ASST' ,'Administration Assistant',3000,6000);
insert into jobs values ('AC_MGR' ,'Accounting Manager',8200,16000);
insert into jobs values ('AC_ACCOUNT' ,'Public Accountant',4200,9000);
insert into jobs values ('SA_MAN' ,'Sales Manager',10000,20000);
insert into jobs values ('SA_REP' ,'Sales Repr',5000,12000);
insert into jobs values ('ST_MAN' ,'Stock Manager',5500,8500);
insert into jobs values ('ST_CLERK' ,'Stock Clerk',2000,5000);
insert into jobs values ('IT_PROG' ,'Programmer',4000,10000);
insert into jobs values ('MK_REP' ,'Marketing Represtentative',4000,9000);
insert into jobs values ('MK_MAN' ,'Marketing Manager',9000,15000);


DROP TABLE job_grades;
CREATE TABLE job_grades(
    grade_level         VARCHAR2(3) ,
    lowest_sal           number(6),
    highest_sal          number(6)
);

insert into job_grades values ('A' ,1000,2999);
insert into job_grades values ('B' ,3000,5999);
insert into job_grades values ('C' ,6000,9999);
insert into job_grades values ('D' ,10000,14999);
insert into job_grades values ('E' ,15000,24999);
insert into job_grades values ('F' ,25000,40000);


DROP TABLE job_history;
CREATE TABLE job_history(
    employee_id   number(6)  not null,
    start_date    date   not null,
    end_date      date   not null,
    job_id        VARCHAR2(10)  not null,
    department_id          number(4)
);

insert into job_history values (102 ,'13-Jan-93','24-Jul-98','IT_PROG',60);
insert into job_history values (101 ,'21-Sep-89','27-Oct-93','AC_ACCOUNT',110);
insert into job_history values (101 ,'28-Oct-93','15-Mar-97','AC_MGR',110);
insert into job_history values (201 ,'17-Feb-96','19-Dec-99','MK_REP',20);
insert into job_history values (114 ,'24-Mar-98','31-Dec-99','ST_CLERK',50);
insert into job_history values (122 ,'1-Jan-99','31-Dec-99','ST_CLERK',60);
insert into job_history values (176 ,'24-Mar-98','31-Dec-98','SA_REP',80);
insert into job_history values (200 ,'01-Jul-94','31-Dec-98','AC_ACCOUNT',90);
insert into job_history values (200 ,'17-Sep-87','17-Jun-93','AD_ASST',90);
insert into job_history values (176,'01-Jan-99','31-Dec-99','SA_MAN',80);

DROP TABLE locations;
CREATE TABLE locations(
    location_id          number(4)  not null,
    street_address       VARCHAR2(40) ,
    postal_code          VARCHAR2(12) ,
    city                 VARCHAR2(30)  not null,
    state_province       VARCHAR2(25)  ,
    country_id           char(2)
);

insert into locations values (1400,'2014 Jab','26192','Southlake','Texas','US');
insert into locations values (1500,'2011 Int','99236','South SanFran','California','US');
insert into locations values (1700,'2004 cha','98199','Seattle','Washington','US');
insert into locations values (1800,'460 BLO','ON M5S 1X8','Toronto','Ontario','CA');
insert into locations values (2500,'mag','OX99ZB','Oxford','Oxford','UK');

DROP TABLE regions;
CREATE TABLE regions(
    region_id          number  not null,
    region_name      VARCHAR2(25)
);

insert into regions values(1,'Europe');
insert into regions values(2,'Americas');
insert into regions values(3,'Asia');
insert into regions values(4,'Middle East and Africa');
commit;
