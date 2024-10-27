cmake_minimum_required(VERSION 3.25)
project(tanslator_space_grpc_service)

set(CMAKE_CXX_STANDARD 17)

find_package(gRPC REQUIRED)
find_package(Protobuf REQUIRED)

include_directories(proto/out/services proto/out/messages)

# Генерируем исполняемые файлы для клиента и сервера
add_executable(translator_space_grpc_service main.cpp proto/out/messages/main.pb.cc proto/out/services/main.grpc.pb.cc)

# Линковка с gRPC и protobuf для сервера и клиента
target_link_libraries(translator_space_grpc_service gRPC::grpc++ protobuf::libprotobuf)
