#!/bin/bash

# Szybki skrypt na upload, zanim rozpracowane zostanie Platformio IO
# Wymagana wersja avrdude >= 6.1 (Obsługa FLIP2 - XMEGA)

pio run # Kompilowanie firmware.hex
cd .pioenvs/native_avr 
avrdude -c flip2 -p x128a3u -U application:w:firmware.hex:i # Upload firmware.hex
# avrdude -c flip2 -p x128a3u -U eep:w:xprotolab-p.eep:i    # Upload EEPROM