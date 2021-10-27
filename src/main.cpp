#include "../include/main.hpp"

int main(int argc, char **argv) {

    std::ifstream tokenFile("token.txt");
    std::string token;

    if (tokenFile.is_open()) {
        tokenFile >> token;
        tokenFile.close();

        std::cout << "Enter a guild ID: ";
        std::string guild_id;
        std::cin >> guild_id;
        std::cout << "Enter a channel ID: ";
        std::string channel_id;
        std::cin >> channel_id;

        std::cout << getContent(getMessages(token, guild_id, channel_id, "1")) << std::endl;
    } else
        std::cout << "well shit fucked up";
    
    return 0;
}