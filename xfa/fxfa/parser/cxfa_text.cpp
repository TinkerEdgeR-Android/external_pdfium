// Copyright 2017 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#include "xfa/fxfa/parser/cxfa_text.h"

#include "fxjs/xfa/cjx_text.h"
#include "third_party/base/ptr_util.h"

namespace {

const CXFA_Node::AttributeData kAttributeData[] = {
    {XFA_Attribute::Id, XFA_AttributeType::CData, nullptr},
    {XFA_Attribute::Name, XFA_AttributeType::CData, nullptr},
    {XFA_Attribute::Rid, XFA_AttributeType::CData, nullptr},
    {XFA_Attribute::Use, XFA_AttributeType::CData, nullptr},
    {XFA_Attribute::MaxChars, XFA_AttributeType::Integer, (void*)0},
    {XFA_Attribute::Usehref, XFA_AttributeType::CData, nullptr},
    {XFA_Attribute::Unknown, XFA_AttributeType::Integer, nullptr}};

constexpr wchar_t kName[] = L"text";

}  // namespace

CXFA_Text::CXFA_Text(CXFA_Document* doc, XFA_PacketType packet)
    : CXFA_Node(doc,
                packet,
                (XFA_XDPPACKET_SourceSet | XFA_XDPPACKET_Template |
                 XFA_XDPPACKET_Form),
                XFA_ObjectType::ContentNode,
                XFA_Element::Text,
                nullptr,
                kAttributeData,
                kName,
                pdfium::MakeUnique<CJX_Text>(this)) {}

CXFA_Text::~CXFA_Text() {}

WideString CXFA_Text::GetContent() {
  return JSObject()->GetContent(false);
}
