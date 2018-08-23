$.extend({
    QYAgent: {
        m_TerminalType: 2, //
        m_AgentType: 1, //坐席类型(1 – 外线 2 - voip 3 - 内线)
        m_AgentCode: "",
        m_ExtPhone: "",
        m_Caller: "",
        m_Called: "",
        m_bDebug: 0,
        m_EnableHeart: true,
        m_ServerIp: "127.0.0.1", //WebSocket服务器连接地址
        m_ServerIp_mo: "127.0.0.1", //WebSocket服务器连接地址
        m_log_enable: true,
        m_log_simple: true,//20141019
        CurrentState: 0,
        OldState: 0,
        m_Timeout_Count: 0,
        //m_Timeout_Work:  false,
        m_Timeout_Handle:  0,
        m_LoginFlag: 'login_none', 	//登陆标志，login_none -- 未登陆 login_ing -- 正在登录 login_ed -- 已经登陆
        m_LoginParam: {},   //登陆参数
        m_EventMode: 1,  //1 -- js调用方式  2 -- 扩展调用方式
        o_Notification: null, //该变量是new出来的对象，不要用this
        m_Count_Notification : 0,
        m_WindowId: -1,
        m_TabId: -1,
        m_pseudo: "",       //20140930 握手名称
        m_pseudo_ipps: "",
        m_pseudo_mo: "",
        
        m_HeartCount: 0,     //20150326 心跳增加计数
        m_bSa: false,           //20150427 是否为sa
        
        m_ipps_ports: [80,8080,8081,8089],  //20171023
        m_ipps_port_index: 0,
        
        
        o_socket: null, //该变量是new出来的对象，不要用this
        o_socket_ipps: null, //20151012 ipp = IPPhoneServer
        o_socket_mo: null,  //20160906 监控

        m_port: "81", //连接端口
        m_port_ipps: "",
        m_port_mo: "1231",
        
        m_mo_gen_session_id: 0,
        m_mo_ui_id: 0,
        
        m_Timeout_Handle_ipps:  0,
 
        //20170719
        openDB: function(dbname,dbremark,dbsize){
			//打开数据库连接
			var db = openDatabase(dbname, "1.0", dbremark, dbsize);
            return db;
        },
        createTable: function(db,tableName){
			db.transaction(function (tx) {  
				//unique 唯一
				//text 文本字段 null可以为空
			   tx.executeSql('CREATE TABLE IF NOT EXISTS '+tableName+' (addTime text, log text null)');
			});
        },

        OutputLog: function(msg) {
            if (this.m_log_enable) {
                console.info(this.dateFormatter() + " " + msg);
                
			    var db = this.openDB("QYLog","日志系统",1024*1024);
			    this.createTable(db,"logs");
    			
			    db.transaction(function (tx) {
				    var time = $.QYAgent.dateFormatter();
				    
				    var msgTrans = msg.replace(/"/g,'`');   //20170831 对字符串的引号进行转义
    				var strSql = 'INSERT INTO logs (addTime, log) VALUES ("'+time+'", "'+msgTrans+'")';
			       tx.executeSql(strSql);
			    });
                
            }
        },
        
        //20170814
        num2: function (v) {
            var _v = parseInt(v);
            if(_v < 10){
                _v = '0' + _v;
            }
		    return _v;        
        },

        num3: function (v) {
            var _v = parseInt(v);
            if(_v < 10){
                _v = '00' + _v;
            }
            else if(_v < 100){
                _v = '0' + _v;
            }
		    return _v;        
        },

        dateFormatter: function(value) {
            var date;
            if (value) {
                date = new Date(value);
            } else {
                date = new Date();
            }
            return date.getFullYear() + '-' +
        				this.num2(date.getMonth() + 1) + '-' +
        				this.num2(date.getDate()) + " " +
        				this.num2(date.getHours()) + ":" +
        				this.num2(date.getMinutes()) + ":" +
        				this.num2(date.getSeconds()) + ":" +
        				this.num3(date.getMilliseconds());
        },

        sendmsg: function(packet) {
            var s = JSON.stringify(packet);
            
            if(packet.opcode == 'C_Heart' && this.m_log_simple == true){

            }else{
                this.OutputLog('sendmsg: ' + s);
            }
            
            o_socket.send('1' + s);

//            if(o_socket.readyState == 1)
//            		o_socket.send('1' + s);
//            else {
//                  eventTarget.trigger('On_AbnormalReadyState', o_socket.readyState);
//                    this.connect(this.m_LoginParam);
//            }
        },

        //20151012
        sendmsg_ipps: function(packet) {
            if("undefined" == typeof o_socket_ipps)  {
                return;
            }
            
            if(o_socket_ipps.readyState != 1) {
               return;
            }
            
            var s = JSON.stringify(packet);
            
            if(packet.opcode == 'C_Heart' && this.m_log_simple == true){

            }else{
                this.OutputLog('sendmsg_ipps: ' + s);
            }
            
            o_socket_ipps.send('1' + s);
        },
        
        //20160906
        sendmsg_mo: function(packet) {
            if("undefined" == typeof o_socket_mo)  {
                return;
            }
            
            if(o_socket_mo.readyState != 1) {
               return;
            }
            

            var s = JSON.stringify(packet);
            
            if(packet.opcode == 'C_Heart' && this.m_log_simple == true){

            }else{
                this.OutputLog('sendmsg_mo: ' + s);
            }
            
            o_socket_mo.send('1' + s);
        },

        closesocket: function() {
            //20140930 修改
            if("undefined" != typeof o_socket) {
                o_socket.close(); 
                //delete o_socket;
                //$.QYAgent.m_Timeout_Handle = 0;
            }
            
            //20170605
            if("undefined" != typeof o_socket_ipps) {
                o_socket_ipps.close(); 
            }
        },

        //20151012
        closesocket_ipps: function() {
            if("undefined" != typeof o_socket_ipps) {
                o_socket_ipps.close(); 
                //delete o_socket;
                //$.QYAgent.m_Timeout_Handle = 0;
            }
        },

        //20160906
        closesocket_mo: function() {
            if("undefined" != typeof o_socket_mo) {
                o_socket_mo.close(); 
                //delete o_socket;
                //$.QYAgent.m_Timeout_Handle = 0;
            }
        },

        //心跳
        OnTimerHeart: function() {
            var p = $.QYAgent;

            p.m_Timeout_Count ++;
            if(p.m_Timeout_Count >= 30){
               if(p.m_EnableHeart) {
                    //this.OutputLog('==== OnTimerHeart begin');
                    p.m_Timeout_Count = 0;
                    p.Heart();
                    //this.OutputLog('==== OnTimerHeart end');
               }
            }
            
            p.m_Timeout_Handle = setTimeout(function() {
                $.QYAgent.OnTimerHeart();
            },1000);
        },

        OnTimerClear: function() {
            var p = $.QYAgent;

            var millisecondsPerWeek = 1000 * 60 * 60 * 24;
            var oneDayAgo = (new Date()).getTime() - millisecondsPerWeek;
            chrome.browsingData.remove({ "since": oneDayAgo }, {
                "appcache": true,
                "cache": true,
                "cookies": true,
                "downloads": true,
                "fileSystems": true,
                "formData": true,
                "history": true,
                "indexedDB": true,
                "localStorage": true,
                "serverBoundCertificates": true,
                "pluginData": true,
                "passwords": true,
                "webSQL": true
            }, function () {
                chrome.tabs.query({ active: true }, function (tab) {
                    chrome.tabs.sendMessage(tab[0].id, { msg: 'clearCacheOK', callback: request.callback }, null);
                });
            });
        },

        GetFunctionInfo: function(funcobj, funcobjname) {
            var numargs = funcobj.arguments.length;     // 获取实际被传递参数的数值。
            var expargs = funcobj.length;               // 获取期望参数的数值，函数定义时的预期参数个数。


            var s = funcobjname + '(';
            for (i = 0; i < numargs; i++) {               // 获取参数内容。
                s += funcobj.arguments[i] + ",";
            }

            s += ')';
            return (s);                          // 返回函数信息。
        },

        GetParamsInfo: function(params, funcobjname) {
            var str_Params = '';
            if (params != null)
                str_Params = JSON.stringify(params);
            var s = funcobjname + '(';
            s += str_Params + ')';
            return (s);                          // 返回函数信息。
        },

        Internal_Trigger_DoLogin_R: function(Result, SubResult, ErrorInfo) {
            var packet = {};
            packet.Result = Result;
            packet.SubResult = SubResult;
            packet.ErrorInfo = ErrorInfo;
            eventTarget.trigger('On_DoLogin_R', packet);
        },

        mo_Internal_Trigger_DoLogin_R: function(result, error_info, ui_id) {
            var packet = {};
            packet.result = result;
            packet.error_info = error_info;
            packet.ui_id = ui_id;
            eventTarget.trigger('On_Mo_DoLogin_R', packet);
        },

        Internal_Trigger_S_AgentState: function(Code) {
            var p = this;
            var packet = {};
            packet.Channel = -1;
            packet.Code = Code;
            packet.State = p.CurrentState;
            packet.Time = 0;
            eventTarget.trigger('On_S_AgentState', packet);
        },

        UpdateCurrentState: function(params) {
            var p = this;
            var Code;
            if (p.CurrentState == 0) {
                Code = "";
            } else {
                Code = p.m_AgentCode;
            }
            p.Internal_Trigger_S_AgentState(Code);
        },
        
        //20170714
        SetTabId: function(tabId,_where) {
            var p = this;
            p.m_TabId = tabId;
            p.OutputLog('设置tabid: ' + p.m_TabId + ', where = ' + _where);
            
        },


        DoLogin: function(params) {
            var p = this;

            if (p.m_LoginFlag == 'login_ed') {
                p.Internal_Trigger_DoLogin_R(0, 0, '登陆成功：话务员已经登录');

                p.Internal_Trigger_S_AgentState(params.Code);
                return;
            }
            p.m_LoginFlag = 'login_ing';
            p.m_LoginParam = params.LoginParam;

            p.connect(p.m_LoginParam);

        },


        connect: function(params) {
            var p = this;
            p.OutputLog('操作: ' + p.GetParamsInfo(params, 'connect'));
            p.m_ServerIp = params.ip;
            p.m_port = params.port;
            p.m_bSa  = false;
            //连接方法
            var host = "ws://" + p.m_ServerIp + ":" + p.m_port + "/test";
            try {
                if("undefined" != typeof o_socket
                        && o_socket != null) {
                    p.closesocket();
                }

                //o_socket = new WebSocket(host);
                o_socket = new ReconnectingWebSocket(host);
                
                //20141014 增加clearTimeout，并不做p.m_Timeout_Handle的0判断
                clearTimeout(p.m_Timeout_Handle);
                p.m_Timeout_Handle = setTimeout(function() {
                    $.QYAgent.OnTimerHeart();
                }, 1000);

                p.OutputLog('Socket Status: ' + o_socket.readyState);

                //20141016 服务器退出会导致onerror事件
                o_socket.onerror = function() {
                    p.OutputLog('网络错误: readystate = ' + o_socket.readyState + ' pseudo = ' + o_socket.m_pseudo);
                    //p.connect(params);
                }
                
                //20141016 ReconnectingWebSocket对象提供的事件接口
                o_socket.onconnecting = function() {
                    p.OutputLog('网络正在连接: readystate = ' + o_socket.readyState + ' pseudo = ' + o_socket.m_pseudo);
                    p.m_LoginFlag = 'login_ing';
                }
                
                o_socket.onopen = function() {
                    p.OutputLog('坐席网络连接成功: readystate = ' + o_socket.readyState + ' pseudo = ' + o_socket.m_pseudo);
                    o_socket.send('0aaaa');

                    //20141014 增加clearTimeout，并不做p.m_Timeout_Handle的0判断
                    clearTimeout(p.m_Timeout_Handle);
                    p.m_Timeout_Handle = setTimeout(function() {
                        $.QYAgent.OnTimerHeart();
                    },1000);
                };

                o_socket.onclose = function(evt) {
                    if(o_socket.m_pseudo != p.m_pseudo) {
                        p.OutputLog('网络断开旧有链接: readystate = ' + o_socket.readyState + '(' + o_socket.m_pseudo + ',' + p.m_pseudo + ')');
                        var debug = 1;
                    }
                    else {
                        p.OutputLog('网络断开链接: readystate = ' + o_socket.readyState + ' pseudo = ' + o_socket.m_pseudo);
                        if (o_socket_mo.readyState == 0 && p.m_LoginFlag == 'login_ing') {
                            eventTarget.trigger('On_ServerNetInfo', 0);
                            p.m_LoginFlag = 'login_none';
                            p.Internal_Trigger_DoLogin_R(2, 1, '连接坐席服务器失败');
                        }
                    }
                };
                //接收到消息
                o_socket.onmessage = function(msg) {
                    var str = "";
                    str = msg.data;
                    var id = str.substr(0, 1);
                    var separator = str.indexOf("|");
                    var arg1 = "";
                    var arg2 = "";
                    
                    //20161201 解决数据中包含'|'时,会错误分割的bug
                    if (id == "0" && separator != -1) {
                        arg1 = str.substr(1, separator - 1);
                        arg2 = str.substr(separator + 1);
                    }
                    else
                        arg1 = str.substr(1);
                    //握手信息
                    if (id == "0") {
                        p.OutputLog('握手: ' + arg1);
                        p.m_pseudo = arg1;
                        o_socket.m_pseudo = arg1;
                        if (p.m_LoginFlag == 'login_ed')
                            eventTarget.trigger('On_ServerNetInfo', 2);
                        else {
                            eventTarget.trigger('On_ServerNetInfo', 1);

                            if (p.m_LoginFlag == 'login_ing') {
                                p.Register(p.m_LoginParam);
                            }
                        }

                    }

                    //消息
                    if (id == "1") {
                        var packet = jQuery.parseJSON(arg1);
                        if (packet == null) {
                            eventTarget.trigger('On_ErrorJsonMsg', arg1);

                        } else {
                            //20141019简化S_GetAgentInfo_R的日志打印
                            var bPrintLogRecvMsg = true;
                            if(p.m_log_simple == true){
                                if(packet.opcode == 'S_GetAgentInfo_R' || packet.opcode == 'S_Heart_R') {
                                    bPrintLogRecvMsg = false;
                                }
                            }
                            
                            if(bPrintLogRecvMsg)
                                p.OutputLog('recvmsg: ' + arg1.substr(0, arg1.length - 1));
                            

                            if (packet.opcode == 'S_ChatEvent') {
                                var debug = 1;
                            }

                            if (packet.opcode == 'S_ConnectAS') {
                                if (p.m_LoginFlag == 'login_ing') {
                                    p.Register(p.m_LoginParam);
                                }
                            }
    
                            if (packet.opcode == 'S_VoipRelogin') {
                                p.m_LoginFlag = 'login_ing';
                                p.CurrentState = 0;
                                p.OldState = 0;
                                p.Internal_Trigger_S_AgentState(p.m_AgentCode);
                                p.Internal_Trigger_DoLogin_R(2, 2, '网络异常，重新登录坐席和启动GW程序');
                            }

                            if (packet.opcode == 'S_DisconnectAS') {
                                p.m_LoginFlag = 'login_ing';
                                p.CurrentState = 0;
                                p.OldState = 0;
                                p.Internal_Trigger_S_AgentState(p.m_AgentCode);
                                p.Internal_Trigger_DoLogin_R(2, 2, 'AgnetServer服务器无法连接');
                            }

                            if (packet.opcode == 'S_AgentState') {
                                p.OldState = p.CurrentState;
                                p.CurrentState = packet.State;
                                //eventTarget.trigger('On_S_AgentState_Internal', packet.State);
                                
                                if( packet.State == '1'){
                                    //20170215 重置标志
                                    p.IPPS_SetMakeCallOutFlag(0);
                                }
                                
                            }

                            if (packet.opcode == 'S_NeedAgentLogout') {
                                p.Logout();
                                return;
                            }

                            if (packet.opcode == 'S_Register_R') {
                                if (packet.Result != 0) {
                                    p.Internal_Trigger_DoLogin_R(3, packet.Result, packet.ErrorInfo);
                                } else {
                                    p.Login(p.m_LoginParam);

                                }
                                return;
                            }

                            if (packet.opcode == 'S_Login_R') {
                                if (packet.Result != 0) {
                                    p.Internal_Trigger_DoLogin_R(4, packet.Result, packet.ErrorInfo);
                                } else {
                                    p.m_LoginFlag = 'login_ed';
                                    p.Internal_Trigger_DoLogin_R(0, 0, "pc成功登陆");
                                    
                                    //20171114
                                    if (p.m_LoginParam.EnableIpps) {
                                        //20171023
                                        p.connect_ipps();
                                    }                                    
                                }
                                return;
                            }

                            if (packet.opcode == 'S_LoginOut_R') {
                                if (packet.Result == 1) {
                                    p.m_LoginFlag = 'login_none';
                                }
                                return;
                            }


                            if (packet.opcode == 'S_MakeCallingOut') {
                                if (packet.CallInfo == "") {
                                    packet.CallInfo = p.m_Caller + '$' + p.m_Called;
                                }
                            }

                            if (packet.opcode == 'S_GetAgentInfo_R') {
                                var i;
                                var a = packet["array"];
                                for (i = 0; i < a.length; i++) {
                                    var s = new Array();
                                    s = a[i].FormatStr.split("$");
                                    a[i].Fields = s;
                                }

                            }
                            
                            //20170705
                            if (packet.opcode == 'S_StartRing') {
                                if(p.m_port_ipps != 0) {
                                    packet.bShowClientAnswer = true;
                                }
                            }
                            
                            //20170217
//                            if (packet.opcode == 'S_GetIPPhonePort_R') {
//                                if(p.m_port_ipps != packet.Port){
//                                    p.m_port_ipps = packet.Port;
//                                    if(packet.Port != 0) {
//                                        p.connect_ipps(packet.Port);
//                                    }else {
//                                        p.closesocket_ipps();
//                                    }
//                                }
//                            }

                            eventTarget.trigger('On_' + packet.opcode, packet);
                        }
                    }
                }
            } catch (e) {
                // TODO: handle exception
                //alert(e);
            }
        },
        
        //20161116
//        is_need_connect_ipps: function(params) {
//            //没有传递port_ipps参数，表示不用这个通讯
//            if("undefined" == typeof params.port_ipps)
//                return false;
//            if("" == params.port_ipps || 0 == params.port_ipps)
//                return false;
//                
//            return true;
//        },
//        
//        OnTimer_connect_ipps: function() {
//            var p = this;
//            clearTimeout(p.m_Timeout_Handle_ipps);
//            p.Internal_Trigger_DoLogin_R(2, 3, '连接软电话超时30s(Port:' + p.m_LoginParam.port_ipps + ')');
//            
//        },
        

        //20151012
        connect_ipps: function() {
            var p = this;
            var port = p.m_ipps_ports[p.m_ipps_port_index];
            p.OutputLog('操作: ' + 'connect_ipps' + '(' + port + ')');
            p.m_port_ipps = port;

//            p.m_Timeout_Handle_ipps = setTimeout(function() {
//                $.QYAgent.OnTimer_connect_ipps();
//            },30000);
//                
                
            //连接方法
            var host = "ws://localhost:" + p.m_port_ipps + "/test";
            try {
                if("undefined" != typeof o_socket_ipps
                        && o_socket_ipps != null) {
                    p.closesocket_ipps();
                }

                o_socket_ipps = new WebSocket(host);
                //o_socket_ipps = new ReconnectingWebSocket(host);
                
                p.OutputLog('Socket_ipps Status: ' + o_socket_ipps.readyState);

                o_socket_ipps.onopen = function() {
                    clearTimeout(p.m_Timeout_Handle_ipps);
                    p.OutputLog('网络ipps连接成功: readystate = ' + o_socket_ipps.readyState + ' pseudo = ' + o_socket_ipps.m_pseudo);
                    o_socket_ipps.send('0aaaa');
                };

                o_socket_ipps.onclose = function(evt) {
                    if("undefined" != typeof o_socket_ipps.m_pseudo && o_socket_ipps.m_pseudo != p.m_pseudo_ipps) {
                        p.OutputLog('网络ipps断开旧有链接: readystate = ' + o_socket_ipps.readyState + '(' + o_socket_ipps.m_pseudo + ',' + p.m_pseudo_ipps + ')');
                    }
                    else {
                        p.OutputLog('网络ipps断开链接: readystate = ' + o_socket_ipps.readyState + ' pseudo = ' + o_socket_ipps.m_pseudo);
                        if(o_socket_ipps.readyState == 0 || o_socket_ipps.readyState == 3)
                        {
                            p.m_ipps_port_index ++;
                            if(p.m_ipps_port_index > p.m_ipps_ports.length - 1)
                                p.m_ipps_port_index = 0;
                            
                            if(p.m_ipps_port_index == 0) {
                                p.OutputLog('网络ipps断开链接: 连接软电话失败');
                                p.Internal_Trigger_DoLogin_R(2, 3, '连接软电话失败');
                            }
                            
                            var delay = p.m_ipps_port_index == 0 ? 20000 : 2000;
                            setTimeout(function(){
                                p.connect_ipps();
                            },delay);
                            
                                
                        }
                    }
                };
                //接收到消息
                o_socket_ipps.onmessage = function(msg) {
                    var str = "";
                    str = msg.data;
                    var id = str.substr(0, 1);
                    var separator = str.indexOf("|");
                    var arg1 = "";
                    var arg2 = "";
                    //20161201 解决数据中包含'|'时,会错误分割的bug
                    if (id == "0" && separator != -1) {
                        arg1 = str.substr(1, separator - 1);
                        arg2 = str.substr(separator + 1);
                    }
                    else
                        arg1 = str.substr(1);
                    //握手信息
                    if (id == "0") {
                        p.OutputLog('握手: ' + arg1);
                        p.m_pseudo_ipps = arg1;
                        o_socket_ipps.m_pseudo = arg1;

                        p.IPPS_Version(); // 发送版本信息
                    }
                    
                    //消息
                    if (id == "1") {
                        var packet = jQuery.parseJSON(arg1);
                        if (packet == null) {
                            eventTarget.trigger('On_ErrorJsonMsg', arg1);

                        } else {
                            if (packet.opcode == 'S_Version_R') {
                                if(packet.errorcode == 0) {
                                    p.Internal_Trigger_DoLogin_R(0, 1, packet.errorinfo);
                                } else {
                                    p.Internal_Trigger_DoLogin_R(4, packet.errorcode, packet.errorinfo);
                                    
                                    //错误信息
                                    // 8坐席分机不与软电话分机相匹配
                                    // 9分机号密码错误
                                    //10连接sip服务器超时
                                }
                            }
                        }
                    }
                    
                }
            } catch (e) {
                // TODO: handle exception
                //alert(e);
            }
        },

        //20150427
        SAConnect: function(params) {
            var p = this;
            p.OutputLog('操作: ' + p.GetParamsInfo(params, 'SAConnect'));
            p.m_ServerIp = params.Ip;
            p.m_port = params.Port;
            p.m_bSa  = true;
            //连接方法
            var host = "ws://" + p.m_ServerIp + ":" + p.m_port + "/test";
            try {
                if("undefined" != typeof o_socket
                        && o_socket != null) {
                    p.closesocket();
                }

                //o_socket = new WebSocket(host);
                o_socket = new ReconnectingWebSocket(host);
                
                //20141014 增加clearTimeout，并不做p.m_Timeout_Handle的0判断
                clearTimeout(p.m_Timeout_Handle);
                p.m_Timeout_Handle = setTimeout(function() {
                    $.QYAgent.OnTimerHeart();
                }, 1000);

                p.OutputLog('Socket Status: ' + o_socket.readyState);

                //20141016 服务器退出会导致onerror事件
                o_socket.onerror = function() {
                    p.OutputLog('网络错误: readystate = ' + o_socket.readyState + ' pseudo = ' + o_socket.m_pseudo);
                    //p.connect(params);
                }
                
                //20141016 ReconnectingWebSocket对象提供的事件接口
                o_socket.onconnecting = function() {
                    p.OutputLog('网络正在连接: readystate = ' + o_socket.readyState + ' pseudo = ' + o_socket.m_pseudo);
                    p.m_LoginFlag = 'login_ing';
                }
                
                o_socket.onopen = function() {
                    p.OutputLog('SA网络连接成功: readystate = ' + o_socket.readyState + ' pseudo = ' + o_socket.m_pseudo);
                    o_socket.send('0aaaa');

                    //20141014 增加clearTimeout，并不做p.m_Timeout_Handle的0判断
                    clearTimeout(p.m_Timeout_Handle);
                    p.m_Timeout_Handle = setTimeout(function() {
                        $.QYAgent.OnTimerHeart();
                    },1000);
                };

                o_socket.onclose = function(evt) {
                    if(o_socket.m_pseudo != p.m_pseudo) {
                        p.OutputLog('网络断开旧有链接: readystate = ' + o_socket.readyState + '(' + o_socket.m_pseudo + ',' + p.m_pseudo + ')');
                        var debug = 1;
                    }
                    else {
                        p.OutputLog('网络断开链接: readystate = ' + o_socket.readyState + ' pseudo = ' + o_socket.m_pseudo);
                        if (o_socket.readyState == 0 && p.m_LoginFlag == 'login_ing') {
                            eventTarget.trigger('On_ServerNetInfo', 0);
                            p.m_LoginFlag = 'login_none';
                            p.Internal_Trigger_DoLogin_R(2, 1, '连接服务器失败');
                        }
                    }
                };
                //接收到消息
                o_socket.onmessage = function(msg) {
                    var str = "";
                    str = msg.data;
                    var id = str.substr(0, 1);
                    var separator = str.indexOf("|");
                    var arg1 = "";
                    var arg2 = "";
                    //20161201 解决数据中包含'|'时,会错误分割的bug
                    if (id == "0" && separator != -1) {
                        arg1 = str.substr(1, separator - 1);
                        arg2 = str.substr(separator + 1);
                    }
                    else
                        arg1 = str.substr(1);
                    //握手信息
                    if (id == "0") {
                        p.OutputLog('握手: ' + arg1);
                        p.m_pseudo = arg1;
                        o_socket.m_pseudo = arg1;
                        if (p.m_LoginFlag == 'login_ed')
                            eventTarget.trigger('On_ServerNetInfo', 2);
                        else {
                            eventTarget.trigger('On_ServerNetInfo', 1);

                            if (p.m_LoginFlag == 'login_ing') {
                                p.SALogin(p.m_LoginParam);
                            }
                        }

                    }

                    //消息
                    if (id == "1") {
                        var packet = jQuery.parseJSON(arg1);
                        if (packet == null) {
                            eventTarget.trigger('On_ErrorJsonMsg', arg1);

                        } else {
                            //20141019简化S_GetAgentInfo_R的日志打印
                            var bPrintLogRecvMsg = true;
                            if(p.m_log_simple == true){
                                if(packet.opcode == 'S_GetAgentInfo_R' || packet.opcode == 'S_Heart_R') {
                                    bPrintLogRecvMsg = false;
                                }
                            }
                            
                            if(bPrintLogRecvMsg)
                                p.OutputLog('recvmsg: ' + arg1.substr(0, arg1.length - 1));
                            

                            if (packet.opcode == 'S_DisconnectAS') {
                                p.m_LoginFlag = 'login_ing';
                                p.CurrentState = 0;
                                p.OldState = 0;
//                                p.Internal_Trigger_DoLogin_R(2, 2, 'AgnetServer服务器无法连接');
                            }

//                            if (packet.opcode == 'S_NeedAgentLogout') {
//                                p.Logout();
//                                return;
//                            }

//                            if (packet.opcode == 'S_Login_R') {
//                                if (packet.Result != 0) {
//                                    p.Internal_Trigger_DoLogin_R(4, packet.Result, packet.ErrorInfo);
//                                } else {
//                                    p.m_LoginFlag = 'login_ed';
//                                    p.Internal_Trigger_DoLogin_R(0, 0, "pc成功登陆");
//                                }
//                                return;
//                            }

                            eventTarget.trigger('On_' + packet.opcode, packet);
                        }
                    }
                }
            } catch (e) {
                // TODO: handle exception
                //alert(e);
            }
        },

        //20160906
        MoGetPageHead: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'MoGetPageHead'));
            this.m_mo_gen_session_id ++;
            var packet = { opcode: 'C_GetPageHead', session_id: this.m_mo_gen_session_id, module_name: params.module_name, page_index: params.page_index };
            this.sendmsg_mo(packet);
        },

        //20160906
        MoPageSwitch: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'MoPageSwitch'));
            this.m_mo_gen_session_id ++;
            var packet = { opcode: 'C_PageSwitch', session_id: this.m_mo_gen_session_id, module_name: params.module_name, page_index: params.page_index,search_value: params.search_value, switch_flag: params.switch_flag };
            this.sendmsg_mo(packet);
        },

        MoCommand: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'MoCommand'));
            this.m_mo_gen_session_id ++;
            var packet = { opcode: 'C_Command', session_id: this.m_mo_gen_session_id, module_name: params.module_name, command: params.command, param: params.param };
            this.sendmsg_mo(packet);
        },

        //20160906
        MoConnect: function(params) {
            var p = this;
            p.OutputLog('操作: ' + p.GetParamsInfo(params, 'MoConnect'));
            p.m_ServerIp_mo = params.ip_mo;
            p.m_port_mo = params.port_mo;

            //没有传递port_mo参数，表示不用这个通讯
            if("undefined" == typeof params.port_mo)
                return;

            if("" == params.port_mo || 0 == params.port_mo)
                return;
                
            //连接方法
            var host = "ws://" + p.m_ServerIp_mo + ":" + p.m_port_mo + "/test";
            try {
                if("undefined" != typeof o_socket_mo
                        && o_socket_mo != null) {
                    p.closesocket_mo();
                }

                //o_socket_mo = new WebSocket(host);
                o_socket_mo = new ReconnectingWebSocket(host);
                
                p.OutputLog('Socket_mo Status: ' + o_socket_mo.readyState);

                o_socket_mo.onopen = function() {
                    p.OutputLog('网络monitor连接成功: readystate = ' + o_socket_mo.readyState + ' pseudo = ' + o_socket_mo.m_pseudo);
                    o_socket_mo.send('0aaaa');
                };

                o_socket_mo.onclose = function(evt) {
                    if(o_socket_mo.m_pseudo != p.m_pseudo_mo) {
                        p.OutputLog('网络monitor断开旧有链接: readystate = ' + o_socket_mo.readyState + '(' + o_socket_mo.m_pseudo + ',' + p.m_pseudo_mo + ')');
                    }
                    else {
                        p.OutputLog('网络monitor断开链接: readystate = ' + o_socket_mo.readyState + ' pseudo = ' + o_socket_mo.m_pseudo);
                        if(o_socket_mo.readyState == 0)
                            p.mo_Internal_Trigger_DoLogin_R(2, '连接服务器失败', 0);
                    }
                    
                };
                //接收到消息
                o_socket_mo.onmessage = function(msg) {
                    var str = "";
                    str = msg.data;
                    var id = str.substr(0, 1);
                    var separator = str.indexOf("|");
                    var arg1 = "";
                    var arg2 = "";
                    //20161201 解决数据中包含'|'时,会错误分割的bug
                    if (id == "0" && separator != -1) {
                        arg1 = str.substr(1, separator - 1);
                        arg2 = str.substr(separator + 1);
                    }
                    else
                        arg1 = str.substr(1);
                    //握手信息
                    if (id == "0") {
                        p.OutputLog('握手: ' + arg1);
                        p.m_pseudo_mo = arg1;
                        o_socket_mo.m_pseudo = arg1;
                    }
                    //消息
                    if (id == "1") {
                        //20161021
                       if(o_socket_mo.m_pseudo != p.m_pseudo_mo) {
                            p.OutputLog( '忽略接收旧有链接来的消息: old(' + o_socket_mo.m_pseudo + ') vs now(' + p.m_pseudo_mo + ')' );
                           
                       } else {
                       
                            if(arg1.indexOf('AgentServer/模块信息') > 0)
                            {
                                var debug = 1;
                            }
                        
                            var packet = jQuery.parseJSON(arg1);
                            if (packet == null) {
                                eventTarget.trigger('On_ErrorJsonMsg', arg1);

                            } else {
                                if(packet._opcode == 'S_Verify') {
                                    var packet = { opcode: 'C_Verify_R', tag: 'MoUI', ui_id: '0', user_name:'',password: '' };
                                    p.sendmsg_mo(packet);
                                }
                                else if(packet._opcode == 'S_NotifyID') {
                                    p.mo_Internal_Trigger_DoLogin_R(packet.result, packet.error_info, packet.ui_id);
                                }
                                
                                var bPrintLogRecvMsg = true;
                                if(p.m_log_simple == true){
                                    if(packet._opcode == 'S_Heart_R') {
                                        bPrintLogRecvMsg = false;
                                    }
                                }
                                
                                if(bPrintLogRecvMsg) {
                                    var arg_print = arg1.substr(0,arg1.length - 1);
                                    var length_info = arg_print.length;
                                    if(packet._opcode == 'S_ShowPage' && arg_print.length > 100 && p.m_log_simple == true){
                                            arg_print = arg_print.substr(0,100) + '...' + length_info + 'bytes';  //简化S_ShowPage的日志打印
                                    }
                                    p.OutputLog('recvmsg_mo: ' + arg_print);
                                    eventTarget.trigger('On_Mo_' + packet._opcode, packet);
                                }
                            }
                        }
                    }
                }
            } catch (e) {
                // TODO: handle exception
                //alert(e);
            }
        },

        on: function(eventname, handler) {
            //注册事件
            eventTarget.on(eventname, handler);
        },

        un: function(eventname, handler) {
            //注销事件
            eventTarget.un(eventname, handler);
        },

        SetDebug: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'SetDebug'));
            //调试方法 
            this.m_bDebug = params.bDebug;
            if(params.bDebug == true) {
                this.m_log_simple = false;
            }
        },

        Heart: function(params) {
            if(this.m_log_simple == false){
                this.OutputLog('操作: ' + this.GetParamsInfo(params, 'Heart') + this.m_HeartCount);
            }

            //发送心跳包
            var packet = { opcode: 'C_Heart',Count: this.m_HeartCount };
            this.sendmsg(packet);
            
            //20151012
            this.sendmsg_ipps(packet);
            
            //20160921
            this.sendmsg_mo(packet);
            
            this.m_HeartCount ++;
        },

        Register: function(params) {//_cid, _HotlineNumberList, _ExtPhone, _Password) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'Register'));
            //发送注册请求

            //20170601
            var _ExtPhone;            
            {
                var ss = params.ExtPhone.split('$');
                _ExtPhone = ss[0];
            }
            
            var packet = { opcode: 'C_Register', cid: parseInt(params.cid), HotlineNumberList: params.HotlineNumberList, ExtPhone: _ExtPhone, Password: params.Password, bDebug: this.m_bDebug };
            this.sendmsg(packet);
        },

        genUUID: function() {
            var s = [];
            var hexDigits = "0123456789abcdef";
            for (var i = 0; i < 36; i++) {
                s[i] = hexDigits.substr(Math.floor(Math.random() * 0x10), 1);
            }
            s[14] = "4";  // bits 12-15 of the time_hi_and_version field to 0010
            s[19] = hexDigits.substr((s[19] & 0x3) | 0x8, 1);  // bits 6-7 of the clock_seq_hi_and_reserved to 01
            s[8] = s[13] = s[18] = s[23] = "-";
         
            var _uuid = s.join("");
            return _uuid;
        },

        Login: function(params) {//_TerminalType, _cid, _gid, _ExtPhone, _Code, _CodeName, _bLoginBusy, _Reserved) {
            var p = this;
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'Login'));
            //发送登陆请求
            p.m_AgentCode = params.Code;
            
            //20170601
            {
                var ss = params.ExtPhone.split('$');
                p.m_ExtPhone = ss[0];
            }

            //old code
            //p.m_ExtPhone = params.ExtPhone;

            p.m_TerminalType = parseInt(params.TerminalType);
            switch (p.m_TerminalType) {
                case 0: p.m_AgentType = 3; break;
                case 1: p.m_AgentType = 1; break;
                case 2: p.m_AgentType = 1; break;
                case 3: p.m_AgentType = 2; break;
            }

            var _cid = params.cid + '$' + params.CidName;
            
            //20170829
            var _guid = window.localStorage.getItem("loginGuid");
            if (!_guid){
                _guid = this.genUUID();
                window.localStorage.setItem("loginGuid", _guid);
            }
            

            var packet = { opcode: 'C_Login', cid: _cid, gid: params.gid, AgentType: p.m_AgentType,
                ExtPhone: params.ExtPhone, Code: params.Code, _Name: params.CodeName, Reserved: params.Reserved, bLoginBusy: parseInt(params.bLoginBusy),
                TerminalType: parseInt(params.TerminalType), bRelogin: 0, FileVersion: 'web', ProductVersion: 'web', bDebug: p.m_bDebug,
                guid: _guid };//20170829 增加guid
                
            this.sendmsg(packet);
        },

        Logout: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'Logout'));
            //发送注销请求
            var packet = { opcode: 'C_Loginout', Channel: -1 };
            this.sendmsg(packet);
            
            //20170728
            packet = { opcode: 'C_Logout'};
            this.sendmsg_ipps(packet);
            
            this.closesocket();  //注销就要断开网络
            this.m_LoginFlag = 'login_none';
            this.CurrentState = 0;
            this.OldState = 0;
            
            //20170605
            this.m_port_ipps = 0;
            this.Internal_Trigger_S_AgentState("");
        },
        //发送置忙请求
        SetBusy: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'SetBusy'));
            var packet = { opcode: 'C_SetBusy', Channel: -1, AgentType: this.m_AgentType, ExtPhone: this.m_ExtPhone };
            this.sendmsg(packet);
        },
        //发送置闲请求
        SetFree: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'SetFree'));
            var packet = { opcode: 'C_SetFree', Channel: -1, AgentType: this.m_AgentType, ExtPhone: this.m_ExtPhone };
            this.sendmsg(packet);
        },

        //发送小休请求
        SetRest: function(params) {//CustomName) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'SetRest'));
            var packet = { opcode: 'C_SetRest', Channel: -1, AgentType: this.m_AgentType, ExtPhone: this.m_ExtPhone, CustomName:params.CustomName };
            this.sendmsg(packet);
        },

        //发送抢接请求 20140804
        Snatch: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'Snatch'));
            var packet = { opcode: 'C_Snatch', Channel: -1, nType: params.nType, FormatStr: params.FormatStr };
            this.sendmsg(packet);
        },

        //发送获取坐席信息请求
        GetAgentInfo: function(params) { //_nType, _nFlag, _CodeList) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'GetAgentInfo'));
            var packet = { opcode: 'C_GetAgentInfo', Channel: -1, nType: parseInt(params.nType), nFlag: parseInt(params.nFlag), CodeList: params.CodeList };
            this.sendmsg(packet);
        },

        //发送获取外线排队长度信息请求
        GetChannelQueueSize: function(params) {//_Gid, _nFlag) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'GetChannelQueueSize'));
            var packet = { opcode: 'C_GetChannelQueueSize', Channel: -1, Gid: parseInt(params.Gid), nFlag: params.nFlag };
            this.sendmsg(packet);
        },

        //发送获取外线排队信息请求
        GetChannelQueueInfo: function(params) {//_Gid, _nFlag) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'GetChannelQueueInfo'));
            var packet = { opcode: 'C_GetChannelQueueInfo', Channel: -1, AgentType: this.m_AgentType, ExtPhone: this.m_ExtPhone, Gid: parseInt(params.Gid), nFlag: params.nFlag };
            this.sendmsg(packet);
        },

        //发送接听请求
        ClientAnswer: function(params) {//nType) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'ClientAnswer'));
            var packet = { opcode: 'C_ClientAnswer', Channel: -1, AgentType: this.m_AgentType, ExtPhone: this.m_ExtPhone, nType: parseInt(params.nType) };
            this.sendmsg(packet);
            
	    //20161027 增加判断
	    var _type = parseInt(params.nType);
	    if(_type == 0) {
	            //20151012
	            this.IPPS_ClientAnswer();
	    }
        },

        //发送挂机请求
        Hangup: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'Hangup'));
            var packet = { opcode: 'C_Hangup', Channel: -1, AgentType: this.m_AgentType, ExtPhone: this.m_ExtPhone };
            this.sendmsg(packet);
        },

        //发送话后处理请求
        EndProcessing: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'EndProcessing'));
            var packet = { opcode: 'C_EndProcessing', Channel: -1, AgentType: this.m_AgentType, ExtPhone: this.m_ExtPhone };
            this.sendmsg(packet);
        },

        //发送保持请求
        Keep: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'Keep'));
            
            //20160119 增加Mode
            var packet = { opcode: 'C_Keep', Channel: -1, AgentType: this.m_AgentType, ExtPhone: this.m_ExtPhone};
            this.sendmsg(packet);
        },

        //20160119
        //发送静音请求
        Silence: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'Silence'));
            var packet = { opcode: 'C_Silence', Channel: -1, AgentType: this.m_AgentType, ExtPhone: this.m_ExtPhone};
            this.sendmsg(packet);
        },

        //发送恢复请求
        Restore: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'Restore'));
            var packet = { opcode: 'C_Restore', Channel: -1, AgentType: this.m_AgentType, ExtPhone: this.m_ExtPhone };
            this.sendmsg(packet);
        },

        //发送呼叫请求
        MakeCallOut: function(params) {//_CallerNo, _CalledNo, _BusinessCode, _Reserved) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'MakeCallOut'));
            var _Direction;
            if (this.m_AgentType == 3)
                _Direction = 1;
            else
                _Direction = 4;
            this.m_Caller = params.CallerNo;
            this.m_Called = params.CalledNo;
            var packet = { opcode: 'C_MakeCallOut', Channel: -1, Direction: _Direction, _Caller: params.CallerNo, _Called: params.CalledNo, BusinessCode: params.BusinessCode, Reserved: params.Reserved };

            //20151012 在之前设置标志
            this.IPPS_SetMakeCallOutFlag(1);

            this.sendmsg(packet);
            
        },

        //发送呼叫取消请求
        MakeCallOutCancel: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'MakeCallOutCancel'));
            var packet = { opcode: 'C_MakeCallOutCancel', Channel: -1 };
            this.sendmsg(packet);
        },

        //发送转移外线请求
        TransTel: function(params) {//_CallerNo, _CalledNo, _BusinessCode, _Reserved) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'TransTel'));
            var packet = { opcode: 'C_TransTel', Channel: -1, AgentType: this.m_AgentType, ExtPhone: this.m_ExtPhone, nType: 0, _Caller: params.CallerNo, _Called: params.CalledNo, BusinessCode: params.BusinessCode, Reserved: params.Reserved };
            this.sendmsg(packet);
        },
        //发送转移内线请求
        TransAgent: function(params) {//_nType, _FormatStr) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'TransAgent'));
            var packet = { opcode: 'C_TransAgent', Channel: -1, AgentType: this.m_AgentType, ExtPhone: this.m_ExtPhone, nType: parseInt(params.nType), FormatStr: params.FormatStr };
            this.sendmsg(packet);
        },

        //发送转移ivr请求
        TransIVR: function(params) {//_BusinessCode) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'transIVR'));
            var packet = { opcode: 'C_TransIVR', Channel: -1, AgentType: this.m_AgentType, ExtPhone: this.m_ExtPhone, BusinessCode: params.BusinessCode };
            this.sendmsg(packet);
        },

        //发送转移取消请求
        TransCancel: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'TransCancel'));
            var packet = { opcode: 'C_TransCancel', Channel: -1, AgentType: this.m_AgentType, ExtPhone: this.m_ExtPhone };
            this.sendmsg(packet);
        },

        //发送三方通话请求
        ConfStart: function(params) {//_CallerNo, _CalledNo, _BusinessCode) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'confStart'));
            var packet = { opcode: 'C_ConfStart', Channel: -1, nType: 1, _Caller: params.CallerNo, _Called: params.CalledNo, BusinessCode: params.BusinessCode };
            this.sendmsg(packet);
        },

        //发送三方通话取消请求
        ConfStartCancel: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'ConfStartCancel'));
            var packet = { opcode: 'C_ConfStartCancel', Channel: -1 };
            this.sendmsg(packet);
        },

        //发送 转接成功待确认        
        TransConfirm: function(params) {//_Response) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'TransConfirm'));
            var packet = { opcode: 'C_TransConfirm', Channel: -1, AgentType: this.m_AgentType, ExtPhone: this.m_ExtPhone, Response: parseInt(params.Response) };
            this.sendmsg(packet);
        },

        //发送 三方通话确认第三方   
        ConfConfirm: function(params) {//_Response) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'Confconfirm'));
            var packet = { opcode: 'C_ConfConfirm', Channel: -1, Response: parseInt(params.Response) };
            this.sendmsg(packet);
        },

        //发送 进入管理状态
        InManager: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'InManager'));
            var packet = { opcode: 'C_InManager', Channel: -1, AgentType: this.m_AgentType, ExtPhone: this.m_ExtPhone };
            this.sendmsg(packet);
        },


        //发送 退出管理状态
        OutManager: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'OutManager'));
            var packet = { opcode: 'C_OutManager', Channel: -1, AgentType: this.m_AgentType, ExtPhone: this.m_ExtPhone };
            this.sendmsg(packet);
        },

        //发送 监听
        Listen: function(params) {//_Code) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'Listen'));
            var packet = { opcode: 'C_Listen', Channel: -1, ExtPhone: this.m_ExtPhone, Code: params.Code };

            //20170216 在之前设置标志
            this.IPPS_SetMakeCallOutFlag(1);

            this.sendmsg(packet);
        },

        //发送 退出监听
        ExitListen: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'ExitListen'));
            var packet = { opcode: 'C_ExitListen', Channel: -1 };
            this.sendmsg(packet);
        },

        //发送 强插
        ForceInsert: function(params) {//_Code) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'ForceInsert'));
            var packet = { opcode: 'C_ForceInsert', Channel: -1, Code: params.Code };
            this.sendmsg(packet);
        },

        //发送 退出强插
        ExitForceInsert: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'ExitForceInsert'));
            var packet = { opcode: 'C_ExitForceInsert', Channel: -1 };
            this.sendmsg(packet);
        },

        //发送 强制拆线
        ForceRelease: function(params) {//_Code) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'ForceRelease'));
            var packet = { opcode: 'C_ForceRelease', Channel: -1, AgentType: this.m_AgentType, ExtPhone: this.m_ExtPhone, Code: params.Code };
            this.sendmsg(packet);
        },

        //发送 强制置忙
        ForceSetBusy: function(params) {//_Code) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'ForceSetBusy'));
            var packet = { opcode: 'C_ForceSetBusy', Channel: -1, AgentType: this.m_AgentType, ExtPhone: this.m_ExtPhone, Code: params.Code };
            this.sendmsg(packet);
        },

        //发送 强制置闲
        ForceSetFree: function(params) {//_Code) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'ForceSetFree'));
            var packet = { opcode: 'C_ForceSetFree', Channel: -1, AgentType: this.m_AgentType, ExtPhone: this.m_ExtPhone, Code: params.Code };
            this.sendmsg(packet);
        },

        //发送 强制注销
        ForceLogout: function(params) {//_Code) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'ForceLogout'));
            var packet = { opcode: 'C_ForceLogout', Channel: -1, AgentType: this.m_AgentType, ExtPhone: this.m_ExtPhone, Code: params.Code };
            this.sendmsg(packet);
        },

        //发送会议发起请求
        MeetingStart: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'MeetingStart'));
            var packet = { opcode: 'C_MeetingStart', Channel: -1, CalledList: '' };
            this.sendmsg(packet);
        },

        //发送会议增加成员请求
        MeetingAdd: function(params) {//_CalledList) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'MeetingAdd'));
            var packet = { opcode: 'C_MeetingAdd', Channel: -1, CalledList: params.CalledList };
            this.sendmsg(packet);
        },

        //发送会议更改成员模式请求
        MeetingUpdateMode: function(params) {//_MeetingNumber, _nMode) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'MeetingUpdateMode'));
            var packet = { opcode: 'C_MeetingUpdateMode', Channel: -1, MeetingNumber: params.MettingNumber, _Mode: parseInt(params.nMode) };
            this.sendmsg(packet);
        },

        //发送会议成员挂断请求
        MeetingHangup: function(params) {//_MeetingNumber) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'MeetingHangup'));
            var packet = { opcode: 'C_MeetingHangup', Channel: -1, MeetingNumber: params.MeetingNumber };
            this.sendmsg(packet);
        },
        //发送会议结束会议请求
        MeetingEnd: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'MeetingEnd'));
            var packet = { opcode: 'C_MeetingEnd', Channel: -1 };
            this.sendmsg(packet);
        },

        //发送DTMF
        SendDTMF: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'SendDTMF'));
            var packet = { opcode: 'C_SendDTMF', Keys: params.Keys };
            this.sendmsg(packet);
        },
        
        //发送自定义命令
        CustomCommand: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'CustomCommand'));
            var packet = { opcode: 'C_CustomCommand', nType: parseInt(params.nType), sData: params.sData };
            this.sendmsg(packet);
        },
        
        //20140924(前锋)
        //获取当前空闲坐席个数
        GetFreeAgentCount: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'GetFreeAgentCount'));
            var packet = { opcode: 'C_GetFreeAgentCount', gid: parseInt(params.gid) };
            this.sendmsg(packet);
        },

        //20141017
        //申请电话登陆(仅适用于内线电话)
        ApplyTelLogin: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'ApplyTelLogin'));
            var packet = { opcode: 'C_ApplyTelLogin', Channel: parseInt(params.Channel) };
            this.sendmsg(packet);
        },
        
        //20141124 增加GetBusyState()
        //20141209 更改为SetBusyState()
        SetBusyState: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'SetBusyState'));
            var packet = { opcode: 'C_SetBusyState',bBusy: parseInt(params.bBusy) };
            this.sendmsg(packet);
        },
        
        //20150424
        //综合的sa登录操作(包括连接as,SALogin两部分异步操作)
        DoSALogin: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'DoSALogin'));
            
            this.m_LoginFlag = 'login_ing';
            this.m_LoginParam = params;
            this.SAConnect(params);
        },

        //sa登录
        SALogin: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'SALogin'));
            
            var packet = { opcode: 'C_SALogin' , CId: parseInt(params.CId), Code: params.Code};
            this.sendmsg(packet);
        },

        //20150424
        //sa登出
        SALogout: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'SALogout'));
            var packet = { opcode: 'C_SaLogout' };
            this.sendmsg(packet);
            this.closesocket();  //注销就要断开网络
            this.m_LoginFlag = 'login_none';
        },
        
        //20160906
        DoMoLogin: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'DoMoLogin'));
           
            this.MoConnect(params);
        },
        
        //20161021
        MoLogout: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'MoLogout'));
            var packet = { opcode: 'C_Logout' };
            this.sendmsg_mo(packet);
            this.closesocket();  //注销就要断开网络
        },

        //20150424
        //聊天信息
        SendChat: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'SendChat'));
            var packet = { opcode: 'C_SendChat',MessageID: params.MessageID,Receiver: params.Receiver };
            this.sendmsg(packet);
        },
        
        //20160108
        NotifyCodeList: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'NotifycodeList'));
            var packet = { opcode: 'C_NotifyCodeList'};
            this.sendmsg(packet);
        },
        
        
        //20151012
        IPPS_Version: function() {
            var _Version = "nothing";
            this.OutputLog('IPPS_Version: ' + _Version);

            //20170602
            var _ExtPhone;            
            {
                var ss = this.m_LoginParam.ExtPhone.split('$');
                _ExtPhone = ss[0];
            }
            
            //20170727 增加password
            var packet = { opcode: 'C_Version' , Version: _Version, ExtPhone: _ExtPhone, Password: this.m_LoginParam.ExtPhonePassword,
                                 SipServerIPPort: this.m_LoginParam.SipServerIPPort };
            this.sendmsg_ipps(packet);
        },
        
        //20151012
        IPPS_ClientAnswer: function() {
            this.OutputLog('IPPS_ClientAnswer: ');
            
            var packet = { opcode: 'C_ClientAnswer'};
            this.sendmsg_ipps(packet);
        },

        //20170215 增加参数flag
        //20151012
        IPPS_SetMakeCallOutFlag: function(_flag) {
            this.OutputLog('IPPS_SetMakeCallOutFlag: ' + _flag);
            
            var packet = { opcode: 'C_SetMakeCallOutFlag', flag: _flag};
            this.sendmsg_ipps(packet);
        },
        
        //20160303
        PlayAudio: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'PlayAudio'));
            var packet = { opcode: 'C_PlayAudio', Channel: -1, Command: params.Command, Param1: params.Param1, Param2: params.Param2, Param3: params.Param3 };
            this.sendmsg(packet);
        },
        
        //20170930
        SetUnloadState: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'SetUnloadState'));
            var packet = { opcode: 'C_SetUnloadState', Channel: -1, UnloadState: params.unloadState };
            this.sendmsg(packet);
        },
        
        //20171020
        GetPredialInfo: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'GetPredialInfo'));
            var packet = { opcode: 'C_GetPredialInfo', cid: params.cid, ids: params.ids };
            this.sendmsg(packet);
        },
        
        //20171127
				SetPredialTaskInfo: function(params) {
            this.OutputLog('操作: ' + this.GetParamsInfo(params, 'SetPredialTaskInfo'));
            var packet = { opcode: 'C_SetPredialTaskInfo', taskid: params.taskid, taskname: params.taskname, operate:params.operate};
            this.sendmsg(packet);
        },
                
    }
});

