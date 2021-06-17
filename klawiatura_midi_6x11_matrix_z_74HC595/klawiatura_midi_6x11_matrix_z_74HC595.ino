#define NUM_ROWS 6
#define NUM_COLS 11

#define NOTE_ON_CMD 0x90
#define NOTE_OFF_CMD 0x80
#define NOTE_VELOCITY 127

//MIDI baud rate
#define SERIAL_RATE 31250

// Pin Definitions

// Row input pins
const int row1Pin = 2;
const int row2Pin = 3;
const int row3Pin = 4;
const int row4Pin = 5;
const int row5Pin = 6;
const int row6Pin = 7;

// 74HC595 pins
const int dataPin = 8;
const int latchPin = 9;
const int clockPin = 10;

boolean keyPressed[NUM_ROWS][NUM_COLS];
uint8_t keyToMidiMap[NUM_ROWS][NUM_COLS];

// bitmasks for scanning columns
int bits[] =
{ 
  B00000001,
  B00000010,
  B00000100,
  B00001000,
  B00010000,
  B00100000,
  B01000000,
  B10000000
};

void setup()
{
  int note = 31;

  for(int colCtr = 0; colCtr < NUM_COLS; ++colCtr)
  {
    for(int rowCtr = 0; rowCtr < NUM_ROWS; ++rowCtr)
    {
      keyPressed[rowCtr][colCtr] = false;
      keyToMidiMap[rowCtr][colCtr] = note;
      note++;
    }
  }

  // setup pins output/input mode
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);

  pinMode(row1Pin, INPUT);
  pinMode(row2Pin, INPUT);
  pinMode(row3Pin, INPUT);
  pinMode(row4Pin, INPUT);
  pinMode(row5Pin, INPUT);
  pinMode(row6Pin, INPUT);

  Serial.begin(SERIAL_RATE);
}

void loop()
{
  for (int colCtr = 0; colCtr < NUM_COLS; ++colCtr)
  {
    //scan next column
    scanColumn(colCtr);

    //get row values at this column
    int rowValue[NUM_ROWS];
    rowValue[0] = digitalRead(row1Pin);
    rowValue[1] = digitalRead(row2Pin);
    rowValue[2] = digitalRead(row3Pin);
    rowValue[3] = digitalRead(row4Pin);
    rowValue[4] = digitalRead(row5Pin);
    rowValue[5] = digitalRead(row6Pin);

    // process keys pressed
    for(int rowCtr=0; rowCtr<NUM_ROWS; ++rowCtr)
    {
      if(rowValue[rowCtr] != 0 && !keyPressed[rowCtr][colCtr])
      {
        keyPressed[rowCtr][colCtr] = true;
        noteOn(rowCtr,colCtr);
      }
    }

    // process keys released
    for(int rowCtr=0; rowCtr<NUM_ROWS; ++rowCtr)
    {
      if(rowValue[rowCtr] == 0 && keyPressed[rowCtr][colCtr])
      {
        keyPressed[rowCtr][colCtr] = false;
        noteOff(rowCtr,colCtr);
      }
    }
  }
}

void scanColumn(int colNum)
{
  digitalWrite(latchPin, LOW);

  if(0 <= colNum && colNum <= 7)
  {
    shiftOut(dataPin, clockPin, MSBFIRST, B00000000); //right sr
    shiftOut(dataPin, clockPin, MSBFIRST, bits[colNum]); //left sr
  }
  else
  {
    shiftOut(dataPin, clockPin, MSBFIRST, bits[colNum-8]); //right sr
    shiftOut(dataPin, clockPin, MSBFIRST, B00000000); //left sr
  }
  digitalWrite(latchPin, HIGH);
}

void noteOn(int row, int col)
{
  Serial.write(NOTE_ON_CMD);
  Serial.write(keyToMidiMap[row][col]);
  Serial.write(NOTE_VELOCITY);
}

void noteOff(int row, int col)
{
  Serial.write(NOTE_OFF_CMD);
  Serial.write(keyToMidiMap[row][col]);
  Serial.write(NOTE_VELOCITY);
}


// Pin Definitions
// Rows are connected to
const int row1 = 5;
const int row2 = 6;
const int row3 = 7;
const int row4 = 8;
const int row5 = 4;
const int row6 = 3;
const int row7 = 2;
const int row8 = 1;




