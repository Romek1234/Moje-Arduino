boolean C0 = 1;
boolean CS0 = 1;
boolean D0 = 1;
boolean DS0 = 1;
boolean E0 = 1;
boolean F0 = 1;
boolean FS0 = 1;
boolean G0 = 1;
boolean GS0 = 1;
boolean A_0 = 1;
boolean AS0 = 1;
boolean B_0 = 1;

boolean C1 = 1;
boolean CS1 = 1;
boolean D1 = 1;
boolean DS1 = 1;
boolean E1 = 1;
boolean F1 = 1;
boolean FS1 = 1;
boolean G1 = 1;
boolean GS1 = 1;
boolean A_1 = 1;
boolean AS1 = 1;
boolean B_1 = 1;

boolean C2 = 1;
boolean CS2 = 1;
boolean D2 = 1;
boolean DS2 = 1;
boolean E2 = 1;
boolean F2 = 1;


boolean C0last = 1;
boolean CS0last = 1;
boolean D0last = 1;
boolean DS0last = 1;
boolean E0last = 1;
boolean F0last = 1;
boolean FS0last = 1;
boolean G0last = 1;
boolean GS0last = 1;
boolean A0last = 1;
boolean AS0last = 1;
boolean B0last = 1;

boolean C1last = 1;
boolean CS1last = 1;
boolean D1last = 1;
boolean DS1last = 1;
boolean E1last = 1;
boolean F1last = 1;
boolean FS1last = 1;
boolean G1last = 1;
boolean GS1last = 1;
boolean A1last = 1;
boolean AS1last = 1;
boolean B1last = 1;

boolean C2last = 1;
boolean CS2last = 1;
boolean D2last = 1;
boolean DS2last = 1;
boolean E2last = 1;
boolean F2last = 1;

int vol = 90;
// int channel_on = 0x90; // kanal 1
// int channel_off = 0x80; // kanal 1

// int channel_on = 0x91; // kanal 2
// int channel_off = 0x81; // kanal 2

// int channel_on = 0x92; // kanal 3
// int channel_off = 0x81; // kanal 3

int channel_on = 0x93; // kanal 4
int channel_off = 0x83; // kanal 4

// int channel_on = 0x94; // kanal 5
// int channel_off = 0x84; // kanal 5

// int channel_on = 0x95; // kanal 6
// int channel_off = 0x85; // kanal 6

// int channel_on = 0x96; // kanal 7
// int channel_off = 0x86; // kanal 7

// int channel_on = 0x97; // kanal 8
// int channel_off = 0x87; // kanal 8

void setup()  {
  Serial.begin(31250);
  pinMode(22, INPUT_PULLUP);
  pinMode(23, INPUT_PULLUP);
  pinMode(24, INPUT_PULLUP);
  pinMode(25, INPUT_PULLUP);
  pinMode(26, INPUT_PULLUP);
  pinMode(27, INPUT_PULLUP);
  pinMode(28, INPUT_PULLUP);
  pinMode(29, INPUT_PULLUP);
  pinMode(30, INPUT_PULLUP);
  pinMode(31, INPUT_PULLUP);
  pinMode(32, INPUT_PULLUP);
  pinMode(33, INPUT_PULLUP);
  pinMode(34, INPUT_PULLUP);
  pinMode(35, INPUT_PULLUP);
  pinMode(36, INPUT_PULLUP);
  pinMode(37, INPUT_PULLUP);
  pinMode(38, INPUT_PULLUP);
  pinMode(39, INPUT_PULLUP);
  pinMode(40, INPUT_PULLUP);
  pinMode(41, INPUT_PULLUP);
  pinMode(42, INPUT_PULLUP);
  pinMode(43, INPUT_PULLUP);
  pinMode(44, INPUT_PULLUP);
  pinMode(45, INPUT_PULLUP);
  pinMode(46, INPUT_PULLUP);
  pinMode(47, INPUT_PULLUP);
  pinMode(48, INPUT_PULLUP);
  pinMode(49, INPUT_PULLUP);
  pinMode(50, INPUT_PULLUP);
  pinMode(51, INPUT_PULLUP);
  
}

