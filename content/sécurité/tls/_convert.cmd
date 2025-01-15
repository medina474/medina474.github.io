@echo off

libressl pkcs12 -export ^
-in certs\%1%.crt ^
-inkey keys\%1%.key ^
-out certs\%1%.p12

libressl pkcs12 -nodes ^
-in certs\%1%.p12 ^
-out certs\%1%.pem 

echo done.
