const unsigned int DOT_DURATION = 1000;    // in ms
const unsigned int DASH_DURATION = DOT_DURATION * 3;
const unsigned int TIME_BETWEEN_DOTS_AND_DASHES_FROM_THE_SAME_LETTER = DOT_DURATION;
const unsigned int EXTRA_TIME_BETWEEN_LETTERS = 3 * DOT_DURATION - TIME_BETWEEN_DOTS_AND_DASHES_FROM_THE_SAME_LETTER;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  blink_text_in_morse("hELlO");
}

void blink_text_in_morse(char* text) {
  char* morse_code;
  for (unsigned int i = 0; i < strlen(text); i++) {
    morse_code = char_to_morse(text[i]);
    Serial.println(morse_code);
  }
}

void blink_dot() {
  blink(DOT_DURATION);
}

void blink_dash() {
  blink(DASH_DURATION);
}

void blink(int duration) {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(duration);
  digitalWrite(LED_BUILTIN, LOW);
}

void add_space_between_dots_and_dashes_from_the_same_letter() {
  delay(TIME_BETWEEN_DOTS_AND_DASHES_FROM_THE_SAME_LETTER);
}

char* char_to_morse(char c) {
  char* morse;
  switch ((char)tolower(c)) {
    case 'a':
      morse = ".-";
      break;
    case 'b':
      morse = "-...";
      break;
    case 'c':
      morse = "-.-.";
      break;
    case 'd':
      morse = "-..";
      break;
    case 'e':
      morse = ".";
      break;
    case 'f':
      morse = "..-.";
      break;
    case 'g':
      morse = "--.";
      break;
    case 'h':
      morse = "....";
      break;
    case 'i':
      morse = "..";
      break;
    case 'j':
      morse = ".---";
      break;
    case 'k':
      morse = "-.-";
      break;
    case 'l':
      morse = ".-..";
      break;
    case 'm':
      morse = "--";
      break;  
    case 'n':
      morse = "-.";
      break; 
    case 'o':
      morse = "---";
      break;  
    case 'p':
      morse = ".--.";
      break;  
    case 'q':
      morse = "--.-";
      break;  
    case 'r':
      morse = ".-.";
      break;  
    case 's':
      morse = "...";
      break;  
    case 't':
      morse = "-";
      break;  
    case 'u':
      morse = "..-";
      break;  
    case 'v':
      morse = "...-";
      break;  
    case 'w':
      morse = ".--";
      break;  
    case 'x':
      morse = "-..-";
      break;
    case 'y':
      morse = "-.--";
      break;
    case 'z':
      morse = "--..";
      break;
  }
  return morse;
} 
