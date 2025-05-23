# Software-Entwickling-Projektarbeit

Überblick
---------
Dieses Projekt besteht aus zwei Hauptprogrammen:

1. ToF-Sensor-Programm
   Mit diesem Programm lassen sich die aktuellen Distanzwerte der angeschlossenen VL53L0X-Sensoren auslesen. 
   Die gemessenen Werte werden direkt im Terminal und auf einem LCD-Display angezeigt.

2. Stepper-Motor-Programm
   Über dieses Programm kann der Schrittmotor (Stepper) gesteuert werden. 
   Die Steuerung erfolgt über die Kommandozeile – es können Befehle wie start, stop, links, rechts, step eingegeben werden.

Bedienung
---------

ToF-Sensor-Programm
- Sensoren sind via I2C angeschlossen (mit Multiplexer, falls mehrere Sensoren verwendet werden).
- Beim Start des Programms werden die Sensoren initialisiert und laufend ausgelesen.
- Die Distanzen werden im seriellen Monitor und auf einem LCD angezeigt.

Stepper-Motor-Programm
- Motorbewegung kann per Kommandozeile gesteuert werden.
- Beispielbefehle:
  - start – startet die Bewegung
  - stop – stoppt den Motor
  - links - linke seite bewegen
  - rechts - rechte seite bewegen
  - step - einzelnen step ausführen

Hinweis
-------
- Die Programme sind unabhängig voneinander, können aber kombiniert werden.
