
// ExampleDSPView.cpp : CExampleDSPView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ExampleDSP.h"
#endif

#include "ExampleDSPDoc.h"
#include "ExampleDSPView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExampleDSPView

IMPLEMENT_DYNCREATE(CExampleDSPView, CView)

BEGIN_MESSAGE_MAP(CExampleDSPView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CExampleDSPView ����/����

CExampleDSPView::CExampleDSPView()
{
	// TODO: �ڴ˴���ӹ������

}

CExampleDSPView::~CExampleDSPView()
{
}

BOOL CExampleDSPView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExampleDSPView ����

void CExampleDSPView::OnDraw(CDC* /*pDC*/)
{
	CExampleDSPDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CExampleDSPView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CExampleDSPView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CExampleDSPView ���

#ifdef _DEBUG
void CExampleDSPView::AssertValid() const
{
	CView::AssertValid();
}

void CExampleDSPView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExampleDSPDoc* CExampleDSPView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExampleDSPDoc)));
	return (CExampleDSPDoc*)m_pDocument;
}
#endif //_DEBUG


// CExampleDSPView ��Ϣ�������
