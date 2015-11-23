
// ExampleDSPView.h : CExampleDSPView ��Ľӿ�
//

#pragma once


class CExampleDSPView : public CView
{
protected: // �������л�����
	CExampleDSPView();
	DECLARE_DYNCREATE(CExampleDSPView)

// ����
public:
	CExampleDSPDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CExampleDSPView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
private:
	CString	m_ImageName;//ͼ����
	// �ڴ��л���ͼ��
	void PreDrawImage(void);
	Bitmap* m_pBitmap;
};

#ifndef _DEBUG  // ExampleDSPView.cpp �еĵ��԰汾
inline CExampleDSPDoc* CExampleDSPView::GetDocument() const
   { return reinterpret_cast<CExampleDSPDoc*>(m_pDocument); }
#endif

