//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Mar 21 16:25:38 2023 by ROOT version 6.24/02
// from TTree DecayTree/DecayTree
// found on file: /data/home/pappenheimer/d2k3pi_data/selected_data_extended/2015/randomly_selected_RS_multiple_candidates.root
//////////////////////////////////////////////////////////

// For use with the K3PiStudies.cpp plotting code when processing data/full MC.

#pragma once

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include "K3PiStudiesHists.h"
#include "K3PiStudiesUtils.h"

namespace K3PiStudies
{

   class K3PiStudies
   {
   public:
      static const double _D0_LIFETIME_CUT_PS;

      TTree *fChain;  //! pointer to the analyzed TTree or TChain
      Int_t fCurrent; //! current Tree number in a TChain

      // Fixed size dimensions of array or collections stored in the TTree if any.

      // Declaration of leaf types
      Double_t D0_IPCHI2_OWNPV;
      Double_t D0_Loki_BPVIPCHI2;
      Double_t D0_Loki_BPVLTIME;
      Double_t D0_Loki_DOCACHI2MAX;
      Double_t D0_Loki_DOCAMAX;
      Double_t D0_Loki_VCHI2NDOF;
      Double_t D0_M;
      Double_t D0_MM;
      Int_t D0_P0_ID;
      Double_t D0_P0_IPCHI2_OWNPV;
      Double_t D0_P0_TRACK_CHI2NDOF;
      Double_t D0_P0_TRACK_GhostProb;
      Int_t D0_P1_ID;
      Double_t D0_P1_IPCHI2_OWNPV;
      Double_t D0_P1_TRACK_CHI2NDOF;
      Double_t D0_P1_TRACK_GhostProb;
      Int_t D0_P2_ID;
      Double_t D0_P2_IPCHI2_OWNPV;
      Double_t D0_P2_TRACK_CHI2NDOF;
      Double_t D0_P2_TRACK_GhostProb;
      Int_t D0_P3_ID;
      Double_t D0_P3_IPCHI2_OWNPV;
      Double_t D0_P3_TRACK_CHI2NDOF;
      Double_t D0_P3_TRACK_GhostProb;
      Double_t Dst_M;
      Double_t Dst_MM;
      Float_t Dst_ReFit_D0_M_best;
      Float_t Dst_ReFit_D0_PT;
      Float_t Dst_ReFit_D0_PX;
      Float_t Dst_ReFit_D0_PY;
      Float_t Dst_ReFit_D0_PZ;
      Float_t Dst_ReFit_D0_P_best;
      Int_t Dst_pi_ID;
      Double_t Dst_pi_IPCHI2_OWNPV;
      Double_t Dst_pi_PT;
      Double_t Dst_pi_PX;
      Double_t Dst_pi_PY;
      Double_t Dst_pi_PZ;
      Double_t Dst_pi_ProbNNe_common;
      Double_t Dst_pi_ProbNNmu_common;
      Double_t Dst_pi_ProbNNpi_common;
      Double_t Dst_pi_TRACK_CHI2NDOF;
      Double_t Dst_pi_TRACK_GhostProb;
      Float_t cos_theta_pis_trig;
      Float_t deltam_ReFit;
      ULong64_t eventNumber;
      Double_t id_verified_D0Fit_K_PE_best;
      Double_t id_verified_D0Fit_K_PX_best;
      Double_t id_verified_D0Fit_K_PY_best;
      Double_t id_verified_D0Fit_K_PZ_best;
      Double_t id_verified_D0Fit_Pi_OS_0_PE_best;
      Double_t id_verified_D0Fit_Pi_OS_0_PX_best;
      Double_t id_verified_D0Fit_Pi_OS_0_PY_best;
      Double_t id_verified_D0Fit_Pi_OS_0_PZ_best;
      Double_t id_verified_D0Fit_Pi_OS_1_PE_best;
      Double_t id_verified_D0Fit_Pi_OS_1_PX_best;
      Double_t id_verified_D0Fit_Pi_OS_1_PY_best;
      Double_t id_verified_D0Fit_Pi_OS_1_PZ_best;
      Double_t id_verified_D0Fit_Pi_SS_PE_best;
      Double_t id_verified_D0Fit_Pi_SS_PX_best;
      Double_t id_verified_D0Fit_Pi_SS_PY_best;
      Double_t id_verified_D0Fit_Pi_SS_PZ_best;
      Double_t id_verified_D0Fit_cos12_best;
      Double_t id_verified_D0Fit_cos12_ord_best;
      Double_t id_verified_D0Fit_cos34_best;
      Double_t id_verified_D0Fit_cos34_ord_best;
      Double_t id_verified_D0Fit_m12_best;
      Double_t id_verified_D0Fit_m12_ord_best;
      Double_t id_verified_D0Fit_m34_best;
      Double_t id_verified_D0Fit_m34_ord_best;
      Double_t id_verified_D0Fit_phi_best;
      Double_t id_verified_D0Fit_phi_ord_best;
      Double_t id_verified_ReFit_D0_K_PE_best;
      Double_t id_verified_ReFit_D0_K_PX_best;
      Double_t id_verified_ReFit_D0_K_PY_best;
      Double_t id_verified_ReFit_D0_K_PZ_best;
      Double_t id_verified_ReFit_D0_Pi_OS_0_PE_best;
      Double_t id_verified_ReFit_D0_Pi_OS_0_PX_best;
      Double_t id_verified_ReFit_D0_Pi_OS_0_PY_best;
      Double_t id_verified_ReFit_D0_Pi_OS_0_PZ_best;
      Double_t id_verified_ReFit_D0_Pi_OS_1_PE_best;
      Double_t id_verified_ReFit_D0_Pi_OS_1_PX_best;
      Double_t id_verified_ReFit_D0_Pi_OS_1_PY_best;
      Double_t id_verified_ReFit_D0_Pi_OS_1_PZ_best;
      Double_t id_verified_ReFit_D0_Pi_SS_PE_best;
      Double_t id_verified_ReFit_D0_Pi_SS_PX_best;
      Double_t id_verified_ReFit_D0_Pi_SS_PY_best;
      Double_t id_verified_ReFit_D0_Pi_SS_PZ_best;
      Bool_t in_both;
      UInt_t multiplicity;
      UInt_t runNumber;
      Bool_t select_mult_cand;
      ULong64_t unique_event_number;
      Double_t verified_id_D0_Part_K_M;
      Double_t verified_id_D0_Part_K_PE;
      Double_t verified_id_D0_Part_K_PX;
      Double_t verified_id_D0_Part_K_PY;
      Double_t verified_id_D0_Part_K_PZ;
      Double_t verified_id_D0_Part_K_ProbNNk;
      Double_t verified_id_D0_Part_K_ProbNNmu;
      Double_t verified_id_D0_Part_OS_Pi_0_M;
      Double_t verified_id_D0_Part_OS_Pi_0_PE;
      Double_t verified_id_D0_Part_OS_Pi_0_PX;
      Double_t verified_id_D0_Part_OS_Pi_0_PY;
      Double_t verified_id_D0_Part_OS_Pi_0_PZ;
      Double_t verified_id_D0_Part_OS_Pi_0_ProbNNk;
      Double_t verified_id_D0_Part_OS_Pi_0_ProbNNmu;
      Double_t verified_id_D0_Part_OS_Pi_0_ProbNNpi;
      Double_t verified_id_D0_Part_OS_Pi_1_M;
      Double_t verified_id_D0_Part_OS_Pi_1_PE;
      Double_t verified_id_D0_Part_OS_Pi_1_PX;
      Double_t verified_id_D0_Part_OS_Pi_1_PY;
      Double_t verified_id_D0_Part_OS_Pi_1_PZ;
      Double_t verified_id_D0_Part_OS_Pi_1_ProbNNk;
      Double_t verified_id_D0_Part_OS_Pi_1_ProbNNmu;
      Double_t verified_id_D0_Part_OS_Pi_1_ProbNNpi;
      Double_t verified_id_D0_Part_SS_Pi_M;
      Double_t verified_id_D0_Part_SS_Pi_PE;
      Double_t verified_id_D0_Part_SS_Pi_PX;
      Double_t verified_id_D0_Part_SS_Pi_PY;
      Double_t verified_id_D0_Part_SS_Pi_PZ;
      Double_t verified_id_D0_Part_SS_Pi_ProbNNk;
      Double_t verified_id_D0_Part_SS_Pi_ProbNNmu;
      Double_t verified_id_D0_Part_SS_Pi_ProbNNpi;

