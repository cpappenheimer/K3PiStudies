//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Nov 25 13:45:09 2014 by ROOT version 5.34/18
// from TTree DalitzEventList/DalitzEventList
// found on file: D02k3pi_RS_5005000evts.root
//////////////////////////////////////////////////////////

#ifndef McK3Pi_Analysis_h
#define McK3Pi_Analysis_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class McK3Pi_Analysis {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Double_t        D0_E;
   Double_t        D0_Px;
   Double_t        D0_Py;
   Double_t        D0_Pz;
   Double_t        D0_pdg;
   Double_t        Kplus_E;
   Double_t        Kplus_Px;
   Double_t        Kplus_Py;
   Double_t        Kplus_Pz;
   Double_t        Kplus_pdg;
   Double_t        Piminus1_E;
   Double_t        Piminus1_Px;
   Double_t        Piminus1_Py;
   Double_t        Piminus1_Pz;
   Double_t        Piminus1_pdg;
   Double_t        Piminus2_E;
   Double_t        Piminus2_Px;
   Double_t        Piminus2_Py;
   Double_t        Piminus2_Pz;
   Double_t        Piminus2_pdg;
   Double_t        Piplus_E;
   Double_t        Piplus_Px;
   Double_t        Piplus_Py;
   Double_t        Piplus_Pz;
   Double_t        Piplus_pdg;
   Double_t        genPdf;
   Double_t        weight;

   // List of branches
   TBranch        *b_D0_E;   //!
   TBranch        *b_D0_Px;   //!
   TBranch        *b_D0_Py;   //!
   TBranch        *b_D0_Pz;   //!
   TBranch        *b_D0_pdg;   //!
   TBranch        *b_Kplus_E;   //!
   TBranch        *b_Kplus_Px;   //!
   TBranch        *b_Kplus_Py;   //!
   TBranch        *b_Kplus_Pz;   //!
   TBranch        *b_Kplus_pdg;   //!
   TBranch        *b_Piminus1_E;   //!
   TBranch        *b_Piminus1_Px;   //!
   TBranch        *b_Piminus1_Py;   //!
   TBranch        *b_Piminus1_Pz;   //!
   TBranch        *b_Piminus1_pdg;   //!
   TBranch        *b_Piminus2_E;   //!
   TBranch        *b_Piminus2_Px;   //!
   TBranch        *b_Piminus2_Py;   //!
   TBranch        *b_Piminus2_Pz;   //!
   TBranch        *b_Piminus2_pdg;   //!
   TBranch        *b_Piplus_E;   //!
   TBranch        *b_Piplus_Px;   //!
   TBranch        *b_Piplus_Py;   //!
   TBranch        *b_Piplus_Pz;   //!
   TBranch        *b_Piplus_pdg;   //!
   TBranch        *b_genPdf;   //!
   TBranch        *b_weight;   //!

   McK3Pi_Analysis(TTree *tree=0);
   virtual ~McK3Pi_Analysis();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef McK3Pi_Analysis_cxx
McK3Pi_Analysis::McK3Pi_Analysis(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("D02k3pi_RS_5005000evts.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("D02k3pi_RS_5005000evts.root");
      }
      f->GetObject("DalitzEventList",tree);

   }
   Init(tree);
}

McK3Pi_Analysis::~McK3Pi_Analysis()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t McK3Pi_Analysis::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t McK3Pi_Analysis::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void McK3Pi_Analysis::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("D0_E", &D0_E, &b_D0_E);
   fChain->SetBranchAddress("D0_Px", &D0_Px, &b_D0_Px);
   fChain->SetBranchAddress("D0_Py", &D0_Py, &b_D0_Py);
   fChain->SetBranchAddress("D0_Pz", &D0_Pz, &b_D0_Pz);
   fChain->SetBranchAddress("D0_pdg", &D0_pdg, &b_D0_pdg);
   fChain->SetBranchAddress("Kplus_E", &Kplus_E, &b_Kplus_E);
   fChain->SetBranchAddress("Kplus_Px", &Kplus_Px, &b_Kplus_Px);
   fChain->SetBranchAddress("Kplus_Py", &Kplus_Py, &b_Kplus_Py);
   fChain->SetBranchAddress("Kplus_Pz", &Kplus_Pz, &b_Kplus_Pz);
   fChain->SetBranchAddress("Kplus_pdg", &Kplus_pdg, &b_Kplus_pdg);
   fChain->SetBranchAddress("Piminus1_E", &Piminus1_E, &b_Piminus1_E);
   fChain->SetBranchAddress("Piminus1_Px", &Piminus1_Px, &b_Piminus1_Px);
   fChain->SetBranchAddress("Piminus1_Py", &Piminus1_Py, &b_Piminus1_Py);
   fChain->SetBranchAddress("Piminus1_Pz", &Piminus1_Pz, &b_Piminus1_Pz);
   fChain->SetBranchAddress("Piminus1_pdg", &Piminus1_pdg, &b_Piminus1_pdg);
   fChain->SetBranchAddress("Piminus2_E", &Piminus2_E, &b_Piminus2_E);
   fChain->SetBranchAddress("Piminus2_Px", &Piminus2_Px, &b_Piminus2_Px);
   fChain->SetBranchAddress("Piminus2_Py", &Piminus2_Py, &b_Piminus2_Py);
   fChain->SetBranchAddress("Piminus2_Pz", &Piminus2_Pz, &b_Piminus2_Pz);
   fChain->SetBranchAddress("Piminus2_pdg", &Piminus2_pdg, &b_Piminus2_pdg);
   fChain->SetBranchAddress("Piplus_E", &Piplus_E, &b_Piplus_E);
   fChain->SetBranchAddress("Piplus_Px", &Piplus_Px, &b_Piplus_Px);
   fChain->SetBranchAddress("Piplus_Py", &Piplus_Py, &b_Piplus_Py);
   fChain->SetBranchAddress("Piplus_Pz", &Piplus_Pz, &b_Piplus_Pz);
   fChain->SetBranchAddress("Piplus_pdg", &Piplus_pdg, &b_Piplus_pdg);
   fChain->SetBranchAddress("genPdf", &genPdf, &b_genPdf);
   fChain->SetBranchAddress("weight", &weight, &b_weight);
   Notify();
}

Bool_t McK3Pi_Analysis::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void McK3Pi_Analysis::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t McK3Pi_Analysis::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef McK3Pi_Analysis_cxx
