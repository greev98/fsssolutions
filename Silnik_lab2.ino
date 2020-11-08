#define SW1 7
#define SW2 8
#define SW3 9
#define M_LEFT 10
#define M_RIGHT 11
//deklaracja zmiennych
int counter = 0;
int buttonState = 0;
int lastButtonState = 0;
int switch_on = 0;

//Czesc programu, ktora wykonuje sie podczas pierwszego uruchomienia
void setup()
{
  Serial.begin(9600); //Rozpoczecie transmisji
  
  pinMode(SW1,INPUT); //konfiguracja pinu 7 jako wejscie
  pinMode(SW2,INPUT);
  pinMode(SW3,INPUT);
  pinMode(M_LEFT,OUTPUT);
  pinMode(M_RIGHT,OUTPUT);
  //ustawienie wyjsc sterujacych kierunkiem na stan niski
  digitalWrite(M_LEFT,LOW);
  digitalWrite(M_RIGHT,LOW);
}
//Czesc programu, ktora bedzie wykonywac sie cyklicznie
void loop() 
{
  //odczyt wejscia sterujacego
    buttonState = digitalRead(SW1);

    if(buttonState != lastButtonState) //wykrywanie zmiany stanu przycisku
    { 
      if(buttonState == HIGH){
        delay(40);
        if(buttonState == HIGH && switch_on == 0){
          switch_on = 1;
          counter = counter+1;
        }

       else if(buttonState == HIGH && switch_on == 1){
         switch_on = 0;
         counter = counter+1;
       }
       
      }
      
    }
    lastButtonState = buttonState; //zapis stanu przycisku jako poprzedni

    if(switch_on == 1) //przycisk SW1 w stanie START
    {
      if(digitalRead(SW2) == true && digitalRead(SW3) == false)
      {
        digitalWrite(M_RIGHT,LOW);
        digitalWrite(M_LEFT,HIGH);
        
      }

      else if(digitalRead(SW2) == false && digitalRead(SW3) == true)
      {
        digitalWrite(M_RIGHT,HIGH);
        digitalWrite(M_LEFT,LOW);
      }

       else if(digitalRead(SW2) == true && digitalRead(SW3) == true) //jezeli oba przyciski wcisniete, to silnik sie nie kreci (zabezpieczenie)
      {
        digitalWrite(M_RIGHT,LOW);
        digitalWrite(M_LEFT,LOW);
      }
    }

    else //przycisk SW1 w stanie STOP
    {
        digitalWrite(M_RIGHT,LOW);
        digitalWrite(M_LEFT,LOW);
    }

    Serial.println(counter); //wyswietlanie liczby wcisniec
    

  
}
