@echo off

libressl ^
req -new -sha256 -nodes -utf8 -newkey rsa:2048 -days 600 ^
-keyout keys\%1%.key ^
-config conf\%1%.cnf ^
-out req\%1%.csr

echo done.
