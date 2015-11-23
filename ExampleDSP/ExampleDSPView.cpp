
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
	ON_COMMAND(ID_FILE_OPEN, &CExampleDSPView::OnFileOpen)
END_MESSAGE_MAP()

// CExampleDSPView ����/����

CExampleDSPView::CExampleDSPView()
{
	// TODO: �ڴ˴���ӹ������
	m_pBitmap = NULL;

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

void CExampleDSPView::OnDraw(CDC* pDC)
{
	CExampleDSPDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	//CRect rect;   
	//GetClientRect(&rect); //��ȡ�ͻ��������Ϣ
	if(m_pBitmap) {
		Graphics graph(pDC->GetSafeHdc());//pDC ���Ǻ��� OnDraw()�еĲ���   
		graph.DrawImage((Image*)m_pBitmap,0,0,m_pBitmap->GetWidth(),m_pBitmap->GetHeight()); //�ڿͻ������л���ͼ��   
	}

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


void CExampleDSPView::OnFileOpen()
{
	// TODO: �ڴ���������������
	CFileDialog dlg(true, NULL, L"", 
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_NOCHANGEDIR, 
		L"����ͼ���ļ�(*.bmp; *.jpg)|*.bmp; *.jpg|�����ļ�(*.*)|*.*||");
	if (dlg.DoModal() == IDOK)
	{
		m_ImageName = dlg.GetFileName();
		PreDrawImage();
		Invalidate();//ˢ��
	}

}


// �ڴ��л���ͼ��
void CExampleDSPView::PreDrawImage(void)
{
	Image image(m_ImageName);

	if(m_pBitmap)
		::delete m_pBitmap;

	m_pBitmap = ::new Bitmap(image.GetWidth(), image.GetHeight(), PixelFormat32bppARGB);
	Graphics* graph = Graphics::FromImage(m_pBitmap);

	graph->DrawImage(&image, 0, 0, image.GetWidth(), image.GetHeight());
	if(graph)
		delete graph;
}
