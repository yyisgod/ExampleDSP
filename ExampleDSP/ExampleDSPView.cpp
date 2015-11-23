
// ExampleDSPView.cpp : CExampleDSPView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CExampleDSPView 构造/析构

CExampleDSPView::CExampleDSPView()
{
	// TODO: 在此处添加构造代码
	m_pBitmap = NULL;

}

CExampleDSPView::~CExampleDSPView()
{
}

BOOL CExampleDSPView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExampleDSPView 绘制

void CExampleDSPView::OnDraw(CDC* pDC)
{
	CExampleDSPDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	//CRect rect;   
	//GetClientRect(&rect); //获取客户区域的信息
	if(m_pBitmap) {
		Graphics graph(pDC->GetSafeHdc());//pDC 就是函数 OnDraw()中的参数   
		graph.DrawImage((Image*)m_pBitmap,0,0,m_pBitmap->GetWidth(),m_pBitmap->GetHeight()); //在客户区域中绘制图像   
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


// CExampleDSPView 诊断

#ifdef _DEBUG
void CExampleDSPView::AssertValid() const
{
	CView::AssertValid();
}

void CExampleDSPView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExampleDSPDoc* CExampleDSPView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExampleDSPDoc)));
	return (CExampleDSPDoc*)m_pDocument;
}
#endif //_DEBUG


// CExampleDSPView 消息处理程序


void CExampleDSPView::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog dlg(true, NULL, L"", 
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_NOCHANGEDIR, 
		L"所有图像文件(*.bmp; *.jpg)|*.bmp; *.jpg|所有文件(*.*)|*.*||");
	if (dlg.DoModal() == IDOK)
	{
		m_ImageName = dlg.GetFileName();
		PreDrawImage();
		Invalidate();//刷新
	}

}


// 内存中绘制图像
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


void CExampleDSPView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	static bool flag = false;
	static CPoint firstPoint;
	if(!flag) {//第一次按下
		firstPoint = point;
		
		//绘制初始点
		Graphics* graph = Graphics::FromImage(m_pBitmap);
		Pen pen(Color(255, 255, 0, 0));

	   // Initialize the variables that define the ellipse.
	   int x = point.x - 10;
	   int y = point.y - 10;
	   int width = 20;
	   int height = 20;

		// Draw the ellipse.
		graph->DrawEllipse(&pen, x, y, width, height);
		delete graph;
		Invalidate();
		flag = true;
	} else {
		//绘制矩阵，计算共生矩阵，绘制共生矩阵
		Graphics* graph = Graphics::FromImage(m_pBitmap);
		Pen pen(Color(255, 255, 0, 0));

		// Draw the ellipse.
		graph->DrawRectangle(&pen, firstPoint.x, firstPoint.y, point.x - firstPoint.x, point.y-firstPoint.y);
		delete graph;
		Invalidate();
		calculateGLCM(m_pBitmap,firstPoint,point);
		flag = false;
	}
	CView::OnLButtonDown(nFlags, point);
}


// //计算共生矩阵参数
std::vector<double> CExampleDSPView::calculateGLCM(Bitmap* pBitmap, CPoint firstPoint, CPoint secondPoint)
{
	return vector<double>();
}
