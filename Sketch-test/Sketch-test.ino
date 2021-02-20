
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "LedControlMS.h"


const char *wifi_ssid     = "tedata-141";
const char *wifi_password = "o1122331125";
WiFiClient Wifi;



int DIN = D7;
int CLK = D5;
int CS  = D4;
int NBR_MTX = 1; //number of matrices attached is one
LedControl LC = LedControl(DIN, CLK, CS, NBR_MTX);

String webpage;
String message;

ESP8266WebServer WebServer(80);


void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(wifi_ssid, wifi_password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  WebServer.on("/", GetMessage);
  WebServer.begin(); Serial.println(F("Webserver started..."));
  

  LC.shutdown(0, false);
  LC.setIntensity(0, 8);
  LC.clearDisplay(0);


  message = "----";
  display_message(message); // Display the message
}

void loop() {

  WebServer.handleClient();
  display_message(message); // Display the message
}


void display_message(char *message) {
  LC.writeString(0, message);   // sending characters to display
}


void GetMessage() {
  webpage = ""; // don't delete this command, it ensures the server works reliably!
  append_page_header();
  String IPaddress = WiFi.localIP().toString();
  webpage += F("<h3>Enter the message to be displayed then Enter</h3><br>");
  webpage += "<form action=\"http://" + IPaddress + "\" method=\"POST\">";
  webpage += F("Enter the required message text:<br><br><input type='text' size='50' name='message' value='' >");
  webpage += F("</form><br/><br/>");
  append_page_footer();
  WebServer.send(200, "text/html", webpage); // Send a response to the client to enter their inputs, if needed, Enter=defaults
  if (WebServer.args() > 0 ) { // Arguments were received
    for ( uint8_t i = 0; i < WebServer.args(); i++ ){
      String Argument_Name   = WebServer.argName(i);
      String client_response = WebServer.arg(i);
      if (Argument_Name == "message") message = client_response; //-----> notice here the value is a string
    }
  }
}
