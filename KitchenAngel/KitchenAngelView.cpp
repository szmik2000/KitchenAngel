
// KitchenAngelView.cpp : implementation of the CKitchenAngelView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "KitchenAngel.h"
#endif

#include "KitchenAngelDoc.h"
#include "KitchenAngelView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CKitchenAngelView

IMPLEMENT_DYNCREATE(CKitchenAngelView, CView)

BEGIN_MESSAGE_MAP(CKitchenAngelView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CKitchenAngelView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CKitchenAngelView construction/destruction

CKitchenAngelView::CKitchenAngelView() noexcept
{
	// TODO: add construction code here

}

CKitchenAngelView::~CKitchenAngelView()
{
}

BOOL CKitchenAngelView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CKitchenAngelView drawing

void CKitchenAngelView::OnDraw(CDC* /*pDC*/)
{
	CKitchenAngelDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CKitchenAngelView printing


void CKitchenAngelView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CKitchenAngelView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CKitchenAngelView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CKitchenAngelView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CKitchenAngelView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CKitchenAngelView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CKitchenAngelView diagnostics

#ifdef _DEBUG
void CKitchenAngelView::AssertValid() const
{
	CView::AssertValid();
}

void CKitchenAngelView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CKitchenAngelDoc* CKitchenAngelView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKitchenAngelDoc)));
	return (CKitchenAngelDoc*)m_pDocument;
}
#endif //_DEBUG


// CKitchenAngelView message handlers
