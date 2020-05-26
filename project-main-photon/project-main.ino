// This #include statement was automatically added by the Particle IDE.
#include <MQTT.h>



// global variables
int led = D0;
int led7 = D7;
int button = D2;
String ledStatus = "off";

// Create an MQTT client
MQTT client("test.mosquitto.org", 1883, callback);


// This is called when a message is received. However, we do not use this feature in
// this project so it will be left empty
void callback(char* topic, byte* payload, unsigned int length) 
{
}


void setup() {
    pinMode(button, INPUT_PULLUP);
    pinMode(led, OUTPUT);
    pinMode(led7, OUTPUT);

    // Connect to the server and call ourselves "photonDev"
    client.connect("photonDev");
    
    // turn off light at start to match ledStatus
    digitalWrite(led, LOW);
    digitalWrite(led7, LOW);
}

void loop() {
    // check button
    int buttonState = digitalRead(button);
    
    if(buttonState == LOW)
    {
        buttonClick();
    }   
    else 
    {

    }
    
    client.loop();  //MQTT Loop
    // wait 0.2 seconds before checking button again
    delay(200);
    
}

void buttonClick()
{

        // if light is currently off, switch to on
        if(ledStatus == "off")
        {
            ledStatus = "on";

            if (client.isConnected())
            {
                
                digitalWrite(led7, HIGH);                       //Dual Function - functions as a indication for timer start as well as for MQTT connection
                client.publish("doorState", "Timer Triggered");      //Doorstate publish
                client.publish("timeStamp", Time.timeStr());    //Time publish
            }
            else
            {
                client.connect("photonDev");
                if (client.isConnected())
                {
                    
                    digitalWrite(led7, HIGH);                       //Dual Function - functions as a indication for timer start as well as for MQTT connection
                    client.publish("doorState", "Timer Triggered");      //Doorstate publish
                    client.publish("timeStamp", Time.timeStr());    //Time publish
                }
            }
            
            //Turn on the timer FAILSAFE
            digitalWrite(led7, HIGH);       //Comment out to test the MQTT connection
            
            delay(15000); //15 second delay to use the sanatizer
            
            //Showcase the door open trigger 
            digitalWrite(led, HIGH);
            
            if (client.isConnected())
            {
                
                digitalWrite(led7, LOW);                       //Dual Function - functions as a indication for timer end as well as for MQTT connection
                client.publish("doorState", "Door Opened");      //Doorstate publish
                client.publish("timeStamp", Time.timeStr());    //Time publish
            }
            else
            {
                client.connect("photonDev");
                if (client.isConnected())
                {
                    
                    digitalWrite(led7, LOW);                       //Dual Function - functions as a indication for end start as well as for MQTT connection
                    client.publish("doorState", "Door Opened");      //Doorstate publish
                    client.publish("timeStamp", Time.timeStr());    //Time publish
                }
            }
            
            //Turn off the timer FAILSAFE
            digitalWrite(led7, LOW);    //Comment out to test the MQTT connection
            
            //Leave the door open for five seconds
            delay(5000);
            
            //Revert ledStatus and turn LED off
            ledStatus = "off";
            digitalWrite(led, LOW);
            
            if (client.isConnected())
            {
                
                client.publish("doorState", "Door Closed");      //Doorstate publish
                client.publish("timeStamp", Time.timeStr());    //Time publish
            }
            else
            {
                client.connect("photonDev");
                if (client.isConnected())
                {
                    
                    client.publish("doorState", "Door Closed");      //Doorstate publish
                    client.publish("timeStamp", Time.timeStr());    //Time publish
                }
            }

        }
        
}