      // List of branches
      TBranch *b_D0_IPCHI2_OWNPV;                      //!
      TBranch *b_D0_Loki_BPVIPCHI2;                    //!
      TBranch *b_D0_Loki_BPVLTIME;                     //!
      TBranch *b_D0_Loki_DOCACHI2MAX;                  //!
      TBranch *b_D0_Loki_DOCAMAX;                      //!
      TBranch *b_D0_Loki_VCHI2NDOF;                    //!
      TBranch *b_D0_M;                                 //!
      TBranch *b_D0_MM;                                //!
      TBranch *b_D0_P0_ID;                             //!
      TBranch *b_D0_P0_IPCHI2_OWNPV;                   //!
      TBranch *b_D0_P0_TRACK_CHI2NDOF;                 //!
      TBranch *b_D0_P0_TRACK_GhostProb;                //!
      TBranch *b_D0_P1_ID;                             //!
      TBranch *b_D0_P1_IPCHI2_OWNPV;                   //!
      TBranch *b_D0_P1_TRACK_CHI2NDOF;                 //!
      TBranch *b_D0_P1_TRACK_GhostProb;                //!
      TBranch *b_D0_P2_ID;                             //!
      TBranch *b_D0_P2_IPCHI2_OWNPV;                   //!
      TBranch *b_D0_P2_TRACK_CHI2NDOF;                 //!
      TBranch *b_D0_P2_TRACK_GhostProb;                //!
      TBranch *b_D0_P3_ID;                             //!
      TBranch *b_D0_P3_IPCHI2_OWNPV;                   //!
      TBranch *b_D0_P3_TRACK_CHI2NDOF;                 //!
      TBranch *b_D0_P3_TRACK_GhostProb;                //!
      TBranch *b_Dst_M;                                //!
      TBranch *b_Dst_MM;                               //!
      TBranch *b_Dst_ReFit_D0_M_best;                  //!
      TBranch *b_Dst_ReFit_D0_PT;                      //!
      TBranch *b_Dst_ReFit_D0_PX;                      //!
      TBranch *b_Dst_ReFit_D0_PY;                      //!
      TBranch *b_Dst_ReFit_D0_PZ;                      //!
      TBranch *b_Dst_ReFit_D0_P_best;                  //!
      TBranch *b_Dst_pi_ID;                            //!
      TBranch *b_Dst_pi_IPCHI2_OWNPV;                  //!
      TBranch *b_Dst_pi_PT;                            //!
      TBranch *b_Dst_pi_PX;                            //!
      TBranch *b_Dst_pi_PY;                            //!
      TBranch *b_Dst_pi_PZ;                            //!
      TBranch *b_Dst_pi_ProbNNe_common;                //!
      TBranch *b_Dst_pi_ProbNNmu_common;               //!
      TBranch *b_Dst_pi_ProbNNpi_common;               //!
      TBranch *b_Dst_pi_TRACK_CHI2NDOF;                //!
      TBranch *b_Dst_pi_TRACK_GhostProb;               //!
      TBranch *b_cos_theta_pis_trig;                   //!
      TBranch *b_deltam_ReFit;                         //!
      TBranch *b_eventNumber;                          //!
      TBranch *b_id_verified_D0Fit_K_PE_best;          //!
      TBranch *b_id_verified_D0Fit_K_PX_best;          //!
      TBranch *b_id_verified_D0Fit_K_PY_best;          //!
      TBranch *b_id_verified_D0Fit_K_PZ_best;          //!
      TBranch *b_id_verified_D0Fit_Pi_OS_0_PE_best;    //!
      TBranch *b_id_verified_D0Fit_Pi_OS_0_PX_best;    //!
      TBranch *b_id_verified_D0Fit_Pi_OS_0_PY_best;    //!
      TBranch *b_id_verified_D0Fit_Pi_OS_0_PZ_best;    //!
      TBranch *b_id_verified_D0Fit_Pi_OS_1_PE_best;    //!
      TBranch *b_id_verified_D0Fit_Pi_OS_1_PX_best;    //!
      TBranch *b_id_verified_D0Fit_Pi_OS_1_PY_best;    //!
      TBranch *b_id_verified_D0Fit_Pi_OS_1_PZ_best;    //!
      TBranch *b_id_verified_D0Fit_Pi_SS_PE_best;      //!
      TBranch *b_id_verified_D0Fit_Pi_SS_PX_best;      //!
      TBranch *b_id_verified_D0Fit_Pi_SS_PY_best;      //!
      TBranch *b_id_verified_D0Fit_Pi_SS_PZ_best;      //!
      TBranch *b_id_verified_D0Fit_cos12_best;         //!
      TBranch *b_id_verified_D0Fit_cos12_ord_best;     //!
      TBranch *b_id_verified_D0Fit_cos34_best;         //!
      TBranch *b_id_verified_D0Fit_cos34_ord_best;     //!
      TBranch *b_id_verified_D0Fit_m12_best;           //!
      TBranch *b_id_verified_D0Fit_m12_ord_best;       //!
      TBranch *b_id_verified_D0Fit_m34_best;           //!
      TBranch *b_id_verified_D0Fit_m34_ord_best;       //!
      TBranch *b_id_verified_D0Fit_phi_best;           //!
      TBranch *b_id_verified_D0Fit_phi_ord_best;       //!
      TBranch *b_id_verified_ReFit_D0_K_PE_best;       //!
      TBranch *b_id_verified_ReFit_D0_K_PX_best;       //!
      TBranch *b_id_verified_ReFit_D0_K_PY_best;       //!
      TBranch *b_id_verified_ReFit_D0_K_PZ_best;       //!
      TBranch *b_id_verified_ReFit_D0_Pi_OS_0_PE_best; //!
      TBranch *b_id_verified_ReFit_D0_Pi_OS_0_PX_best; //!
      TBranch *b_id_verified_ReFit_D0_Pi_OS_0_PY_best; //!
      TBranch *b_id_verified_ReFit_D0_Pi_OS_0_PZ_best; //!
      TBranch *b_id_verified_ReFit_D0_Pi_OS_1_PE_best; //!
      TBranch *b_id_verified_ReFit_D0_Pi_OS_1_PX_best; //!
      TBranch *b_id_verified_ReFit_D0_Pi_OS_1_PY_best; //!
      TBranch *b_id_verified_ReFit_D0_Pi_OS_1_PZ_best; //!
      TBranch *b_id_verified_ReFit_D0_Pi_SS_PE_best;   //!
      TBranch *b_id_verified_ReFit_D0_Pi_SS_PX_best;   //!
      TBranch *b_id_verified_ReFit_D0_Pi_SS_PY_best;   //!
      TBranch *b_id_verified_ReFit_D0_Pi_SS_PZ_best;   //!
      TBranch *b_in_both;                              //!
      TBranch *b_multiplicity;                         //!
      TBranch *b_runNumber;                            //!
      TBranch *b_select_mult_cand;                     //!
      TBranch *b_unique_event_number;                  //!
      TBranch *b_verified_id_D0_Part_K_M;              //!
      TBranch *b_verified_id_D0_Part_K_PE;             //!
      TBranch *b_verified_id_D0_Part_K_PX;             //!
      TBranch *b_verified_id_D0_Part_K_PY;             //!
      TBranch *b_verified_id_D0_Part_K_PZ;             //!
      TBranch *b_verified_id_D0_Part_K_ProbNNk;        //!
      TBranch *b_verified_id_D0_Part_K_ProbNNmu;       //!
      TBranch *b_verified_id_D0_Part_OS_Pi_0_M;        //!
      TBranch *b_verified_id_D0_Part_OS_Pi_0_PE;       //!
      TBranch *b_verified_id_D0_Part_OS_Pi_0_PX;       //!
      TBranch *b_verified_id_D0_Part_OS_Pi_0_PY;       //!
      TBranch *b_verified_id_D0_Part_OS_Pi_0_PZ;       //!
      TBranch *b_verified_id_D0_Part_OS_Pi_0_ProbNNk;  //!
      TBranch *b_verified_id_D0_Part_OS_Pi_0_ProbNNmu; //!
      TBranch *b_verified_id_D0_Part_OS_Pi_0_ProbNNpi; //!
      TBranch *b_verified_id_D0_Part_OS_Pi_1_M;        //!
      TBranch *b_verified_id_D0_Part_OS_Pi_1_PE;       //!
      TBranch *b_verified_id_D0_Part_OS_Pi_1_PX;       //!
      TBranch *b_verified_id_D0_Part_OS_Pi_1_PY;       //!
      TBranch *b_verified_id_D0_Part_OS_Pi_1_PZ;       //!
      TBranch *b_verified_id_D0_Part_OS_Pi_1_ProbNNk;  //!
      TBranch *b_verified_id_D0_Part_OS_Pi_1_ProbNNmu; //!
      TBranch *b_verified_id_D0_Part_OS_Pi_1_ProbNNpi; //!
      TBranch *b_verified_id_D0_Part_SS_Pi_M;          //!
      TBranch *b_verified_id_D0_Part_SS_Pi_PE;         //!
      TBranch *b_verified_id_D0_Part_SS_Pi_PX;         //!
      TBranch *b_verified_id_D0_Part_SS_Pi_PY;         //!
      TBranch *b_verified_id_D0_Part_SS_Pi_PZ;         //!
      TBranch *b_verified_id_D0_Part_SS_Pi_ProbNNk;    //!
      TBranch *b_verified_id_D0_Part_SS_Pi_ProbNNmu;   //!
      TBranch *b_verified_id_D0_Part_SS_Pi_ProbNNpi;   //!

