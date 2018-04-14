//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StartingPage.h"
#include "DidacticPage.h"
#include "EducationalPage.h"
#include "AdvancedPage.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfEducationalPage *fEducationalPage;

int n, if_count, arr_access;

// n - aktualna wielko�� tablicy
// if_count - ilo�� zliczonych por�wna�
// arr_access - ilo�� zliczonych dost�p�w do tablicy

//---------------------------------------------------------------------------
__fastcall TfEducationalPage::TfEducationalPage(TComponent* Owner)
        : TForm(Owner)
{
   n= sbAmount->Position; // Przypisanie pocz�tkowej ilo�ci s�upk�w
   if_count = 0; // Przypisanie pocz�tkowej warto�ci zliczania if'�w
   arr_access = 0; // Nadanie pocz�tkowej warto�ci dost�p�w do tablicy
}
//---------------------------------------------------------------------------

/* ��czy dwie podtablice arr[].
   Pierwsza podtablica to arr[l..m]
   Druga podtablica to arr[m+1..r]
*/
void TfDidacticPage::merge(int *arr[], int l, int m, int r) /* l - left, m - middle, r- right */
{

    int i, j, k;
    int n1 = m - l + 1; // ilo�� element�w w pierwszej podtablicy
    int n2 =  r - m; // ilo�� element�w w drugiej podtablicy

    // Tworzenie pomocniczych tablic
    int *L = new int [n1];
    int *R = new int [n2];

    // Skopiowanie danych do pomocniczych tablic L[] i R[]
    lComparisonsAmount->Caption = ++if_count;

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];

        lArrAccessAmount->Caption = ++arr_access;
        lComparisonsAmount->Caption = ++if_count;
    }
    lComparisonsAmount->Caption = ++if_count;

    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1+ j];

        lArrAccessAmount->Caption = ++arr_access;
        lComparisonsAmount->Caption = ++if_count;
    }

    // ��czenie pomocniczych tablic spowrotem do arr[l..r]
    i = 0; // Pocz�tkowy indeks pierwszej podtablicy
    j = 0; // Pocz�tkowy indeks drugiej podtablicy
    k = l; // Pocz�tkowy indeks po��czonej podtablicy

    if(i<n1) // Zabezpieczenie, gdy i < n1 jest prawd�, wtedy mamy 2 por�wnania i<n1 i j<n2
      lComparisonsAmount->Caption = ++if_count;
    lComparisonsAmount->Caption = ++if_count;

    while (i < n1 && j < n2)
    {
        lComparisonsAmount->Caption = ++if_count;
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;

            lArrAccessAmount->Caption = ++arr_access;
        }
        else
        {
            arr[k] = R[j];
            j++;

            lArrAccessAmount->Caption = ++arr_access;
        }

        k++;

        if(i<n1) // Zabezpieczenie, gdy i < n1 jest prawd�, wtedy mamy 2 por�wnania i<n1 i j<n2
            lComparisonsAmount->Caption = ++if_count;
        lComparisonsAmount->Caption = ++if_count;
    }
    // Skopiowanie pozosta�ych element�w podtablicy L[], je�li jakie� istniej�
    lComparisonsAmount->Caption = ++if_count;
    while (i < n1)
    {
        arr[k] = L[i];

        lArrAccessAmount->Caption = ++arr_access;

        i++;
        k++;

        lComparisonsAmount->Caption = ++if_count;
    }
    // Skopiowanie pozosta�ych element�w podtablicy R[], je�li jakie� istniej�
    lComparisonsAmount->Caption = ++if_count;
    while (j < n2)
    {
        arr[k] = R[j];

        lArrAccessAmount->Caption = ++arr_access;

        j++;
        k++;

        lComparisonsAmount->Caption = ++if_count;
    }

    // Usuni�cie dodatkowch tablic
    delete [] L;
    delete [] R;
}
//---------------------------------------------------------------------------

void TfDidacticPage::mergeSort(int *arr[], int l, int r)
{
  lComparisonsAmount->Caption = ++if_count;

  if (l < r)
  {
    // To samo co (l+r)/2, ale unika przepe�nienia dla du�ego l i r
    int m = l+(r-l)/2;

    // Sortowanie pierwszej i drugiej po�owy tablicy arr
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);

    merge(arr, l, m, r);
  }
}
//---------------------------------------------------------------------------

void __fastcall TfEducationalPage::mDydClick(TObject *Sender)
{
   fEducationalPage->Hide();
   fDidacticPage->Show();
}
//---------------------------------------------------------------------------

void __fastcall TfEducationalPage::mAdvClick(TObject *Sender)
{
   fEducationalPage->Hide();
   fAdvancedPage->Show();
}
//---------------------------------------------------------------------------

void __fastcall TfEducationalPage::mExitClick(TObject *Sender)
{
   fStartingPage->Close();   
}
//---------------------------------------------------------------------------

void __fastcall TfEducationalPage::mStartClick(TObject *Sender)
{
   fEducationalPage->Hide();
   fStartingPage->Show();
}
//---------------------------------------------------------------------------

