
// ImageProcessingDoc.cpp : CImageProcessingDoc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "ImageProcessing.h"
#endif

#include "ImageProcessingDoc.h"
#include <math.h>
#include <propkey.h>
#include "stdafx.h"
#include "ImageProcessing.h"
#include "ImageProcessingDoc.h"
#include "DownSampleDlg.h" // ��ȭ���� ����� ���� ��� ����
#include "UpSampleDlg.h"
#include "QuantizationDlg.h" 
#include "ConstantDlg.h" 
#include "StressTransformDlg.h" // ���� ���� ��ȭ���ڸ� ���� ��� ����
#include "Histogram.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CImageProcessingDoc

IMPLEMENT_DYNCREATE(CImageProcessingDoc, CDocument)

BEGIN_MESSAGE_MAP(CImageProcessingDoc, CDocument)
	ON_COMMAND(ID_SUM_CONSTANT, &CImageProcessingDoc::OnSumConstant)
	ON_COMMAND(ID_MUL_CONSTANT, &CImageProcessingDoc::OnMulConstant)
	ON_COMMAND(ID_SUB_CONSTANT, &CImageProcessingDoc::OnSubConstant)
	ON_COMMAND(ID_DIV_CONSTANT, &CImageProcessingDoc::OnDivConstant)
	ON_COMMAND(ID_AND_OPERATE, &CImageProcessingDoc::OnAndOperate)
	ON_COMMAND(ID_OR_OPERATE, &CImageProcessingDoc::OnOrOperate)
	ON_COMMAND(ID_XOR_OPERATE, &CImageProcessingDoc::OnXorOperate)
	ON_COMMAND(ID_brightandcontrast, &CImageProcessingDoc::Onbrightandcontrast)
	ON_COMMAND(ID_NEGA_TRANSFORM, &CImageProcessingDoc::OnNegaTransform)
	ON_COMMAND(ID_GAMMA_CORRECTION, &CImageProcessingDoc::OnGammaCorrection)
	ON_COMMAND(ID_BINARIZATION, &CImageProcessingDoc::OnBinarization)
	ON_COMMAND(ID_STRESS_TRANSFORM, &CImageProcessingDoc::OnStressTransform)
	ON_COMMAND(ID_HISTO_STRETCH, &CImageProcessingDoc::OnHistoStretch)
	ON_COMMAND(ID_HISTOGRAM, &CImageProcessingDoc::OnHistogram)
	ON_COMMAND(ID_HISTO_EQUAL, &CImageProcessingDoc::OnHistoEqual)
	ON_COMMAND(ID_HISTO_SPEC, &CImageProcessingDoc::OnHistoSpec)
	ON_COMMAND(ID_EMBOSSING, &CImageProcessingDoc::OnEmbossing)
	ON_COMMAND(ID_BLURR, &CImageProcessingDoc::OnBlurr)
	ON_COMMAND(ID_GAUSSIAN_FILTER, &CImageProcessingDoc::OnGaussianFilter)
	ON_COMMAND(ID_SHARPENING, &CImageProcessingDoc::OnSharpening)
	ON_COMMAND(ID_HPF_SHARP, &CImageProcessingDoc::OnHpfSharp)
	ON_COMMAND(ID_LPF_SHARP, &CImageProcessingDoc::OnLpfSharp)
	ON_COMMAND(ID_DIFF_OPERATOR_HOR, &CImageProcessingDoc::OnDiffOperatorHor)
	ON_COMMAND(ID_HOMOGEN_OPERATOR, &CImageProcessingDoc::OnHomogenOperator)
	ON_COMMAND(ID_MEDI, &CImageProcessingDoc::OnMedi)
	ON_COMMAND(ID_NEAREST, &CImageProcessingDoc::OnNearest)
	ON_COMMAND(ID_BILINEAR, &CImageProcessingDoc::OnBilinear)
	ON_COMMAND(ID_ROTATE30, &CImageProcessingDoc::OnRotate30)
	ON_COMMAND(ID_COFFEE_CUP, &CImageProcessingDoc::OnCoffeeCup)
	ON_COMMAND(ID_TRANSLATION, &CImageProcessingDoc::OnTranslation)
	ON_COMMAND(ID_MIRROR_HOR, &CImageProcessingDoc::OnMirrorHor)
END_MESSAGE_MAP()


// CImageProcessingDoc ����/�Ҹ�

CImageProcessingDoc::CImageProcessingDoc()
	: m_InputImage(0)
	, m_width(0)
	, m_height(0)
	, m_size(0)
	, m_OutputImage(NULL)
	, m_Re_width(0)
	, m_Re_height(0)
	, m_Re_size(0)
	, m_tempImage(NULL)
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CImageProcessingDoc::~CImageProcessingDoc()
{
}

BOOL CImageProcessingDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CImageProcessingDoc serialization

void CImageProcessingDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}

#ifdef SHARED_HANDLERS

// ����� �׸��� �����մϴ�.
void CImageProcessingDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// �˻� ó���⸦ �����մϴ�.
void CImageProcessingDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CImageProcessingDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CImageProcessingDoc ����

#ifdef _DEBUG
void CImageProcessingDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CImageProcessingDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CImageProcessingDoc ����


BOOL CImageProcessingDoc::OnOpenDocument(LPCTSTR lpszPathName)
{

	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	
      CFile File; // ���� ��ü ����

      File.Open(lpszPathName, CFile::modeRead | CFile::typeBinary);
      // ���� ���� ��ȭ���ڿ��� ������ ������ �����ϰ� �б� ��� ����

      // �� å������ ������ ũ�� 256*256, 512*512, 640*480���� ����Ѵ�.
      if(File.GetLength() == 256*256){ // RAW ������ ũ�� ����

      m_height = 256;
      m_width = 256;
   }
   else if(File.GetLength() == 512*512){ // RAW ������ ũ�� ����
      m_height = 512;
      m_width = 512;
   }
   else if(File.GetLength() == 640*480){ // RAW ������ ũ�� ����
      m_height = 480;
      m_width = 640;
   }
   else{
      AfxMessageBox(_T("Not Support Image Size")); // �ش� ũ�Ⱑ ���� ���
      return 0;
   }
      CSize sizeTotal;
   sizeTotal.cx = m_width;
   sizeTotal.cy = m_height;
   m_size = m_width * m_height; // ������ ũ�� ���

   m_InputImage = new unsigned char [m_size];
   // �Է� ������ ũ�⿡ �´� �޸� �Ҵ�

   for(int i = 0 ; i<m_size ; i++)
      m_InputImage[i] = 255; // �ʱ�ȭ
   File.Read(m_InputImage, m_size); // �Է� ���� ���� �б�
   File.Close(); // ���� �ݱ�

	return TRUE;
}


