@echo off

set PATH=%~dp0\bin;$PATH
set OPENSSL_CONF=conf\openssl.cnf

call _request.cmd raspberry
call _control.cmd raspberry
call _accept.cmd raspberry
call _convert.cmd raspberry
