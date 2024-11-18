@echo off

set PATH=%~dp0\bin;$PATH
set OPENSSL_CONF=conf\openssl.cnf

call _request.cmd workshop.neotechweb.net
call _control.cmd workshop.neotechweb.net
call _accept.cmd workshop.neotechweb.net
call _convert.cmd workshop.neotechweb.net