void CImageProcessingDoc::OnDownSampling()
{
	
   int i, j;
   CDownSampleDlg dlg;
   if(dlg.DoModal() == IDOK) // ��ȭ������ Ȱ��ȭ ����
   {
      m_Re_height = m_height / dlg.m_DownSampleRate;
      // ��� ������ ���� ���̸� ���
      m_Re_width = m_width / dlg.m_DownSampleRate;
      // ��� ������ ���� ���̸� ���
      m_Re_size = m_Re_height * m_Re_width;
      // ��� ������ ũ�⸦ ���

      m_OutputImage = new unsigned char [m_Re_size];     
      // ��� ������ ���� �޸� �Ҵ�

      for(i=0 ; i<m_Re_height ; i++){
       for(j=0 ; j<m_Re_width ; j++){
         m_OutputImage[i*m_Re_width + j]
          = m_InputImage[(i*dlg.m_DownSampleRate*m_width)+dlg.m_DownSampleRate*j];
                // ��� ������ ����
         }
     }
   }
}


void CImageProcessingDoc::OnUpSampling()
{
	 int i, j;
   
   CUpSampleDlg dlg;
   if(dlg.DoModal() == IDOK){ // DoModal ��ȭ������ Ȱ��ȭ ����
       m_Re_height = m_height * dlg.m_UpSampleRate;
       // Ȯ�� ������ ���� ���� ���
       m_Re_width = m_width * dlg.m_UpSampleRate;
       // Ȯ�� ������ ���� ���� ���
       m_Re_size = m_Re_height * m_Re_width;
       // Ȯ�� ������ ũ�� ���
       m_OutputImage = new unsigned char[m_Re_size];
       // Ȯ�� ������ ���� �޸� �Ҵ�

       for(i=0 ; i<m_Re_size ; i++)
           m_OutputImage[i] = 0; // �ʱ�ȭ

       for(i=0 ; i<m_height ; i++){
           for(j=0 ; j<m_width ; j++){
			   for (int k = 0; k <dlg.m_UpSampleRate; k++)
			   {
				   for (int b = 0; b < dlg.m_UpSampleRate; b++)
				   {
					   m_OutputImage[i*dlg.m_UpSampleRate*m_Re_width + k*m_Re_width + dlg.m_UpSampleRate*j+b]= m_InputImage[i*m_width + j];
				   }
			   }
             // m_OutputImage[i*dlg.m_UpSampleRate*m_Re_width + dlg.m_UpSampleRate*j]= m_InputImage[i*m_width + j];
           } // ���ġ�Ͽ� ���� Ȯ��
       }
   }
   
}


void CImageProcessingDoc::OnQuantization(void)
{
	CQuantizationDlg dlg;
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;
	m_OutputImage = new unsigned char[m_Re_size];

	if(dlg.DoModal() == IDOK)
	{
		int i, sb;
		sb = 8 - dlg.mQuantBit;
		for(i=0 ; i<m_size ; i++){
			m_OutputImage[i] = m_InputImage[i]>>sb<<sb;
		}
	}

}


void CImageProcessingDoc::OnSumConstant()
{
	CConstantDlg dlg; // ��� ���� �Է¹޴� ��ȭ����

   int i;

   m_Re_height = m_height;
   m_Re_width = m_width;
   m_Re_size = m_Re_height * m_Re_width;

   m_OutputImage = new unsigned char[m_Re_size];

   if(dlg.DoModal() == IDOK){
     for(i=0 ; i<m_size ; i++){
       if(m_InputImage[i] + dlg.m_Constant >= 255)
          m_OutputImage[i] = 255;
       // ��� ���� 255���� ũ�� 255 ���
       else
       m_OutputImage[i]=(unsigned char)(m_InputImage[i] + dlg.m_Constant);
       // ��� ���� ȭ�� ������ ����
     }
  }

}


void CImageProcessingDoc::OnMulConstant()
{
	CConstantDlg dlg;

   int i;

   m_Re_height = m_height;
   m_Re_width = m_width;
   m_Re_size = m_Re_height * m_Re_width;

   m_OutputImage = new unsigned char[m_Re_size];

   if(dlg.DoModal() == IDOK){
      for(i=0 ; i<m_size ; i++){
         if(m_InputImage[i] * dlg.m_Constant > 255)
                 m_OutputImage[i] = 255;
         // ���� ���� 255���� ũ�� 255�� ���
         else if(m_InputImage[i] * dlg.m_Constant < 0)
                 m_OutputImage[i] = 0;
         // ���� ���� 0���� ������ 0�� ���
         else
            m_OutputImage [i] 
                  = (unsigned char)(m_InputImage[i] * dlg.m_Constant);
         // ��� ���� ȭ�� �� ����
      }
   }

}


void CImageProcessingDoc::OnSubConstant()
{
   CConstantDlg dlg;

   int i;

   m_Re_height = m_height;
   m_Re_width = m_width;
   m_Re_size = m_Re_height * m_Re_width;

   m_OutputImage = new unsigned char[m_Re_size];

   if(dlg.DoModal() == IDOK){
      for(i=0 ; i<m_size ; i++){
         if(m_InputImage[i] - dlg.m_Constant < 0)
                   m_OutputImage[i] = 0; // ��� ���� 255���� ũ�� 255�� ���
         else
            m_OutputImage [i]                    = (unsigned char)(m_InputImage[i] - dlg.m_Constant);
         // ��� ���� ȭ�� ������ ����
      }
   }

}


void CImageProcessingDoc::OnDivConstant()
{
	   CConstantDlg dlg;

   int i;

   m_Re_height = m_height;
   m_Re_width = m_width;
   m_Re_size = m_Re_height * m_Re_width;

   m_OutputImage = new unsigned char[m_Re_size];

   if(dlg.DoModal() == IDOK){
      for(i=0 ; i<m_size ; i++){
         if(m_InputImage[i] / dlg.m_Constant > 255)
                   m_OutputImage[i] = 255;
         // �������� ���� 255���� ũ�� 255�� ���
         else if(m_InputImage[i] / dlg.m_Constant < 0)
                   m_OutputImage[i] = 0;
         // �������� ���� 0���� ������ 0�� ���
         else
            m_OutputImage [i] 
                    = (unsigned char)(m_InputImage[i] / dlg.m_Constant);
         // ��� ���� ȭ�� �� ������
      }
   }

}


void CImageProcessingDoc::OnAndOperate()
{
   CConstantDlg dlg;
   int i;

   m_Re_height = m_height;
   m_Re_width = m_width;
   m_Re_size = m_Re_height * m_Re_width;

   m_OutputImage = new unsigned char[m_Re_size];

   if(dlg.DoModal() == IDOK){
      for(i=0 ; i<m_size ; i++){
         // ��Ʈ ���� AND ����
         if((m_InputImage[i] & (unsigned char)dlg.m_Constant)>= 255)
                            {m_OutputImage[i] = 255;
         }
         else if((m_InputImage[i] & (unsigned char)dlg.m_Constant)< 0)
                            {m_OutputImage[i] = 0;
         }
         else{
              m_OutputImage [i] = (m_InputImage[i] 
                             & (unsigned char)dlg.m_Constant);
         }
      }
   }
}


