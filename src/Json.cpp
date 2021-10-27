#include "../include/Json.hpp"

std::string getContent(std::string data) {
    if (!data.empty()) {
        nlohmann::json jsonData = nlohmann::json::parse(data.substr(1, data.size() - 2).c_str());
        return jsonData["content"];
    } else
        return "COCK";
}