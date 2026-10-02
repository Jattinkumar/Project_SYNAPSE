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
        uint8_t payload_length = 5;
        uint8_t message[5] = {'H','E','L','P','!'};
        uint16_t hopCount = 10;
        uint8_t ttl = 10;
    };
    #pragma pack(pop)
    mypacket packet1;

    // we want to see the raw values and the raw memory addresses of the bytes, now packet is stored somewhere we want to track every byte 
    uint8_t *byte_ptr = reinterpret_cast<uint8_t*>(&packet1);
    for(size_t i = 0; i < sizeof(packet1); i++)
    {
        cout << "Offset [" << i << "] | Addr: " << (void*)(byte_ptr + i) 
             << " | Value (Dec): " << (int)*(byte_ptr + i) << endl;
    }
        cout << "-----------------------------" << endl;


  
    // checksum part
    uint16_t manual_chain=0;
    for(int i=0;i<5;i++)
    {
        manual_chain=manual_chain ^ packet1.message[i];
    }
    int final_message = manual_chain ^ our_key;
    cout << "[*] Pack physical size in RAM: " << sizeof(packet1) << " Bytes" << endl;
    cout << "final output: " << final_message << endl;

    cout<< " write you message: "<<endl;
    // how we would actuclly take char basically string into array of string  


    return 0;
}