void CImageProcessingDoc::OnOrOperate()
{
	CConstantDlg dlg;
   int i;

   m_Re_height = m_height;
   m_Re_width = m_width;
   m_Re_size = m_Re_height * m_Re_width;

   m_OutputImage = new unsigned char[m_Re_size];

   if(dlg.DoModal() == IDOK){
      for(i=0 ; i<m_size ; i++){
        // ��Ʈ ���� OR ����
        if((m_InputImage[i] | (unsigned char)dlg.m_Constant) >= 255){
                          m_OutputImage[i] = 255;
        }
        else if((m_InputImage[i] |(unsigned char)dlg.m_Constant) < 0){
                          m_OutputImage[i] = 0;
        }
       else{
            m_OutputImage [i] = (m_InputImage[i] | (unsigned char)dlg.m_Constant);
       }
     }
  }

}


void CImageProcessingDoc::OnXorOperate()
{
   CConstantDlg dlg;
   int i;

   m_Re_height = m_height;
   m_Re_width = m_width;
   m_Re_size = m_Re_height * m_Re_width;

   m_OutputImage = new unsigned char[m_Re_size];
   
   if(dlg.DoModal() == IDOK){
      for(i=0 ; i<m_size ; i++){
         // ��Ʈ ���� XOR ����
         if((m_InputImage[i] ^ (unsigned char)dlg.m_Constant) >= 255){
               m_OutputImage[i] = 255;
         }
         else if((m_InputImage[i] ^ (unsigned char)dlg.m_Constant) < 0){ 
               m_OutputImage[i] = 0;
         }
         else{
            m_OutputImage [i] = (m_InputImage[i] 
                                ^ (unsigned char)dlg.m_Constant);
         }
      }
   }
}


void CImageProcessingDoc::Onbrightandcontrast()
{
	//CQuantizationDlg dlg;
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;
	m_OutputImage = new unsigned char[m_Re_size];


	int i,j,k;
	double m = 0.0;
	double s = 0.0;
	for(i=0 ; i<m_size ; i++){
		m += m_InputImage[i]/m_size;
	}
	for (int k = 0; k < m_size; k++)
	{
		s += pow(m_InputImage[k]-m, 2);
	}
	s = sqrt(s/m_size);
	double a = 0.0;
	a = 30/s;
	for (j= 0; j < m_size; j++)
	{
		m_OutputImage[j] = a*(m_InputImage[j] - m) + 128;
	}
}


void CImageProcessingDoc::OnNegaTransform()
{
	int i;

   m_Re_height = m_height;
   m_Re_width = m_width;
   m_Re_size = m_Re_height * m_Re_width;

   m_OutputImage = new unsigned char[m_Re_size];

   for(i=0 ; i<m_size ; i++)
      m_OutputImage[i] = 255 - m_InputImage[i]; // ���� ������ ����
}


void CImageProcessingDoc::OnGammaCorrection()
{
	CConstantDlg dlg;

   int i;
   double temp;

   m_Re_height = m_height;
   m_Re_width = m_width;
   m_Re_size = m_Re_height * m_Re_width;

   m_OutputImage = new unsigned char[m_Re_size];

   if(dlg.DoModal() == IDOK){
      for(i=0 ; i<m_size ; i++){
         temp = pow(m_InputImage[i], 1/dlg.m_Constant);
         // ���� �� ���
      if(temp < 0)
         m_OutputImage[i] = 0;
      else if(temp > 255)
         m_OutputImage[i] = 255;
      else
         m_OutputImage[i] = (unsigned char)temp;
      }
   }
}


void CImageProcessingDoc::OnBinarization()
{
   CConstantDlg dlg;

   int i;

   m_Re_height = m_height;
   m_Re_width = m_width;
   m_Re_size = m_Re_height * m_Re_width;

   m_OutputImage = new unsigned char[m_Re_size];

   if(dlg.DoModal() == IDOK){
      for(i=0 ; i<m_size ; i++){
         if(m_InputImage[i] >= dlg.m_Constant)
             m_OutputImage[i] = 255; // �Ӱ� ������ ũ�� 255 ���
         else
             m_OutputImage[i] = 0; // �Ӱ� ������ ������ 0 ���
      }
   }

}


void CImageProcessingDoc::OnStressTransform()
{
	CStressTransformDlg dlg;

   int i;

   m_Re_height = m_height;
   m_Re_width = m_width;
   m_Re_size = m_Re_height * m_Re_width;

   m_OutputImage = new unsigned char[m_Re_size];

   if(dlg.DoModal() == IDOK){
      for(i=0 ; i<m_size ; i++){
         // �Է� ���� ���� ���� ���� ���� ���� �� ���̿� ��ġ�ϸ� 255 ���
         if(m_InputImage[i] >= dlg.m_StartPoint &&
            m_InputImage[i] <= dlg.m_EndPoint)
            m_OutputImage[i] = 255;
         else
            m_OutputImage[i] = m_InputImage[i];
      }
   }

}


void CImageProcessingDoc::OnHistoStretch()
{
   CHistogram dlg;
   int i;
   unsigned char LOW, HIGH, MAX, MIN;

   m_Re_height = m_height;
   m_Re_width = m_width;
   m_Re_size = m_Re_height * m_Re_width;
   if(dlg.DoModal() == IDOK){
   LOW = dlg.m_HistoMin;
   HIGH = dlg.m_HistoMax;

   MIN = m_InputImage[0]; // �ּҰ��� ã�� ���� �ʱⰪ
   MAX = m_InputImage[0]; // �ִ밪�� ã�� ���� �ʱⰪ

   // �Է� ������ �ּҰ� ã��
   for(i=0 ; i<m_size ; i++){
      if(m_InputImage[i] < MIN)
         MIN = m_InputImage[i];
   }

   // �Է� ������ �ִ밪 ã��
   for(i=0 ; i<m_size ; i++){
      if(m_InputImage[i] > MAX)
         MAX = m_InputImage[i];
   }

   m_OutputImage = new unsigned char[m_Re_size];

   // ������׷� stretch
   for(i=0 ; i<m_size ; i++)
	   m_OutputImage[i] = (unsigned char)((m_InputImage[i] - MIN)*HIGH / (MAX-MIN) + LOW);
   }
}
double m_HIST[256];
double m_Sum_Of_HIST[256];
unsigned char m_Scale_HIST[256];


