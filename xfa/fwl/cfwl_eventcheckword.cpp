// Copyright 2016 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#include "xfa/fwl/cfwl_eventcheckword.h"

CFWL_EventCheckWord::CFWL_EventCheckWord(CFWL_Widget* pSrcTarget)
    : CFWL_Event(CFWL_Event::Type::CheckWord, pSrcTarget) {}

CFWL_EventCheckWord::~CFWL_EventCheckWord() {}
