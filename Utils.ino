void updateClicks() {
  static bool preModeState;
  static bool preTrackState;
  static bool preSetState[4];
  bool tempState;

  tempState = digitalRead(modePin);
  modeClick = tempState && !preModeState;
  preModeState = tempState;

  tempState = digitalRead(trackPin);
  trackClick = tempState && !preTrackState;
  preTrackState = tempState;

  rep(i, 4) {
    tempState = digitalRead(setPins[i]);
    setClicks[i] = tempState && !preSetState[i];
    preSetState[i] = tempState;
  }
}

void playSound(const unsigned char *sound, int size) {
  rep(i, size) {
    OCR2A = pgm_read_word(sound + i);
    delayMicroseconds(125 + soundOffset);
  }
}

void printMode() {
  static unsigned char *kanas[] = {" [ﾊｯﾄ]  ", " [ｽﾈｱ]  ", " [ｷｯｸ]  ", " [ﾃﾝﾎﾟ] ", " [ﾌﾟﾚｲ] "};
  lcd.kana(kanas[modeIndex]);
}

void printBpm() {
  lcd.print("BPM:");
  lcd.print(String(bpm));
}

void num2bit(bool *bits, unsigned char num) {
  rep(i, 8) bits[i] = (num >> (7 - i)) & 1;
}

unsigned char bit2num(bool *bits) {
  unsigned char num = 0;
  rep(i, 8) num += (bits[i] << (7 - i));
  return num;
}
