#include <iostream>
#include <string>


class CompressionStrategy {
public:
    virtual void compress(const std::string& data) = 0;
    virtual ~CompressionStrategy() = default;
};

class ZipCompression : public CompressionStrategy {
public:
    void compress(const std::string& data) override {
        std::cout << "ZIP compressing " << data << std::endl;
    }
};

class RarCompression : public CompressionStrategy {
public:
    void compress(const std::string& data) override {
        std::cout << "RAR compressing " << data << std::endl;
    }
};

class Compressor {
private:
    CompressionStrategy* strategy;

public:
    Compressor(CompressionStrategy* s) : strategy(s) {}

    void setStrategy(CompressionStrategy* s) {
        strategy = s;
    }

    void compress(const std::string& data) {
        strategy->compress(data);
    }
};

int main() {
    ZipCompression zip;
    RarCompression rar;

    Compressor compressor(&zip);
    compressor.compress("file.txt");

    compressor.setStrategy(&rar);
    compressor.compress("file.txt");
}