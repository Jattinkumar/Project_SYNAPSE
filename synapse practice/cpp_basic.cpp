#include<iostream>
using namespace std;
int main()
{
    struct packet
    {
        unsigned short device_id = 100; /*100 is just for example*/
        unsigned char device_status = 0;      /*just for refrencing*/
        unsigned char payload[5]={'H','E','L','P','!'};
        unsigned char checksum=0;
    };
    packet mypacket;
    unsigned char* byte_ptr=(unsigned char*)&mypacket;
    cout<<"--- SYNAPSE WORKING ---\n";
    cout<<"Size taken by packet in RAM: "<<sizeof(mypacket)<<" Bytes"<<endl;
    cout<<"[*] First index or first value at 0: "<<(int)byte_ptr[0]<<"\n"<<endl;
    cout<<"[*] First index or first value at 2: "<<(int)byte_ptr[2]<<"\n"<<endl;
    cout<<"[*] First index or first value at 3: "<<(int)byte_ptr[3]<<"\n"<<endl;

    return 0;
}