#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>

class ConfigManager {
private:
    std::map<std::string, std::string> config;
    std::string file_path = "design_patterns/singleton/config.txt";
    static int instance_count;

    ConfigManager() {
        instance_count++;
        std::cout << "[SINGLETON] Creando instancia #" << instance_count << std::endl;
        loadConfig();
    }

    void loadConfig() {
        std::ifstream file(file_path);
        if (!file.is_open()) {
            std::cerr << "[ERROR] No se pudo abrir " << file_path << std::endl;
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            if (line.empty()) continue;
            
            size_t pos = line.find('=');
            if (pos != std::string::npos) {
                std::string key = line.substr(0, pos);
                std::string value = line.substr(pos + 1);
                config[key] = value;
            }
        }
        std::cout << "[CONFIG] Cargadas " << config.size() << " configuraciones" << std::endl;
    }

public:
    ConfigManager(const ConfigManager&) = delete;
    ConfigManager& operator=(const ConfigManager&) = delete;

    static ConfigManager& getInstance() {
        static ConfigManager instance;
        std::cout << "[SINGLETON] Retornando instancia existente (Total creadas: " 
                  << instance_count << ")" << std::endl;
        return instance;
    }

    std::string get(const std::string& key, const std::string& default_value = "") {
        auto it = config.find(key);
        if (it != config.end()) {
            return it->second;
        }
        return default_value;
    }
};

int ConfigManager::instance_count = 0;

int main() {
    std::cout << "\n=== Primer acceso ===" << std::endl;
    auto& config1 = ConfigManager::getInstance();
    std::cout << "db_host: " << config1.get("db_host") << std::endl;
    std::cout << "db_user: " << config1.get("db_user") << std::endl;

    std::cout << "\n=== Segundo acceso ===" << std::endl;
    auto& config2 = ConfigManager::getInstance();
    std::cout << "app_name: " << config2.get("app_name") << std::endl;

    std::cout << "\n=== Verificación ===" << std::endl;
    std::cout << "config1 es config2: " << (&config1 == &config2 ? "true" : "false") << std::endl;
    std::cout << "Dirección config1: " << &config1 << std::endl;
    std::cout << "Dirección config2: " << &config2 << std::endl;

    return 0;
}