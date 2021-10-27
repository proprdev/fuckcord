#include "../include/misc.hpp"

std::string referer(std::string guild_id, std::string channel_id) {
   return "referer: https://discord.com/channels/" + guild_id + "/" + channel_id;
}

std::string data(std::string content) {
    return "{\"content\": \"" + content + "\"}";
}

std::string authorization(std::string token) {
    return "authorization: " + token;
}

std::string post_message_url(std::string channel_id) {
    return "https://discord.com/api/v9/channels/" + channel_id;
}

std::string get_message_url(std::string channel_id, std::string limit) {
    return post_message_url(channel_id) + "/messages?limit=" + limit;
}

size_t write_data(char *ptr, size_t size, size_t nmemb, void *userdata) {
    std::ostringstream *stream = (std::ostringstream*)userdata;
    size_t count = size * nmemb;
    stream->write(ptr, count);
    return count;
}