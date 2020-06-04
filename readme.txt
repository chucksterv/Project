Setup and Installation

Hardware
• The hardware architecture should follow the diagram displayed in hardware architecture and
design section provided in the project artifact. The LED and the button should be connected to the relevant pins. If different
pins are used, the program should be modified to incorporate the relevant pins.
• Proper grounding and resistors should be used to ensure the safety of the equipment used.
• Raspberry Pi should be setup with a working Python installation. The Pi should either be
connected to a screen and relevant control devices or a remote connection should be setup with
an PC via relevant methods.

Software
• The program provided under the included repository should be used with the Particle Photon.
MQTT library should be included with the program before the device is flashed. MQTT library is 
included in the project repository. The flash should be done using either the web IDE or the CLI.
Web IDE is recommended due to the ease of use and the ease of adding the libraries
automatically.
• The flash should be successful in order for the program to work.
• MQTT libraries should be installed in Raspberry Pi for the project to work.
pip install paho-mqtt

Usage
• The Photon should be connected to a stable power source after the installation.
• The Photon will function without the Raspberry Pi connection, emulating the system working
even if integration was not present.
• If setup correctly, the button press will turn the onboard LED on. After a 15 second delay, the
onboard LED will turn off and the main LED will turn on. After 5 seconds the main LED will turn
off.
• To receive and record data from the Photon, the included python program should be run in the
Raspberry Pi. This can be done using the terminal or the included python IDE in the Raspberry.
• After the program is run on the Pi, the console will receive information from the photon with
every state change. The state changes are, ‘timer start’, ‘door open’ and ‘door close’.
• The information will be displayed on the console along with the relevant time stamp.
• The project_log.csv file will be created on the root directory and the information received will
be saved onto this file.

