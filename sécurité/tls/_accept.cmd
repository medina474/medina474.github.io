@echo off

rem  the first time

libressl ^
x509 -req -sha256 ^
-in req\%1%.csr ^
-CA certs\autority.crt ^
-CAkey keys\autority.key ^
-CAcreateserial ^
-extensions v3_req ^
-extfile conf\%1%.extensions.cnf ^
-out certs\%1%.crt

echo done.
