@echo off

set PATH=%~dp0\bin;$PATH
set OPENSSL_CONF=conf\openssl.cnf

call _request.cmd atv
call _control.cmd atv
call _accept.cmd atv
call _convert.cmd atv
