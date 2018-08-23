-- test data for table 'Department'
insert into Department values ('RND', 'R D Development', 'Beijing');
insert into Department values ('SAL', 'Sales depart', 'Shanghai');
insert into Department values ('PUR', 'Purchasing Department', 'Shenzhen');
insert into Department values ('ACC', 'Accounting Department', 'Beijing');
insert into Department values ('HRO', 'Human Resources Department', 'Beijing');

-- test data for table 'Employee'
insert into Employee values ('RND0025', 'Zhang fei', 'RND', 5850, to_date('2001-06-12', 'YYYY-MM-DD'), 'zhangshan@xishu.cn');
insert into Employee values ('RND0026', 'Guan yu', 'RND', 5850, to_date('2001-06-12', 'YYYY-MM-DD'), 'guanyu@xishu.cn');
insert into Employee values ('RND0028', 'Zhao yun', 'RND', 5850, to_date('2002-05-12', 'YYYY-MM-DD'), 'zhaoyun@xishu.cn');
insert into Employee values ('RND0032', 'Huang zhong', 'RND', 6000, to_date('2002-06-22', 'YYYY-MM-DD'), 'huangzhong@xishu.cn');
insert into Employee values ('RND0122', 'Wei yan', 'RND', 5200, to_date('2002-06-25', 'YYYY-MM-DD'), 'weiyan@xishu.cn');
insert into Employee values ('HRO0001', 'Kong ming', 'HRO', 3200, to_date('2002-08-09', 'YYYY-MM-DD'), 'zhuge@xishu.cn');
insert into Employee values ('PUR0021', 'Hui dong', 'PUR', 3860, to_date('2002-03-09', 'YYYY-MM-DD'), 'huidong@xishu.cn');
insert into Employee values ('ACC0001', 'Luo jin', 'ACC', 4100, to_date('2002-09-19', 'YYYY-MM-DD'), 'luolin@xishu.cn');

