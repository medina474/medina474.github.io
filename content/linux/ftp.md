https://doc.ubuntu-fr.org/vsftpd

– On oublies pas de créer le répertoire des comptes FTP selon ce que vous avez indiqué dans le fichier de configuration vsftpd.conf. Dans notre cas /srv/ftp
– Créez le fichier de user ftp (touch /etc/vsftpd/login.txt) et on le renseigne comme l’exemple ci dessous:
user1
passworduser1
user2
passworduser2

– On génère ensuite le fichier login.db (bekerley DB):
db5.3_load -T -t hash -f /etc/vsftpd/login.txt /etc/vsftpd/login.db

– Créez le répertoire FTP associé à l’utilisateur:
mkdir -p /srv/ftp/user1
mkdir -p /srv/ftp/user2
chown -R ftp:ftp /srv/ftp

– Enfin on redémarre le service vsftpd
service vsftpd restart

https://journaldunadminlinux.fr/tutoriel-installer-et-parametrer-un-ftp-securise-avec-vsftpd/?print=print
