#include <iostream>
#include <logger.hpp>

int main() {
    Logger *log = new Logger("debug");
    auto logger = log->return_logger();
    logger->info("Hello from Bojack!");

    return 0;
}