int a, b, wynik;
char operacja;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  while(Serial.available() >0)
  {
    a = Serial.parseInt();
    operacja = Serial.read();
    b = Serial.parseInt();
    
    if(a>99 || b>99)
    {
      Serial.println("Tylko liczby dwucyfrowe!");
      break;
    }
    
    if(operacja == '/' && b==0)
    {
      Serial.println("Nie dzielimy przez 0!");
      break;
    }
    Oblicz();
    Serial.print("Wynik: ");
    Serial.print(wynik);
    Serial.println();
  }
}

void Oblicz() { 
  
  switch (operacja) {
    
    case '+' :
    wynik = a + b;
    break; 
    
    case '-' : 
    wynik = a - b; 
    break; 
    
    case '*' : 
    wynik = a * b;
    break; 
    
    case '/' :
    wynik = a / b; 
    break;
    
    default :
    Serial.println("Niepoprawny symbol! (Uzyj +, -, *, /");
    wynik = 0;
    break;
  }
}