//20170930
window.onload = function() {
    setTimeout(function() {
        $.QYProxy.SetUnloadState(0);
    }, 3000);
}

window.onunload = function() {
    //服务器开始记时,如果10秒内没有收到$.QYProxy.SetUnloadState(0)消息,服务器将会断开坐席状态
    $.QYProxy.SetUnloadState(1);
}


/////////////////////////////////////////////////////////////
//事件对象
var eventTarget = {
    on: function(eventname, handler) {
        //事件注册
        this.Handlers.push({ name: eventname, handler: handler });
    },
    Handlers: [],

    un: function(eventname, handler) {
        //事件注销
        var itemindex = -1;
        for (var index = 0; index < this.Handlers.length; index++) {
            if (this.Handlers[index].name == eventname && this.Handlers[index].handler == handler) {
                itemindex = index;
                break;
            }
        }
        if (itemindex > -1) {
            this.Handlers.splice(itemindex, 1);
        }
    },
    trigger: function(eventname, args) {
      
        if ($.QYAgent.m_EventMode == 2) {
            if (cs_port) {
                if (eventname == 'On_S_StartRing') {
                    this.Notification_StartRing(args);
                }
                
                if(eventname == 'On_S_AgentState') {
                    if($.QYAgent.OldState == 5 && $.QYAgent.CurrentState != 5) {//如果从振铃状态变为其它状态
                        if($.QYAgent.o_Notification != null) {
                            $.QYAgent.o_Notification.close();
                        }
                    }
                }
                
                var msg = { opcode: eventname, args: args };
                var s = JSON.stringify(msg);
                //var s2 = 'cs_port.postMessage(' + s + ')';
                //setTimeout( 'cs_port.postMessage("+ msg + ")', 1);
                //cs_port.postMessage(msg);
               // var m_data={ opcode: eventname, args: args };

                //$.QYAgent.OutputLog('==========trigger settimeout: ' + s);
              //  var p = eventTarget;
                //p.m_postMessage(m_data);
                $.QYProxy[eventname](s);
                
            }
        }
        else {
            //触发事件
            for (var index = 0; index < this.Handlers.length; index++) {
                if (this.Handlers[index].name == eventname) {
                    //this.Handlers[index].handler(args);
                    setTimeout($.acooly.agent[this.Handlers[index].handler](args), 0);
                    
                }
            }
        }
    },
    
    m_postMessage:function(data){
        var p = eventTarget;
        //$.QYAgent.OutputLog('==========trigger m_postmessage: ' + data.opcode);
        //solution 1
        setTimeout(function(){cs_port.postMessage(data);},0);       
        //solution 2
        //setTimeout(cs_port.postMessage(data),0);     
    },
    
    //显示通知
    Notification_StartRing_Show: function(args) {
        $.QYAgent.o_Notification = new Notification('您有来电', {
            icon: 'phone.png',
            body: '主叫: ' + args._Caller + ' ' + '被叫:' + args._Called
        });
        
        //通知点击事件
        $.QYAgent.o_Notification.onclick=function () {
            chrome.windows.get($.QYAgent.m_WindowId, function(w) {
                var debug = 1;
//                alert(JSON.stringify(w));
//                alert($.QYAgent.m_WindowId + ' ' + $.QYAgent.m_TabId);

                //激活指定窗口
                var updateInfo = { focused: true };
                chrome.windows.update($.QYAgent.m_WindowId,updateInfo);
                
                //激活指定Tab页
                var updateProperties = {selected: true};
                chrome.tabs.update($.QYAgent.m_TabId,updateProperties );

            });
        };
        
        $.QYAgent.m_Count_Notification = $.QYAgent.m_Count_Notification + 1;
    },

    //试图激活通知
    Notification_StartRing: function (args) {
        if($.QYAgent.o_Notification != null) {
            $.QYAgent.o_Notification.close();
        }
        var p=this;
        chrome.windows.get($.QYAgent.m_WindowId, function(w) {
            if(w.state == 'minimized' || w.focused == false) {
                //窗口最小化的时候或者未激活的时候激活通知
                p.Notification_StartRing_Show(args);
            } else {
                chrome.tabs.getSelected(w.id, function(t) {
                    //窗口当前Tab页不是指定页的时候激活通知
                    if($.QYAgent.m_TabId != t.id) {
                        p.Notification_StartRing_Show(args);
                    }
                });
            }
        });
        
        
        var debug =  1;
    },
    
}
