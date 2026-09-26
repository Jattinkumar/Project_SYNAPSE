#include<iostream>
#include<cstdint>
using namespace std;

int main()
{
    
    uint16_t our_key = 8699;
    #pragma pack(push,1)
    struct mypacket
    {
        uint16_t deviceId = 7868;
        uint8_t deviceStatus = 0;
        uint8_t message[5] = {'H','E','L','P','!'};
        uint16_t hopCount = 10;
    };
    #pragma pack(pop)
    
    mypacket packet1;
    uint16_t manual_chain=0;
    for(int i=0;i<5;i++)
    {
        manual_chain=manual_chain ^ packet1.message[i];
    }
    int final_message = manual_chain^our_key;
    cout << "[*] Pack physical size in RAM: " << sizeof(packet1) << " Bytes" << endl;
    cout << "final output: " << final_message << endl;
    return 0;
}