void loop()  {
  // vol = analogRead(A5);
  // vol = map(vol, 0, 1023, 0, 127);
  
  
  C0 = digitalRead(22);
  CS0 = digitalRead(23);
  D0 = digitalRead(24);
  DS0 = digitalRead(25);
  E0 = digitalRead(26);
  F0 = digitalRead(27);
  FS0 = digitalRead(28);
  G0 = digitalRead(29);
  GS0 = digitalRead(30);
  A_0 = digitalRead(31);
  AS0 = digitalRead(32);
  B_0 = digitalRead(33);

  C1 = digitalRead(34);
  CS1 = digitalRead(35);
  D1 = digitalRead(36);
  DS1 = digitalRead(37);
  E1 = digitalRead(38);
  F1 = digitalRead(39);
  FS1 = digitalRead(40);
  G1 = digitalRead(41);
  GS1 = digitalRead(42);
  A_1 = digitalRead(43);
  AS1 = digitalRead(44);
  B_1 = digitalRead(45);

  C2 = digitalRead(46);
  CS2 = digitalRead(47);
  D2 = digitalRead(48);
  DS2 = digitalRead(49);
  E2 = digitalRead(50);
  F2 = digitalRead(51);

// pierwsza oktawa
  
  if(C0 != C0last)  {
    if(C0 == 0)  {
      noteOn(channel_on, 36, vol);
    }
    else  {
      noteOn(channel_off, 36, 0x00);
      noteOn(channel_off, 36, 0x00);
    }
  }
  
  if(CS0 != CS0last)  {
    if(CS0 == 0)  {
      noteOn(channel_on, 37, vol);
    }
    else  {
      noteOn(channel_off, 37, 0x00);
      noteOn(channel_off, 37, 0x00);
    }
  }
  if(D0 != D0last)  {
    if(D0 == 0)  {
      noteOn(channel_on, 38, vol);
    }
    else  {
      noteOn(channel_off, 38, 0x00);
      noteOn(channel_off, 38, 0x00);
    }
  }
  if(DS0 != DS0last)  {
    if(DS0 == 0)  {
      noteOn(channel_on, 39, vol);
    }
    else  {
      noteOn(channel_off, 39, 0x00);
      noteOn(channel_off, 39, 0x00);
    }
  }
  if(E0 != E0last)  {
    if(E0 == 0)  {
      noteOn(channel_on, 40, vol);
    }
    else  {
      noteOn(channel_off, 40, 0x00);
      noteOn(channel_off, 40, 0x00);
    }
  }
  if(F0 != F0last)  {
    if(F0 == 0)  {
      noteOn(channel_on, 41, vol);
    }
    else  {
      noteOn(channel_off, 41, 0x00);
      noteOn(channel_off, 41, 0x00);
    }
  }
  if(FS0 != FS0last)  {
    if(FS0 == 0)  {
      noteOn(channel_on, 42, vol);
    }
    else  {
      noteOn(channel_off, 42, 0x00);
      noteOn(channel_off, 42, 0x00);
    }
  }
  if(G0 != G0last)  {
    if(G0 == 0)  {
      noteOn(channel_on, 43, vol);
    }
    else  {
      noteOn(channel_off, 43, 0x00);
      noteOn(channel_off, 43, 0x00);
    }
  }
  if(GS0 != GS0last)  {
    if(GS0 == 0)  {
      noteOn(channel_on, 44, vol);
    }
    else  {
      noteOn(channel_off, 44, 0x00);
      noteOn(channel_off, 44, 0x00);
    }
  }
  if(A_0 != A0last)  {
    if(A_0 == 0)  {
      noteOn(channel_on, 45, vol);
    }
    else  {
      noteOn(channel_off, 45, 0x00);
      noteOn(channel_off, 45, 0x00);
    }
  }
  if(AS0 != AS0last)  {
    if(AS0 == 0)  {
      noteOn(channel_on, 46, vol);
    }
    else  {
      noteOn(channel_off, 46, 0x00);
      noteOn(channel_off, 46, 0x00);
    }
  }
  if(B_0 != B0last)  {
    if(B_0 == 0)  {
      noteOn(channel_on, 47, vol);
    }
    else  {
      noteOn(channel_off, 47, 0x00);
      noteOn(channel_off, 47, 0x00);
    }
  }

  // druga oktawa

    if(C1 != C1last)  {
    if(C1 == 0)  {
      noteOn(channel_on, 48, vol);
    }
    else  {
      noteOn(channel_off, 48, 0x00);
      noteOn(channel_off, 48, 0x00);
    }
  }
  
  if(CS1 != CS1last)  {
    if(CS1 == 0)  {
      noteOn(channel_on, 49, vol);
    }
    else  {
      noteOn(channel_off, 49, 0x00);
      noteOn(channel_off, 49, 0x00);
    }
  }
  if(D1 != D1last)  {
    if(D1 == 0)  {
      noteOn(channel_on, 50, vol);
    }
    else  {
      noteOn(channel_off, 50, 0x00);
      noteOn(channel_off, 50, 0x00);
    }
  }
  if(DS1 != DS1last)  {
    if(DS1 == 0)  {
      noteOn(channel_on, 51, vol);
    }
    else  {
      noteOn(channel_off, 51, 0x00);
      noteOn(channel_off, 51, 0x00);
    }
  }
  if(E1 != E1last)  {
    if(E1 == 0)  {
      noteOn(channel_on, 52, vol);
    }
    else  {
      noteOn(channel_off, 52, 0x00);
      noteOn(channel_off, 52, 0x00);
    }
  }
  if(F1 != F1last)  {
    if(F1 == 0)  {
      noteOn(channel_on, 53, vol);
    }
    else  {
      noteOn(channel_off, 53, 0x00);
      noteOn(channel_off, 53, 0x00);
    }
  }
  if(FS1 != FS1last)  {
    if(FS1 == 0)  {
      noteOn(channel_on, 54, vol);
    }
    else  {
      noteOn(channel_off, 54, 0x00);
      noteOn(channel_off, 54, 0x00);
    }
  }
  if(G1 != G1last)  {
    if(G1 == 0)  {
      noteOn(channel_on, 55, vol);
    }
    else  {
      noteOn(channel_off, 55, 0x00);
      noteOn(channel_off, 55, 0x00);
    }
  }
  if(GS1 != GS1last)  {
    if(GS1 == 0)  {
      noteOn(channel_on, 56, vol);
    }
    else  {
      noteOn(channel_off, 56, 0x00);
      noteOn(channel_off, 56, 0x00);
    }
  }
  if(A_1 != A1last)  {
    if(A_1 == 0)  {
      noteOn(channel_on, 57, vol);
    }
    else  {
      noteOn(channel_off, 57, 0x00);
      noteOn(channel_off, 57, 0x00);
    }
  }
  if(AS1 != AS1last)  {
    if(AS1 == 0)  {
      noteOn(channel_on, 58, vol);
    }
    else  {
      noteOn(channel_off, 58, 0x00);
      noteOn(channel_off, 58, 0x00);
    }
  }
  if(B_1 != B1last)  {
    if(B_1 == 0)  {
      noteOn(channel_on, 59, vol);
    }
    else  {
      noteOn(channel_off, 59, 0x00);
      noteOn(channel_off, 59, 0x00);
    }
  }

  //trzecia oktawa

if(C2 != C2last)  {
    if(C2 == 0)  {
      noteOn(channel_on, 60, vol);
    }
    else  {
      noteOn(channel_off, 60, 0x00);
      noteOn(channel_off, 60, 0x00);
    }
  }
  
  if(CS2 != CS2last)  {
    if(CS2 == 0)  {
      noteOn(channel_on, 61, vol);
    }
    else  {
      noteOn(channel_off, 61, 0x00);
      noteOn(channel_off, 61, 0x00);
    }
  }
  if(D2 != D2last)  {
    if(D2 == 0)  {
      noteOn(channel_on, 62, vol);
    }
    else  {
      noteOn(channel_off, 62, 0x00);
      noteOn(channel_off, 62, 0x00);
    }
  }
  if(DS2 != DS2last)  {
    if(DS2 == 0)  {
      noteOn(channel_on, 63, vol);
    }
    else  {
      noteOn(channel_off, 63, 0x00);
      noteOn(channel_off, 63, 0x00);
    }
  }
  if(E2 != E2last)  {
    if(E2 == 0)  {
      noteOn(channel_on, 64, vol);
    }
    else  {
      noteOn(channel_off, 64, 0x00);
      noteOn(channel_off, 64, 0x00);
    }
  }
  if(F2 != F2last)  {
    if(F2 == 0)  {
      noteOn(channel_on, 65, vol);
    }
    else  {
      noteOn(channel_off, 65, 0x00);
      noteOn(channel_off, 65, 0x00);
    }
  }
 
  C0last = C0;
  CS0last = CS0;
  D0last = D0;
  DS0last = DS0;
  E0last = E0;
  F0last = F0;
  FS0last = FS0;
  G0last = G0;
  GS0last = GS0;
  A0last = A_0;
  AS0last = AS0;
  B0last = B_0;

  C1last = C1;
  CS1last = CS1;
  D1last = D1;
  DS1last = DS1;
  E1last = E1;
  F1last = F1;
  FS1last = FS1;
  G1last = G1;
  GS1last = GS1;
  A1last = A_1;
  AS1last = AS1;
  B1last = B_1;

  C2last = C2;
  CS2last = CS2;
  D2last = D2;
  DS2last = DS2;
  E2last = E2;
  F2last = F2;
  
  delay(50);
}

 void noteOn(byte cmd, byte data1, byte data2) {
   Serial.write(cmd);
   Serial.write(data1);
   Serial.write(data2);
   delay(10);
 }
