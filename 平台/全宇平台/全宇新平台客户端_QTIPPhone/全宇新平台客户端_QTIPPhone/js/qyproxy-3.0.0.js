(function($) {
    $.extend({
        QYProxy: {
            m_bLoging: false,
            o_LoginParam: "",
            m_CurrentState: 0,

            Internal_trim: function(str) {
                str = str.replace(/^(\s|\u00A0)+/, '');
                for (var i = str.length - 1; i >= 0; i--) {
                    if (/\S/.test(str.charAt(i))) {
                        str = str.substring(0, i + 1);
                        break;
                    }
                }
                return str;
            },

            //将函数的参数列表转换为Json对象
            GetFunctionJsonParamInfo: function(funcobj, funcobjname) {

                //获取参数名称列表
                var text = funcobj.toString();
                var pos1 = text.indexOf('(');
                var pos2 = text.indexOf(')');
                text = text.substring(pos1 + 1, pos2);
                var paramnames = text.split(',');

                //
                var numargs = funcobj.arguments.length;     // 获取实际被传递参数的数值。
                var expargs = funcobj.length;               // 获取期望参数的数值，函数定义时的预期参数个数。
                // expargs 是等于 paramnames数组元素的个数的


                var ss = { opcode: funcobjname };
                if (paramnames.length != 0) {
                    ss[this.Internal_trim(paramnames[0])] = funcobj.arguments[0];
                    for (i = 1; i < paramnames.length; i++) {               // 获取参数内容。
                        ss[this.Internal_trim(paramnames[i])] = funcobj.arguments[i];
                    }
                }

                return (ss);                          // 返回函数信息。
            },

            dateFormatter: function(value) {
                var date;
                if (value) {
                    date = new Date(value);
                } else {
                    date = new Date();
                }
                return date.getFullYear() + '-' +
        				    parseInt(date.getMonth() + 1) + '-' +
        				    parseInt(date.getDate()) + " " +
        				    parseInt(date.getHours()) + ":" +
        				    parseInt(date.getMinutes()) + ":" +
        				    parseInt(date.getSeconds()) + ":" +
        				    parseInt(date.getMilliseconds());
            },

            Internal_postMessage: function(funcobj, funcobjname) {

                // console.info(this.dateFormatter() + " ===========0 ---- " + funcobjname);

                var s = this.GetFunctionJsonParamInfo(funcobj, funcobjname);
                try {
                    //  console.info(this.dateFormatter() + " ===========1 ---- " + funcobjname);

                    //setTimeout( window.postMessage(msg, "*"), 0);
                    //window.postMessage(msg, "*");
                    $.QYAgent[funcobjname](s);
                    // console.info(this.dateFormatter() + " ===========2 ----" + funcobjname);
                }
                catch (e) {
                }
            },

            on: function(eventname, handler) {
                try {
                   // var s = { type: "FROM_PAGE", text: { opcode: "RegisterEvent", eventname: eventname, handler: handler} };
                  //  window.postMessage(s, "*");

                    eventTarget.on(eventname, handler);
                }
                catch (e) {
                }
            },

            un: function(eventname, handler) {
            eventTarget.un(eventname, handler);
            },

            //更新当前坐席状态
            UpdateCurrentState: function() {
                this.Internal_postMessage(this.UpdateCurrentState, 'UpdateCurrentState');
            },

            //获取当前坐席状态
            GetCurrentState: function() {
                return this.m_CurrentState;
            },

            //综合的登录操作(包括连接as,AgentRegister,AgentLogin三部分异步操作)
            DoLogin: function(LoginParam) {
                this.Internal_postMessage(this.DoLogin, 'DoLogin');

            },

            //20150424
            //综合的sa登录操作(包括连接as,SALogin两部分异步操作)
            DoSALogin: function(Ip, Port, CId, Code) {
                this.Internal_postMessage(this.DoSALogin, 'DoSALogin');
            },

            //sa登出
            SALogout: function() {
                this.Internal_postMessage(this.SALogout, 'SALogout');
            },

            //20160906
            DoMoLogin: function(ip_mo, port_mo, user, password) {
                this.Internal_postMessage(this.DoMoLogin, 'DoMoLogin');
            },

            //20161021
            MoLogout: function() {
                this.Internal_postMessage(this.MoLogout, 'MoLogout');
            },

            //20160906
            MoGetPageHead: function(module_name, page_index) {
                this.Internal_postMessage(this.MoGetPageHead, 'MoGetPageHead');
            },

            //20160906
            MoPageSwitch: function(module_name, page_index, search_value, switch_flag) {
                this.Internal_postMessage(this.MoPageSwitch, 'MoPageSwitch');
            },

            MoCommand: function(module_name, command, param) {
                this.Internal_postMessage(this.MoCommand, 'MoCommand');
            },

            //20150424
            //聊天信息
            SendChat: function(MessageID, Receiver) {
                this.Internal_postMessage(this.SendChat, 'SendChat');
            },

            //
            NotifyCodeList: function() {
                this.Internal_postMessage(this.NotifycodeList, 'NotifycodeList');
            },

            SetDebug: function(bDebug) {
                this.Internal_postMessage(this.SetDebug, 'SetDebug');
            },

            Logout: function() {
                this.Internal_postMessage(this.Logout, 'Logout');
                this.m_CurrentState = 0;
            },
            //发送置忙请求
            SetBusy: function() {
                this.Internal_postMessage(this.SetBusy, 'SetBusy');
            },
            //发送置闲请求
            SetFree: function() {
                this.Internal_postMessage(this.SetFree, 'SetFree');
            },
            //发送小休请求 20170517 增加参数CustomName
            SetRest: function(CustomName) {
                this.Internal_postMessage(this.SetRest, 'SetRest');
            },

            //发送抢接请求 20140806
            Snatch: function(nType, FormatStr) {
                this.Internal_postMessage(this.Snatch, 'Snatch');
            },

            //发送获取坐席信息请求
            GetAgentInfo: function(nType, nFlag, CodeList) {
                this.Internal_postMessage(this.GetAgentInfo, 'GetAgentInfo');
            },

            //发送获取外线排队长度信息请求
            GetChannelQueueSize: function(Gid, nFlag) {
                this.Internal_postMessage(this.GetChannelQueueSize, 'GetChannelQueueSize');
            },

            //发送获取外线排队信息请求
            GetChannelQueueInfo: function(Gid, nFlag) {
                this.Internal_postMessage(this.GetChannelQueueInfo, 'GetChannelQueueInfo');
            },

            //发送接听请求
            ClientAnswer: function(nType) {
                this.Internal_postMessage(this.ClientAnswer, 'ClientAnswer');
            },

            //发送挂机请求
            Hangup: function() {
                this.Internal_postMessage(this.Hangup, 'Hangup');
            },

            //发送话后处理请求
            EndProcessing: function() {
                this.Internal_postMessage(this.EndProcessing, 'EndProcessing');
            },

            //发送保持请求
            Keep: function() {
                this.Internal_postMessage(this.Keep, 'Keep');
            },

            //20160119
            //发送静音请求
            Silence: function() {
                this.Internal_postMessage(this.Silence, 'Silence');
            },

            //发送恢复请求
            Restore: function() {
                this.Internal_postMessage(this.Restore, 'Restore');
            },

            //发送呼叫请求
            MakeCallOut: function(CallerNo, CalledNo, BusinessCode, Reserved) {
                this.Internal_postMessage(this.MakeCallOut, 'MakeCallOut');
            },

            //发送呼叫取消请求
            MakeCallOutCancel: function() {
                this.Internal_postMessage(this.MakeCallOutCancel, 'MakeCallOutCancel');
            },

            //发送转移外线请求
            TransTel: function(CallerNo, CalledNo, BusinessCode, Reserved) {
                this.Internal_postMessage(this.TransTel, 'TransTel');
            },

            //发送转移内线请求
            TransAgent: function(nType, FormatStr) {
                this.Internal_postMessage(this.TransAgent, 'TransAgent');
            },

            //发送转移ivr请求
            TransIVR: function(BusinessCode) {
                this.Internal_postMessage(this.TransIVR, 'TransIVR');
            },

            //发送转移取消请求
            TransCancel: function() {
                this.Internal_postMessage(this.TransCancel, 'TransCancel');
            },

            //发送三方通话请求
            //BusinessCode后附带  $ConfType -- 1-三方通话 2-邀请教练
            ConfStart: function(CallerNo, CalledNo, BusinessCode) {
                this.Internal_postMessage(this.ConfStart, 'ConfStart');
            },

            //发送三方通话取消请求
            ConfStartCancel: function() {
                this.Internal_postMessage(this.ConfStartCancel, 'ConfStartCancel');
            },

            //发送 转接成功待确认        
            TransConfirm: function(Response) {
                this.Internal_postMessage(this.TransConfirm, 'TransConfirm');
            },

            //发送 三方通话确认第三方   
            ConfConfirm: function(Response) {
                this.Internal_postMessage(this.ConfConfirm, 'ConfConfirm');
            },

            //发送 进入管理状态
            InManager: function() {
                this.Internal_postMessage(this.InManager, 'InManager');
            },


            //发送 退出管理状态
            OutManager: function() {
                this.Internal_postMessage(this.OutManager, 'OutManager');
            },

            //发送 监听
            Listen: function(Code) {
                this.Internal_postMessage(this.Listen, 'Listen');
            },

            //发送 退出监听
            ExitListen: function() {
                this.Internal_postMessage(this.ExitListen, 'ExitListen');
            },

            //发送 强插
            ForceInsert: function(Code) {
                this.Internal_postMessage(this.ForceInsert, 'ForceInsert');
            },

            //发送 退出强插
            ExitForceInsert: function() {
                this.Internal_postMessage(this.ExitForceInsert, 'ExitForceInsert');
            },

            //发送 强制拆线
            ForceRelease: function(Code) {
                this.Internal_postMessage(this.ForceRelease, 'ForceRelease');
            },

            //发送 强制置忙
            ForceSetBusy: function(Code) {
                this.Internal_postMessage(this.ForceSetBusy, 'ForceSetBusy');
            },

            //发送 强制置闲
            ForceSetFree: function(Code) {
                this.Internal_postMessage(this.ForceSetFree, 'ForceSetFree');
            },

            //发送 强制注销
            ForceLogout: function(Code) {
                this.Internal_postMessage(this.ForceLogout, 'ForceLogout');
            },

            //发送会议发起请求
            MeetingStart: function() {
                this.Internal_postMessage(this.MeetingStart, 'MeetingStart');
            },

            //发送会议增加成员请求
            MeetingAdd: function(CalledList) {
                this.Internal_postMessage(this.MeetingAdd, 'MeetingAdd');
            },

            //发送会议更改成员模式请求
            MeetingUpdateMode: function(MeetingNumber, nMode) {
                this.Internal_postMessage(this.MeetingUpdateMode, 'MeetingUpdateMode');
            },

            //发送会议成员挂断请求
            MeetingHangup: function(MeetingNumber) {
                this.Internal_postMessage(this.MeetingHangup, 'MeetingHangup');
            },

            //发送会议结束会议请求
            MeetingEnd: function() {
                this.Internal_postMessage(this.MeetingEnd, 'MeetingEnd');
            },

            //发送DTMF
            SendDTMF: function(Keys) {
                this.Internal_postMessage(this.SendDTMF, 'SendDTMF');
            },

            //发送自定义命令 //20140827
            CustomCommand: function(nType, sData) {
                this.Internal_postMessage(this.CustomCommand, 'CustomCommand');
            },

            //20140924(前锋)
            //获取当前空闲坐席个数
            GetFreeAgentCount: function(gid) {
                this.Internal_postMessage(this.GetFreeAgentCount, 'GetFreeAgentCount');
            },

            //20141017
            //申请电话登陆(仅适用于内线电话)
            ApplyTelLogin: function(Channel) {
                this.Internal_postMessage(this.ApplyTelLogin, 'ApplyTelLogin');
            },

            //20141124 增加GetBusyState  1-当前状态为忙 0-当前状态为闲
            //20141209 更改为SetBusyState
            SetBusyState: function(bBusy) {
                this.Internal_postMessage(this.SetBusyState, 'SetBusyState');
            },

            //20160303
            //播音
            PlayAudio: function(Command, Param1, Param2, Param3) {
                this.Internal_postMessage(this.PlayAudio, 'PlayAudio');
            },

            //20170930
            //设置unload状态
            //unloadstate - 1 当前处于unload状态(刷新或关闭浏览器)  0 - 当前处于刷新后load状态
            SetUnloadState: function(unloadState) {
                this.Internal_postMessage(this.SetUnloadState, 'SetUnloadState');
            },

            //20171020
            //获取predial info
            GetPredialInfo: function(cid, ids) {
                this.Internal_postMessage(this.GetPredialInfo, 'GetPredialInfo');
            },
            
            //20171127
            //任务模式下发送任务相关操作
            //operate -- 0退出任务 1进入任务
            SetPredialTaskInfo: function(taskid,taskname,operate) {
                this.Internal_postMessage(this.SetPredialTaskInfo, 'SetPredialTaskInfo');
            },

        }
    });

    //插件事件入口
    window.addEventListener("message", function(event) {
        if (event.source != window)
            return;
        if (event.data.type && (event.data.type == "FROM_BK")) {
            //$.QYProxy.SocektEvent[event.data.handler](event.data.bkdata.args);
            //		console.info(event.data.handler+":"+JSON.stringify(event.data.bkdata.args)+"---------------1:"+(new Date()).toLocaleString()+":"+(new Date()).getMilliseconds());
            if (event.data.handler == 'S_AgentState') {
                //		console.info("QYAgent:  ON_S_AgentState:"+event.data.bkdata.args.State+"----------------2");
                $.QYProxy.m_CurrentState = event.data.bkdata.args.State;
            }
            setTimeout($.acooly.agent[event.data.handler](event.data.bkdata.args), 0);
        }
    }, false);
})(jQuery);

