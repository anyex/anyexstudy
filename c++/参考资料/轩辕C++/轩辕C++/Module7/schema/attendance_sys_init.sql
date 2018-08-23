-- test data for table 'Department'
insert into Department values ('RND', 'R&D Development', 'Beijing'),
('SAL', 'Sales depart', 'Shanghai'),
('PUR', 'Purchasing Department', 'Shenzhen'),
('ACC', 'Accounting Department', 'Beijing'),
('HRO', 'Human Resources Department', 'Beijing');

-- test data for table 'Employee'
insert into Employee values ('RND0025', 'Zhang fei', 'RND', 5850, '2001-06-12', 'zhangshan@xishu.cn'),
('RND0026', 'Guan yu ', 'RND', 5850, '2001-06-12', 'guanyu@xishu.cn'),
('RND0028', 'Zhao yun', 'RND', 5850, '2002-05-12', 'zhaoyun@xishu.cn'),
('RND0032', 'Huang zhong', 'RND', 6000, '2002-06-22', 'huangzhong@xishu.cn'),
('RND0122', 'Wei yan', 'RND', 5200, '2002-06-25', 'weiyan@xishu.cn'),
('HRO0001', 'Kong ming', 'HRO', 3200, '2002-08-09', 'zhuge@xishu.cn'),
('PUR0021', 'Hui dong', 'PUR', 3860, '2002-03-09', 'huidong@xishu.cn'),
('ACC0001', 'Luo jin', 'ACC', 4100, '2002-09-19', 'luolin@xishu.cn');

-- test data for table 'Attendance_Plan'
insert into Attendance_Plan values (1, 0, null, null), -- Sunday
(1, 1, '09:00:00', '17:00:00'), -- Monday
(1, 2, '09:00:00', '17:00:00'),
(1, 3, '09:00:00', '17:00:00'),
(1, 4, '09:00:00', '17:00:00'),
(1, 5, '09:00:00', '17:00:00'),
(1, 6, null, null), -- Saturday
(2, 0, null, null), -- Sunday
(2, 1, '08:00:00', '16:00:00'), -- Monday
(2, 2, '08:00:00', '16:00:00'),
(2, 3, '08:00:00', '16:00:00'),
(2, 4, '08:00:00', '16:00:00'),
(2, 5, '08:00:00', '16:00:00'),
(2, 6, null, null); -- Saturday


insert into Empl_Attendance_Plan values ('RND0026', 1), 
('RND0028', 1), 
('ACC0001', 2);








