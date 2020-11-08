float pozycja_now=0;
float pozycja_zadana=0;
float syg_ster=0;
float uchyb=0;
float kp=0;


long odleglosc_aktualna(int pin_start, int pin_read)
{
  pinMode(pin_start,OUTPUT);
  digitalWrite(pin_start,LOW);
  delay(10);
  digitalWrite(pin_start,HIGH);
  delay(10);
  digitalWrite(pin_start,LOW);

  pinMode(pin_read, INPUT);
   return pulseIn(pin_read, HIGH);
}
void setup() 
{
Serial.begin(9600);

pinMode(9,OUTPUT); // okreslenie Pina 9 oraz 10 jako wyjścia
digitalWrite(9,LOW);

pinMode(10,OUTPUT);
digitalWrite(10,LOW);

}

void loop()
{

  pozycja_zadana=50; // definiujemy pozycje
  pozycja_now=0.01723*odleglosc_aktualna(7,7); //zczytanie aktualnej pozycji z dalmierza

  uchyb=pozycja_zadana-pozycja_now;

kp=3;


syg_ster=kp*uchyb; //definiujemy sygnal sterujacy dla regulatora proporcjonalnego

if(syg_ster>255) // ograniczenie wartosci sygnalu sterujacego od -255 do 255
{syg_ster=255;}
else if (syg_ster<-255)
{syg_ster=-255;};


if(syg_ster>=0)
{
  digitalWrite(9,HIGH);
digitalWrite(10,LOW);
}
else if (syg_ster<=0)
{
 digitalWrite(10,HIGH);
digitalWrite(9,LOW);
} 
analogWrite(6,syg_ster);

}
