enum Estados {Imprimir_Op, Leer_Op, Calcular, Reiniciar};
int op = 0, val = 0;
int ran1 = 0, ran2 = 0;
int score [2] = {0, 0};
int estado = 0,i=0;
String temporal;
String Nombres[] ={"Manzanas","Tomates","Numeros"};

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(950);


}

void loop() {

  switch (estado) {
    case Imprimir_Op:
      Serial.println("Inicio del Examen");
      Serial.println("Muestreo de preguntas");
      ran1 = random(1, 100);
      ran2 = random(1, 100);
      Serial.println("Si tengo " + String(ran1) + " y " + String(ran2) + " "+String(Nombres[i]));
      Serial.println();
      i++;
      estado++;
      break;

    case Leer_Op:
      if (Serial.available() > 0) {
        temporal = Serial.readString();
        op = temporal.toInt();
        estado++;
        Serial.println();
      }
      break;

    case Calcular:

      Serial.println("\nOperaciones:");
      val = (ran1 + ran2);
      Serial.println("Buenas y Malas ");
      if (op == val) {
        Serial.println("BUENA\n");
        score[0]++;
      }
      else {
        Serial.println("MAL\n");
        score[1]++;
      }
      Serial.println("Puntaje: ");
      estado++;
      Serial.println("Respuestas malas: " + String(score[1]) + "  "
                     + "Respuestas positivas: " + String(score[0]));
      break;

    case Reiniciar:
      op = 0;
      temporal = "";
      estado = 0;
      val = 0;
      Serial.println("\n \n");
      break;
  }
}
