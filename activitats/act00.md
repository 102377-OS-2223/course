
# Activitat 00: Profunditzant en UNIX (Mòdul 1)

*Instructor*: [Jordi Mateo Fornés](http:jordimateofornes.com)

*Course*: [Grau en Tècniques d'Interacció Digital i de Computació](http://www.grauinteraccioicomputacio.udl.cat/ca/index.html)

*University*: University of Lleida - Campus Igualada - Escola Politècnica Superior

*Estudiants*: Álex Pellitero García

## Part teòrica

### Enunciat
Cerca la diferència entre Virtualització i Emulació. *Doneu exemples i casos d'ús on es puguin fer servir*.

### Resposta
Quan virtualitzem el que estem fent és utilitzar el nostre ordinador i els seus recursos per a fer correr una màquina virtual, utilitzant el hardware actual, funcionant per a tots els sistemes amb Intel x86 i treballa com si fossin màquines separades.
En el cas de l'emulació el que volem fer és utilitzar un ordinador per a utilitzar una versió antiga, una consola o sistema operatiu, un programa que ja no funciona en l'actual sistema operatiu, etc. Tot això ho podem fer servir i treure'n arxius i dades a partir d'un programa que imita el programa/sistema desitjat.

Enllaç:

https://computerhoy.com/noticias/tecnologia/estas-son-principales-diferencias-virtualizacion-emulacion-1004357

### Enunciat
Cerca les diferències entre les particions **GTP** i **MRB**. *Feu una taula comparativa*.

### Resposta
Amb MBR un pot fer fins a 4 particions al seu disc dur i de mida màxima 2TB, en canvi amb el format GPT, podem fer tantes particions com ho permeti el nostre ordinador o fins a 128 particions.

MBR:
MBR, 1a partició primària (:C), 2a partició primària (:D), 3a partició primària (:E), particions extendides.

GPT:
MBR, cabeçera de taula de partició GPT primària, matriu d'entrades de particions primària, 1a partició primària (:C), 2a partició primària (:D), ..., 128a partició primària, backup de matrius d'entrades de particions, backup cabeçera de taula de partició GPT primària. 

Enllaç MBR vs GPT:

https://www.profesionalreview.com/guias/mbr-vs-gpt/

### Enunciat
Cerqueu informació sobre el procediment de **Fingerprint** del protocol SSH. Per a què serveix i quins problemes intenta solucionar.

### Resposta
El procediment Fingerprint del protocol SSH serveix com a clau única del nostre servidor, a l'hora de crear un servidor SSH, és crea un identificador públic i privat, el Fingerprint vetlla per a que n'hi hagi diferencies entre l'un i l'altre. Si no s'utilitza ens protegeix de que els hackers camuflin servidors il·legitims com a legitims i que no ens redirigeixin cap a les seves màquines.

Enllaços:

https://geekland.eu/fingerprint-servidor-ssh/

https://support.jamsscheduler.com/hc/en-us/articles/206894247-SSH-Fingerprints

## Part pràctica: Instal·lar un paquet 

### Enunciat
La majoria de les distribucions UNIX o Linux gaudeixen de repositoris estàndard que inclouen la majoria del programari que necessitareu per executar al vostre servidor o sistema d'escriptori basat en UNIX o Linux. Si falta algun paquet, és molt probable que trobeu un repositori que podeu afegir, de manera que la instal·lació es pugui gestionar amb el gestor de paquets integrat. Això s'ha de considerar una bona pràctica. Per què? Perquè és important per a la integritat de la plataforma assegurar-se que el gestor de paquets coneix el programari instal·lat. Quan aquest és el cas, els paquets es poden actualitzar fàcilment (per solucionar vulnerabilitats i similars). Un altre motiu per instal·lar des dels dipòsits és que les dependències es compleixen fàcilment. 

La vostra tasca és investigar el seu funcionament a NetBSD i indicar els passos per instal·lar el paquet, **vim** a *bsdlab*. 

### Resposta

```sh
git clone https://github.com/NetBSDfr/pkgin.git
./configure --prefix=/usr/pkg --with-libraries=/usr/pkg/lib --with-includes=/usr/pkg/include
make
echo ftp://ftp.fr.netbsd.org/pub/pkgsrc/packages/NetBSD/i386/5.0/All > /usr/pkg/etc/pkgin/repositories.conf
pkgin update
pkgin install vim
```

## Part pràctica: Personalitzant la comanda ```ls``` 

### Enunciat

Una de les comandes més utilitzades quan treballem amb sistemes UNIX és ```ls```. Ara bé, la gran majoria de vegades acabarem fent servir els arguments ```ls -la```}.
Configureu el vostre sistema **bsdlab** amb una nova comanda ```la``` que permeti fer ```ls -la```.Veure exemple. Expliqueu els passos realitzats.

