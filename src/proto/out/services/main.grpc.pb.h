// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: main.proto
#ifndef GRPC_main_2eproto__INCLUDED
#define GRPC_main_2eproto__INCLUDED

#include "main.pb.h"

#include <functional>
#include <grpcpp/generic/async_generic_service.h>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/client_context.h>
#include <grpcpp/completion_queue.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/rpc_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/support/stub_options.h>
#include <grpcpp/support/sync_stream.h>

namespace mypackage {

// gRPC-сервис
class MyService final {
 public:
  static constexpr char const* service_full_name() {
    return "mypackage.MyService";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status SayHello(::grpc::ClientContext* context, const ::mypackage::HelloRequest& request, ::mypackage::HelloResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::mypackage::HelloResponse>> AsyncSayHello(::grpc::ClientContext* context, const ::mypackage::HelloRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::mypackage::HelloResponse>>(AsyncSayHelloRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::mypackage::HelloResponse>> PrepareAsyncSayHello(::grpc::ClientContext* context, const ::mypackage::HelloRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::mypackage::HelloResponse>>(PrepareAsyncSayHelloRaw(context, request, cq));
    }
    class async_interface {
     public:
      virtual ~async_interface() {}
      virtual void SayHello(::grpc::ClientContext* context, const ::mypackage::HelloRequest* request, ::mypackage::HelloResponse* response, std::function<void(::grpc::Status)>) = 0;
      virtual void SayHello(::grpc::ClientContext* context, const ::mypackage::HelloRequest* request, ::mypackage::HelloResponse* response, ::grpc::ClientUnaryReactor* reactor) = 0;
    };
    typedef class async_interface experimental_async_interface;
    virtual class async_interface* async() { return nullptr; }
    class async_interface* experimental_async() { return async(); }
   private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::mypackage::HelloResponse>* AsyncSayHelloRaw(::grpc::ClientContext* context, const ::mypackage::HelloRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::mypackage::HelloResponse>* PrepareAsyncSayHelloRaw(::grpc::ClientContext* context, const ::mypackage::HelloRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    ::grpc::Status SayHello(::grpc::ClientContext* context, const ::mypackage::HelloRequest& request, ::mypackage::HelloResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::mypackage::HelloResponse>> AsyncSayHello(::grpc::ClientContext* context, const ::mypackage::HelloRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::mypackage::HelloResponse>>(AsyncSayHelloRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::mypackage::HelloResponse>> PrepareAsyncSayHello(::grpc::ClientContext* context, const ::mypackage::HelloRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::mypackage::HelloResponse>>(PrepareAsyncSayHelloRaw(context, request, cq));
    }
    class async final :
      public StubInterface::async_interface {
     public:
      void SayHello(::grpc::ClientContext* context, const ::mypackage::HelloRequest* request, ::mypackage::HelloResponse* response, std::function<void(::grpc::Status)>) override;
      void SayHello(::grpc::ClientContext* context, const ::mypackage::HelloRequest* request, ::mypackage::HelloResponse* response, ::grpc::ClientUnaryReactor* reactor) override;
     private:
      friend class Stub;
      explicit async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class async* async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::mypackage::HelloResponse>* AsyncSayHelloRaw(::grpc::ClientContext* context, const ::mypackage::HelloRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::mypackage::HelloResponse>* PrepareAsyncSayHelloRaw(::grpc::ClientContext* context, const ::mypackage::HelloRequest& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_SayHello_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status SayHello(::grpc::ServerContext* context, const ::mypackage::HelloRequest* request, ::mypackage::HelloResponse* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_SayHello : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_SayHello() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_SayHello() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SayHello(::grpc::ServerContext* /*context*/, const ::mypackage::HelloRequest* /*request*/, ::mypackage::HelloResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSayHello(::grpc::ServerContext* context, ::mypackage::HelloRequest* request, ::grpc::ServerAsyncResponseWriter< ::mypackage::HelloResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_SayHello<Service > AsyncService;
  template <class BaseClass>
  class WithCallbackMethod_SayHello : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_SayHello() {
      ::grpc::Service::MarkMethodCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::mypackage::HelloRequest, ::mypackage::HelloResponse>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::mypackage::HelloRequest* request, ::mypackage::HelloResponse* response) { return this->SayHello(context, request, response); }));}
    void SetMessageAllocatorFor_SayHello(
        ::grpc::MessageAllocator< ::mypackage::HelloRequest, ::mypackage::HelloResponse>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::mypackage::HelloRequest, ::mypackage::HelloResponse>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_SayHello() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SayHello(::grpc::ServerContext* /*context*/, const ::mypackage::HelloRequest* /*request*/, ::mypackage::HelloResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* SayHello(
      ::grpc::CallbackServerContext* /*context*/, const ::mypackage::HelloRequest* /*request*/, ::mypackage::HelloResponse* /*response*/)  { return nullptr; }
  };
  typedef WithCallbackMethod_SayHello<Service > CallbackService;
  typedef CallbackService ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_SayHello : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_SayHello() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_SayHello() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SayHello(::grpc::ServerContext* /*context*/, const ::mypackage::HelloRequest* /*request*/, ::mypackage::HelloResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_SayHello : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_SayHello() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_SayHello() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SayHello(::grpc::ServerContext* /*context*/, const ::mypackage::HelloRequest* /*request*/, ::mypackage::HelloResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSayHello(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_SayHello : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_SayHello() {
      ::grpc::Service::MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->SayHello(context, request, response); }));
    }
    ~WithRawCallbackMethod_SayHello() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SayHello(::grpc::ServerContext* /*context*/, const ::mypackage::HelloRequest* /*request*/, ::mypackage::HelloResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* SayHello(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_SayHello : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_SayHello() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::mypackage::HelloRequest, ::mypackage::HelloResponse>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::mypackage::HelloRequest, ::mypackage::HelloResponse>* streamer) {
                       return this->StreamedSayHello(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_SayHello() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status SayHello(::grpc::ServerContext* /*context*/, const ::mypackage::HelloRequest* /*request*/, ::mypackage::HelloResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedSayHello(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::mypackage::HelloRequest,::mypackage::HelloResponse>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_SayHello<Service > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_SayHello<Service > StreamedService;
};

}  // namespace mypackage


#endif  // GRPC_main_2eproto__INCLUDED
