-- gen_dir_user_xml.lua
-- example script for generating user directory XML
--    CREATE TABLE   userinfo(
--      `id` int(11) NOT NULL auto_increment,
--       username	varchar(64) NOT NULL default '',
--       password    varchar(64) NOT NULL default '',
--       state    int NOT NULL default 0,
--       updatedate	timestamp NOT NULL default CURRENT_TIMESTAMP ,
--      PRIMARY KEY  (`id`)
--    ) ENGINE=MyISAM DEFAULT CHARSET=gbk;

-- comment the following line for production:
--freeswitch.consoleLog("notice", "Debug from gen_dir_user_xml.lua, provided params:\n" .. params:serialize() .. "\n")

local req_domain = params:getHeader("domain")
local req_key    = params:getHeader("key")
local req_user   = params:getHeader("user")
local tt = freeswitch.getGlobalVariable("global_codec_prefs")

freeswitch.consoleLog("notice","ttttt=" .. tt .. "\n")

if req_domain==nil then
	req_domain="192.168.1.3"
end
if req_user==nil then
	req_user="1001"
end

  XML_STRING =
[[<?xml version="1.0" encoding="UTF-8" standalone="no"?>
<document type="freeswitch/xml">
  <section name="directory">
    <domain name="]] .. req_domain .. [[">       
       <user id="]] .. req_user  .. [[" cacheable="14400">
        <params>
           <param name="password" value="11111111"/>           
           <param name="dial-string" value="{sip_invite_domain=${dialed_domain},presence_id=${dialed_user}@${dialed_domain}}${sofia_contact(${dialed_user}@${dialed_domain})}"/>
        </params>
         <variables>	       
	      <variable name="user_context" value="default"/>	       
	</variables>
      </user>
    </domain>
  </section>
</document>]]

  -- comment the following line for production:
-- freeswitch.consoleLog("warning", "Debug from user.lua, generated XML:\n" .. XML_STRING .. "\n")