void __fastcall TfEducationalPage::FormClose(TObject *Sender,
      TCloseAction &Action)
{
   fStartingPage->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfEducationalPage::rgTableTypesClick(TObject *Sender)
{
  rgTableTypes->Top = 33;
  lAmount->Visible = true;
  sbAmount->Visible = true;
  bGenerate->Visible = true;
  bGenerateClick(this);
}
//---------------------------------------------------------------------------

void __fastcall TfEducationalPage::bGenerateClick(TObject *Sender)
{
/*
  lComparisonsAmount->Caption = if_count = 0;
  n = sbAmount->Position;
  int option = rgTableTypes->ItemIndex;
  switch(option)
  {
    case 0: randomTable();
            bGenerate->Enabled = true;
            break;
    case 1: reversedTable();
            bGenerate->Enabled = false;
            break;
    case 2: constantTable();
            bGenerate->Enabled = true;
            break;
    case 3: arrowUpTable();
            bGenerate->Enabled = false;
            break;
    case 4: arrowDownTable();
            bGenerate->Enabled = false;
            break;
    case 5: almostSortedTable();
            bGenerate->Enabled = true;
            break;
    case 6: fewUniqueTable();
            bGenerate->Enabled = true;
            break;
    case 7: sortedTable();
            bGenerate->Enabled = false;
            break;
  }
  */
}
//---------------------------------------------------------------------------

void __fastcall TfEducationalPage::sbAmountChange(TObject *Sender)
{
   bGenerate->Enabled = true;
   lAmount->Caption = sbAmount->Position;
}/*
//---------------------------------------------------------------------------
void TfEducationalPage::randomTable()
{
    deleteTable();

    srand( time( NULL ) );

    for(int i=0; i < n; i++)
    {
        tab[i]->Width = 15;
        tab[i]->Height = -((rand() % 300) + 5);
        tab[i]->Left = (tab[i]->Width) * (i%n) + center - (n*tab[i]->Width)/2;
        tab[i]->Top = 400;
    }
    Repaint();
}
//---------------------------------------------------------------------------

void TfEducationalPage::reversedTable()
{
    deleteTable();

    for(int i=0, j=n; i < n; i++, j--)
    {
        tab[i]->Width = 15;
        tab[i]->Height = -10 * (j+1);
        tab[i]->Left = (tab[i]->Width) * (i%n) + center - (n*tab[i]->Width)/2;
        tab[i]->Top = 400;
    }
    Repaint();
}
//---------------------------------------------------------------------------

void TfEducationalPage::constantTable()
{
  deleteTable();

  srand( time( NULL ) );

  int height =  (rand() % 300) + 2;

  for(int i=0; i < n; i++)
  {
      tab[i]->Width = 15;
      tab[i]->Height = - height;
      tab[i]->Left = (tab[i]->Width) * (i%n) + center - (n*tab[i]->Width)/2;
      tab[i]->Top = 400;
  }
  Repaint();
}
//---------------------------------------------------------------------------


void TfEducationalPage::arrowDownTable()
{
  deleteTable();
  int temp = 0;
  if(n > 20 && n < 28)
     temp = 40;
  else if(n >= 28)
     temp = 60;
  for(int i=0, j = n; i < n; i++, j--)
  {
      if(j <= i)
         j = i + 1;
      tab[i]->Width = 15;
      tab[i]->Height = (-10 * (2.5*j)) + (10 * n) + temp;
      tab[i]->Left = (tab[i]->Width) * (i%n) + center - (n*tab[i]->Width)/2;
      tab[i]->Top = 400;
  }
  Repaint();
}
//---------------------------------------------------------------------------

void TfEducationalPage::arrowUpTable()
{
  deleteTable();

  for(int i=0, j = 0; i < n; i++)
  {
      if(i > n/2)
         j--;
      else
         j++;
      tab[i]->Width = 15;
      tab[i]->Height = (-10 * (2.5*j));
      tab[i]->Left = (tab[i]->Width) * (i%n) + center - (n*tab[i]->Width)/2;
      tab[i]->Top = 400;
  }
  Repaint();
}
//---------------------------------------------------------------------------

void TfEducationalPage::almostSortedTable()
{
  deleteTable();

  srand( time( NULL ) );

  for(int i=0; i < n; i++)
  {
    tab[i]->Width = 15;
    tab[i]->Height = -10 * (i+1);
    tab[i]->Left = (tab[i]->Width) * (i%n) + center - (n*tab[i]->Width)/2;
    tab[i]->Top = 400;
  }
  int rand1;
  if(n > 4)
  {
     for(int i=0; i < n/4; i++)
     {
        rand1 = rand() % n;
        tab[rand1]->Height = -((rand() % 300) + 5);
     }
  }
  else
  {
     rand1 = rand() % n;
     tab[rand1]->Height = -((rand() % 300) + 5);
  }
  Repaint();
}
//---------------------------------------------------------------------------

void TfEducationalPage::fewUniqueTable()
{
  deleteTable();

  srand( time( NULL ) );
  int tab_length = (n>9)? 5 : 2;
  int *tabRand = new int[tab_length];
  int *temp = new int[n];
  for(int i = 0; i< tab_length; i++)
  {
    tabRand[i] = -(rand() % 300 + 5);
  }
  for(int i=0; i<n; i++)
  {
      temp[i] = tabRand[i % tab_length];
  }

  int rand1;
  for(int i=0; i < n; i++)
  {
      tab[i]->Width = 15;
      do{
              rand1 = rand() % n;
      }while(temp[rand1] == 0);
      tab[i]->Height = temp[rand1];
      temp[rand1] = 0;
      tab[i]->Left = (tab[i]->Width) * (i%n) + center - (n*tab[i]->Width)/2;
      tab[i]->Top = 400;
  }
  Repaint();
  delete [] tabRand;
  delete [] temp;
}
//---------------------------------------------------------------------------

void TfEducationalPage::sortedTable()
{
  deleteTable();

  for(int i=0; i < n; i++)
  {
    tab[i]->Width = 15;
    tab[i]->Height = -10 * (i+1);
    tab[i]->Left = (tab[i]->Width) * (i%n) + center - (n*tab[i]->Width)/2;
    tab[i]->Top = 400;
  }
  Repaint();
}
//---------------------------------------------------------------------------
void TfEducationalPage::deleteTable(){
  delete tab [];
}  */
