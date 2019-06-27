void setBpmMode() {
  if (modeClick) printBpmDisp();

  if (trackClick) trackPos = ++trackPos % 2;

  rep(i, 4) {
    if (setClicks[i]) {
      nowTrack[i] = !nowTrack[i];
      bpm = bit2num(bpmBits);
      printBpmDisp();
    }
    digitalWrite(ledPins[i], nowTrack[i]);
  }

  lcd.setCursor(5 + 4 * trackPos + (int)((millis() % 1000)/1000.0 * 4.0), 1);
  delay(1000 / 60);
}

void printBpmDisp() {
  lcd.clear();
  printMode();
  printBpm();
  lcd.setCursor(3, 1);
  lcd.print("0b");
  rep(i, 8) lcd.print(bpmBits[i] ? "1" : "0");
}
