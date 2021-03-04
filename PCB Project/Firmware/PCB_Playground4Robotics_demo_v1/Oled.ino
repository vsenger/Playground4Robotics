//    ssd1306_printFixed(0,  8, "Normal text", STYLE_NORMAL);
//    ssd1306_printFixed(0, 16, "Bold text", STYLE_BOLD);
//    ssd1306_printFixed(0, 24, "Italic text", STYLE_ITALIC);



void serialtextToOled(String texto){
  ssd1306_printFixed(0, 48, "                ", STYLE_BOLD);
  ssd1306_printFixed(0, 48, String(texto).c_str(), STYLE_NORMAL);
}

void IPoled() {
  ssd1306_printFixed(0, 8, "IP:", STYLE_BOLD);
  ssd1306_printFixed(18,  8, (IPAddress2String(WiFi.localIP()).c_str()) , STYLE_NORMAL);
}



void oledAccelerometer() {
  ssd1306_printFixed(0, 16, "X:", STYLE_BOLD);
  ssd1306_printFixed(12,  16, String(Xacc).c_str(), STYLE_NORMAL);

  ssd1306_printFixed(45, 16, "Y:", STYLE_BOLD);
  ssd1306_printFixed(57,  16, String(Yacc).c_str(), STYLE_NORMAL);

  ssd1306_printFixed(90, 16, "Z:", STYLE_BOLD);
  ssd1306_printFixed(102,  16, String(Zacc).c_str(), STYLE_NORMAL);
}

void oledTempUmi() {
  ssd1306_printFixed(0, 24, "Temp:", STYLE_BOLD);
  //ssd1306_printFixed(30,  24, String(Temperatura).c_str(), STYLE_NORMAL);
  ssd1306_printFixed(58,  24, "oC", STYLE_NORMAL);

  ssd1306_printFixed(76, 24, "Umi:", STYLE_BOLD);
  //ssd1306_printFixed(100,  24, String(Umidade).c_str(), STYLE_NORMAL);
  ssd1306_printFixed(122,  24, "%", STYLE_NORMAL);
}

void AN_voltageOled() {
  ssd1306_printFixed(0, 24, "ANVP:", STYLE_BOLD);
  ssd1306_printFixed(30,  24, String(AN_36_voltage).c_str(), STYLE_NORMAL);
  ssd1306_printFixed(58,  24, "V", STYLE_NORMAL);

  ssd1306_printFixed(64, 24, "AN35:", STYLE_BOLD);
  ssd1306_printFixed(94,  24, String(AN_35_voltage).c_str(), STYLE_NORMAL);
  ssd1306_printFixed(122,  24, "V", STYLE_NORMAL);

  ssd1306_printFixed(0, 32, "AN33:", STYLE_BOLD);
  ssd1306_printFixed(30,  32, String(AN_33_voltage).c_str(), STYLE_NORMAL);
  ssd1306_printFixed(58,  32, "V", STYLE_NORMAL);

  ssd1306_printFixed(64, 32, "AN34:", STYLE_BOLD);
  ssd1306_printFixed(94,  32, String(AN_34_voltage).c_str(), STYLE_NORMAL);
  ssd1306_printFixed(122,  32, "V", STYLE_NORMAL);
  
}

void batteryOled() {
  ssd1306_printFixed(0, 56, "Vbat:", STYLE_BOLD);
  ssd1306_printFixed(30,  56, String(batteryVoltage).c_str(), STYLE_NORMAL);
  ssd1306_printFixed(52,  56, "V", STYLE_NORMAL);

  if (batteryChargeStatus == true) {
    ssd1306_printFixed(107,  8, "FULL", STYLE_NORMAL);
  } else {
    ssd1306_printFixed(107,  8, "    ", STYLE_NORMAL);
  }

}

void buttonOled() {
  if (userButtonState == 0) {
    ssd1306_printFixed(107,  8, "USER", STYLE_NORMAL);
  } else {
    ssd1306_printFixed(107,  8, "    ", STYLE_NORMAL);
  }
}


String IPAddress2String(IPAddress address) {
  return String(address[0]) + "." +
         String(address[1]) + "." +
         String(address[2]) + "." +
         String(address[3]);
}
