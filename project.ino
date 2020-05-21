

// global variables
int led = D0;
int button = D2;
String ledStatus = "off";

void setup() {
    pinMode(button, INPUT_PULLUP);
    pinMode(led, OUTPUT);

    // turn off light at start to match ledStatus
    digitalWrite(led, LOW);
}

void loop() {
    // check button
    int buttonState = digitalRead(button);

    // LOW means button is being pushed
    if(buttonState == LOW) {

        // if light is currently off, switch to on
        if(ledStatus == "off") {
            //delay(20000);
            ledStatus = "on";
            digitalWrite(led, HIGH);
            delay(5000);
            ledStatus = "off";
            digitalWrite(led, LOW);
            
        }
        // else light must be on, so switch to off
        else {

        }
    }

    // wait 0.2 seconds before checking button again
    delay(200);
}