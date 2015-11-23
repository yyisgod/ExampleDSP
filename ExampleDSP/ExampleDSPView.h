
// ExampleDSPView.h : CExampleDSPView 类的接口
//

#pragma once


class CExampleDSPView : public CView
{
protected: // 仅从序列化创建
	CExampleDSPView();
	DECLARE_DYNCREATE(CExampleDSPView)

// 特性
public:
	CExampleDSPDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CExampleDSPView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
private:
	CString	m_ImageName;//图像名
	// 内存中绘制图像
	void PreDrawImage(void);
	Bitmap* m_pBitmap;
};

#ifndef _DEBUG  // ExampleDSPView.cpp 中的调试版本
inline CExampleDSPDoc* CExampleDSPView::GetDocument() const
   { return reinterpret_cast<CExampleDSPDoc*>(m_pDocument); }
#endif

