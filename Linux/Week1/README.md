# Opdrachten Practicum week 1

## Basic Commandos
Deze opdracht is onhandig, er staan geen Java bestanden op een verse Linux installatie dus zal het testen erg moeilijk worden..

A) find . -name "*.java" -exec grep "Main" {} -newermt "7 days ago" -ls \;

B) Een hardlink is een link die alleen kan verwijzen naar een file en die ook altijd naar dezelfde file blijft verwijzen. Ook als deze bijvoorbeeld verplaatst wordt omdat deze in de directory database wel hetzelfde blijft. Een soft link is een beetje het zelfde als je shortcut in windows. Het kan verwijzen naar dingen buiten het zelfde volume, het kan verwijzen naar dingen die niet bestaan en kan verwijzen naar mappen.

C) Echo $SHELL (/bin/bash)

D) ps ax|egrep "^ [100]"

E) export PATH=/usr/bla/test:$PATH'

F) man -K "String"

G)
- /bin commands die nodig zijn gedurende startup en die gebruikt kunnen worden door normale users
- /boot Files die gebruikt worden door de bootstrap loader (LILO or GRUB). Kernal images worden hier ook vaak opgeslagen ipv root directory.
- /dev  Device files, dit zijn files om die de user te interfacen met decices op het systeem.
- /etc configuratie files specifiek voor de machine
- /home It is the specifc home directory of a specific user en heeft over het algemeen files van de user.
- /lib gedeelde billiotheken die nodig zijn voor programmas op het root filesystem.
- /proc Het is een nep of virueel filesystem waarin files komen die worden opgeslagen in de memory zoals bijvoorbeeld proces informatie.
- /root Het home directory van de root user.
- /usr Dit is waar programmas vaak worden ginstaleerd. Dit zijn meestal files van de distro.
- /usr/bin Bijna alle user commands.
- /usr/sbin System admin commands die niet nodig zijn in de root filesystem.
- /media heeft subdirectories waar removable media devices (usb sticks etc.) in staan.
- /mnt mount point voor tijdelijke mounts van de SA.
- /sbin zelfde als bin, maar voor non-normal users tenzij ze specifiek rechten krijgen
- /usr/share Gebruiksaanwijzing, GNA info docs, verschillende andere docs.
- /var In var staan dingen die tijdens normale operation veranderd kunnen worden. Denk bijvoorbeeld aan een website die in /var/www staat.

H)
- mount /usr/sbin
- ping /usr/bin
- rm /usr/bin
- mkfs /usr/sbin
- fdisk /usr/sbin
- syslogd /usr/sbin (maar dan wel rsyslog)
- grub/lilo /user/sbin en /user/bin
- man pages /usr/share
- interface en host config /etc

## SYSTEM Management
A) Alias. Met welk commando zorg je er voor dat wanneer op de console ‘home’ wordt ingevoerd,dat dan de huidige directory gelijk wordt aan je ‘home’ directory?
alias home="cd /home"
B) Welk commando geeft een overzicht van alle gebruikte filesystemen ?
findmnt
C) /proc. Waarvoor worden deze files gebruikt?
Voor het opslaan van bijvoorbeeld procesinformatie. Het zijn tijdelijke bestanden die worden opgeslagen in het geheugen..
D) In de directory /proc staan o.a. de volgende (virtuele) files : version, cpuinfo, meminfo en ioports. Welke informatie geven deze files ?
- cpuinfo = info over de cpu.
- version = info over de versie van Linux.
- meminfo = info over hoeveel memory er is en hoeveel er over is.
- ioports = Een lijst met I/O ports die geclaimed zijn door kernel drivers
E)Device files. Wat zijn de namen van de device files waarmee de kernel de harde schijven kan benaderen ?
Ze beginnen met sd en hebben dan afhankelijk van waar je naartoe gaat een naam. sd(x)(n)
F) Syslog. Met welk commando kan ik de laatste belangrijke systeem meldingen tonen ?
Nu kom ik er achter dat ik dus geen syslog geinstaleerd heb, komt niet standaard bij Ubuntu Desktop I guess
less /var/log/syslog
G)Processen. Met welk commando krijg ik een overzicht van alle processen ?
ps aux | less
H) Hoe start je services en hoe kun je een service zo instellen dat deze start bij het opstarten van het systeem?
- systemctl status= check status van services
- systemctl enable= on startup start service
- systemctl start= start services
Nu weet ik niet of dit misschien anders is op Ubuntu, meer dit is hoe ik het doe met CentOS
Nvm, werkt ook op Ubuntu

