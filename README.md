# Software-Entwickling-Projektarbeit

Überblick
---------
Dieses Projekt besteht aus zwei Hauptprogrammen:

1. ToF-Sensor-Programm
   Mit diesem Programm lassen sich die aktuellen Distanzwerte der angeschlossenen VL53L0X-Sensoren auslesen. 
   Die gemessenen Werte werden direkt im Terminal oder optional auf einem LCD-Display angezeigt.

2. Stepper-Motor-Programm
   Über dieses Programm kann der Schrittmotor (Stepper) gesteuert werden. 
   Die Steuerung erfolgt über die Kommandozeile – es können Befehle wie Start, Stopp, Richtung wechseln oder Geschwindigkeit setzen eingegeben werden.

Bedienung
---------

ToF-Sensor-Programm
- Sensoren sind via I2C angeschlossen (mit Multiplexer, falls mehrere Sensoren verwendet werden).
- Beim Start des Programms werden die Sensoren initialisiert und laufend ausgelesen.
- Die Distanzen werden im seriellen Monitor (oder auf einem LCD) angezeigt.

Stepper-Motor-Programm
- Motorbewegung kann per Kommandozeile gesteuert werden.
- Beispielbefehle:
  - start – startet die Bewegung
  - stop – stoppt den Motor
  - dir – wechselt die Richtung
  - speed 200 – setzt die Geschwindigkeit auf 200 Schritte/s

Hinweis
-------
- Die Programme sind unabhängig voneinander, können aber kombiniert werden (z. B. zur geregelten Annäherung basierend auf Distanzwerten).
