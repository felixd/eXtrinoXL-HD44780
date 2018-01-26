#!/bin/bash

# Szybki skrypt na upload, zanim rozpracowane zostanie Platformio IO
# Wymagana wersja avrdude >= 6.1 (Obsługa FLIP2 - XMEGA)

# Kompilowanie oraz upload HEX do pamięci Flash mikrokontrolera
pio run -t program

# AVRDUDE firmware.hex upload
# avrdude -c flip2 -U application:w:.pioenvs/native_avr/firmware.hex:i -p x128a3u 