## Performance Monitoring
A) Het commando “top” geeft een overzicht van processen en hun resource gebruik (default is CPU
gebruik). Het standaard sample-interval is 5 seconde.
Met welke toets kun je een “toggle” doen tussen een enkeloverzicht en het “alternate display”?
d.w.z. een gesorteerd overzicht (van de belangrijkste “consumers” van diverse system resources)

G? Weet ik niet 100% zeker

B) Het “vmstat” commando geeft informatie over processen, geheugen, paging, block IO, traps en
cpu activity. Probeer het vmstat commando. Onder “procs” zie je kolommen zie je “r” en “b”.

- Wat betekenen deze velden ?
r: The number of processes waiting for run time.
b: The number of processes in uninterruptible sleep.

Hoe groot is ongeveer het aantal interrupts en context switches per seconde ?
in: 59
CS: 99 (denk ik, US en CS staan slecht onder elkaar)
C) Geef het commando “mpstat –A”. Hoeveel processoren zitten er in je PC ?
mpstat is not installed.
Na installatie: 4, net zo veel als dat ik de VM heb gegeven.

## Users en permissies
A) Leg de rwx permissies uit als deze betrekking hebben op een directory.
RWX. Read, Write, Execute. Het is letterlijk wat het zegt, met R kan je lezen, met W kan je schrijven en met X kan je dingen executen in de specifieke directory.

B) Met welk commando zorg je ervoor dat de rechten van een file “rwxrwxrwx” worden?
sudo chmod 777 (-R voor recursive)

C) Hoe kun je de 'group' van een user veranderen?
sudo usermod (-a) -g (cap voor non-primary) groupname username

D) Creëerdrie gebruikers die elk met hun eigen key in kunnen loggen
sudo useradd -m user1
sudo useradd -m user2
sudo useradd -m user3
sudo passwd user1
sudo passwd user2
sudo passwd user3
gebruikte password: password

E) Maak één van beide gebruikers lid van de sudoers groep
sudo usermod -aG sudo user1

F) Maak in de home directory van alle drie de gebruikers een directory aan met de naam
“shared_dir” en realiseer een groep “shared_usr” waar je de hiervoor gecreëerde users lid maakt.

Geef de groep read en write rechten op de “shared_dir”. Controleer of de gebruikers onderling
elkaar “shared_dir” kunnen benaderen.
sudo mkdir shared_dir
sudo groupadd shared_usr
sudo chown -R dany:shared_usr shared_dir/
sudo chmod 770 -R shared_dir/

sudo usermod -g shared_usr user(1-3)

Het werkt

## Installeren van applicaties
A)Veel Linux software is beschikbaar in een zogenaamde “tarball”, deze hebben extensies .tgz of tar.gz. Met welke commando’s pak je zo’n bestand uit?
tar -xf (filename)
B) Met welk dpkg commando krijg je een lijst van alle geïnstalleerde pakketten?
sudo apt list --installed
C) Met welke dpkg commando kun je achterhalen uit welke files het pakket “apache2” bestaat ?
Ik heb apache2 momenteel niet geinstaleerd, er is nergens vermeld dat dit nodig was.
Volgens internet: dpkg-query -L <package_name>
D) Waar staat de “executable” apache2 ?
Nergens, want apache is niet geinstaleerd bij default. Sudo apt-get install apache2 doet dat zo, maar ik wacht nog even tot week 2.
E) En waar wordt de variabele DocumentRoot gedefinieerd ?
DocumentRoot zou in de normale plek zijn. /var/www/html