void CImageProcessingDoc::OnHistogram()
{
	 int i, j, value;
   unsigned char LOW, HIGH;
   double MAX, MIN, DIF;

   m_Re_height = 256;
   m_Re_width = 256;
   m_Re_size = m_Re_height * m_Re_width;

   LOW = 0;
   HIGH = 255;

   // �ʱ�ȭ
   for(i=0 ; i<256 ; i++)
      m_HIST[i] = LOW;

   // �� �� ����
   for(i=0 ; i<m_size ; i++){
      value = (int)m_InputImage[i];
      m_HIST[value]++;
   }

   // ����ȭ
   MAX = m_HIST[0];
   MIN = m_HIST[0];

   for(i=0 ; i<256 ; i++){
      if(m_HIST[i] > MAX)
         MAX = m_HIST[i];
   }

   for(i=0 ; i<256 ; i++){
      if(m_HIST[i] < MIN)
         MIN = m_HIST[i];
   }
   DIF = MAX - MIN;

   // ����ȭ�� ������׷�
   for(i=0 ; i<256 ; i++)
      m_Scale_HIST[i] = (unsigned char)((m_HIST[i] - MIN) * HIGH / DIF);
   
   // ����ȭ�� ������׷� ���
   m_OutputImage = new unsigned char [m_Re_size + (256*20)];

   for(i=0 ; i<m_Re_size ; i++)
      m_OutputImage[i] = 255;

   // ����ȭ�� ������׷��� ���� ��� �迭�� ���� ��(0)���� ǥ��
   for(i=0 ; i<256 ; i++){
      for(j = 0 ; j<m_Scale_HIST[i] ; j++){
         m_OutputImage[m_Re_width*(m_Re_height-j-1) + i] = 0;
      }
   }

   // ������׷��� ����ϰ� �� �Ʒ� �κп� ������׷��� ���� ǥ��
   for(i = m_Re_height ; i<m_Re_height + 5 ; i++){
      for(j=0 ; j<256 ; j++){
         m_OutputImage[m_Re_height * i + j] = 255;
      }
   }

   for(i = m_Re_height+5 ; i<m_Re_height + 20 ; i++){
         for(j=0 ; j<256 ; j++){
         m_OutputImage[m_Re_height * i + j] = j;
      }
   }

   m_Re_height = m_Re_height + 20;
   m_Re_size = m_Re_height * m_Re_width;
}


void CImageProcessingDoc::OnHistoEqual()
{
	
   int i, value;
   unsigned char LOW, HIGH, Temp;
   double SUM = 0.0;

   m_Re_height = m_height;
   m_Re_width = m_width;
   m_Re_size = m_Re_height * m_Re_width;

   LOW = 0;
   HIGH = 255;

   // �ʱ�ȭ
   for(i=0 ; i<256 ; i++)
      m_HIST[i] = LOW;

   // �� �� ����
   for(i=0 ; i<m_size ; i++){
      value = (int)m_InputImage[i];
      m_HIST[value]++;
   }

   // ���� ������׷� ����
   for(i=0 ; i<256 ; i++){
      SUM += m_HIST[i];
      m_Sum_Of_HIST[i] = SUM;
   }

   m_OutputImage = new unsigned char[m_Re_size];

   // �Է� ������ ��Ȱȭ�� �������� ���
   for(i=0 ; i<m_size ; i++){
      Temp = m_InputImage[i];
      m_OutputImage[i]=(unsigned char)(m_Sum_Of_HIST[Temp]*HIGH/m_size);
   }
}


void CImageProcessingDoc::OnHistoSpec()
{
	int i, value, Dvalue, top, bottom, DADD;
   unsigned char *m_DTEMP, m_Sum_Of_ScHIST[256], m_TABLE[256];
   unsigned char LOW, HIGH, Temp, *m_Org_Temp;
   double m_DHIST[256], m_Sum_Of_DHIST[256], SUM = 0.0, DSUM = 0.0;
   double DMAX, DMIN;
   
   top = 255;
   bottom = top - 1;

   m_Re_height = m_height;
   m_Re_width = m_width;
   m_Re_size = m_Re_height * m_Re_width;

   m_OutputImage = new unsigned char [m_Re_size];
   m_Org_Temp = new unsigned char [m_size];

   CFile File;
   CFileDialog OpenDlg(TRUE);
// ���ϴ� ������׷��� �ִ� ������ �Է¹���
   if(OpenDlg.DoModal() == IDOK){
      File.Open(OpenDlg.GetPathName(), CFile::modeRead);
      
      if(File.GetLength() == (unsigned)m_size){
         m_DTEMP = new unsigned char[m_size];
         File.Read(m_DTEMP, m_size);
         File.Close();
      }
      else{
         AfxMessageBox (_T(" Image size not matched"));
         // ���� ũ���� ������ ������� ��
         return;
      }
}

   LOW = 0;
   HIGH = 255;

   // �ʱ�ȭ
   for(i=0 ; i<256 ; i++){
      m_HIST[i] = LOW;
      m_DHIST[i] = LOW;
      m_TABLE[i] = LOW;
   }
   // �� �� ����
   for(i=0 ; i<m_size ; i++){
      value = (int)m_InputImage[i];
      m_HIST[value]++;
      Dvalue = (int)m_DTEMP[i];
      m_DHIST[Dvalue]++;
   }

   // ���� ������׷� ����
   for(i=0 ; i<256 ; i++){
      SUM += m_HIST[i];
      m_Sum_Of_HIST[i] = SUM;
      DSUM += m_DHIST[i];
      m_Sum_Of_DHIST[i] = DSUM;
   }
   // ���� ������ ��Ȱȭ
   for(i=0 ; i<m_size ; i++){
      Temp = m_InputImage[i];
      m_Org_Temp[i]=(unsigned char)(m_Sum_Of_HIST[Temp]*HIGH/m_size);
   }

   // ���� ������׷����� �ּҰ��� �ִ밪 ����
   DMIN = m_Sum_Of_DHIST[0];
   DMAX = m_Sum_Of_DHIST[255];

   // ���ϴ� ������ ��Ȱȭ
   for(i=0 ; i<256 ; i++){
      m_Sum_Of_ScHIST[i]=(unsigned char)((m_Sum_Of_DHIST[i]
      -DMIN)*HIGH/(DMAX - DMIN));
   }


   // ������̺��� �̿��� ����ȭ
   for( ; ; ){
      for(i=m_Sum_Of_ScHIST[bottom] ;
      i <= m_Sum_Of_ScHIST [top] ; i++){
      m_TABLE[i] = top;
   }
   top = bottom;
   bottom = bottom - 1;

   if(bottom < -1)
   break;
   }

   for(i=0 ; i<m_size ; i++){
      DADD = (int)m_Org_Temp[i];
      m_OutputImage[i] = m_TABLE[DADD];
   }

}


