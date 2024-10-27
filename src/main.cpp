#include <iostream>
#include <grpcpp/grpcpp.h>
#include "proto/out/services/main.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using mypackage::MyService;
using mypackage::HelloRequest;
using mypackage::HelloResponse;

class MyServiceImpl final : public MyService::Service {
public:
    Status SayHello(ServerContext* context, const HelloRequest* request, HelloResponse* response) override {
        std::string prefix("Hello ");
        response->set_message(prefix + request->name());
        return Status::OK;
    }
};

void RunServer() {
    std::string server_address("0.0.0.0:50051");
    MyServiceImpl service;

    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Сервер запущен на " << server_address << std::endl;
    server->Wait();
}

int main() {
    RunServer();
    return 0;
}