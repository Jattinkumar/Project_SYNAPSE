#include<iostream>
#include<cstdint>
using namespace std;

int main()
{
    struct mypacket
    {
        uint16_t deviceId = 7868;
        uint8_t deviceStatus = 0;
        uint8_t message[5] = {'H','E','L','P','!'};
        uint16_t hopCount = 10;
        uint8_t checksum = 0;
    };
    mypacket packet1;
    for(int i = 0; i<5; i++)
        cout<<"[*] Value that got stored in position ["<<i+1<<"]: "<< (int)packet1.message[i]<<"\n"<<endl;
    return 0;
}