void CImageProcessingDoc::OnEmbossing()
{
   int i, j;
// double EmboMask[3][3] = {{-1., 0., 0.}, {0., 0., 0.}, {0., 0., 1.}};
   // ����ũ ����
//double EmboMask[3][3] = {{0., 0., 0.}, {0., 1., 0.}, {0., 0., 0.}};
//double EmboMask[3][3] = {{1., 1., 1.}, {1., -8.,1.}, {1., 1., 1.}};
//double EmboMask[3][3] = {{1.,-2.,3.},{-4,5.,-6.},{7.,-8.,9.}};
//double EmboMask[3][3] = {{1.,1.,1.},{-2.,-2.,-2.},{1.,1.,1.}};
//double EmboMask[3][3] = {{-1.,-1.,-1.},{2.,2.,2.},{-1.,-1.,-1.}};
   double EmboMask[3][3] = {{100.,50.,0.},{-75.,-150.,-75.},{0.,50.,100.}};

   m_Re_height = m_height;
   m_Re_width = m_width;
   m_Re_size = m_Re_height * m_Re_width;
   m_OutputImage = new unsigned char [m_Re_size];
   m_tempImage = OnMaskProcess(m_InputImage, EmboMask);
   // OnMaskProcess �Լ��� ȣ���Ͽ� ȸ�� ó���� �Ѵ�.

  /* for(i=0 ; i<m_Re_height ; i++){
      for(j=0 ; j<m_Re_width ; j++){
         if(m_tempImage[i][j] > 255.)
            m_tempImage[i][j] = 255.;
         if(m_tempImage[i][j] < 0.)
            m_tempImage[i][j] = 0.;
      }
   }*/ // ȸ�� ó�� ����� 0~255 ���� ���� �ǵ��� �Ѵ�.
 m_tempImage = OnScale(m_tempImage, m_Re_height, m_Re_width);
   // ����ȭ �Լ��� ����� ��

   // ȸ�� ó�� ����� ����ȭ ó�� ����� 2���� �迭 ���� �ǹǷ�
   // 2���� �迭�� 1���� �迭�� �ٲپ� ����ϵ��� �Ѵ�.
   for(i=0 ; i<m_Re_height ; i++){
      for(j=0 ; j<m_Re_width ; j++){
         m_OutputImage[i*m_Re_width + j]
            = (unsigned char)m_tempImage[i][j];
      }
   }
}   


double** CImageProcessingDoc::OnMaskProcess(unsigned char *Target, double Mask[3][3])
{ // ȸ�� ó���� �Ͼ�� �Լ�
   int i, j, n, m;
   double **tempInputImage, **tempOutputImage, S = 0.0;

   tempInputImage = Image2DMem(m_height + 2, m_width + 2);
   // �Է� ���� ���� �޸� �Ҵ�
   tempOutputImage = Image2DMem(m_height, m_width);
   // ��� ���� ���� �޸� �Ҵ�

   // 1���� �Է� ������ ���� 2���� �迭�� �Ҵ��Ѵ�.
   for(i=0 ; i<m_height ; i++){
      for(j=0 ; j<m_width ; j++){
         tempInputImage[i+1][j+1]
            = (double)Target[i * m_width + j];
      }
   }

   // ȸ������
   for(i=0 ; i<m_height ; i++){
      for(j=0 ; j<m_width ; j++){
         for(n=0 ; n<3 ; n++){
            for(m=0 ; m<3 ; m++){
               S += Mask[n][m] * tempInputImage[i+n][j+m];
            }
         } // ȸ�� ����ũ�� ũ�� ��ŭ �̵��ϸ鼭 ���� ����
         tempOutputImage[i][j] = S; // ������ ���� ��� �޸𸮿� ����
         S = 0.0; // ���� �������� �̵��ϸ� ���� ���� �ʱ�ȭ
         }
      }
   return tempOutputImage; // ��� �� ��ȯ
}   


double** CImageProcessingDoc::OnScale(double **Target, int height, int width)
{ // ����ȭ�� ���� �Լ�
   int i, j;
   double min, max;

   min = max = Target[0][0];

   for(i=0 ; i<height ; i++){
      for(j=0 ; j<width ; j++){
         if(Target[i][j] <= min)
            min = Target[i][j];
      }
   }

   for(i=0 ; i<height ; i++){
      for(j=0 ; j<width ; j++){
         if(Target[i][j] >= max)
            max = Target[i][j];
      }
   }

   max = max - min;

   for(i=0 ; i<height ; i++){
      for(j=0 ; j<width ; j++){
         Target[i][j] = (Target[i][j] - min) * (255. / max);
      }
   }

   return Target;
}


double** CImageProcessingDoc::Image2DMem(int height, int width)
{ // 2���� �޸� �Ҵ��� ���� �Լ�
   double** temp;
   int i, j;
   temp = new double *[height];
   for(i=0 ; i<height ; i++){
      temp[i] = new double [width];
   }
   for(i=0 ; i<height ; i++){
      for(j=0 ; j<width ; j++){
         temp[i][j] = 0.0;
      }
   } // �Ҵ�� 2���� �޸𸮸� �ʱ�ȭ
   return temp;
}   


void CImageProcessingDoc::OnBlurr()
{
	int i, j;
   double BlurrMask[3][3] = {{1./9., 1./9., 1./9.},
      {1./9., 1./9., 1./9.}, {1./9., 1./9., 1./9.}};

   m_Re_height = m_height;
   m_Re_width = m_width;
   m_Re_size = m_Re_height * m_Re_width;

   m_OutputImage = new unsigned char [m_Re_size];

   m_tempImage = OnMaskProcess(m_InputImage, BlurrMask);
   // ������ ó��
   // m_tempImage = OnScale(m_tempImage, m_Re_height, m_Re_width);

   // ����ȭ
   for(i=0 ; i<m_Re_height ; i++){
      for(j=0 ; j<m_Re_width ; j++){
         if(m_tempImage[i][j] > 255.)
            m_tempImage[i][j] = 255.;
         if(m_tempImage[i][j] < 0.)
            m_tempImage[i][j] = 0.;
      }
   }
   for(i=0 ; i<m_Re_height ; i++){
         for(j=0 ; j<m_Re_width ; j++){
            m_OutputImage[i*m_Re_width + j]
               = (unsigned char)m_tempImage[i][j];
      }
   }
}


