# TemperatureLightStation
An Arduino temperature station and automatic light bulb that lights when darkness exceeds a configurable level.

The temperature in Centigrade, the level of darkness and a darkness threshold setting are displayed on an LCD screen.
When the environment darkness exceeds the threshold, a signal is sent to a relay that turns on a dim light.
The darkness threshold setting is configurable via a potentio meter by the user.

The station is implemented as a single device in a wooden enclosure with just a sinle power cord.
A breadboard schematic and photos of the wooden enclosure are included.

The box includes an Arduino Uno, a mini breadboard, a PSU, a relay, two USB DC power supplies (for the Arduino and the PSU) 
and power cords. The relay is powered by a separate PSU, so that signaling the relay does not cause Voltage 
fluctuations in the rest of the circuit. That way, the temperature and other readings are reliable and stable.

The wooden enclosure consists of:

Two top - bottom boards of 24cm length * 18cm width.
Two side boards of 18cm width * 14cm height.
Two front - rear boards of 20cm width * 14cm height.

The LCD opening in the front board is 7cm * 2.5cm. The sensors and the darkness threshold regulator are accessible 
on the right side board. The light is attached on the left side and is dim (0.5 Watts) so that it does not influence
the light sensor that is on the right side. The top board opens up to give access in the inside. The USB cable can be
removed from the DC power supply and inserted to a computer so that the Arduino can be programmed.
