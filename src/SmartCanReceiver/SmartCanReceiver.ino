#include "SerialFlow.h"

SerialFlow rd(9, 10);

union Packet
{
  uint16_t data[4];
  struct {
    uint16_t event;
    int16_t ypr[3];
  } v;
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
        p.data[3] = rd.getPacketValue(3);

        if (p.v.event > 5)
            return;
        if (p.v.event == 0) {
          if (p.v.ypr[0] > 180 || p.v.ypr[0] < - 180)
            return;
          if (p.v.ypr[1] > 180 || p.v.ypr[1] < - 180)
            return;
          if (p.v.ypr[2] > 180 || p.v.ypr[2] < - 180)
            return;
        }

        Serial.print("event: ");
        Serial.print(p.v.event);
        Serial.print("\typr\t");
        Serial.print(p.v.ypr[0]);
        Serial.print("\t");
        Serial.print(p.v.ypr[1]);
        Serial.print("\t");
        Serial.println(p.v.ypr[2]);
    }
}
