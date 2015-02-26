esphttpd
========
esp8266 httpd server with some extras

The original software comes from:
- http://www.esp8266.com/viewtopic.php?f=6&t=376
- http://git.spritesserver.nl/esphttpd.git/


Erstellen
=========

# Makefile
In der Makefile wird die Variable "ESPRESSIF_ROOT" verwendet die man in der Datei "Makefile.uservars" anlegen sollte. Dort ist der Pfad anzugeben in dem das esp-open-sdk liegt.
<br>Weitere Informationen dazu gibt es in meiner sdk Installationshilfe.

# vor dem make
Es ist ganz wichtig vor dem make im Hauptverzeichnis des Projekts folgende git befehle aus zu fuehren:
<br>git submodule init
<br>git submodule update
<br><br>Damit wird sichergestellt, dass alle submodule auch geladen werden.



LICENSE
=======

Dieses Material steht unter der Creative-Commons-Lizenz Namensnennung 4.0 International. Um eine Kopie dieser Lizenz zu sehen, besuchen Sie http://creativecommons.org/licenses/by/4.0/.
cc-by Pascal Gollor (http://www.pgollor.de)
