#include <iostream>

#include "simple_resp.h"

int main()
{
    simple_resp::decoder dec;
    std::string input("*3\r\n$3\r\nSET\r\n$1\r\na\r\n$1\r\nb\r\n*3\r\n$3\r\nSET\r\n$1\r\na\r\n$1\r\nc\r\n");
    simple_resp::decode_context ctx([](std::vector<std::string>& result){

            std::cout << "decode OK" << std::endl;
            for (const auto &c : result) {
            std::cout << c << " ";
            }
            std::cout << std::endl;
            });
    ctx.append_new_buffer(input);

    dec.decode(ctx);
    return 0;
}
