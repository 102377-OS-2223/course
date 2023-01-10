### Activitat #03: OSSH v1.0 (Mòdul 2)

## Fet per

Álex Pellitero García

### Helpers.c

Aquí vaig voler-ne fer diferents comandes que ens facilitesin el codi, com per exemple la comanda enters que el que faria seria alliberar-ne memoria cada cop que detectés un salt de linia. La funció errors ens mana un missatge debug en cas de trobar-ne un dels simbols "prohibits" a utilitzar-ne.

A més d'ho esmentat, vaig voler-ne fer un debug que ens digués si la commanda ficada podia ser executada per la nostra ossh. És a dir si el buffer és trobat a commands (on estan "help" i "exit"), no dirà res, però si no el troba manarà un missatge dient que no el pot reconèixer.

### Main.c

Launchcmd s'encarregarà de fer funcionar el nostre ossh fent un procés pare i un fill. I el pare s'esperarà a que el fill acabi. ossh> s'imprimirà cada cop que es doni una nova línia, i he volgut que es faci de color blau, així com que quan aparegui un error surti el missatge de color vermell i quan s'acabi el programa surti en color magenta.

El programa primer mirarà si la primera comanda és un exit, per acabar-ne o continuar, després mirarà si no és una comanda registrada i després si té caracters no permitits. Després comprobarà si el missatge passat és un help, i si no, alliberarà memoria del buffer amb la funció enters. Per a acabar-ne amb un missatge de que està acabant i retornar un EXIT_SUCCESS.

### Makefile

Els fitxers de recursos son el main.c, log.c i helpers.c.