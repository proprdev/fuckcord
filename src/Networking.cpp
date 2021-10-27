#include "../include/Networking.hpp"

void sendMessage(std::string token, std::string guild_id, std::string channel_id, std::string content) {

    CURL *curl = curl_easy_init();

    if (curl) {
        struct curl_slist *list = NULL;

        const std::string message_content = data(content);
        const std::string url = post_message_url(channel_id);

        FILE *devnull = fopen("/dev/null", "w+");

        list = curl_slist_append(list, "accept: */*");
        list = curl_slist_append(list, authorization(token).c_str());
        list = curl_slist_append(list, "Content-Type: application/json");
        list = curl_slist_append(list, "origin: https://discord.com");
        list = curl_slist_append(list, referer(guild_id, channel_id).c_str());
        list = curl_slist_append(list, "sec-fetch-dest: empty");
        list = curl_slist_append(list, "sec-fetch-mode: cors");


        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_POST, 1);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, message_content.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, devnull);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(devnull);

    }
    
}

std::string getMessages(std::string token, std::string guild_id, std::string channel_id, std::string limit) {
    CURL *curl = curl_easy_init();

    if (curl) {
        struct curl_slist* list = NULL;

        const std::string url = get_message_url(channel_id, limit);

        std::ostringstream data;

        list = curl_slist_append(list, "accept: */*");
        list = curl_slist_append(list, authorization(token).c_str());
        list = curl_slist_append(list, referer(guild_id, channel_id).c_str());
        list = curl_slist_append(list, "sec-fetch-dest: empty");
        list = curl_slist_append(list, "sec-fetch-mode: cors");


        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPGET, 1);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        return data.str();
    }

    return NULL;

}
