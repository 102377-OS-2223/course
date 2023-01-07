
# Activitat 02: Programant el Kernel de Linux

*Instructor*: [Jordi Mateo Fornés](http:jordimateofornes.com)

*Course*: [Grau en Tècniques d'Interacció Digital i de Computació](http://www.grauinteraccioicomputacio.udl.cat/ca/index.html)

*University*: University of Lleida - Campus Igualada - Escola Politècnica Superior

*Estudiants*: Álex Pellitero García

## Part teòrica: Booting

Respon de forma sintètica, raonada i acurada:

### Enunciat
Quina és la funcionalitat del fitxer que es troben a la carpeta /boot/ de Linux?

### Resposta
vmlinuz-*: vmlinuz és un arxiu que serveix per a executar el Kernel de Linux, básicament, és un Kernel de Linux comprimit i booteable.

initrd.img: és un Disc de RAM inicial, utilitzat per a carregar arxius temporals a la memoria i que es pot fer servir per a iniciar el Linux.

grub: grub és un programa de Linux que et permet inicialitzar diferents sistemes operatius instal·lats o el Kernel al arrencar el sistema, a més de poder permetre transmetre arguments al Kernel.

config*: serveix per a poder configurar el Kernel de Linux


https://www.compuhoy.com/que-es-initrd-y-vmlinuz-en-linux/#¿Que_es_Vmlinuz_en_Linux

https://web.mit.edu/rhel-doc/4/RH-DOCS/rhel-rg-es-4/s1-grub-whatis.html#:~:text=GNU%20GRand%20Unified%20Boot%20loader,usuario%20transmita%20argumentos%20al%20kernel.

https://academicos.azc.uam.mx/oan/linux/compKernel.html

## Part teòrica: Lectura de codi

### Enunciat
Analitza el següent fragment de codi:

SYSCALL_DEFINE1 ( my_syscall , char * , msg ) {

  printk ( KERN_INFO "my_syscall:\"%s\"\n" , msg );
  
  return 0;
  
}

a) Explica amb tots els detalls possibles que fa aquest fragment.

b) Documentat i detalla la sintaxi utiltizada.

c) Analitza si aquest fragment pot tenir algun perill en temps d’execució o compilació. En cas
afirmatiu indica quin. En cas negatiu, justifica la resposta.

### Resposta
a) A la funció SYSCALL_DEFINE1 se li pasen els paràmetres my_syscall, un punter (char *) i un String (msg). En la següent comanda, imprimeix el que n'hi hagi  a la funció KERN_INFO, més un text que possi my_syscall : msg (osigui, el valor de msg) i un salt de línia. Després simplement retorna un 0 finalitzant el programa.

b) El métode SYSCALL_DEFINEn (on n és un numero) és una crida al sistema, on el primer paràmetre que s'el passa és el nom del system call, el segon és el pid_t i el tercer és el pid. A més SYSCALL_DEFINEn té l'n que representa el numero d'arguments que tindrà el sistema. El que ens farà el printk() és manar un missatge del sistema a la terminal. KERN_INFO el que fa és dir que el missatge serà de tipus informatiu.

A un printk() li has de passar un missatge entre cometes i una al·lusió del argument que has de passar-ne, més despres l'argument a passar-ne. Cal dir, que aquesta és la manera més comú de fer-ho, 'printk(KERN_INFO "Message: %s\n", arg);'.

El printk() está basat en el mateix printf(), però difereix en dues parts:

1 - printk() pot manar missatges del nivell log

2 - Té altres limitacions i extensions.

https://stackoverflow.com/questions/17751216/writing-a-new-system-call
https://www.kernel.org/doc/html/latest/core-api/printk-basics.html

c) -

https://www.kernel.org/doc/html/latest/process/adding-syscalls.html?highlight=syscall_define

https://lwn.net/Articles/604287/

## Part pràctica: Hackejant chmod

### Pregunta
Hackegeu el vostre kernel de manera que imprimeixi la cadena ("chmod is drunk!!!") cada vegada que es fa una crida a chmod. Explicar els passos realitzats i adjunteu captures de pantalla per veure el hack.

### Resposta
1 - Primer hem de dirigir-nos a la carpeta de linux.

2 - Després trobar la carpeta que n'hi és la carpeta fs i invocar la comanda 'vi fs/open.c strace chmod'.

3 - A l'editor vim busquem la paraula chmod prenent la tecla '/'. Imatge "Chmod".

4 - Escribim 'write("chmod is drunk!!!");' per a que escribeixi aquesta frase cada cop que s'invoqui el chmod. Imatge "Chmod2".

5 - Sortim amb ':wq!' per a guardar i sortir sense que ens digui res.

6 - Al terminal només queda ja comprobar amb un arxiu si hem "hackejat" el chmod. Imatge "Chmod3".

Per a entendre per a que serveix strace:
https://www.solvetic.com/tutoriales/article/4414-comandos-strace-para-solucionar-problemas-procesos-linux/

Per a entendre per a que serveix chmod i com invocar-lo:
https://www.ionos.es/digitalguide/servidores/know-how/asignacion-de-permisos-de-acceso-con-chmod/
https://www.howtogeek.com/437958/how-to-use-the-chmod-command-on-linux/

Open.c versió web:
https://elixir.bootlin.com/linux/latest/source/fs/open.c

