/*
	Titulo: Voltimetro Simple
	Autor: Edixon Piña
	Fecha: 30/06/2018
*/

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	float adc = analogRead(A0);						   // A0: El primer pin analogico del arduino
	float volt = adc * (Aref() / 1023.0);			   // Aref(): Voltaje referencia del ADC
	Serial.println("Volt = " + (String)voltaje + "v"); // Se concatena con (String)
}

// Funcion para adaptar la medicion a los valores de la fuente de alimentación
float Aref()
{
	ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
	delay(2);
	ADCSRA |= _BV(ADSC);

	while (bit_is_set(ADCSRA, ADSC)) // Banderas ADC
	{
	}

	int result = ADCL;
	result |= ADCH << 8;
	float result = 1126.400 / result; // Back-calculate AVcc in mV
	return result;
}