void CImageProcessingDoc::OnGaussianFilter()
{
	int i, j;
   double GaussianMask[3][3] = {{1./16., 1./8., 1./16.},
         {1./8., 1./4., 1./8.}, {1./16., 1./8., 1./16.}};

   m_Re_height = m_height;
   m_Re_width = m_width;
   m_Re_size = m_Re_height * m_Re_width;

   m_OutputImage = new unsigned char [m_Re_size];

   m_tempImage = OnMaskProcess(m_InputImage, GaussianMask);
   // m_tempImage = OnScale(m_tempImage, m_Re_height, m_Re_width);

   for(i=0 ; i<m_Re_height ; i++){
      for(j=0 ; j<m_Re_width ; j++){
         if(m_tempImage[i][j] > 255.)
            m_tempImage[i][j] = 255.;
         if(m_tempImage[i][j] < 0.)
            m_tempImage[i][j] = 0.;
      }
   }

   for(i=0 ; i<m_Re_height ; i++){
      for(j=0 ; j<m_Re_width ; j++){
         m_OutputImage[i*m_Re_width + j]
            = (unsigned char)m_tempImage[i][j];
      }
   }

}


void CImageProcessingDoc::OnSharpening()
{
	int i, j;
   //double SharpeningMask[3][3] = {{-1., -1., -1.},      {-1., 9., -1.}, {-1., -1., -1.}};
   double SharpeningMask[3][3] = {{0., -1., 0.}, {-1., 5.,
      -1.}, {0., -1., 0.}};

   m_Re_height = m_height;
   m_Re_width = m_width;
   m_Re_size = m_Re_height * m_Re_width;

   m_OutputImage = new unsigned char [m_Re_size];

   m_tempImage = OnMaskProcess(m_InputImage, SharpeningMask);
   // m_tempImage = OnScale(m_tempImage, m_Re_height, m_Re_width);

   for(i=0 ; i<m_Re_height ; i++){
      for(j=0 ; j<m_Re_width ; j++){
         if(m_tempImage[i][j] > 255.)
            m_tempImage[i][j] = 255.;
         if(m_tempImage[i][j] < 0.)
            m_tempImage[i][j] = 0.;
      }
   }

   for(i=0 ; i<m_Re_height ; i++){
      for(j=0 ; j<m_Re_width ; j++){
         m_OutputImage[i*m_Re_width + j]
            = (unsigned char)m_tempImage[i][j];
      }
   }

}


void CImageProcessingDoc::OnHpfSharp()
{
	int i, j;
   double HpfSharpMask[3][3] = {{-1./9., -1./9., -1./9.},{-1./9., 8./9., -1./9.}, {-1./9., -1./9., -1./9.}};

   m_Re_height = m_height;
   m_Re_width = m_width;
   m_Re_size = m_Re_height * m_Re_width;

   m_OutputImage = new unsigned char [m_Re_size];

   m_tempImage = OnMaskProcess(m_InputImage, HpfSharpMask);
   //m_tempImage = OnScale(m_tempImage, m_Re_height, m_Re_width);

   for(i=0 ; i<m_Re_height ; i++){
      for(j=0 ; j<m_Re_width ; j++){
         if(m_tempImage[i][j] > 255.)
            m_tempImage[i][j] = 255.;
         if(m_tempImage[i][j] < 0.)
            m_tempImage[i][j] = 0.;
      }
   }

   for(i=0 ; i<m_Re_height ; i++){
      for(j=0 ; j<m_Re_width ; j++){
         m_OutputImage[i*m_Re_width + j]
            = (unsigned char)m_tempImage[i][j];
      }
   }

}


void CImageProcessingDoc::OnLpfSharp()
{
	CConstantDlg dlg; // ����� �Է¹������� ��ȭ���� ����

   int i, j, alpha;
   double LpfSharpMask[3][3] = {{1./9., 1./9., 1./9.},
      {1./9., 1./9., 1./9.}, {1./9., 1./9., 1./9.}};

   m_Re_height = m_height;
   m_Re_width = m_width;
   m_Re_size = m_Re_height * m_Re_width;

   m_OutputImage = new unsigned char [m_Re_size];

   if(dlg.DoModal() == IDOK){
      alpha = (int)dlg.m_Constant;
      // ��ȭ���ڸ� �̿��Ͽ� ����� �Է¹޴´�.
   }

   m_tempImage = OnMaskProcess(m_InputImage, LpfSharpMask);

   for(i=0 ; i<m_height ; i++){
      for(j=0 ; j<m_width ; j++){
         m_tempImage[i][j] = (alpha * m_InputImage
            [i*m_width + j]) - (unsigned char) m_tempImage[i][j];
      }
   }
// m_tempImage = OnScale(m_tempImage, m_Re_height, m_Re_width);

   for(i=0 ; i<m_Re_height ; i++){
      for(j=0 ; j<m_Re_width ; j++){
         if(m_tempImage[i][j] > 255.)
            m_tempImage[i][j] = 255.;
         if(m_tempImage[i][j] < 0.)
            m_tempImage[i][j] = 0.;
      }
   }

   for(i=0 ; i<m_Re_height ; i++){
      for(j=0 ; j<m_Re_width ; j++){
         m_OutputImage[i*m_Re_width + j]
            = (unsigned char)m_tempImage[i][j];
      }
   }
}


void CImageProcessingDoc::OnDiffOperatorHor()
{
	int i, j;
   double DiffHorMask[3][3] 
        = {{0., -1., 0.}, {0., 1., 0.}, {0., 0., 0.}};
   // ���� ���� ����

   m_Re_height = m_height;
   m_Re_width = m_width;
   m_Re_size = m_Re_height * m_Re_width;
   m_OutputImage = new unsigned char [m_Re_size];

   m_tempImage = OnMaskProcess(m_InputImage, DiffHorMask);
   // m_tempImage = OnScale(m_tempImage, m_Re_height, m_Re_width);

for(i=0 ; i< m_Re_height ; i++){
      for(j=0 ; j< m_Re_width ; j++){
         if(m_tempImage[i][j] > 255.) 
            m_tempImage[i][j] = 255.;
         if(m_tempImage[i][j] < 0.)
            m_tempImage[i][j] = 0.;
      }
   }

   for(i=0 ; i< m_Re_height ; i++){
      for(j=0 ; j< m_Re_width ; j++){
         m_OutputImage[i* m_Re_width + j] = (unsigned char)m_tempImage[i][j];
      }
   }
}


