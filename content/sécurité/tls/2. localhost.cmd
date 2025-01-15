@echo off

set PATH=%~dp0\bin;$PATH
set OPENSSL_CONF=conf\openssl.cnf

call _request.cmd localhost
call _control.cmd localhost
call _accept.cmd localhost
call _convert.cmd localhost
