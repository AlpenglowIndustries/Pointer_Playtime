/*
Who the hell can keep pointers straight?
Not me.
Especially when I only use them once every 6 months or so.

I created this sketch to help me re-learn how pointers
  and their syntax works, espeically pertaining to strings.

I hope it helps you too!

It's written & tested on an Arduino Uno but likely works on pretty much
  any Arduino-compatible platform.

Carrie Sundra
03/29/2022
MIT License
*/

// // LCD code kept around in case you want to play with displaying
// // text in that output form.
//
// #include <LiquidCrystal.h>
//
// const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
// LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:

  // lcd.begin(16, 2);
  // lcd.clear();
  // lcd.print("This is a test.");
  // delay(1000);

  Serial.begin(9600);

  char singleChar = 'Y';
  char aString[] = "I am a string!";
  char* stringPointer = aString;

  Serial.print("singleChar: \t\t");
  Serial.println(singleChar);
  Serial.print("aString: \t\t");
  Serial.println(aString);
  Serial.print("&aString[0]: \t\t");
  Serial.println(&aString[0]);
  Serial.print("stringPointer: \t");
  Serial.println(stringPointer);
  Serial.print("&stringPointer[0]: \t");
  Serial.println(&stringPointer[0]);
  Serial.print("stringPointer + 2: \t");
  Serial.println(stringPointer + 2);
  Serial.print("*stringPointer: \t");
  Serial.println(*stringPointer);
  Serial.print("aString[0]: \t\t");
  Serial.println(aString[0]);
  Serial.print("(uint16_t) &aString[0]: \t");
  Serial.println((uint16_t) &aString[0]);
  Serial.print("(uint16_t) stringPointer: \t");
  Serial.println((uint16_t) stringPointer);
  Serial.print("(uint16_t) aString: \t");
  Serial.println((uint16_t) aString);
  Serial.println();
  Serial.println("Trying to print &stringPointer returns an error: it's the address of an address, or a pointer to a pointer");
  Serial.println();

  Serial.println("Which brings us to passing a pointer to a pointer into a function:");

  char* anotherString = "I am another String!";

  Serial.println("Here is the string we are passing into the function:");
  Serial.print("anotherString: \t");
  Serial.println(anotherString);
  incStringPP(&anotherString);
  Serial.println();
  Serial.println("===== I'm back in main! =====");
  Serial.print("anotherString: \t");
  Serial.println(anotherString);
  Serial.println("Notice anotherString remains incremented");
  Serial.println();
  Serial.println("Now we reset anotherString to its original form:");
  anotherString -= 2;
  Serial.print("anotherString: \t");
  Serial.println(anotherString);
  incStringP(anotherString);
  Serial.println();
  Serial.println("===== I'm back in main! =====");
  Serial.print("anotherString: \t");
  Serial.println(anotherString);
  Serial.println("Notice anotherString is not incremented");
}

void loop() {
  // put your main code here, to run repeatedly:

}

// Sometimes you want to pass a string into a function, have that function perform some kind of parsing action,
// then return the rest of the string that hasn't been parsed yet.  But maybe you also want to return something
// else as the official function return parameter, like a length or UTF-8 character code point or something.
// This syntax allows you to return some other variable, and the string pointer is moved as well when it returns to main.

void incStringPP (char** inputString) {
  // Note that we now have to dereference inputString by one level, and use *inputString to access the string itself.
  // If you try Serial.println(inputString); you'll get a compiler error because you can't print a pointer to a pointer
  Serial.println();
  Serial.println("===== I'm in incStringPP now! =====");
  Serial.print("*inputString: \t");
  Serial.println(*inputString);
  Serial.print("**inputString: \t");
  Serial.println(**inputString);
  *inputString += 2;
  Serial.println("After *inputString += 2; ...");
  Serial.print("*inputString: \t");
  Serial.println(*inputString);
}

// This is more standard syntax for passing a string to a function using a single pointer.
// Note that all string manipulation is local to this function, when it returns to main,
// anotherString (the inputString) still points to the beginning of the string.
void incStringP (char* inputString) {
  // Here we use "normal" pointer notation where inputString accesses the string itself.
  Serial.println();
  Serial.println("===== I'm in incStringP now! =====");
  Serial.print("inputString: \t\t");
  Serial.println(inputString);
  Serial.print("*inputString: \t");
  Serial.println(*inputString);
  inputString += 2;
  Serial.println("After inputString += 2; ...");
  Serial.print("inputString: \t\t");
  Serial.println(inputString);
}
