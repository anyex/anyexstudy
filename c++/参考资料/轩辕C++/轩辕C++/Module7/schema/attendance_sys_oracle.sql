/*==============================================================*/
/* DBMS name:      ORACLE Version 10g                           */
/* Created on:     2010-5-6 8:02:32                             */
/*==============================================================*/


alter table Attendance_Sheet
   drop constraint FK_ATTENDAN_RELATIONS_EMPLOYEE;

alter table Empl_Attendance_Plan
   drop constraint FK_EMPL_ATT_RELATIONS_EMPLOYEE;

alter table Empl_Attendance_Plan
   drop constraint FK_EMPL_ATT_RELATIONS_ATTENDAN;

alter table Employee
   drop constraint FK_EMPLOYEE_RELATIONS_DEPARTME;

drop table Attendance_Plan cascade constraints;

drop index Relationship_4_FK;

drop table Attendance_Sheet cascade constraints;

drop table Department cascade constraints;

drop index Relationship_3_FK;

drop index Relationship_2_FK;

drop table Empl_Attendance_Plan cascade constraints;

drop index Relationship_1_FK;

drop table Employee cascade constraints;

/*==============================================================*/
/* Table: Attendance_Plan                                     */
/*==============================================================*/
create table Attendance_Plan  (
   plan_id            INTEGER                         not null,
   weekday            INTEGER                         not null,
   begin_time         DATE,
   over_time          DATE,
   constraint PK_ATTENDANCE_PLAN primary key (plan_id, weekday)
);

/*==============================================================*/
/* Table: Attendance_Sheet                                    */
/*==============================================================*/
create table Attendance_Sheet  (
   attendance_date    DATE                            not null,
   Emp_empl_id        VARCHAR2(8)                     not null,
   start_time         DATE,
   leave_time         DATE,
   constraint PK_ATTENDANCE_SHEET primary key (attendance_date)
);

/*==============================================================*/
/* Index: Relationship_4_FK                                   */
/*==============================================================*/
create index Relationship_4_FK on Attendance_Sheet (
   Emp_empl_id ASC
);

/*==============================================================*/
/* Table: Department                                          */
/*==============================================================*/
create table Department  (
   depart_id          VARCHAR2(6)                     not null,
   depart_name        VARCHAR2(32)                    not null,
   location           VARCHAR2(64)                    not null,
   constraint PK_DEPARTMENT primary key (depart_id)
);

/*==============================================================*/
/* Table: Empl_Attendance_Plan                                */
/*==============================================================*/
create table Empl_Attendance_Plan  (
   Emp_empl_id        VARCHAR2(8)                     not null,
   Att_plan_id        INTEGER                         not null,
   Att_weekday        INTEGER                         not null,
   constraint PK_EMPL_ATTENDANCE_PLAN primary key (Emp_empl_id, Att_plan_id, Att_weekday)
);

/*==============================================================*/
/* Index: Relationship_2_FK                                   */
/*==============================================================*/
create index Relationship_2_FK on Empl_Attendance_Plan (
   Emp_empl_id ASC
);

/*==============================================================*/
/* Index: Relationship_3_FK                                   */
/*==============================================================*/
create index Relationship_3_FK on Empl_Attendance_Plan (
   Att_plan_id ASC,
   Att_weekday ASC
);

/*==============================================================*/
/* Table: Employee                                            */
/*==============================================================*/
create table Employee  (
   empl_id            VARCHAR2(8)                     not null,
   empl_name          VARCHAR2(16)                    not null,
   Dep_depart_id      VARCHAR2(6)                     not null,
   salary             INTEGER                         not null,
   hire_date          DATE                            not null,
   email              VARCHAR2(64),
   constraint PK_EMPLOYEE primary key (empl_id)
);

/*==============================================================*/
/* Index: Relationship_1_FK                                   */
/*==============================================================*/
create index Relationship_1_FK on Employee (
   Dep_depart_id ASC
);

alter table Attendance_Sheet
   add constraint FK_ATTENDAN_RELATIONS_EMPLOYEE foreign key (Emp_empl_id)
      references Employee (empl_id);

alter table Empl_Attendance_Plan
   add constraint FK_EMPL_ATT_RELATIONS_EMPLOYEE foreign key (Emp_empl_id)
      references Employee (empl_id);

alter table Empl_Attendance_Plan
   add constraint FK_EMPL_ATT_RELATIONS_ATTENDAN foreign key (Att_plan_id, Att_weekday)
      references Attendance_Plan (plan_id, weekday);

alter table Employee
   add constraint FK_EMPLOYEE_RELATIONS_DEPARTME foreign key (Dep_depart_id)
      references Department (depart_id);

