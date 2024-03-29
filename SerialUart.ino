/* SerialMonitor_SEND_RCVE<br> - WHAT IT DOES: 
   - Receives characters from Serial Monitor
   - Displays received character as Decimal, Hexadecimal and Character
   - Controls LED from Keyboard
 - SEE the comments after "//" on each line below
 
  

/*-----( Import needed libraries )-----*/
/*-----( Declare Constants and Pin Numbers )-----*/

/*-----( Declare objects )-----*/
/*-----( Declare Variables )-----*/
int ByteReceived;
void setup()   /****** SETUP: RUNS ONCE ******/
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output  
  Serial.println("--- Start Serial Monitor SEND_RECV ---");
  Serial.println(" Type in Box above, . ");
  Serial.println("(Decimal)(Hex)(Character)");  
  Serial.println(); 
}
//--(end setup )---

void loop()   /****** LOOP: RUNS CONSTANTLY ******/
{
  while (Serial.available() > 0)
  {
    ByteReceived = Serial.read();
    Serial.print(ByteReceived);   
    Serial.print("         ");      
    Serial.print(ByteReceived, HEX);
    Serial.print("        ");     
    Serial.print(char(ByteReceived));
    
    if(ByteReceived == '1') // Single Quote! This is a character.
    {
      digitalWrite(LED_BUILTIN, LOW);
      Serial.print(" LED ON ");
    }
    
    if(ByteReceived == '0')
    {
      digitalWrite(LED_BUILTIN,HIGH);
      Serial.print(" LED OFF");
    }

        
    Serial.println();    // End the line
  }
  // END Serial Available
  }


//--(end main loop )---

/*-----( Declare User-written Functions )-----*/

/*********( THE END )***********/
