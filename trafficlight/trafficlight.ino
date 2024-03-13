//Smart Traffic Light System Using Arduino//
// Author Jeslin Augustin//

//Red, Green, Yellow LED Pin Selection Signal 1//
int led_red1 = 10;
int led_green1 = 9;
int led_yellow1 = 8;

//Red, Green, Yellow LED Pin Selection Signal 2//
int led_red2 = 14;
int led_green2 = 15;
int led_yellow2 = 16;

//Button Pin Selection Signal 1//
int button_pin1 = 2;

//Button Pin Selection Signal 2//
int button_pin2 = 3;


//Buzzer Pin Selection pedestrian cross1//
int buzzer_pin1=11;

//Buzzer Pin Selection pedestrian cross2//
int buzzer_pin2=19;

//LDR pin selection//
int ldrsensorPin = A0;

//Declaration and initialization of variables used//
volatile byte buttonReleased1 = false;       
volatile byte buttonReleased2 = false;
unsigned int sensorValue = 0;  

//Function to handle button release interrupt at pedestrial crossing 1//
void buttonReleasedInterruptPed1() 
{
  buttonReleased1 = true;
  Serial.println("interrupt at croosing 1");
  Serial.println(buttonReleased1);
}

//Function to handle button release interrupt at pedestrial crossing 2//
void buttonReleasedInterruptPed2() 
{
  buttonReleased2 = true;
  Serial.println("interrupt at croosing 2");
  Serial.println(buttonReleased2);
}


//Function to control red led in regular mode//
void regular_signal_cycle1()
{
  digitalWrite(led_red1,HIGH);
  digitalWrite(led_green2,HIGH);

  digitalWrite(led_red2,LOW);
  digitalWrite(led_green1,LOW);
  digitalWrite(led_yellow1,LOW);
  digitalWrite(led_yellow2,LOW);

  delay(500);
  if (buttonReleased1)
    {
      buttonReleased1 = false;
      Serial.println("Interrupt handling");
      tone(buzzer_pin1,260);
      delay(2000)
      noTone(buzzer_pin1); 
    } 
}

//Function to control yellow led in regular mode//
void regular_signal_cycle2()
{
  digitalWrite(led_red2,HIGH);
  digitalWrite(led_green1,HIGH);

  digitalWrite(led_red1,LOW);
  digitalWrite(led_green2,LOW);
  digitalWrite(led_yellow1,LOW);
  digitalWrite(led_yellow2,LOW);

  delay(500);
  if (buttonReleased2)
    {
      buttonReleased2 = false;
      Serial.println("Interrupt handling");
      tone(buzzer_pin2,260);
      delay(2000)
      noTone(buzzer_pin2);  
    } 
}

//Function to control green led in regular mode//
void regular_signal_amber()
{
  digitalWrite(led_yellow1,HIGH);
  digitalWrite(led_yellow2,HIGH);

  digitalWrite(led_red2,LOW);
  digitalWrite(led_green1,LOW);
  digitalWrite(led_red1,LOW);
  digitalWrite(led_green2,LOW);
  
}

//Function to handle Regular mode of operation//
void regularmode()
{
  regular_signal_cycle1();
  delay(5000);  
  regular_signal_amber(); 
  delay(2000);
  regular_signal_cycle2();
  delay(5000);  
  regular_signal_amber(); 
  delay(2000);
}

//Function to handle night mode//
void nightmode()
{
  digitalWrite(led_yellow1,LOW);
  digitalWrite(led_yellow2,LOW);
  delay(2000);
  digitalWrite(led_yellow1,HIGH);
  digitalWrite(led_yellow2,HIGH);
  
  }

// Setup Function//
void setup() 
{                
  pinMode(led_red1, OUTPUT); 
  pinMode(led_green1, OUTPUT);
  pinMode(led_yellow1, OUTPUT);  
  pinMode(button_pin1, INPUT); 

  pinMode(led_red2, OUTPUT); 
  pinMode(led_green2, OUTPUT);
  pinMode(led_yellow2, OUTPUT);  
  pinMode(button_pin2, INPUT);

  attachInterrupt(digitalPinToInterrupt(button_pin1),
                  buttonReleasedInterruptPed1,
                  FALLING);    

  attachInterrupt(digitalPinToInterrupt(button_pin2),
                  buttonReleasedInterruptPed2,
                  FALLING); 
  Serial.begin(9600); 
}

//Main loop function//
void loop() 
{
sensorValue = analogRead(ldrsensorPin);    // read the value from the sensor
Serial.println("LDR");
Serial.println(sensorValue); //prints the values coming from the sensor on the screen
if (sensorValue>200)
  {
    Serial.println("RegularMode ON");
    regularmode();
  }
else
  {
    nightmode();
  }
}
          
        
 
