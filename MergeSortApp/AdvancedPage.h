//---------------------------------------------------------------------------

#ifndef AdvancedPageH
#define AdvancedPageH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TfAdvancedPage : public TForm
{
__published:	// IDE-managed Components
   TMainMenu *MainMenu;
   TMenuItem *mFile;
   TMenuItem *mStart;
   TMenuItem *mGoTo;
   TMenuItem *mDid;
   TMenuItem *mEdu;
   TMenuItem *mExit;
   TMenuItem *mHelp;
   TMenuItem *mAbout;
   void __fastcall mDidClick(TObject *Sender);
   void __fastcall mEduClick(TObject *Sender);
   void __fastcall mExitClick(TObject *Sender);
   void __fastcall mStartClick(TObject *Sender);
   void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TfAdvancedPage(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfAdvancedPage *fAdvancedPage;
//---------------------------------------------------------------------------
#endif
