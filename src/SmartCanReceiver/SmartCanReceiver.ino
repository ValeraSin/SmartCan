#include "SerialFlow.h"

SerialFlow rd(9, 10);

union Packet
{
  uint16_t data[3];
  int16_t ypr[3];
};

void setup()
{
    Serial.begin(57600);
    rd.setPacketFormat(2, 3);
    rd.begin(0xF0F0F0F0D1LL,0xF0F0F0F0E3LL);
    //rd.begin(0xF0F0F0F0D1LL,0xF0F0F0F0E2LL ,0xF0F0F0F0E3LL);
}

void loop()
{
    Packet p;
    if( rd.receivePacket() ){
        p.data[0] = rd.getPacketValue(0);
        p.data[1] = rd.getPacketValue(1);
        p.data[2] = rd.getPacketValue(2);

        if (p.ypr[0] > 180 || p.ypr[0] < - 180)
          return;
        if (p.ypr[1] > 180 || p.ypr[1] < - 180)
          return;
        if (p.ypr[2] > 180 || p.ypr[2] < - 180)
          return;

        Serial.print("ypr\t");
        Serial.print(p.ypr[0]);
        Serial.print("\t");
        Serial.print(p.ypr[1]);
        Serial.print("\t");
        Serial.println(p.ypr[2]);
    }
}