      K3PiStudies(TTree *tree = 0);
      virtual ~K3PiStudies();
      virtual Int_t Cut(Long64_t entry);
      virtual Int_t GetEntry(Long64_t entry);
      virtual Long64_t LoadTree(Long64_t entry);
      virtual void Init(TTree *tree);
      virtual Bool_t Notify();
      virtual void Show(Long64_t entry = -1);

      void processData(
          CommonHistsWithKinematics &commonHists,
          const TString &outputSubDir,
          const std::pair<double,
                          double> &decayTimeLimits_ps,
          bool applyDecayTimeCut,
          bool applyCuts,
          const std::string &mode,
          bool usingCTau,
          const TString &histNamePrefix,
          bool printSanityChecks,
          const std::string &varType,
          bool comparePhsp,
          bool verifyAngles);
   };

   K3PiStudies::K3PiStudies(TTree *tree) : fChain(0)
   {
      Init(tree);
   }

   K3PiStudies::~K3PiStudies()
   {
      if (!fChain)
         return;
      delete fChain->GetCurrentFile();
   }

   Int_t K3PiStudies::GetEntry(Long64_t entry)
   {
      // Read contents of entry.
      if (!fChain)
         return 0;
      return fChain->GetEntry(entry);
   }
   Long64_t K3PiStudies::LoadTree(Long64_t entry)
   {
      // Set the environment to read one entry
      if (!fChain)
         return -5;
      Long64_t centry = fChain->LoadTree(entry);
      if (centry < 0)
         return centry;
      if (fChain->GetTreeNumber() != fCurrent)
      {
         fCurrent = fChain->GetTreeNumber();
         Notify();
      }
      return centry;
   }

