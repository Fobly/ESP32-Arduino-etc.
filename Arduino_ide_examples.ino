
// ================PID regulator================
int computePID(float input, float setpoint, float kp, float ki, float kd, float dt) {
  float err = setpoint - input;
  static float integral = 0, prevErr = 0;
  integral += err * dt;
  float D = (err - prevErr) / dt;
  prevErr = err;
  return (err * kp + integral * ki + D * kd);
}

// ================WiFi Connection================
const char ssid[] = "Testy";
const char pass[] = "22222222";

const char addr[] = "server.tasty"; //Delete if without UDP
int port = 7001; //Delete if without UDP

WiFiUDP udp; //Delete if without UDP

void setup() {
Serial.println("WIFI_CONNECTION");
   WiFi.mode(WIFI_STA);
   WiFi.begin(ssid, pass);
   if (WiFi.waitForConnectResult() != WL_CONNECTED){
      Serial.println("Fail");
      delay(1000);
      ESP.restart();
   }
   Serial.printf("Success");
   udp.begin(WiFi.localIP(), 7000); //Delete if without UDP

  
}
