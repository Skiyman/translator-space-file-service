FROM debian:bookworm

RUN apt-get update && apt-get install -y \
  autoconf \
  automake \
  build-essential \
  cmake \
  curl \
  g++ \
  make \
  protobuf-compiler \
  libgrpc++-dev \
  protobuf-compiler-grpc \
  && apt-get clean

COPY . /usr/src/translator-space-grpc-service
RUN mkdir /usr/src/translator-space-grpc-service/src/build
WORKDIR /usr/src/translator-space-grpc-service/src/build

RUN protoc -I=./src/proto/ --cpp_out=src/proto/out/messages/ \
                            --grpc_out=src/proto/out/services/ \
                            --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` \
                            src/proto/main.proto
RUN cmake ..
RUN make
RUN ls -l /usr/src/translator-space-grpc-service/src/build

CMD ["./translator_space_grpc_service"]

LABEL Name=tanslatorspacegrpcservice Version=0.0.1
