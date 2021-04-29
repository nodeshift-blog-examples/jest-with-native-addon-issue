#include <assert.h>
#include <node_api.h>

static napi_value Method(napi_env env, napi_callback_info info) {
  napi_status status;
  napi_value world;
  status = napi_create_string_utf8(env, "world", 5, &world);
  assert(status == napi_ok);
  return world;
}

static napi_value ExceptionMethod(napi_env env, napi_callback_info info) {
   napi_throw_type_error(env, "code1", "type exception");
   return NULL;
}


#define DECLARE_NAPI_METHOD(name, func)                                        \
  { name, 0, func, 0, 0, 0, napi_default, 0 }

static napi_value Init(napi_env env, napi_value exports) {
  napi_status status;
  napi_property_descriptor desc = DECLARE_NAPI_METHOD("hello", Method);
  napi_property_descriptor desc2 = DECLARE_NAPI_METHOD("exception", ExceptionMethod);
  status = napi_define_properties(env, exports, 1, &desc);
  status = napi_define_properties(env, exports, 1, &desc2);
  assert(status == napi_ok);
  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)

