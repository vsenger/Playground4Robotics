void le_voltagem_bateria(){
  unsigned int ADC1=analogRead(32);
  Serial.print("ADC1:");
  Serial.println(ADC1);
  float leitura = (ADC1 * 3.3) / 4096.0;   
  //float batteryVoltage = temp / (R22/(R21+R22));   
  batteryVoltage = (leitura / (1000000.0/(2700000.0+1000000.0))) + 0.36;   
  Serial.print("baterryVoltage:");
  Serial.println(String(batteryVoltage));
  batteryOled();
}

void le_battery_status(){
  batteryChargeStatus = (digitalRead(batteryStatusPin));
}

void le_battery_percent(){
  batteryStatusPerCent = map((batteryVoltage*100),280,420,0,100);
}



void le_voltagem_portasAnalogicas(){
  unsigned int ADC1=analogRead(36);
  Serial.print("ADC1:");
  Serial.println(ADC1);
  float leitura = (ADC1 * 3.3) / 4096.0;   
  //float batteryVoltage = temp / (R22/(R21+R22));   
  AN_36_voltage = (leitura / (191000.0/(100000.0+191000.0)));   
  Serial.print("AN_36_voltage:");
  Serial.println(String(AN_36_voltage));
  AN_voltageOled();

  ADC1=analogRead(35);
  Serial.print("ADC1:");
  Serial.println(ADC1);
  leitura = (ADC1 * 3.3) / 4096.0;   
  //float batteryVoltage = temp / (R22/(R21+R22));   
  AN_35_voltage = (leitura / (191000.0/(100000.0+191000.0)));   
  Serial.print("AN_35_voltage:");
  Serial.println(String(AN_35_voltage));
  AN_voltageOled();

  ADC1=analogRead(33);
  Serial.print("ADC1:");
  Serial.println(ADC1);
  leitura = (ADC1 * 3.3) / 4096.0;   
  //float batteryVoltage = temp / (R22/(R21+R22));   
  AN_33_voltage = (leitura / (191000.0/(100000.0+191000.0)));   
  Serial.print("AN_33_voltage:");
  Serial.println(String(AN_33_voltage));
  AN_voltageOled();

  ADC1=analogRead(34);
  Serial.print("ADC1:");
  Serial.println(ADC1);
  leitura = (ADC1 * 3.3) / 4096.0;   
  //float batteryVoltage = temp / (R22/(R21+R22));   
  AN_34_voltage = (leitura / (191000.0/(100000.0+191000.0)));   
  Serial.print("AN_34_voltage:");
  Serial.println(String(AN_34_voltage));
  AN_voltageOled();

}
