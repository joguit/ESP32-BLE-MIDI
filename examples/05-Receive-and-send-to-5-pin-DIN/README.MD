
# Interface BLE-MIDI-to-input-5-pin -DIN

this file allow to conect a input BLE MIDI trasmission (like a 'Piano MIDI BLE USB Android app ' ) with a input MIDI device, such a piano.




## Component list
* ESP32 DEVKIT V1
* MIDI DIN connector
* 2 ressistance 220 ohms
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

schematic (this is for arduino uno, but it works the same):
https://google.es

![alt text](https://github.com/joguit/ESP32-BLE-MIDI/edit/master/examples/05-Receive-and-send-to-5-pin-DIN/Arduino Uno schematic.png)
