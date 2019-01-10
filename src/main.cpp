#include <napi.h>

// create overlay function
std::string CreateOverlay (std::string buffer, int pid) {
  
  // ADD CODE HERE

  return buffer;
}

// remove overlay function
int RemoveOverlay (int pid) {
  
  // ADD CODE HERE

  return pid;
}

// Create overlay wrapper
Napi::Value Create(const Napi::CallbackInfo& info) {
  // add args list in a variable
  Napi::Env env = info.Env();

  // if args list is less than 2, show an error
  if (info.Length() < 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  // if arg type is bad, show an error
  if (!info[0].IsString() || !info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  // set args in a variable
  std::string buffer = info[0].As<Napi::String>();
  int pid = info[1].As<Napi::Number>();
  
  // Execute the fuction and return the value
  return Napi::String::New(env, CreateOverlay(buffer, pid));
}

// Remove overlay wrapper
Napi::Value Remove(const Napi::CallbackInfo& info) {
  // add args in a variable
  Napi::Env env = info.Env();

  // if args list is less than 1, show an error
  if (info.Length() < 1) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  // if arg type is bad, show an error
  if (!info[0].IsNumber()) {
    Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  // set args in a variable
  int pid = info[0].As<Napi::Number>();

  // Execute the fuction and return the value
  return Napi::Number::New(env, RemoveOverlay(pid));
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  // Export "create" function
  exports.Set(Napi::String::New(env, "create"), Napi::Function::New(env, Create));
  // Export "remove" function
  exports.Set(Napi::String::New(env, "remove"), Napi::Function::New(env, Remove));
  return exports;
}

// Export for node
NODE_API_MODULE(addon, Init)