#ifndef NETWORKING_HPP
#define NETWORKING_HPP

#include <curl/curl.h>
#include <string>
#include "../include/misc.hpp"

void sendMessage(std::string token, std::string guild_id, std::string channel_id, std::string content);
std::string getMessages(std::string token, std::string guild_id, std::string channel_id, std::string limit = "50");

#endif