void CImageProcessingDoc::OnHomogenOperator()
{
	int i, j, n, m;
   double max, **tempOutputImage;

   m_Re_height = m_height;
   m_Re_width = m_width;
   m_Re_size = m_Re_height * m_Re_width;
   m_OutputImage = new unsigned char [m_Re_size];

   m_tempImage = Image2DMem(m_height + 2, m_width + 2);
   tempOutputImage = Image2DMem(m_Re_height, m_Re_width);

   for(i=0 ; i<m_height ; i++){
      for(j=0 ; j<m_width ; j++){
         m_tempImage[i+1][j+1] = (double)m_InputImage[i * m_width + j];
      }
   }
for(i=0 ; i<m_height ; i++){
      for(j=0 ; j<m_width ; j++){
         max = 0.0; // ������ �̵��� ������ �ִ밪 �ʱ�ȭ
         for(n=0 ; n<3 ; n++){
            for(m=0 ; m<3 ; m++){
               if(DoubleABS(m_tempImage[i+1][j+1] -
                  m_tempImage[i+n][j+m]) >= max)
                  // ������ ��� �� - ������ �ֺ� �ȼ� ���� ���� ��
                  // �߿��� �ִ밪�� ã�´�.

                     max = DoubleABS(m_tempImage[i+1]
                           [j+1] - m_tempImage[i+n][j+m]);
            }
         }
         tempOutputImage[i][j] = max; // ã�� �ִ밪�� ��� ������ ����
      }
   }
   for(i=0 ; i< m_Re_height ; i++){
      for(j=0 ; j< m_Re_width ; j++){
         if(tempOutputImage[i][j] > 255.)
            tempOutputImage[i][j] = 255.;
         if(tempOutputImage[i][j] < 0.)
            tempOutputImage[i][j] = 0.;
      }
   }

   for(i=0 ; i< m_Re_height ; i++){
      for(j=0 ; j< m_Re_width ; j++){
         m_OutputImage[i* m_Re_width + j]
            = (unsigned char)tempOutputImage[i][j];
      }
   }

}


double CImageProcessingDoc::DoubleABS(double X)
{
	// �Ǽ��� ���� �� ���� �Լ�
   if(X >= 0)
      return X;
   else
      return -X;

}


void CImageProcessingDoc::OnMedi()
{
	int i, j, n, m;
	double buf[9] = {0,};
	double temp = 0;

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_OutputImage = new unsigned char [m_Re_size];

	// ȸ������
	for(i=0 ; i<m_height ; i++)
	{
		for(j=0 ; j<m_width ; j++)
		{
			for(n=0 ; n<3 ; n++) //9�� ȭ�� ����
			{
				for(m=0 ; m<3 ; m++)
				{
					if (((i+n)*m_Re_width + (j+m))>=m_Re_size)
					{//ȭ���� ������ �Ѿ�� �� ��� ó���� ���� if�� 3��
						buf[n*3 + m] = m_InputImage[m_Re_size - 1];
						continue;
					}
					else if ((i+n)>=m_Re_height)
					{
						buf[n*3 + m] = m_InputImage[(m_height-1)*m_Re_width + (j+m)];
						continue;
					}
					else if ((j+m)>=m_Re_width)
					{
						buf[n*3 + m] = m_InputImage[(i+n)*m_Re_width + m_Re_height-1];
						continue;
					}
					buf[n*3 + m] = m_InputImage[(i+n)*m_Re_width + (j+m)];
				}
			}
			for (n = 0; n < 9; n++) //�������� ����
			{
				for (m = 0; m < 8; m++)
				{
					if (buf[m+1] < buf[m])
					{
						temp = buf[m+1];
						buf[m+1] = buf[m];
						buf[m] = temp;
					}
				}
			}
			m_OutputImage[i*m_Re_width + j] = buf[4]; //�߰���(�޵�Ȱ�) ����
			
			if(m_OutputImage[i*m_Re_width + j] > 255.)
				m_OutputImage[i*m_Re_width + j] = 255.;
			if(m_OutputImage[i*m_Re_width + j] < 0)
				m_OutputImage[i*m_Re_width + j] = 0.;
			
			for (n = 0; n < 9; n++)
			{
				buf[n] = 0.0;
			} // �ʱ�ȭ
		}
	}
}


void CImageProcessingDoc::OnNearest()
{
   int i,j;
   int ZoomRate = 2; // ���� Ȯ�� ����
   double **tempArray;
   
   m_Re_height = int(ZoomRate*m_height); // Ȯ��� ������ ����
   m_Re_width = int(ZoomRate*m_width); // Ȯ��� ������ �ʺ�
   m_Re_size = m_Re_height * m_Re_width;

   m_tempImage = Image2DMem(m_height, m_width);
   tempArray = Image2DMem(m_Re_height, m_Re_width);

   m_OutputImage = new unsigned char [m_Re_size];

   for(i=0 ; i<m_height ; i++){
      for(j=0 ; j<m_width ; j++){
         m_tempImage[i][j] = (double)m_InputImage[i*m_width + j];
      }
   }

   for(i=0 ; i< m_Re_height ; i++){
      for(j=0 ; j< m_Re_width ; j++){
         tempArray[i][j] = m_tempImage[i/ZoomRate][j/ZoomRate];
         // �̿��� ȭ�Ҹ� �̿��� ����
      }
   }

   for(i=0 ; i< m_Re_height ; i++){
      for(j=0 ; j< m_Re_width ; j++){
         m_OutputImage[i* m_Re_width + j] = (unsigned char)tempArray[i][j];
      }
   }
}


void CImageProcessingDoc::OnBilinear()
{
   int i, j, point, i_H, i_W;
   unsigned char newValue;
   double ZoomRate = 2.0, r_H, r_W, s_H, s_W;
   double C1, C2, C3, C4;

   m_Re_height = (int)(m_height * ZoomRate); // Ȯ��� ������ ����
   m_Re_width = (int)(m_width * ZoomRate); // Ȯ��� ������ �ʺ�
   m_Re_size = m_Re_height * m_Re_width;

   m_tempImage = Image2DMem(m_height, m_width);
   m_OutputImage = new unsigned char [m_Re_size];

   for(i=0 ; i<m_height ; i++){
      for(j=0 ; j<m_width ; j++){
         m_tempImage[i][j] = (double)m_InputImage[i*m_width + j];
      }
   }
   for(i=0 ; i< m_Re_height ; i++){
      for(j=0 ; j< m_Re_width ; j++){
         r_H = i / ZoomRate;//��� ���� ȭ����ġ. ����� �����ε� �Էºκ��� �Ҽ��� �κ��ϼ��� �ִ�.
         r_W = j / ZoomRate;

         i_H = (int)floor(r_H); //�Ǽ����� ������
         i_W = (int)floor(r_W);

         s_H = r_H - i_H; //�Ǽ����� �Ҽ�����
         s_W = r_W - i_W;

         if(i_H < 0 || i_H >= (m_height-1) || i_W < 0  
            || i_W >= (m_width-1))
         {
            point = i* m_Re_width + j;
            m_OutputImage[point] = 255;
         }
         
         else // �Ҽ��� �� �����ϱ�
         {
            C1 = (double)m_tempImage[i_H][i_W];
            C2 = (double)m_tempImage[i_H][i_W+1];
            C3 = (double)m_tempImage[i_H+1][i_W+1];
            C4 = (double)m_tempImage[i_H+1][i_W];

            newValue = (unsigned char)(C1*(1-s_H)*(1-s_W)
               +C2*s_W*(1-s_H)+C3*s_W*s_H+C4*(1-s_W)*s_H);
            point = i* m_Re_width+j;
            m_OutputImage[point] = newValue;
         }
      }
   }

}


