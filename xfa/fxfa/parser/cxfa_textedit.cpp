// Copyright 2017 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#include "xfa/fxfa/parser/cxfa_textedit.h"

#include "fxjs/xfa/cjx_textedit.h"
#include "third_party/base/ptr_util.h"

namespace {

const CXFA_Node::PropertyData kPropertyData[] = {{XFA_Element::Margin, 1, 0},
                                                 {XFA_Element::Border, 1, 0},
                                                 {XFA_Element::Comb, 1, 0},
                                                 {XFA_Element::Extras, 1, 0},
                                                 {XFA_Element::Unknown, 0, 0}};
const CXFA_Node::AttributeData kAttributeData[] = {
    {XFA_Attribute::Id, XFA_AttributeType::CData, nullptr},
    {XFA_Attribute::VScrollPolicy, XFA_AttributeType::Enum,
     (void*)XFA_AttributeEnum::Auto},
    {XFA_Attribute::Use, XFA_AttributeType::CData, nullptr},
    {XFA_Attribute::AllowRichText, XFA_AttributeType::Boolean, (void*)0},
    {XFA_Attribute::MultiLine, XFA_AttributeType::Boolean, (void*)0},
    {XFA_Attribute::Usehref, XFA_AttributeType::CData, nullptr},
    {XFA_Attribute::HScrollPolicy, XFA_AttributeType::Enum,
     (void*)XFA_AttributeEnum::Auto},
    {XFA_Attribute::Unknown, XFA_AttributeType::Integer, nullptr}};

constexpr wchar_t kName[] = L"textEdit";

}  // namespace

CXFA_TextEdit::CXFA_TextEdit(CXFA_Document* doc, XFA_PacketType packet)
    : CXFA_Node(doc,
                packet,
                (XFA_XDPPACKET_Template | XFA_XDPPACKET_Form),
                XFA_ObjectType::Node,
                XFA_Element::TextEdit,
                kPropertyData,
                kAttributeData,
                kName,
                pdfium::MakeUnique<CJX_TextEdit>(this)) {}

CXFA_TextEdit::~CXFA_TextEdit() {}
