Opdrachten Practicum week 1

Basic Commandos
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
- fdisk /user/sbin