void CImageProcessingDoc::OnRotate30()
{
   int i, j, point, i_H, i_W;
   unsigned char newValue;
   double ZoomRate = 1.0, r_H, r_W, s_H, s_W;
   double C1, C2, C3, C4;

   m_Re_height = (int)(m_height * ZoomRate); // Ȯ��� ������ ����
   m_Re_width = (int)(m_width * ZoomRate); // Ȯ��� ������ �ʺ�
   m_Re_size = m_Re_height * m_Re_width;

   m_tempImage = Image2DMem(m_height, m_width);
   m_OutputImage = new unsigned char [m_Re_size];

   for(i=0 ; i<m_height ; i++){
      for(j=0 ; j<m_width ; j++){
         m_tempImage[i][j] = (double)m_InputImage[i*m_width + j];
      }
   }
   for(i=0 ; i< m_Re_height ; i++){
      for(j=0 ; j< m_Re_width ; j++){

		  r_W = (cos((30.0/180)*3.14)*(j-m_Re_width/2)) + (sin((30.0/180)*3.14)*(i-m_Re_height/2)) + m_Re_width/2;
		  r_H = -(sin((30.0/180)*3.14)*(j-m_Re_width/2))+ (cos((30.0/180)*3.14)*(i-m_Re_height/2)) + m_Re_height/2;

         i_H = (int)floor(r_H);
         i_W = (int)floor(r_W);

         s_H = r_H - i_H;
         s_W = r_W - i_W;

         if(i_H < 0 || i_H >= (m_height-1) || i_W < 0  
            || i_W >= (m_width-1))
         {
            point = i* m_Re_width + j;
            m_OutputImage[point] = 255;
         }
         
         else
         {
            C1 = (double)m_tempImage[i_H][i_W];
            C2 = (double)m_tempImage[i_H][i_W+1];
            C3 = (double)m_tempImage[i_H+1][i_W+1];
            C4 = (double)m_tempImage[i_H+1][i_W];

            newValue = (unsigned char)(C1*(1-s_H)*(1-s_W)
               +C2*s_W*(1-s_H)+C3*s_W*s_H+C4*(1-s_W)*s_H);
            point = i* m_Re_width+j;
            m_OutputImage[point] = newValue;
         }
      }
   }
}


void CImageProcessingDoc::OnCoffeeCup()
{
   int i, j, point, i_H, i_W;
   unsigned char newValue;
   double ZoomRate = 1.0, r_H, r_W, s_H, s_W;
   double C1, C2, C3, C4;
   double d;


   m_Re_height = (int)(m_height * ZoomRate); // Ȯ��� ������ ����
   m_Re_width = (int)(m_width * ZoomRate); // Ȯ��� ������ �ʺ�
   m_Re_size = m_Re_height * m_Re_width;

   m_tempImage = Image2DMem(m_height, m_width);
   m_OutputImage = new unsigned char [m_Re_size];

   for(i=0 ; i<m_height ; i++){
      for(j=0 ; j<m_width ; j++){
         m_tempImage[i][j] = (double)m_InputImage[i*m_width + j];
      }
   }
   for(i=0 ; i< m_Re_height ; i++){
      for(j=0 ; j< m_Re_width ; j++){

		  d = sqrt(pow((m_Re_width-1.0)/2.0 - (double)j, 2.0) +pow((m_Re_height-1.0)/2.0 - (double)i, 2.0)); 
		  r_W = (cos(d*3.1415/60)*(j-m_Re_width/2)) + (sin(d*3.1415/60)*(i-m_Re_height/2)) + m_Re_width/2;
		  r_H = -(sin(d*3.1415/60)*(j-m_Re_width/2))+ (cos(d*3.1415/60)*(i-m_Re_height/2)) + m_Re_height/2;

         i_H = (int)floor(r_H);
         i_W = (int)floor(r_W);

         s_H = r_H - i_H;
         s_W = r_W - i_W;

         if(i_H < 0 || i_H >= (m_height-1) || i_W < 0  
            || i_W >= (m_width-1))
         {
            point = i* m_Re_width + j;
            m_OutputImage[point] = 255;
         }
         
         else
         {
            C1 = (double)m_tempImage[i_H][i_W];
            C2 = (double)m_tempImage[i_H][i_W+1];
            C3 = (double)m_tempImage[i_H+1][i_W+1];
            C4 = (double)m_tempImage[i_H+1][i_W];

            newValue = (unsigned char)(C1*(1-s_H)*(1-s_W)
               +C2*s_W*(1-s_H)+C3*s_W*s_H+C4*(1-s_W)*s_H);
            point = i* m_Re_width+j;
            m_OutputImage[point] = newValue;
         }
      }
   }
}


void CImageProcessingDoc::OnTranslation()
{
	   int i,j;
   int h_pos = 30, w_pos = 30;
   double **tempArray;

   m_Re_height = m_height;
   m_Re_width = m_width;
   m_Re_size = m_Re_height * m_Re_width;

   m_OutputImage = new unsigned char [m_Re_size];

   m_tempImage = Image2DMem(m_height, m_width);
   tempArray = Image2DMem(m_Re_height, m_Re_width);

   for(i=0 ; i<m_height ; i++)
   {
      for(j=0 ; j<m_width ; j++)
	  {
         m_tempImage[i][j] = (double)m_InputImage[i*m_width + j];
      }
   }
   for(i=0 ; i<m_height - h_pos ; i++)
   {
      for(j=0 ; j<m_width - w_pos ; j++)
	  {
         tempArray[i + h_pos][j + w_pos] = m_tempImage[i][j];
         // �Է� ������ h_pos, w_pos��ŭ �̵�
      }
   }

   for(i=0 ; i< m_Re_height ; i++)
   {
      for(j=0 ; j< m_Re_width ; j++)
	  {
         m_OutputImage[i* m_Re_width + j] = (unsigned char)tempArray[i][j];
      }
   }

   delete [] m_tempImage;
   delete [] tempArray;

}



void CImageProcessingDoc::OnMirrorHor()
{
   int i,j;

   m_Re_height = m_height;
   m_Re_width = m_width;
   m_Re_size = m_Re_height * m_Re_width;

   m_OutputImage = new unsigned char [m_Re_size];

   for(i=0 ; i<m_height ; i++)
   {
      for(j=0 ; j<m_width ; j++)
	  {
         m_OutputImage[i*m_width + m_width - j - 1] = m_InputImage[i*m_width + j];
         // �Է� ������ �迭 ���� ��� ������ ���� 
         // �迭�� ������ ���ڸ����� ����
      }
   }

}