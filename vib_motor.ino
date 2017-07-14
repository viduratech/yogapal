
int vib1 = 5;
int vib2 = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(vib1, OUTPUT);
  pinMode(vib2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite( vib1 , LOW );
  delay(500);
  digitalWrite( vib1 , HIGH );
  delay(500);
  digitalWrite( vib2 , LOW );
  delay(500);
  digitalWrite( vib2 , HIGH );
  delay(1000);
  digitalWrite( vib1 , LOW );
  delay(500);
  digitalWrite( vib1 , HIGH );
  delay(500);
  digitalWrite( vib2 , LOW );
  delay(500);
  digitalWrite( vib2 , HIGH );
  delay(1000);
  digitalWrite( vib1 , LOW );
  delay(500);
  digitalWrite( vib1 , HIGH );
  delay(500);
  digitalWrite( vib2 , LOW );
  delay(500);
  digitalWrite( vib2 , HIGH );
  delay(5000);

}
