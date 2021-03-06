// Copyright 2014 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef FXJS_CJS_OBJECT_H_
#define FXJS_CJS_OBJECT_H_

#include <memory>

#include "fpdfsdk/fsdk_define.h"
#include "fxjs/cjs_embedobj.h"
#include "fxjs/cjs_runtime.h"
#include "fxjs/fxjs_v8.h"

struct JSConstSpec {
  enum Type { Number = 0, String = 1 };

  const char* pName;
  Type eType;
  double number;
  const char* pStr;
};

struct JSPropertySpec {
  const char* pName;
  v8::AccessorGetterCallback pPropGet;
  v8::AccessorSetterCallback pPropPut;
};

struct JSMethodSpec {
  const char* pName;
  v8::FunctionCallback pMethodCall;
};

class CJS_Object {
 public:
  static void DefineConsts(CFXJS_Engine* pEngine,
                           int objId,
                           const JSConstSpec consts[],
                           size_t count);
  static void DefineProps(CFXJS_Engine* pEngine,
                          int objId,
                          const JSPropertySpec props[],
                          size_t count);
  static void DefineMethods(CFXJS_Engine* pEngine,
                            int objId,
                            const JSMethodSpec methods[],
                            size_t count);

  explicit CJS_Object(v8::Local<v8::Object> pObject);
  virtual ~CJS_Object();

  virtual void InitInstance(IJS_Runtime* pIRuntime);

  v8::Local<v8::Object> ToV8Object() { return m_pV8Object.Get(m_pIsolate); }

  // Takes ownership of |pObj|.
  void SetEmbedObject(CJS_EmbedObj* pObj) { m_pEmbedObj.reset(pObj); }
  CJS_EmbedObj* GetEmbedObject() const { return m_pEmbedObj.get(); }

  v8::Isolate* GetIsolate() const { return m_pIsolate; }

 protected:
  std::unique_ptr<CJS_EmbedObj> m_pEmbedObj;
  v8::Global<v8::Object> m_pV8Object;
  v8::Isolate* m_pIsolate;
};

#endif  // FXJS_CJS_OBJECT_H_