   void K3PiStudies::Init(TTree *tree)
   {
      // The Init() function is called when the selector needs to initialize
      // a new tree or chain. Typically here the branch addresses and branch
      // pointers of the tree will be set.
      // It is normally not necessary to make changes to the generated
      // code, but the routine can be extended by the user if needed.
      // Init() will be called many times when running on PROOF
      // (once per file to be processed).

      // Set branch addresses and branch pointers
      if (!tree)
         return;
      fChain = tree;
      fCurrent = -1;
      fChain->SetMakeClass(1);

      fChain->SetBranchAddress("D0_IPCHI2_OWNPV", &D0_IPCHI2_OWNPV, &b_D0_IPCHI2_OWNPV);
      fChain->SetBranchAddress("D0_Loki_BPVIPCHI2", &D0_Loki_BPVIPCHI2, &b_D0_Loki_BPVIPCHI2);
      fChain->SetBranchAddress("D0_Loki_BPVLTIME", &D0_Loki_BPVLTIME, &b_D0_Loki_BPVLTIME);
      fChain->SetBranchAddress("D0_Loki_DOCACHI2MAX", &D0_Loki_DOCACHI2MAX, &b_D0_Loki_DOCACHI2MAX);
      fChain->SetBranchAddress("D0_Loki_DOCAMAX", &D0_Loki_DOCAMAX, &b_D0_Loki_DOCAMAX);
      fChain->SetBranchAddress("D0_Loki_VCHI2NDOF", &D0_Loki_VCHI2NDOF, &b_D0_Loki_VCHI2NDOF);
      fChain->SetBranchAddress("D0_M", &D0_M, &b_D0_M);
      fChain->SetBranchAddress("D0_MM", &D0_MM, &b_D0_MM);
      fChain->SetBranchAddress("D0_P0_ID", &D0_P0_ID, &b_D0_P0_ID);
      fChain->SetBranchAddress("D0_P0_IPCHI2_OWNPV", &D0_P0_IPCHI2_OWNPV, &b_D0_P0_IPCHI2_OWNPV);
      fChain->SetBranchAddress("D0_P0_TRACK_CHI2NDOF", &D0_P0_TRACK_CHI2NDOF, &b_D0_P0_TRACK_CHI2NDOF);
      fChain->SetBranchAddress("D0_P0_TRACK_GhostProb", &D0_P0_TRACK_GhostProb, &b_D0_P0_TRACK_GhostProb);
      fChain->SetBranchAddress("D0_P1_ID", &D0_P1_ID, &b_D0_P1_ID);
      fChain->SetBranchAddress("D0_P1_IPCHI2_OWNPV", &D0_P1_IPCHI2_OWNPV, &b_D0_P1_IPCHI2_OWNPV);
      fChain->SetBranchAddress("D0_P1_TRACK_CHI2NDOF", &D0_P1_TRACK_CHI2NDOF, &b_D0_P1_TRACK_CHI2NDOF);
      fChain->SetBranchAddress("D0_P1_TRACK_GhostProb", &D0_P1_TRACK_GhostProb, &b_D0_P1_TRACK_GhostProb);
      fChain->SetBranchAddress("D0_P2_ID", &D0_P2_ID, &b_D0_P2_ID);
      fChain->SetBranchAddress("D0_P2_IPCHI2_OWNPV", &D0_P2_IPCHI2_OWNPV, &b_D0_P2_IPCHI2_OWNPV);
      fChain->SetBranchAddress("D0_P2_TRACK_CHI2NDOF", &D0_P2_TRACK_CHI2NDOF, &b_D0_P2_TRACK_CHI2NDOF);
      fChain->SetBranchAddress("D0_P2_TRACK_GhostProb", &D0_P2_TRACK_GhostProb, &b_D0_P2_TRACK_GhostProb);
      fChain->SetBranchAddress("D0_P3_ID", &D0_P3_ID, &b_D0_P3_ID);
      fChain->SetBranchAddress("D0_P3_IPCHI2_OWNPV", &D0_P3_IPCHI2_OWNPV, &b_D0_P3_IPCHI2_OWNPV);
      fChain->SetBranchAddress("D0_P3_TRACK_CHI2NDOF", &D0_P3_TRACK_CHI2NDOF, &b_D0_P3_TRACK_CHI2NDOF);
      fChain->SetBranchAddress("D0_P3_TRACK_GhostProb", &D0_P3_TRACK_GhostProb, &b_D0_P3_TRACK_GhostProb);
      fChain->SetBranchAddress("Dst_M", &Dst_M, &b_Dst_M);
      fChain->SetBranchAddress("Dst_MM", &Dst_MM, &b_Dst_MM);
      fChain->SetBranchAddress("Dst_ReFit_D0_M_best", &Dst_ReFit_D0_M_best, &b_Dst_ReFit_D0_M_best);
      fChain->SetBranchAddress("Dst_ReFit_D0_PT", &Dst_ReFit_D0_PT, &b_Dst_ReFit_D0_PT);
      fChain->SetBranchAddress("Dst_ReFit_D0_PX", &Dst_ReFit_D0_PX, &b_Dst_ReFit_D0_PX);
      fChain->SetBranchAddress("Dst_ReFit_D0_PY", &Dst_ReFit_D0_PY, &b_Dst_ReFit_D0_PY);
      fChain->SetBranchAddress("Dst_ReFit_D0_PZ", &Dst_ReFit_D0_PZ, &b_Dst_ReFit_D0_PZ);
      fChain->SetBranchAddress("Dst_ReFit_D0_P_best", &Dst_ReFit_D0_P_best, &b_Dst_ReFit_D0_P_best);
      fChain->SetBranchAddress("Dst_pi_ID", &Dst_pi_ID, &b_Dst_pi_ID);
      fChain->SetBranchAddress("Dst_pi_IPCHI2_OWNPV", &Dst_pi_IPCHI2_OWNPV, &b_Dst_pi_IPCHI2_OWNPV);
      fChain->SetBranchAddress("Dst_pi_PT", &Dst_pi_PT, &b_Dst_pi_PT);
      fChain->SetBranchAddress("Dst_pi_PX", &Dst_pi_PX, &b_Dst_pi_PX);
      fChain->SetBranchAddress("Dst_pi_PY", &Dst_pi_PY, &b_Dst_pi_PY);
      fChain->SetBranchAddress("Dst_pi_PZ", &Dst_pi_PZ, &b_Dst_pi_PZ);
      fChain->SetBranchAddress("Dst_pi_ProbNNe_common", &Dst_pi_ProbNNe_common, &b_Dst_pi_ProbNNe_common);
      fChain->SetBranchAddress("Dst_pi_ProbNNmu_common", &Dst_pi_ProbNNmu_common, &b_Dst_pi_ProbNNmu_common);
      fChain->SetBranchAddress("Dst_pi_ProbNNpi_common", &Dst_pi_ProbNNpi_common, &b_Dst_pi_ProbNNpi_common);
      fChain->SetBranchAddress("Dst_pi_TRACK_CHI2NDOF", &Dst_pi_TRACK_CHI2NDOF, &b_Dst_pi_TRACK_CHI2NDOF);
      fChain->SetBranchAddress("Dst_pi_TRACK_GhostProb", &Dst_pi_TRACK_GhostProb, &b_Dst_pi_TRACK_GhostProb);
      fChain->SetBranchAddress("cos_theta_pis_trig", &cos_theta_pis_trig, &b_cos_theta_pis_trig);
      fChain->SetBranchAddress("deltam_ReFit", &deltam_ReFit, &b_deltam_ReFit);
      fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
      fChain->SetBranchAddress("id_verified_D0Fit_K_PE_best", &id_verified_D0Fit_K_PE_best, &b_id_verified_D0Fit_K_PE_best);
      fChain->SetBranchAddress("id_verified_D0Fit_K_PX_best", &id_verified_D0Fit_K_PX_best, &b_id_verified_D0Fit_K_PX_best);
      fChain->SetBranchAddress("id_verified_D0Fit_K_PY_best", &id_verified_D0Fit_K_PY_best, &b_id_verified_D0Fit_K_PY_best);
      fChain->SetBranchAddress("id_verified_D0Fit_K_PZ_best", &id_verified_D0Fit_K_PZ_best, &b_id_verified_D0Fit_K_PZ_best);
      fChain->SetBranchAddress("id_verified_D0Fit_Pi_OS_0_PE_best", &id_verified_D0Fit_Pi_OS_0_PE_best, &b_id_verified_D0Fit_Pi_OS_0_PE_best);
      fChain->SetBranchAddress("id_verified_D0Fit_Pi_OS_0_PX_best", &id_verified_D0Fit_Pi_OS_0_PX_best, &b_id_verified_D0Fit_Pi_OS_0_PX_best);
      fChain->SetBranchAddress("id_verified_D0Fit_Pi_OS_0_PY_best", &id_verified_D0Fit_Pi_OS_0_PY_best, &b_id_verified_D0Fit_Pi_OS_0_PY_best);
      fChain->SetBranchAddress("id_verified_D0Fit_Pi_OS_0_PZ_best", &id_verified_D0Fit_Pi_OS_0_PZ_best, &b_id_verified_D0Fit_Pi_OS_0_PZ_best);
      fChain->SetBranchAddress("id_verified_D0Fit_Pi_OS_1_PE_best", &id_verified_D0Fit_Pi_OS_1_PE_best, &b_id_verified_D0Fit_Pi_OS_1_PE_best);
      fChain->SetBranchAddress("id_verified_D0Fit_Pi_OS_1_PX_best", &id_verified_D0Fit_Pi_OS_1_PX_best, &b_id_verified_D0Fit_Pi_OS_1_PX_best);
      fChain->SetBranchAddress("id_verified_D0Fit_Pi_OS_1_PY_best", &id_verified_D0Fit_Pi_OS_1_PY_best, &b_id_verified_D0Fit_Pi_OS_1_PY_best);
      fChain->SetBranchAddress("id_verified_D0Fit_Pi_OS_1_PZ_best", &id_verified_D0Fit_Pi_OS_1_PZ_best, &b_id_verified_D0Fit_Pi_OS_1_PZ_best);
      fChain->SetBranchAddress("id_verified_D0Fit_Pi_SS_PE_best", &id_verified_D0Fit_Pi_SS_PE_best, &b_id_verified_D0Fit_Pi_SS_PE_best);
      fChain->SetBranchAddress("id_verified_D0Fit_Pi_SS_PX_best", &id_verified_D0Fit_Pi_SS_PX_best, &b_id_verified_D0Fit_Pi_SS_PX_best);
      fChain->SetBranchAddress("id_verified_D0Fit_Pi_SS_PY_best", &id_verified_D0Fit_Pi_SS_PY_best, &b_id_verified_D0Fit_Pi_SS_PY_best);
      fChain->SetBranchAddress("id_verified_D0Fit_Pi_SS_PZ_best", &id_verified_D0Fit_Pi_SS_PZ_best, &b_id_verified_D0Fit_Pi_SS_PZ_best);
      fChain->SetBranchAddress("id_verified_D0Fit_cos12_best", &id_verified_D0Fit_cos12_best, &b_id_verified_D0Fit_cos12_best);
      fChain->SetBranchAddress("id_verified_D0Fit_cos12_ord_best", &id_verified_D0Fit_cos12_ord_best, &b_id_verified_D0Fit_cos12_ord_best);
      fChain->SetBranchAddress("id_verified_D0Fit_cos34_best", &id_verified_D0Fit_cos34_best, &b_id_verified_D0Fit_cos34_best);
      fChain->SetBranchAddress("id_verified_D0Fit_cos34_ord_best", &id_verified_D0Fit_cos34_ord_best, &b_id_verified_D0Fit_cos34_ord_best);
      fChain->SetBranchAddress("id_verified_D0Fit_m12_best", &id_verified_D0Fit_m12_best, &b_id_verified_D0Fit_m12_best);
      fChain->SetBranchAddress("id_verified_D0Fit_m12_ord_best", &id_verified_D0Fit_m12_ord_best, &b_id_verified_D0Fit_m12_ord_best);
      fChain->SetBranchAddress("id_verified_D0Fit_m34_best", &id_verified_D0Fit_m34_best, &b_id_verified_D0Fit_m34_best);
      fChain->SetBranchAddress("id_verified_D0Fit_m34_ord_best", &id_verified_D0Fit_m34_ord_best, &b_id_verified_D0Fit_m34_ord_best);
      fChain->SetBranchAddress("id_verified_D0Fit_phi_best", &id_verified_D0Fit_phi_best, &b_id_verified_D0Fit_phi_best);
      fChain->SetBranchAddress("id_verified_D0Fit_phi_ord_best", &id_verified_D0Fit_phi_ord_best, &b_id_verified_D0Fit_phi_ord_best);
      fChain->SetBranchAddress("id_verified_ReFit_D0_K_PE_best", &id_verified_ReFit_D0_K_PE_best, &b_id_verified_ReFit_D0_K_PE_best);
      fChain->SetBranchAddress("id_verified_ReFit_D0_K_PX_best", &id_verified_ReFit_D0_K_PX_best, &b_id_verified_ReFit_D0_K_PX_best);
      fChain->SetBranchAddress("id_verified_ReFit_D0_K_PY_best", &id_verified_ReFit_D0_K_PY_best, &b_id_verified_ReFit_D0_K_PY_best);
      fChain->SetBranchAddress("id_verified_ReFit_D0_K_PZ_best", &id_verified_ReFit_D0_K_PZ_best, &b_id_verified_ReFit_D0_K_PZ_best);
      fChain->SetBranchAddress("id_verified_ReFit_D0_Pi_OS_0_PE_best", &id_verified_ReFit_D0_Pi_OS_0_PE_best, &b_id_verified_ReFit_D0_Pi_OS_0_PE_best);
      fChain->SetBranchAddress("id_verified_ReFit_D0_Pi_OS_0_PX_best", &id_verified_ReFit_D0_Pi_OS_0_PX_best, &b_id_verified_ReFit_D0_Pi_OS_0_PX_best);
      fChain->SetBranchAddress("id_verified_ReFit_D0_Pi_OS_0_PY_best", &id_verified_ReFit_D0_Pi_OS_0_PY_best, &b_id_verified_ReFit_D0_Pi_OS_0_PY_best);
      fChain->SetBranchAddress("id_verified_ReFit_D0_Pi_OS_0_PZ_best", &id_verified_ReFit_D0_Pi_OS_0_PZ_best, &b_id_verified_ReFit_D0_Pi_OS_0_PZ_best);
      fChain->SetBranchAddress("id_verified_ReFit_D0_Pi_OS_1_PE_best", &id_verified_ReFit_D0_Pi_OS_1_PE_best, &b_id_verified_ReFit_D0_Pi_OS_1_PE_best);
      fChain->SetBranchAddress("id_verified_ReFit_D0_Pi_OS_1_PX_best", &id_verified_ReFit_D0_Pi_OS_1_PX_best, &b_id_verified_ReFit_D0_Pi_OS_1_PX_best);
      fChain->SetBranchAddress("id_verified_ReFit_D0_Pi_OS_1_PY_best", &id_verified_ReFit_D0_Pi_OS_1_PY_best, &b_id_verified_ReFit_D0_Pi_OS_1_PY_best);
      fChain->SetBranchAddress("id_verified_ReFit_D0_Pi_OS_1_PZ_best", &id_verified_ReFit_D0_Pi_OS_1_PZ_best, &b_id_verified_ReFit_D0_Pi_OS_1_PZ_best);
      fChain->SetBranchAddress("id_verified_ReFit_D0_Pi_SS_PE_best", &id_verified_ReFit_D0_Pi_SS_PE_best, &b_id_verified_ReFit_D0_Pi_SS_PE_best);
      fChain->SetBranchAddress("id_verified_ReFit_D0_Pi_SS_PX_best", &id_verified_ReFit_D0_Pi_SS_PX_best, &b_id_verified_ReFit_D0_Pi_SS_PX_best);
      fChain->SetBranchAddress("id_verified_ReFit_D0_Pi_SS_PY_best", &id_verified_ReFit_D0_Pi_SS_PY_best, &b_id_verified_ReFit_D0_Pi_SS_PY_best);
      fChain->SetBranchAddress("id_verified_ReFit_D0_Pi_SS_PZ_best", &id_verified_ReFit_D0_Pi_SS_PZ_best, &b_id_verified_ReFit_D0_Pi_SS_PZ_best);
      fChain->SetBranchAddress("in_both", &in_both, &b_in_both);
      fChain->SetBranchAddress("multiplicity", &multiplicity, &b_multiplicity);
      fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
      fChain->SetBranchAddress("select_mult_cand", &select_mult_cand, &b_select_mult_cand);
      fChain->SetBranchAddress("unique_event_number", &unique_event_number, &b_unique_event_number);
      fChain->SetBranchAddress("verified_id_D0_Part_K_M", &verified_id_D0_Part_K_M, &b_verified_id_D0_Part_K_M);
      fChain->SetBranchAddress("verified_id_D0_Part_K_PE", &verified_id_D0_Part_K_PE, &b_verified_id_D0_Part_K_PE);
      fChain->SetBranchAddress("verified_id_D0_Part_K_PX", &verified_id_D0_Part_K_PX, &b_verified_id_D0_Part_K_PX);
      fChain->SetBranchAddress("verified_id_D0_Part_K_PY", &verified_id_D0_Part_K_PY, &b_verified_id_D0_Part_K_PY);
      fChain->SetBranchAddress("verified_id_D0_Part_K_PZ", &verified_id_D0_Part_K_PZ, &b_verified_id_D0_Part_K_PZ);
      fChain->SetBranchAddress("verified_id_D0_Part_K_ProbNNk", &verified_id_D0_Part_K_ProbNNk, &b_verified_id_D0_Part_K_ProbNNk);
      fChain->SetBranchAddress("verified_id_D0_Part_K_ProbNNmu", &verified_id_D0_Part_K_ProbNNmu, &b_verified_id_D0_Part_K_ProbNNmu);
      fChain->SetBranchAddress("verified_id_D0_Part_OS_Pi_0_M", &verified_id_D0_Part_OS_Pi_0_M, &b_verified_id_D0_Part_OS_Pi_0_M);
      fChain->SetBranchAddress("verified_id_D0_Part_OS_Pi_0_PE", &verified_id_D0_Part_OS_Pi_0_PE, &b_verified_id_D0_Part_OS_Pi_0_PE);
      fChain->SetBranchAddress("verified_id_D0_Part_OS_Pi_0_PX", &verified_id_D0_Part_OS_Pi_0_PX, &b_verified_id_D0_Part_OS_Pi_0_PX);
      fChain->SetBranchAddress("verified_id_D0_Part_OS_Pi_0_PY", &verified_id_D0_Part_OS_Pi_0_PY, &b_verified_id_D0_Part_OS_Pi_0_PY);
      fChain->SetBranchAddress("verified_id_D0_Part_OS_Pi_0_PZ", &verified_id_D0_Part_OS_Pi_0_PZ, &b_verified_id_D0_Part_OS_Pi_0_PZ);
      fChain->SetBranchAddress("verified_id_D0_Part_OS_Pi_0_ProbNNk", &verified_id_D0_Part_OS_Pi_0_ProbNNk, &b_verified_id_D0_Part_OS_Pi_0_ProbNNk);
      fChain->SetBranchAddress("verified_id_D0_Part_OS_Pi_0_ProbNNmu", &verified_id_D0_Part_OS_Pi_0_ProbNNmu, &b_verified_id_D0_Part_OS_Pi_0_ProbNNmu);
      fChain->SetBranchAddress("verified_id_D0_Part_OS_Pi_0_ProbNNpi", &verified_id_D0_Part_OS_Pi_0_ProbNNpi, &b_verified_id_D0_Part_OS_Pi_0_ProbNNpi);
      fChain->SetBranchAddress("verified_id_D0_Part_OS_Pi_1_M", &verified_id_D0_Part_OS_Pi_1_M, &b_verified_id_D0_Part_OS_Pi_1_M);
      fChain->SetBranchAddress("verified_id_D0_Part_OS_Pi_1_PE", &verified_id_D0_Part_OS_Pi_1_PE, &b_verified_id_D0_Part_OS_Pi_1_PE);
      fChain->SetBranchAddress("verified_id_D0_Part_OS_Pi_1_PX", &verified_id_D0_Part_OS_Pi_1_PX, &b_verified_id_D0_Part_OS_Pi_1_PX);
      fChain->SetBranchAddress("verified_id_D0_Part_OS_Pi_1_PY", &verified_id_D0_Part_OS_Pi_1_PY, &b_verified_id_D0_Part_OS_Pi_1_PY);
      fChain->SetBranchAddress("verified_id_D0_Part_OS_Pi_1_PZ", &verified_id_D0_Part_OS_Pi_1_PZ, &b_verified_id_D0_Part_OS_Pi_1_PZ);
      fChain->SetBranchAddress("verified_id_D0_Part_OS_Pi_1_ProbNNk", &verified_id_D0_Part_OS_Pi_1_ProbNNk, &b_verified_id_D0_Part_OS_Pi_1_ProbNNk);
      fChain->SetBranchAddress("verified_id_D0_Part_OS_Pi_1_ProbNNmu", &verified_id_D0_Part_OS_Pi_1_ProbNNmu, &b_verified_id_D0_Part_OS_Pi_1_ProbNNmu);
      fChain->SetBranchAddress("verified_id_D0_Part_OS_Pi_1_ProbNNpi", &verified_id_D0_Part_OS_Pi_1_ProbNNpi, &b_verified_id_D0_Part_OS_Pi_1_ProbNNpi);
      fChain->SetBranchAddress("verified_id_D0_Part_SS_Pi_M", &verified_id_D0_Part_SS_Pi_M, &b_verified_id_D0_Part_SS_Pi_M);
      fChain->SetBranchAddress("verified_id_D0_Part_SS_Pi_PE", &verified_id_D0_Part_SS_Pi_PE, &b_verified_id_D0_Part_SS_Pi_PE);
      fChain->SetBranchAddress("verified_id_D0_Part_SS_Pi_PX", &verified_id_D0_Part_SS_Pi_PX, &b_verified_id_D0_Part_SS_Pi_PX);
      fChain->SetBranchAddress("verified_id_D0_Part_SS_Pi_PY", &verified_id_D0_Part_SS_Pi_PY, &b_verified_id_D0_Part_SS_Pi_PY);
      fChain->SetBranchAddress("verified_id_D0_Part_SS_Pi_PZ", &verified_id_D0_Part_SS_Pi_PZ, &b_verified_id_D0_Part_SS_Pi_PZ);
      fChain->SetBranchAddress("verified_id_D0_Part_SS_Pi_ProbNNk", &verified_id_D0_Part_SS_Pi_ProbNNk, &b_verified_id_D0_Part_SS_Pi_ProbNNk);
      fChain->SetBranchAddress("verified_id_D0_Part_SS_Pi_ProbNNmu", &verified_id_D0_Part_SS_Pi_ProbNNmu, &b_verified_id_D0_Part_SS_Pi_ProbNNmu);
      fChain->SetBranchAddress("verified_id_D0_Part_SS_Pi_ProbNNpi", &verified_id_D0_Part_SS_Pi_ProbNNpi, &b_verified_id_D0_Part_SS_Pi_ProbNNpi);
      Notify();
   }

   Bool_t K3PiStudies::Notify()
   {
      // The Notify() function is called when a new file is opened. This
      // can be either for a new TTree in a TChain or when when a new TTree
      // is started when using PROOF. It is normally not necessary to make changes
      // to the generated code, but the routine can be extended by the
      // user if needed. The return value is currently not used.

      return kTRUE;
   }

   void K3PiStudies::Show(Long64_t entry)
   {
      // Print contents of entry.
      // If entry is not specified, print current entry
      if (!fChain)
         return;
      fChain->Show(entry);
   }
   Int_t K3PiStudies::Cut(Long64_t entry)
   {
      // This function may be called from Loop.
      // returns  1 if entry is accepted.
      // returns -1 otherwise.
      return 1;
   }

} // end namespace K3PiStudies