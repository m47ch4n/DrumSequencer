void playMode() {
  if (modeClick) printPlayDisp();

  soundOffset = (analogRead(0) - 100) / 32;
  int beforeTime = millis();

  unsigned char note = track[trackPos];
  if (1 <= note && note <= 7)
    playSound(sounds[note], sizes[note]);


  int delayTime = millis() - beforeTime;
  int waitTime = (((60000 / bpm) / 4) - delayTime);
  delay(abs(waitTime));

  lcd.setCursor(trackPos, 1);
  lcd.kana(soundToken[track[trackPos]]);

  trackPos = ++trackPos % 16;
  rep(i, 4) digitalWrite(ledPins[i], trackPos % 4 == i);
}

void printPlayDisp() {
  lcd.clear();
  printMode();
  printBpm();
}
