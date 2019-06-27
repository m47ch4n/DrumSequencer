void setTrackMode() {
  if (modeClick) {
    switch (mode) {
      case setHat  : playSound(sounds[1], sizes[1]); break;
      case setSnare: playSound(sounds[2], sizes[2]); break;
      case setKick : playSound(sounds[4], sizes[4]); break;
    }
    printSetDisp();
  }

  if (trackClick) trackPos = ++trackPos % 4;

  rep(i, 4) {
    if (setClicks[i]) {
      nowTrack[i] = !nowTrack[i];
      rep(i, 16) track[i] =
          (unsigned char)hatTrack[i]   * 1
        + (unsigned char)snareTrack[i] * 2
        + (unsigned char)kickTrack[i]  * 4;
      printSetDisp();
    }
    digitalWrite(ledPins[i], nowTrack[i]);
  }

  lcd.setCursor(4 * trackPos + (int)((millis() % 1000)/1000.0 * 4.0), 1);
  delay(1000 / 60);
}

void printSetDisp() {
  lcd.clear();
  printMode();
  printBpm();
  lcd.setCursor(0, 1);
  rep(i, 16) lcd.kana(soundToken[track[i]]);
  lcd.setCursor(4 * trackPos, 1);
}
