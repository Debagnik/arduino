// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define TOTAL_MOLES 4
struct Mole
{
	int led_pin;
  	int button_pin;
};

struct Mole mole_array[TOTAL_MOLES] = {
  {.led_pin = A0, .button_pin = 6},
  {.led_pin = A1, .button_pin = 7},
  {.led_pin = A2, .button_pin = 8},
  {.led_pin = A3, .button_pin=9}
};

int total_score;
void setup() {
  randomSeed(analogRead(A5));
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  total_score = 0;
}

void use_mole(struct Mole* mole)
{
  lcd.clear();
  lcd.print("Score: " + String(total_score));
  
  digitalWrite(mole->led_pin, HIGH);
  delay(2000);
  digitalWrite(mole->led_pin, LOW);
  lcd.clear();
  if(digitalRead(mole->button_pin) == LOW)
  {
    lcd.print("You hit the mole!");
    total_score += 1;
  }
  else
  {
    lcd.print("You failed!");
    total_score -= 1;
  }
  
  delay(1500);
}

void loop() {
 int r = random(TOTAL_MOLES);
 struct Mole* mole = &mole_array[r];
 use_mole(mole);
}
 