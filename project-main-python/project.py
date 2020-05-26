import paho.mqtt.client as mqtt         # Import the MQTT library
import time                 # The time library is useful for delays
import os

# Our "on message" event
def messageFunction (client, userdata, message):
    topic = str(message.topic)
    message = str(message.payload.decode("utf-8"))
    print(topic + " " +message)

    file = open("/home/pi/project_log.csv", "a")
    if os.stat("/home/pi/project_log.csv").st_size == 0:
        file.write("DoorState,Time\n")
    file.close()
    
    if topic=='doorState':
        doorState(message)
    elif topic=='timeStamp':
        timeStamp(message)

    
def doorState(message):
    file = open("/home/pi/project_log.csv", "a")
    file.write(message + ",")
    file.flush()
    time.sleep(5)<br>file.close()
    
def timeStamp(message):
    file = open("/home/pi/project_log.csv", "a")
    file.write(message + "\n")
    file.flush()
    time.sleep(5)<br>file.close()
    
 
def main():
    ourClient = mqtt.Client("project_mqtt")     # Create a MQTT client object
    ourClient.connect("test.mosquitto.org", 1883)   # Connect to the test MQTT broker
    ourClient.subscribe("doorState")        # Subscribe to the topic doorState
    ourClient.subscribe("timeStamp")    #Subscribe to the topic timeStamp
    ourClient.on_message = messageFunction      # Attach the messageFunction to subscription
    ourClient.loop_start()              # Start the MQTT client
     
    # Main program loop
    while(1):
        time.sleep(1)               # Sleep for a second

if __name__=="__main__":
    main()