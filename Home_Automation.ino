void setup() {
  pinMode(2,INPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
}

void loop() {
  
  if(digitalRead(2))
    {
      digitalWrite(13,HIGH); 
      Serial.println("CONNECTED");  
  if(Serial.available()>0)
  {
    char data = Serial.read();
    if(data == 'A')
    {
      Serial.println("L1 ON");
      digitalWrite(9,LOW);
    }
    else if(data == 'a')
    {
      Serial.println("L1 OFF");
      digitalWrite(9,HIGH);
    }
    else if(data == 'b')
    {
      Serial.println("L2 OFF");
      digitalWrite(10,HIGH);
    }
    else if(data == 'B')
    {
      Serial.println("L2 ON");
      digitalWrite(10,LOW);
    }
    else if(data == 'c')
    {
      Serial.println("F1 OFF");
      digitalWrite(11,HIGH);
    }
    else if(data == 'C')
    {
      Serial.println("F1 ON");
      digitalWrite(11,LOW);
    }
    else if(data == 'd')
    {
      Serial.println("F2 OFF");
      digitalWrite(12,HIGH);
    }
    else if(data == 'D')
    {
      Serial.println("F2 ON");
      digitalWrite(12,LOW);
    }
  }

  }
  else digitalWrite(13,LOW);
 delay(250);
}