// The 74HC595 uses a serial communication 
// link which has three pins
const int clock = 9;
const int latch = 10;
const int data = 11;


uint8_t keyToMidiMap[64];

boolean keyPressed[64];

int noteVelocity = 127;


// use prepared bit vectors instead of shifting bit left everytime
int bits[] = { B00000001, B00000010, B00000100, B00001000, B00010000, B00100000, B01000000, B10000000 };


// 74HC595 shift to next column
void scanColumn(int value) {
  digitalWrite(latch, LOW); //Pulls the chips latch low
  shiftOut(data, clock, MSBFIRST, value); //Shifts out the 8 bits to the shift register
  digitalWrite(latch, HIGH); //Pulls the latch high displaying the data
}

void setup() {
  
  // Map scan matrix buttons/keys to actual Midi note number. Lowest num 41 corresponds to F MIDI note.
  keyToMidiMap[0] = 48;
  keyToMidiMap[1] = 41;
  keyToMidiMap[2] = 42;
  keyToMidiMap[3] = 43;
  keyToMidiMap[4] = 44;
  keyToMidiMap[5] = 45;
  keyToMidiMap[6] = 46;
  keyToMidiMap[7] = 47;

  keyToMidiMap[8] = 56;
  keyToMidiMap[1 + 8] = 49;
  keyToMidiMap[2 + 8] = 50;
  keyToMidiMap[3 + 8] = 51;
  keyToMidiMap[4 + 8] = 52;
  keyToMidiMap[5 + 8] = 53;
  keyToMidiMap[6 + 8] = 54;
  keyToMidiMap[7 + 8] = 55;

  keyToMidiMap[16] = 64;
  keyToMidiMap[1 + 16] = 57;
  keyToMidiMap[2 + 16] = 58;
  keyToMidiMap[3 + 16] = 59;
  keyToMidiMap[4 + 16] = 60;
  keyToMidiMap[5 + 16] = 61;
  keyToMidiMap[6 + 16] = 62;
  keyToMidiMap[7 + 16] = 63;

  keyToMidiMap[24] = 72;
  keyToMidiMap[1 + 24] = 65;
  keyToMidiMap[2 + 24] = 66;
  keyToMidiMap[3 + 24] = 67;
  keyToMidiMap[4 + 24] = 68;
  keyToMidiMap[5 + 24] = 69;
  keyToMidiMap[6 + 24] = 70;
  keyToMidiMap[7 + 24] = 71;
  
  keyToMidiMap[32] = 72;
  keyToMidiMap[1 + 32] = 65;
  keyToMidiMap[2 + 32] = 66;
  keyToMidiMap[3 + 32] = 67;
  keyToMidiMap[4 + 32] = 68;
  keyToMidiMap[5 + 32] = 69;
  keyToMidiMap[6 + 32] = 70;
  keyToMidiMap[7 + 32] = 71;
  
  keyToMidiMap[40] = 72;
  keyToMidiMap[1 + 40] = 65;
  keyToMidiMap[2 + 40] = 66;
  keyToMidiMap[3 + 40] = 67;
  keyToMidiMap[4 + 40] = 68;
  keyToMidiMap[5 + 40] = 69;
  keyToMidiMap[6 + 40] = 70;
  keyToMidiMap[7 + 40] = 71;
  
  keyToMidiMap[48] = 72;
  keyToMidiMap[1 + 48] = 65;
  keyToMidiMap[2 + 48] = 66;
  keyToMidiMap[3 + 48] = 67;
  keyToMidiMap[4 + 48] = 68;
  keyToMidiMap[5 + 48] = 69;
  keyToMidiMap[6 + 48] = 70;
  keyToMidiMap[7 + 48] = 71;

  keyToMidiMap[56] = 72;
  keyToMidiMap[1 + 56] = 65;
  keyToMidiMap[2 + 56] = 66;
  keyToMidiMap[3 + 56] = 67;
  keyToMidiMap[4 + 56] = 68;
  keyToMidiMap[5 + 56] = 69;
  keyToMidiMap[6 + 56] = 70;
  keyToMidiMap[7 + 56] = 71;

  // setup pins output/input mode
  pinMode(data, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(latch, OUTPUT);

  pinMode(row1, INPUT);
  pinMode(row2, INPUT);
  pinMode(row3, INPUT);
  pinMode(row4, INPUT);
  pinMode(row5, INPUT);
  pinMode(row6, INPUT);
  pinMode(row7, INPUT);
  pinMode(row8, INPUT);

    Serial.begin(31250);

  delay(1000);

}

void loop() {

  for (int col = 0; col < 8; col++) {
    
    // shift scan matrix to following column
    scanColumn(bits[col]);

    // check if any keys were pressed - rows will have HIGH output in this case corresponding
    int groupValue1 = digitalRead(row1);
    int groupValue2 = digitalRead(row2);
    int groupValue3 = digitalRead(row3);
    int groupValue4 = digitalRead(row4);
    int groupValue5 = digitalRead(row5);
    int groupValue6 = digitalRead(row6);
    int groupValue7 = digitalRead(row7);
    int groupValue8 = digitalRead(row8);

    // process if any combination of keys pressed
    if (groupValue1 != 0 || groupValue2 != 0 || groupValue3 != 0 || groupValue4 != 0 || groupValue5 != 0 || groupValue6 != 0 || groupValue7 != 0 || groupValue8 != 0) {

      if (groupValue1 != 0 && !keyPressed[col]) {
        keyPressed[col] = true;
        noteOn(0x91, keyToMidiMap[col], noteVelocity);
      }

      if (groupValue2 != 0 && !keyPressed[col + 8]) {
        keyPressed[col + 8] = true;
        noteOn(0x91, keyToMidiMap[col + 8], noteVelocity);
      }

      if (groupValue3 != 0 && !keyPressed[col + 16]) {
        keyPressed[col + 16] = true;
        noteOn(0x91, keyToMidiMap[col + 16], noteVelocity);
      }

      if (groupValue4 != 0 && !keyPressed[col + 24]) {
        keyPressed[col + 24] = true;
        noteOn(0x91, keyToMidiMap[col + 24], noteVelocity);
      }
      
      if (groupValue5 != 0 && !keyPressed[col + 32]) {
        keyPressed[col + 32] = true;
        noteOn(0x91, keyToMidiMap[col + 32], noteVelocity);
      }
      
      if (groupValue6 != 0 && !keyPressed[col + 40]) {
        keyPressed[col + 40] = true;
        noteOn(0x91, keyToMidiMap[col + 40], noteVelocity);
      }

      if (groupValue7 != 0 && !keyPressed[col + 48]) {
        keyPressed[col + 48] = true;
        noteOn(0x91, keyToMidiMap[col + 48], noteVelocity);
      }

      if (groupValue8 != 0 && !keyPressed[col + 56]) {
        keyPressed[col + 56] = true;
        noteOn(0x91, keyToMidiMap[col + 56], noteVelocity);
      }

    }

    //  process if any combination of keys released
    if (groupValue1 == 0 && keyPressed[col]) {
      keyPressed[col] = false;
      noteOn(0x91, keyToMidiMap[col], 0);
    }

    if (groupValue2 == 0 && keyPressed[col + 8]) {
      keyPressed[col + 8] = false;
      noteOn(0x91, keyToMidiMap[col + 8], 0);
    }

    if (groupValue3 == 0 && keyPressed[col + 16]) {
      keyPressed[col + 16] = false;
      noteOn(0x91, keyToMidiMap[col + 16], 0);
    }

    if (groupValue4 == 0 && keyPressed[col + 24]) {
      keyPressed[col + 24] = false;
      noteOn(0x91, keyToMidiMap[col + 24], 0);
    }
    
    if (groupValue5 == 0 && keyPressed[col + 32]) {
      keyPressed[col + 32] = false;
      noteOn(0x91, keyToMidiMap[col + 32], 0);
    }

    if (groupValue6 == 0 && keyPressed[col + 40]) {
      keyPressed[col + 40] = false;
      noteOn(0x91, keyToMidiMap[col + 40], 0);
    }

    if (groupValue7 == 0 && keyPressed[col + 48]) {
      keyPressed[col + 48] = false;
      noteOn(0x91, keyToMidiMap[col + 48], 0);
    }

    if (groupValue8 == 0 && keyPressed[col + 56]) {
      keyPressed[col + 56] = false;
      noteOn(0x91, keyToMidiMap[col + 56], 0);
    }
  }
}


void noteOn(int cmd, int pitch, int velocity) {
    Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}
