@echo off

set PATH=%~dp0\bin;$PATH
set OPENSSL_CONF=conf\openssl.cnf

call _request.cmd neotech
call _control.cmd neotech
call _accept.cmd neotech
call _convert.cmd neotech
