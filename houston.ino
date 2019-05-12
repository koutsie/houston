int val = 0; // initialize val
int analogPin = 5; // initialize analogPin
int safety = 0; // initialize safety
void setup() // basic first time, basic stuff.
{
  pinMode(LED_BUILTIN, OUTPUT); // so pin, much mode.
  Serial.begin(9600); // 9600 baud cus that shit rules.
  digitalWrite(LED_BUILTIN, LOW); // lets turn the LED off.
  Serial.println("H O U S T O N"); // yes it is, count it.
  Serial.println(""); // lets print this fancy box with info because we can, and also this just looks cool; doesent it?
}

void loop () // main loop, basic stuff you know.
{
  if (Serial.available() > 0) // if we have serial connectivity to houston.service:
    safety = analogRead(analogPin); // lets read the safety's (aka: the buttons) state.
  {
    val = Serial.read(); // we read what we got and
    if (val == '1') // if serial gets an 1:
    {
      delay(200); // delay.... for stability?
      Serial.println("_"); // we send the underscore via the serial to our service to indicate an unload.
      digitalWrite(LED_BUILTIN, LOW); // turn the LED off.
    }
    else if (val == '2' && safety == '0') { // if both serial gets an 1 and our button is held down, load.
      Serial.println(safety);
      delay(200); // delay.... for stability?
      Serial.println("*"); // we send the asterix via the serial to our service to indicate an load.
      digitalWrite(LED_BUILTIN, HIGH); // turn the LED on.
    }
    else if (val == '3') { // if serial gets an 3:
      delay(200); // delay.... for stability?
      Serial.println("Succesfully injected!"); // send this to the arduino to get some cool text via serial :D
    }
    else if (val == '4' && safety == '0') { // if serial gets an 4:
      delay(200); // delay.... for stability?
      Serial.println("Re-injecting..."); // if cs:go crashes were just gonna re-inject automatically.
      Serial.println("%");
    }
  }
}

  //     ▄█    █▄     ▄██████▄  ███    █▄     ▄████████     ███      ▄██████▄  ███▄▄▄▄        ████████▄   ▄██████▄      ███           ▄█  ███▄▄▄▄    ▄██████▄
  //    ███    ███   ███    ███ ███    ███   ███    ███ ▀█████████▄ ███    ███ ███▀▀▀██▄      ███   ▀███ ███    ███ ▀█████████▄      ███  ███▀▀▀██▄ ███    ███
  //    ███    ███   ███    ███ ███    ███   ███    █▀     ▀███▀▀██ ███    ███ ███   ███      ███    ███ ███    ███    ▀███▀▀██      ███▌ ███   ███ ███    ███
  //   ▄███▄▄▄▄███▄▄ ███    ███ ███    ███   ███            ███   ▀ ███    ███ ███   ███      ███    ███ ███    ███     ███   ▀      ███▌ ███   ███ ███    ███
  //  ▀▀███▀▀▀▀███▀  ███    ███ ███    ███ ▀███████████     ███     ███    ███ ███   ███      ███    ███ ███    ███     ███          ███▌ ███   ███ ███    ███
  //    ███    ███   ███    ███ ███    ███          ███     ███     ███    ███ ███   ███      ███    ███ ███    ███     ███          ███  ███   ███ ███    ███
  //    ███    ███   ███    ███ ███    ███    ▄█    ███     ███     ███    ███ ███   ███      ███   ▄███ ███    ███     ███          ███  ███   ███ ███    ███
  //    ███    █▀     ▀██████▀  ████████▀   ▄████████▀     ▄████▀    ▀██████▀   ▀█   █▀       ████████▀   ▀██████▀     ▄████▀        █▀    ▀█   █▀   ▀██████▀
  //
  //                                                                                                                                             by koutsie 2019
  //                                                                                                                                        koutsie@disroot.org
  // fuck aqua!Hook
  // Sincerely, Koutsie.
