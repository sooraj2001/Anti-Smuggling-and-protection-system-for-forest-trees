# Anti-Smuggling-and-protection-system-for-forest-trees

It is observed in the newspapers headlines about smuggling of the trees like Red sandal wood (sagwan). The trees being stolen by the smugglers are very costly and were less available in the world , such trees are used for medical sciences as well as cosmetics for that reason the sandal wood trees costs high in the world . So , I developed an embedded system device of hardware parts which can be used to avoid and to restrict the smuggling of sandal wood trees from the smuggler’s , the system can also be used to detect forest fire which could prevent a natural disaster. This System can be used to save trees from smuggling and to prevent the deforestation  that could act as preventive measure against Global Warming.


**METHODOLOGY**
<br><br>
•	used four sensors (Metallic, Vibration, tilt and Temperature Sensor) in this system , that collects the sensed data and sends it to Arduino Uno.

•	After receiving the data, the Arduino Uno decides whether the tree is being smuggled or not , based on the received data and threshold values loaded in controller through program. 

•	If the sensed data reaches the threshold value then smuggling is identified and the controller creates an alert and sends notification to the users.

•	It also identifies rise in surrounding temperature through temperature sensor and creates alert about the forest fire and  sends message to users.
<br><br>

**BLOCK DIAGRAM OF THE SYSTEM**
<br>
<img src="https://user-images.githubusercontent.com/53194222/179401031-4d5c502a-b34a-488e-9778-3af060703f3e.png">

<br><br>

**COMPONENTS USED**
<br>

**Metallic Sensor** (KY036 Metallic Sensor) : This sensor emits signal  if the front metal tip of the sensor is touched. The sensitivity of the sensor can be adjusted by means of a controller. This sensor has been used to detect the metals which has been used during cutting of trees. If it senses the metal then it will send signal to micro-controller. 

**Vibration Sensor** (sw 420 vibration sensor) : A vibration sensor is a device that measures the amount and frequency of vibration in a given system. Those measurements can be used to detect imbalances or other issues in the asset and predict future breakdowns.it is used to detect vibration caused during cutting of trees. If it senses the vibration then it sends signal to micro-controller.

**Temperature Sensor** (DHT 11 Temperature Sensor) : A temperature sensor is an electronic device that measures the temperature of its environment and converts the input data into electronic data to record, monitor, or signal temperature changes.  It is used to detect changes in temperature of forest. If the temperature exceeds certain value then it will send signal to micro-controller.

**Tilt Sensor** (SW 520d Tilt Sensor) :  A tilt sensor is an instrument that is used for measuring the tilt in multiple axes of a reference plane. Tilt sensors measure the tilting position with reference to gravity and are used in numerous applications. They enable the easy detection of orientation or inclination. It is used to detect fall of the trees. If it bends more than threshold angle then it will send signal to micro-controller.

**Battery** (3.7V Li-Po batterie) : it has been used to provide power to the system.

**Arduino** (Arduino Uno) : Arduino Uno is a microcontroller board based on the ATmega328P. It has 14 digital input/output pins (of which 6 can be used as PWM outputs), 6 analog inputs, a 16 MHz quartz crystal, a USB connection, a power jack, an ICSP header and a reset button. Micro controller receives values from sensor and compare it with threshold values. If it is reaches threshold values then send signals to GSM module.

**GSM** (SIM800L GSM Module) : it consists SIM-800L where it is used to sends messages to the registered number if the problem is detected.

<br>

**WORKING -**<br>
The module along with all 4 sensors will be placed on the tree trunk . all three sensors vibration, tilt, metallic sensor will start sensing continously and when all the three sensors gets activated together a message through GSM will be sent on the phone as "Tree is Being Smuggled" . In case of detecting the forest fires our module contnously measures temperature and humidity of the surrounding after every second , when the surrounding temperature rises upto 52 degree and humidity falls below 40 percent then an alert message is sent on the phone through GSM as "Forest under fire !!!!" .

<br><br>
**CIRCUIT**
<br>

<img src="https://user-images.githubusercontent.com/53194222/179401988-f3a23375-e9cd-4564-b96a-98096d306016.jpg">

<br><br>
**ALERT MESSAGE ON SMUGGLING OR TEMPERATURE RAISE**
<br>

<img src="https://user-images.githubusercontent.com/53194222/179405122-396abbc6-bc1a-48c5-bd3b-dbb83be31080.jpeg" width="360" height="760">
