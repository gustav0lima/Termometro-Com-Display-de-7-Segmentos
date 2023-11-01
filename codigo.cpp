int unidades[] = {14, 15, 2, 3, 4, 5, 6};
int dezenas[] = {7, 8, 9, 10, 11, 12, 16};

static int digito[10][7] = {
   {1, 1, 1, 1, 1, 1, 0}, // 0
   {0, 1, 1, 0, 0, 0, 0}, // 1
   {1, 1, 0, 1, 1, 0, 1}, // 2
   {1, 1, 1, 1, 0, 0, 1}, // 3
   {0, 1, 1, 0, 0, 1, 1}, // 4
   {1, 0, 1, 1, 0, 1, 1}, // 5
   {1, 0, 1, 1, 1, 1, 1}, // 6
   {1, 1, 1, 0, 0, 0, 0}, // 7
   {1, 1, 1, 1, 1, 1, 1}, // 8
   {1, 1, 1, 1, 0, 1, 1}  // 9
};

const int leds_display = 7;
const int digits_display = 10;

void setup() {
    for(int i = 0; i < leds_display; i++) {
        pinMode(dezenas[i], OUTPUT);
        pinMode(unidades[i], OUTPUT);
    }
}

void acende(int* disp, int dig) {
    for(int i = 0; i < leds_display; i++) {
        digitalWrite(disp[i], digito[dig][i]);
    }
}

void loop() {
    int sensorValue = analogRead(A0); 
    float temperatura = (sensorValue / 1024.0) * 500;

    int dezena = int(temperatura) / 10;
    int unidade = int(temperatura) % 10;

    acende(dezenas, dezena);
    delay(1000);  // Exibe a dezena da temperatura por 1 segundo
    acende(unidades, unidade);
    delay(1000);  // Exibe a unidade da temperatura por 1 segundo
}