```sh
$ la
total 68
drwxr-xr-x  3 jordi  users   512 Sep  9 15:54 .
drwxr-xr-x  3 root   wheel   512 Sep  9 11:10 ..
-rw-r--r--  1 jordi  users  1772 Sep  6 02:31 .cshrc
-rw-r--r--  1 jordi  users   431 Sep  6 02:31 .login
-rw-r--r--  1 jordi  users   265 Sep  6 02:31 .logout
-rw-r--r--  1 jordi  users  1498 Sep  6 02:31 .profile
-rw-r--r--  1 jordi  users   166 Sep  6 02:31 .shrc
drwxr-xr-x  2 jordi  users   512 Sep  9 15:54 .ssh
-rw-r--r--  1 jordi  users     0 Sep  9 14:13 a.txt
-rw-r--r--  1 jordi  users     0 Sep  9 14:51 b.txt
-rw-r--r--  1 jordi  users  2048 Sep  9 14:52 f.tar
-rw-r--r--  1 jordi  users   125 Sep  9 14:52 f.tar.bz2
-rw-r--r--  1 jordi  users   106 Sep  9 14:52 f.tar.gz
-rwxr-xr-x  1 jordi  users  8744 Sep  9 15:26 hello
-rw-r--r--  1 jordi  users   150 Sep  9 15:26 hello.c
```

### Resposta

1 - Creem l'arxiu la.c.

2 - Obrim l'arxiu amb l'editor de text.

3 - Escribim: 

'#!/bin/bash'

'ls -la'

4 - Guardem l'arxiu i el fem executable amb 'chmod +x la'

5 - El movem a una ruta on es quedarà per sempre. Per exemple: cp la.sh /usr/bin/

6 - Comprobem que fent 'la' a la terminal es dona la comanda.


## Part pràctica: Problema de l'any 2038 

### Enunciat
Com us he explicat a classe els sistemes UNIX sofreixen d'un problema amb les dates causat: ```time_t``` emmagatzema el temps com un nombre enter signat de 32 bits. Per tant, únicament pot representar enters entre -(231) i 231 -1, per tant l'última hora que es pot codificar correctament és 231 - 1 segons després de l'època UNIX (03:14:07 UTC el 19 de gener de 2038). Intentar augmentar al segon següent (03:14:08) farà que l'enter es desbordi, establint el seu valor a -(231), que els sistemes interpretaran com a 231 segons abans de l'època (20:45:52 UTC el 13 de desembre de 1901).

La vostra tasca és obtenir una prova del delicte en el vostre sistema **bsdlad**. Heu de demostrar si aquest afer existeix o no en la vostra instal·lació actual. Heu d'indicar els passos a realitzar per demostrar-ho.

### Resposta
xxxxx

## Part pràctica: Shell 

### Enunciat

En aquest punt repassarem les comandes treballades a la sessió de laboratori 0. 

La vostra tasca és anotar totes les comandes ordenades que aneu utilitzant per resoldre cada ítem.

1. En el vostre directori *home*, heu de crear la següent estructura de *fitxers i directoris*: **week0/teoria/, week0/laboratori/, week0/handson, week0/notes.md, code/, activities/ README.md**
2. Feu servir l'eina *sftp* per pujar els documents vl00.pdf, lab00.pdf, ho00.pdf a la carpeta corresponent.
3. Editeu el fitxer notes.md amb el text **template.md**.
4. Mostreu les 3 primeres línies i les 2 ultimes per **stdout** del fitxer **template.md**.
5. Copieu el fitxer */etc/passwd* al vostre directori d'inici. La còpia ha d'incloure: *el nom, la data i l'hora de la darrera modificació*. (**man cp**). Anomeneu el fitxer com *cpasswd*.
6. Transformeu el fitxer en un fitxer ocult anomenat **.pass**.
7. Permeteu que **qualsevol usuari del sistema** pugui **llegir, escriure i executar** dins la carpeta *code*.
8. Comprimiu tot el contingut del vostre directori en un **backup.tar.gz2**}.
9. Descarregueu per *sftp* el fitxer *backup.tar.gz2* a la vostra màquina real.
10. Elimineu tots els fitxers del vostre home. Alerta (reviseu **man rm**) no volem eliminar els fitxers ocults com  **.ssh, .cshrc,.login,.logout...***}

template.md:

```md
# Week 00

echo $HOME
unset HOME
cd $HOME

```

### Resposta

```

## 1

mkdir week0
cd week0
mkdir teoria
mkdir laboratori
mkdir handson
mkdir notes.md
cd ..
mkdir code
mkdir activities
cd activities
mkdir README.md

## 2

cd teoria
get v100.pdf
cd ..
cd laboratori
get lab00.pdf
cd ..
cd handson
get ho00.pdf

## 3

## 4

## 5

cp passwd $HOME
mv passwd cpasswd

## 6

mv cpasswd .cpasswd.pass

## 7

chmod 777 /code

## 8

tar cvf backup.tar.bz2 $HOME

## 9

put backup.tar.bz2

## 10

rm -r $HOME

```