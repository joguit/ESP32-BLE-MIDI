
# Interface BLE-MIDI-to-input-5-pin -DIN

This file allow to conect an input BLE MIDI transmission (like a 'Piano MIDI BLE USB' Android app  ) with a input MIDI device, such a piano.




## Component list
* ESP32 DEVKIT V1
* MIDI DIN connector
* 2 resistance 220 ohms
* 3 wires dupont 

## Reference

#### hardware definitions

```http
  GPIO PIN definitions for Serial2 port.
```

| Parameter |      | Value                |
| :-------- | :------- | :------------------------- |
| `#define RXD2` | ` ` | **16** |
| `#define TXD2` | ` ` | **17** |
#### 


## Appendix

Schematic (this is for Arduino Uno, but it works the same:wink: ):


![schematic](https://github.com/joguit/ESP32-BLE-MIDI/edit/master/examples/05-Receive-and-send-to-5-pin-DIN/Arduino-Uno-schematic.png)
