#ifndef MISC_CPP
#define MISC_CPP

#include <iostream>
#include <string>
#include <sstream>

std::string referer(std::string guild_id, std::string channel_id);

std::string data(std::string content);

std::string authorization(std::string token);

std::string post_message_url(std::string channel_id);

std::string get_message_url(std::string channel_id, std::string limit);

size_t write_data(char *ptr, size_t size, size_t nmemb, void *userdata);

#endif