#include <BleKeyboard.h>

BleKeyboard bleKeyboard;

void setup() {
  Serial.begin(115200);
  bleKeyboard.begin();
}

void loop() {
  if (bleKeyboard.isConnected()) {
    delay(10000);
    writeMessage("**pass**");
    bleKeyboard.write(KEY_RETURN);
    delay(10000);
    bleKeyboard.end();
    delay(10000);
  }
}

void writeMessage(const char* message) {
  for (int i = 0; message[i] != '\0'; i++) {
    char c = message[i];
    if (c == '@') {
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press(KEY_LEFT_ALT);
      bleKeyboard.press('q');
      bleKeyboard.releaseAll();
    } else if (c == '*') {
      bleKeyboard.press(KEY_LEFT_SHIFT);
      bleKeyboard.press(']');
      bleKeyboard.releaseAll();
    } else {
      bleKeyboard.print(c);
    }
    delay(100);
  }
}
