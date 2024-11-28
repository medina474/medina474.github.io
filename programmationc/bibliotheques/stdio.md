---
title: stdio
---

fonction|macro|description
---|---
gets|Lit une chaine depuis le clavier
puts|Écrit une chaine à l'écran
fgets|Lit une chaine depuis un fichier
fputs|Écrit une chaine dans un fichier


fonction|description
---|---
getc|Get character from stream
putc|Write character to stream
fgetc|Get character from stream
fputc|Write character to stream
getchar|Get character from stdin
putchar|Write character to stdout
ungetc|Unget character from stream

fonction|description
---|---
fprintf|Write formatted data to stream
fscanf|Read formatted data from stream
printf|Print formatted data to stdout
scanf|Read formatted data from stdin
snprintf|Write formatted output to sized buffer
sprintf|Write formatted data to string
sscanf|Read formatted data from string
vfprintf|Write formatted data from variable argument list to stream
vfscanf|Read formatted data from stream into variable argument list
vprintf|Print formatted data from variable argument list to stdout
vscanf|Read formatted data into variable argument list
vsnprintf|Write formatted data from variable argument list to sized buffer
vsprintf|Write formatted data from variable argument list to string
vsscaf|Read formatted data from string into variable argument list

fonction|description
---|---
fread|Read block of data from stream
fwrite|Write block of data to stream

fonction|description
---|---
fclose|Close file
fflush|Flush stream
fopen|Open file
freopen|Reopen stream with different file or mode
setbuf|Set stream buffer
setvbufChange stream buffering

fonction|description
---|---
fgetpos|Get current position in stream
fseek|Reposition stream position indicator
fsetpos|Set position indicator of stream
ftell|Get current position in stream
rewind|St position of stream to the beginning

clearerr|Clear error indicators
feof|Check end-of-file indicator
ferror|Check error indicator
perror|Print error message
remove|Remove file
rename|Rename file
tmpfile|Open a temporary file
tmpnam|Generate temporary filename
