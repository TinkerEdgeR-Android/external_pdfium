// Copyright 2014 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef XFA_FXFA_CXFA_FFPUSHBUTTON_H_
#define XFA_FXFA_CXFA_FFPUSHBUTTON_H_

#include <memory>

#include "xfa/fxfa/cxfa_fffield.h"

#define XFA_FWL_PSBSTYLEEXT_HiliteInverted (1L << 0)
#define XFA_FWL_PSBSTYLEEXT_HilitePush (1L << 1)
#define XFA_FWL_PSBSTYLEEXT_HiliteOutLine (1L << 2)

class CXFA_TextProvider;

class CXFA_FFPushButton : public CXFA_FFField {
 public:
  explicit CXFA_FFPushButton(CXFA_Node* pNode);
  ~CXFA_FFPushButton() override;

  // CXFA_FFField
  void RenderWidget(CXFA_Graphics* pGS,
                    const CFX_Matrix& matrix,
                    uint32_t dwStatus) override;
  bool LoadWidget() override;
  void UnloadWidget() override;
  bool PerformLayout() override;
  void UpdateWidgetProperty() override;
  void OnProcessMessage(CFWL_Message* pMessage) override;
  void OnProcessEvent(CFWL_Event* pEvent) override;
  void OnDrawWidget(CXFA_Graphics* pGraphics,
                    const CFX_Matrix& matrix) override;
  FormFieldType GetFormFieldType() override;

 private:
  void LoadHighlightCaption();
  void LayoutHighlightCaption();
  void RenderHighlightCaption(CXFA_Graphics* pGS, CFX_Matrix* pMatrix);
  float GetLineWidth();
  FX_ARGB GetLineColor();
  FX_ARGB GetFillColor();

  std::unique_ptr<CXFA_TextLayout> m_pRolloverTextLayout;
  std::unique_ptr<CXFA_TextLayout> m_pDownTextLayout;
  std::unique_ptr<CXFA_TextProvider> m_pRollProvider;
  std::unique_ptr<CXFA_TextProvider> m_pDownProvider;
  IFWL_WidgetDelegate* m_pOldDelegate;
};

#endif  // XFA_FXFA_CXFA_FFPUSHBUTTON_H_
