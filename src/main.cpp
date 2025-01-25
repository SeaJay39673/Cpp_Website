/**
 * @file main.cpp
 * @author Christopher Edmunds
 * @brief Launch point for a C++ based website
 * @date 2025-01-23
 *
 */
#include "oatpp/network/Server.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include "AppComponent.hpp"
#include "controller/MyController.hpp"

void run();

int main(int args, char **argv)
{
    oatpp::base::Environment::init();

    run();

    oatpp::base::Environment::destroy();

    return 0;
}

void run()
{
    AppComponent components;

    OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);

    auto myController = std::make_shared<MyController>();
    router->addController(myController);

    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, connectionHandler);
    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, connectionProvider);

    oatpp::network::Server server(connectionProvider, connectionHandler);

    OATPP_LOGI("Cpp_Website", "Server running on port %s", connectionProvider->getProperty("port").getData());

    server.run();
}