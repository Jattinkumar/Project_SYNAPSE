#include <iostream>
#include <vector>
#include <cstdint>

int main()
{
    std::vector<uint8_t>buffer(20,0);

    uint8_t* start_ptr=buffer.data();
    *start_ptr=89;
    *(start_ptr+1)=90;
    *(start_ptr+2)=91;
    std::cout<<"[+] starting address (index 0): "<<(void*)start_ptr<< std::endl;
    std::cout<<"[*] Value inside 1stbox: "<<(int)buffer[0]<<std::endl;
     std::cout<<"[*] Value inside 2ndbox: "<<(int)buffer[1]<<std::endl;
      std::cout<<"[*] Value inside 3rdbox: "<<(int)buffer[2]<<std::endl;
    std::cout<<"[+] jump 4 bytes ahead address: "<< (void*)(start_ptr +4)<< std::endl;
    return 0;
}