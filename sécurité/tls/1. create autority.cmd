@echo off

set PATH=%~dp0\bin;$PATH
set OPENSSL_CONF=conf\openssl.cnf

libressl ^
req -x509 -sha256 -utf8 -newkey rsa:4096 ^
-keyout keys\autority.key ^
-config conf\autority.cnf ^
-extensions v3_ca -days 1826 ^
-out certs\autority.crt
