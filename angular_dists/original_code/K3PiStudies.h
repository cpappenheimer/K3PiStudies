//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Sep  1 18:46:18 2014 by ROOT version 5.34/14
// from TTree DecayTree/DecayTree
// found on file: DVntuple-Aug13Ca1.root
//////////////////////////////////////////////////////////

#ifndef K3PiStudies_h
#define K3PiStudies_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.
const Int_t kMaxDstar_ENDVERTEX_COV = 1;
const Int_t kMaxDstar_OWNPV_COV = 1;
const Int_t kMaxD0_ENDVERTEX_COV = 1;
const Int_t kMaxD0_OWNPV_COV = 1;
const Int_t kMaxD0_ORIVX_COV = 1;
const Int_t kMaxKminus_OWNPV_COV = 1;
const Int_t kMaxKminus_ORIVX_COV = 1;
const Int_t kMaxPiplus1_OWNPV_COV = 1;
const Int_t kMaxPiplus1_ORIVX_COV = 1;
const Int_t kMaxPiplus2_OWNPV_COV = 1;
const Int_t kMaxPiplus2_ORIVX_COV = 1;
const Int_t kMaxPiminus_OWNPV_COV = 1;
const Int_t kMaxPiminus_ORIVX_COV = 1;
const Int_t kMaxSlowPi_OWNPV_COV = 1;
const Int_t kMaxSlowPi_ORIVX_COV = 1;

class K3PiStudies {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Double_t        Dstar_ENDVERTEX_X;
   Double_t        Dstar_ENDVERTEX_Y;
   Double_t        Dstar_ENDVERTEX_Z;
   Double_t        Dstar_ENDVERTEX_XERR;
   Double_t        Dstar_ENDVERTEX_YERR;
   Double_t        Dstar_ENDVERTEX_ZERR;
   Double_t        Dstar_ENDVERTEX_CHI2;
   Int_t           Dstar_ENDVERTEX_NDOF;
   Float_t         Dstar_ENDVERTEX_COV_[3][3];
   Double_t        Dstar_OWNPV_X;
   Double_t        Dstar_OWNPV_Y;
   Double_t        Dstar_OWNPV_Z;
   Double_t        Dstar_OWNPV_XERR;
   Double_t        Dstar_OWNPV_YERR;
   Double_t        Dstar_OWNPV_ZERR;
   Double_t        Dstar_OWNPV_CHI2;
   Int_t           Dstar_OWNPV_NDOF;
   Float_t         Dstar_OWNPV_COV_[3][3];
   Double_t        Dstar_IP_OWNPV;
   Double_t        Dstar_IPCHI2_OWNPV;
   Double_t        Dstar_FD_OWNPV;
   Double_t        Dstar_FDCHI2_OWNPV;
   Double_t        Dstar_DIRA_OWNPV;
   Double_t        Dstar_P;
   Double_t        Dstar_PT;
   Double_t        Dstar_PE;
   Double_t        Dstar_PX;
   Double_t        Dstar_PY;
   Double_t        Dstar_PZ;
   Double_t        Dstar_MM;
   Double_t        Dstar_MMERR;
   Double_t        Dstar_M;
   Int_t           Dstar_ID;
   Double_t        Dstar_BPV_nTracks;
   Int_t           Dstar_PVFit_nPV;
   Float_t         Dstar_PVFit_D0_Kplus_ID[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_D0_Kplus_PE[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_D0_Kplus_PX[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_D0_Kplus_PY[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_D0_Kplus_PZ[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_D0_M[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_D0_MERR[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_D0_P[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_D0_PERR[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_D0_ctau[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_D0_ctauErr[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_D0_decayLength[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_D0_decayLengthErr[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_D0_piplus_0_ID[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_D0_piplus_0_PE[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_D0_piplus_0_PX[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_D0_piplus_0_PY[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_D0_piplus_0_PZ[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_D0_piplus_1_ID[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_D0_piplus_1_PE[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_D0_piplus_1_PX[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_D0_piplus_1_PY[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_D0_piplus_1_PZ[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_D0_piplus_ID[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_D0_piplus_PE[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_D0_piplus_PX[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_D0_piplus_PY[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_D0_piplus_PZ[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_M[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_MERR[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_P[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_PERR[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_PV_X[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_PV_Y[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_PV_Z[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_PV_key[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_chi2[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_ctau[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_ctauErr[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_decayLength[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_decayLengthErr[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_nDOF[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_nIter[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_piplus_ID[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_piplus_PE[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_piplus_PX[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_piplus_PY[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_piplus_PZ[100];   //[Dstar_PVFit_nPV]
   Float_t         Dstar_PVFit_status[100];   //[Dstar_PVFit_nPV]
   Double_t        D0_ENDVERTEX_X;
   Double_t        D0_ENDVERTEX_Y;
   Double_t        D0_ENDVERTEX_Z;
   Double_t        D0_ENDVERTEX_XERR;
   Double_t        D0_ENDVERTEX_YERR;
   Double_t        D0_ENDVERTEX_ZERR;
   Double_t        D0_ENDVERTEX_CHI2;
   Int_t           D0_ENDVERTEX_NDOF;
   Float_t         D0_ENDVERTEX_COV_[3][3];
   Double_t        D0_OWNPV_X;
   Double_t        D0_OWNPV_Y;
   Double_t        D0_OWNPV_Z;
   Double_t        D0_OWNPV_XERR;
   Double_t        D0_OWNPV_YERR;
   Double_t        D0_OWNPV_ZERR;
   Double_t        D0_OWNPV_CHI2;
   Int_t           D0_OWNPV_NDOF;
   Float_t         D0_OWNPV_COV_[3][3];
   Double_t        D0_IP_OWNPV;
   Double_t        D0_IPCHI2_OWNPV;
   Double_t        D0_FD_OWNPV;
   Double_t        D0_FDCHI2_OWNPV;
   Double_t        D0_DIRA_OWNPV;
   Double_t        D0_ORIVX_X;
   Double_t        D0_ORIVX_Y;
   Double_t        D0_ORIVX_Z;
   Double_t        D0_ORIVX_XERR;
   Double_t        D0_ORIVX_YERR;
   Double_t        D0_ORIVX_ZERR;
   Double_t        D0_ORIVX_CHI2;
   Int_t           D0_ORIVX_NDOF;
   Float_t         D0_ORIVX_COV_[3][3];
   Double_t        D0_FD_ORIVX;
   Double_t        D0_FDCHI2_ORIVX;
   Double_t        D0_DIRA_ORIVX;
   Double_t        D0_P;
   Double_t        D0_PT;
   Double_t        D0_PE;
   Double_t        D0_PX;
   Double_t        D0_PY;
   Double_t        D0_PZ;
   Double_t        D0_MM;
   Double_t        D0_MMERR;
   Double_t        D0_M;
   Int_t           D0_ID;
   Double_t        Kminus_OWNPV_X;
   Double_t        Kminus_OWNPV_Y;
   Double_t        Kminus_OWNPV_Z;
   Double_t        Kminus_OWNPV_XERR;
   Double_t        Kminus_OWNPV_YERR;
   Double_t        Kminus_OWNPV_ZERR;
   Double_t        Kminus_OWNPV_CHI2;
   Int_t           Kminus_OWNPV_NDOF;
   Float_t         Kminus_OWNPV_COV_[3][3];
   Double_t        Kminus_IP_OWNPV;
   Double_t        Kminus_IPCHI2_OWNPV;
   Double_t        Kminus_ORIVX_X;
   Double_t        Kminus_ORIVX_Y;
   Double_t        Kminus_ORIVX_Z;
   Double_t        Kminus_ORIVX_XERR;
   Double_t        Kminus_ORIVX_YERR;
   Double_t        Kminus_ORIVX_ZERR;
   Double_t        Kminus_ORIVX_CHI2;
   Int_t           Kminus_ORIVX_NDOF;
   Float_t         Kminus_ORIVX_COV_[3][3];
   Double_t        Kminus_P;
   Double_t        Kminus_PT;
   Double_t        Kminus_PE;
   Double_t        Kminus_PX;
   Double_t        Kminus_PY;
   Double_t        Kminus_PZ;
   Double_t        Kminus_M;
   Int_t           Kminus_ID;
   Double_t        Kminus_PIDe;
   Double_t        Kminus_PIDmu;
   Double_t        Kminus_PIDK;
   Double_t        Kminus_PIDp;
   Double_t        Kminus_ProbNNe;
   Double_t        Kminus_ProbNNk;
   Double_t        Kminus_ProbNNp;
   Double_t        Kminus_ProbNNpi;
   Double_t        Kminus_ProbNNmu;
   Double_t        Kminus_ProbNNghost;
   Bool_t          Kminus_hasMuon;
   Bool_t          Kminus_isMuon;
   Bool_t          Kminus_hasRich;
   Bool_t          Kminus_hasCalo;
   Int_t           Kminus_TRACK_Type;
   Int_t           Kminus_TRACK_Key;
   Double_t        Kminus_TRACK_CHI2NDOF;
   Double_t        Kminus_TRACK_PCHI2;
   Double_t        Kminus_TRACK_MatchCHI2;
   Double_t        Kminus_TRACK_GhostProb;
   Double_t        Kminus_TRACK_CloneDist;
   Double_t        Kminus_TRACK_Likelihood;
   Double_t        Piplus1_OWNPV_X;
   Double_t        Piplus1_OWNPV_Y;
   Double_t        Piplus1_OWNPV_Z;
   Double_t        Piplus1_OWNPV_XERR;
   Double_t        Piplus1_OWNPV_YERR;
   Double_t        Piplus1_OWNPV_ZERR;
   Double_t        Piplus1_OWNPV_CHI2;
   Int_t           Piplus1_OWNPV_NDOF;
   Float_t         Piplus1_OWNPV_COV_[3][3];
   Double_t        Piplus1_IP_OWNPV;
   Double_t        Piplus1_IPCHI2_OWNPV;
   Double_t        Piplus1_ORIVX_X;
   Double_t        Piplus1_ORIVX_Y;
   Double_t        Piplus1_ORIVX_Z;
   Double_t        Piplus1_ORIVX_XERR;
   Double_t        Piplus1_ORIVX_YERR;
   Double_t        Piplus1_ORIVX_ZERR;
   Double_t        Piplus1_ORIVX_CHI2;
   Int_t           Piplus1_ORIVX_NDOF;
   Float_t         Piplus1_ORIVX_COV_[3][3];
   Double_t        Piplus1_P;
   Double_t        Piplus1_PT;
   Double_t        Piplus1_PE;
   Double_t        Piplus1_PX;
   Double_t        Piplus1_PY;
   Double_t        Piplus1_PZ;
   Double_t        Piplus1_M;
   Int_t           Piplus1_ID;
   Double_t        Piplus1_PIDe;
   Double_t        Piplus1_PIDmu;
   Double_t        Piplus1_PIDK;
   Double_t        Piplus1_PIDp;
   Double_t        Piplus1_ProbNNe;
   Double_t        Piplus1_ProbNNk;
   Double_t        Piplus1_ProbNNp;
   Double_t        Piplus1_ProbNNpi;
   Double_t        Piplus1_ProbNNmu;
   Double_t        Piplus1_ProbNNghost;
   Bool_t          Piplus1_hasMuon;
   Bool_t          Piplus1_isMuon;
   Bool_t          Piplus1_hasRich;
   Bool_t          Piplus1_hasCalo;
   Int_t           Piplus1_TRACK_Type;
   Int_t           Piplus1_TRACK_Key;
   Double_t        Piplus1_TRACK_CHI2NDOF;
   Double_t        Piplus1_TRACK_PCHI2;
   Double_t        Piplus1_TRACK_MatchCHI2;
   Double_t        Piplus1_TRACK_GhostProb;
   Double_t        Piplus1_TRACK_CloneDist;
   Double_t        Piplus1_TRACK_Likelihood;
   Double_t        Piplus2_OWNPV_X;
   Double_t        Piplus2_OWNPV_Y;
   Double_t        Piplus2_OWNPV_Z;
   Double_t        Piplus2_OWNPV_XERR;
   Double_t        Piplus2_OWNPV_YERR;
   Double_t        Piplus2_OWNPV_ZERR;
   Double_t        Piplus2_OWNPV_CHI2;
   Int_t           Piplus2_OWNPV_NDOF;
   Float_t         Piplus2_OWNPV_COV_[3][3];
   Double_t        Piplus2_IP_OWNPV;
   Double_t        Piplus2_IPCHI2_OWNPV;
   Double_t        Piplus2_ORIVX_X;
   Double_t        Piplus2_ORIVX_Y;
   Double_t        Piplus2_ORIVX_Z;
   Double_t        Piplus2_ORIVX_XERR;
   Double_t        Piplus2_ORIVX_YERR;
   Double_t        Piplus2_ORIVX_ZERR;
   Double_t        Piplus2_ORIVX_CHI2;
   Int_t           Piplus2_ORIVX_NDOF;
   Float_t         Piplus2_ORIVX_COV_[3][3];
   Double_t        Piplus2_P;
   Double_t        Piplus2_PT;
   Double_t        Piplus2_PE;
   Double_t        Piplus2_PX;
   Double_t        Piplus2_PY;
   Double_t        Piplus2_PZ;
   Double_t        Piplus2_M;
   Int_t           Piplus2_ID;
   Double_t        Piplus2_PIDe;
   Double_t        Piplus2_PIDmu;
   Double_t        Piplus2_PIDK;
   Double_t        Piplus2_PIDp;
   Double_t        Piplus2_ProbNNe;
   Double_t        Piplus2_ProbNNk;
   Double_t        Piplus2_ProbNNp;
   Double_t        Piplus2_ProbNNpi;
   Double_t        Piplus2_ProbNNmu;
   Double_t        Piplus2_ProbNNghost;
   Bool_t          Piplus2_hasMuon;
   Bool_t          Piplus2_isMuon;
   Bool_t          Piplus2_hasRich;
   Bool_t          Piplus2_hasCalo;
   Int_t           Piplus2_TRACK_Type;
   Int_t           Piplus2_TRACK_Key;
   Double_t        Piplus2_TRACK_CHI2NDOF;
   Double_t        Piplus2_TRACK_PCHI2;
   Double_t        Piplus2_TRACK_MatchCHI2;
   Double_t        Piplus2_TRACK_GhostProb;
   Double_t        Piplus2_TRACK_CloneDist;
   Double_t        Piplus2_TRACK_Likelihood;
   Double_t        Piminus_OWNPV_X;
   Double_t        Piminus_OWNPV_Y;
   Double_t        Piminus_OWNPV_Z;
   Double_t        Piminus_OWNPV_XERR;
   Double_t        Piminus_OWNPV_YERR;
   Double_t        Piminus_OWNPV_ZERR;
   Double_t        Piminus_OWNPV_CHI2;
   Int_t           Piminus_OWNPV_NDOF;
   Float_t         Piminus_OWNPV_COV_[3][3];
   Double_t        Piminus_IP_OWNPV;
   Double_t        Piminus_IPCHI2_OWNPV;
   Double_t        Piminus_ORIVX_X;
   Double_t        Piminus_ORIVX_Y;
   Double_t        Piminus_ORIVX_Z;
   Double_t        Piminus_ORIVX_XERR;
   Double_t        Piminus_ORIVX_YERR;
   Double_t        Piminus_ORIVX_ZERR;
   Double_t        Piminus_ORIVX_CHI2;
   Int_t           Piminus_ORIVX_NDOF;
   Float_t         Piminus_ORIVX_COV_[3][3];
   Double_t        Piminus_P;
   Double_t        Piminus_PT;
   Double_t        Piminus_PE;
   Double_t        Piminus_PX;
   Double_t        Piminus_PY;
   Double_t        Piminus_PZ;
   Double_t        Piminus_M;
   Int_t           Piminus_ID;
   Double_t        Piminus_PIDe;
   Double_t        Piminus_PIDmu;
   Double_t        Piminus_PIDK;
   Double_t        Piminus_PIDp;
   Double_t        Piminus_ProbNNe;
   Double_t        Piminus_ProbNNk;
   Double_t        Piminus_ProbNNp;
   Double_t        Piminus_ProbNNpi;
   Double_t        Piminus_ProbNNmu;
   Double_t        Piminus_ProbNNghost;
   Bool_t          Piminus_hasMuon;
   Bool_t          Piminus_isMuon;
   Bool_t          Piminus_hasRich;
   Bool_t          Piminus_hasCalo;
   Int_t           Piminus_TRACK_Type;
   Int_t           Piminus_TRACK_Key;
   Double_t        Piminus_TRACK_CHI2NDOF;
   Double_t        Piminus_TRACK_PCHI2;
   Double_t        Piminus_TRACK_MatchCHI2;
   Double_t        Piminus_TRACK_GhostProb;
   Double_t        Piminus_TRACK_CloneDist;
   Double_t        Piminus_TRACK_Likelihood;
   Double_t        SlowPi_OWNPV_X;
   Double_t        SlowPi_OWNPV_Y;
   Double_t        SlowPi_OWNPV_Z;
   Double_t        SlowPi_OWNPV_XERR;
   Double_t        SlowPi_OWNPV_YERR;
   Double_t        SlowPi_OWNPV_ZERR;
   Double_t        SlowPi_OWNPV_CHI2;
   Int_t           SlowPi_OWNPV_NDOF;
   Float_t         SlowPi_OWNPV_COV_[3][3];
   Double_t        SlowPi_IP_OWNPV;
   Double_t        SlowPi_IPCHI2_OWNPV;
   Double_t        SlowPi_ORIVX_X;
   Double_t        SlowPi_ORIVX_Y;
   Double_t        SlowPi_ORIVX_Z;
   Double_t        SlowPi_ORIVX_XERR;
   Double_t        SlowPi_ORIVX_YERR;
   Double_t        SlowPi_ORIVX_ZERR;
   Double_t        SlowPi_ORIVX_CHI2;
   Int_t           SlowPi_ORIVX_NDOF;
   Float_t         SlowPi_ORIVX_COV_[3][3];
   Double_t        SlowPi_P;
   Double_t        SlowPi_PT;
   Double_t        SlowPi_PE;
   Double_t        SlowPi_PX;
   Double_t        SlowPi_PY;
   Double_t        SlowPi_PZ;
   Double_t        SlowPi_M;
   Int_t           SlowPi_ID;
   Double_t        SlowPi_PIDe;
   Double_t        SlowPi_PIDmu;
   Double_t        SlowPi_PIDK;
   Double_t        SlowPi_PIDp;
   Double_t        SlowPi_ProbNNe;
   Double_t        SlowPi_ProbNNk;
   Double_t        SlowPi_ProbNNp;
   Double_t        SlowPi_ProbNNpi;
   Double_t        SlowPi_ProbNNmu;
   Double_t        SlowPi_ProbNNghost;
   Bool_t          SlowPi_hasMuon;
   Bool_t          SlowPi_isMuon;
   Bool_t          SlowPi_hasRich;
   Bool_t          SlowPi_hasCalo;
   Int_t           SlowPi_TRACK_Type;
   Int_t           SlowPi_TRACK_Key;
   Double_t        SlowPi_TRACK_CHI2NDOF;
   Double_t        SlowPi_TRACK_PCHI2;
   Double_t        SlowPi_TRACK_MatchCHI2;
   Double_t        SlowPi_TRACK_GhostProb;
   Double_t        SlowPi_TRACK_CloneDist;
   Double_t        SlowPi_TRACK_Likelihood;
   UInt_t          nCandidate;
   ULong64_t       totCandidates;
   ULong64_t       EventInSequence;
   UInt_t          runNumber;
   ULong64_t       eventNumber;
   UInt_t          BCID;
   Int_t           BCType;
   UInt_t          OdinTCK;
   UInt_t          L0DUTCK;
   UInt_t          HLTTCK;
   ULong64_t       GpsTime;
   Short_t         Polarity;
   Int_t           L0Global;
   UInt_t          Hlt1Global;
   UInt_t          Hlt2Global;
   Int_t           L0HadronDecision;
   UInt_t          L0nSelections;
   Int_t           Hlt1TrackAllL0Decision;
   Int_t           Hlt1L0AnyDecision;
   Int_t           Hlt1GlobalDecision;
   UInt_t          Hlt1nSelections;
   UInt_t          Hlt2nSelections;
   Int_t           MaxRoutingBits;
   Float_t         RoutingBits[64];   //[MaxRoutingBits]

   // List of branches
   TBranch        *b_Dstar_ENDVERTEX_X;   //!
   TBranch        *b_Dstar_ENDVERTEX_Y;   //!
   TBranch        *b_Dstar_ENDVERTEX_Z;   //!
   TBranch        *b_Dstar_ENDVERTEX_XERR;   //!
   TBranch        *b_Dstar_ENDVERTEX_YERR;   //!
   TBranch        *b_Dstar_ENDVERTEX_ZERR;   //!
   TBranch        *b_Dstar_ENDVERTEX_CHI2;   //!
   TBranch        *b_Dstar_ENDVERTEX_NDOF;   //!
   TBranch        *b_Dstar_ENDVERTEX_COV_;   //!
   TBranch        *b_Dstar_OWNPV_X;   //!
   TBranch        *b_Dstar_OWNPV_Y;   //!
   TBranch        *b_Dstar_OWNPV_Z;   //!
   TBranch        *b_Dstar_OWNPV_XERR;   //!
   TBranch        *b_Dstar_OWNPV_YERR;   //!
   TBranch        *b_Dstar_OWNPV_ZERR;   //!
   TBranch        *b_Dstar_OWNPV_CHI2;   //!
   TBranch        *b_Dstar_OWNPV_NDOF;   //!
   TBranch        *b_Dstar_OWNPV_COV_;   //!
   TBranch        *b_Dstar_IP_OWNPV;   //!
   TBranch        *b_Dstar_IPCHI2_OWNPV;   //!
   TBranch        *b_Dstar_FD_OWNPV;   //!
   TBranch        *b_Dstar_FDCHI2_OWNPV;   //!
   TBranch        *b_Dstar_DIRA_OWNPV;   //!
   TBranch        *b_Dstar_P;   //!
   TBranch        *b_Dstar_PT;   //!
   TBranch        *b_Dstar_PE;   //!
   TBranch        *b_Dstar_PX;   //!
   TBranch        *b_Dstar_PY;   //!
   TBranch        *b_Dstar_PZ;   //!
   TBranch        *b_Dstar_MM;   //!
   TBranch        *b_Dstar_MMERR;   //!
   TBranch        *b_Dstar_M;   //!
   TBranch        *b_Dstar_ID;   //!
   TBranch        *b_Dstar_BPV_nTracks;   //!
   TBranch        *b_Dstar_PVFit_nPV;   //!
   TBranch        *b_Dstar_PVFit_D0_Kplus_ID;   //!
   TBranch        *b_Dstar_PVFit_D0_Kplus_PE;   //!
   TBranch        *b_Dstar_PVFit_D0_Kplus_PX;   //!
   TBranch        *b_Dstar_PVFit_D0_Kplus_PY;   //!
   TBranch        *b_Dstar_PVFit_D0_Kplus_PZ;   //!
   TBranch        *b_Dstar_PVFit_D0_M;   //!
   TBranch        *b_Dstar_PVFit_D0_MERR;   //!
   TBranch        *b_Dstar_PVFit_D0_P;   //!
   TBranch        *b_Dstar_PVFit_D0_PERR;   //!
   TBranch        *b_Dstar_PVFit_D0_ctau;   //!
   TBranch        *b_Dstar_PVFit_D0_ctauErr;   //!
   TBranch        *b_Dstar_PVFit_D0_decayLength;   //!
   TBranch        *b_Dstar_PVFit_D0_decayLengthErr;   //!
   TBranch        *b_Dstar_PVFit_D0_piplus_0_ID;   //!
   TBranch        *b_Dstar_PVFit_D0_piplus_0_PE;   //!
   TBranch        *b_Dstar_PVFit_D0_piplus_0_PX;   //!
   TBranch        *b_Dstar_PVFit_D0_piplus_0_PY;   //!
   TBranch        *b_Dstar_PVFit_D0_piplus_0_PZ;   //!
   TBranch        *b_Dstar_PVFit_D0_piplus_1_ID;   //!
   TBranch        *b_Dstar_PVFit_D0_piplus_1_PE;   //!
   TBranch        *b_Dstar_PVFit_D0_piplus_1_PX;   //!
   TBranch        *b_Dstar_PVFit_D0_piplus_1_PY;   //!
   TBranch        *b_Dstar_PVFit_D0_piplus_1_PZ;   //!
   TBranch        *b_Dstar_PVFit_D0_piplus_ID;   //!
   TBranch        *b_Dstar_PVFit_D0_piplus_PE;   //!
   TBranch        *b_Dstar_PVFit_D0_piplus_PX;   //!
   TBranch        *b_Dstar_PVFit_D0_piplus_PY;   //!
   TBranch        *b_Dstar_PVFit_D0_piplus_PZ;   //!
   TBranch        *b_Dstar_PVFit_M;   //!
   TBranch        *b_Dstar_PVFit_MERR;   //!
   TBranch        *b_Dstar_PVFit_P;   //!
   TBranch        *b_Dstar_PVFit_PERR;   //!
   TBranch        *b_Dstar_PVFit_PV_X;   //!
   TBranch        *b_Dstar_PVFit_PV_Y;   //!
   TBranch        *b_Dstar_PVFit_PV_Z;   //!
   TBranch        *b_Dstar_PVFit_PV_key;   //!
   TBranch        *b_Dstar_PVFit_chi2;   //!
   TBranch        *b_Dstar_PVFit_ctau;   //!
   TBranch        *b_Dstar_PVFit_ctauErr;   //!
   TBranch        *b_Dstar_PVFit_decayLength;   //!
   TBranch        *b_Dstar_PVFit_decayLengthErr;   //!
   TBranch        *b_Dstar_PVFit_nDOF;   //!
   TBranch        *b_Dstar_PVFit_nIter;   //!
   TBranch        *b_Dstar_PVFit_piplus_ID;   //!
   TBranch        *b_Dstar_PVFit_piplus_PE;   //!
   TBranch        *b_Dstar_PVFit_piplus_PX;   //!
   TBranch        *b_Dstar_PVFit_piplus_PY;   //!
   TBranch        *b_Dstar_PVFit_piplus_PZ;   //!
   TBranch        *b_Dstar_PVFit_status;   //!
   TBranch        *b_D0_ENDVERTEX_X;   //!
   TBranch        *b_D0_ENDVERTEX_Y;   //!
   TBranch        *b_D0_ENDVERTEX_Z;   //!
   TBranch        *b_D0_ENDVERTEX_XERR;   //!
   TBranch        *b_D0_ENDVERTEX_YERR;   //!
   TBranch        *b_D0_ENDVERTEX_ZERR;   //!
   TBranch        *b_D0_ENDVERTEX_CHI2;   //!
   TBranch        *b_D0_ENDVERTEX_NDOF;   //!
   TBranch        *b_D0_ENDVERTEX_COV_;   //!
   TBranch        *b_D0_OWNPV_X;   //!
   TBranch        *b_D0_OWNPV_Y;   //!
   TBranch        *b_D0_OWNPV_Z;   //!
   TBranch        *b_D0_OWNPV_XERR;   //!
   TBranch        *b_D0_OWNPV_YERR;   //!
   TBranch        *b_D0_OWNPV_ZERR;   //!
   TBranch        *b_D0_OWNPV_CHI2;   //!
   TBranch        *b_D0_OWNPV_NDOF;   //!
   TBranch        *b_D0_OWNPV_COV_;   //!
   TBranch        *b_D0_IP_OWNPV;   //!
   TBranch        *b_D0_IPCHI2_OWNPV;   //!
   TBranch        *b_D0_FD_OWNPV;   //!
   TBranch        *b_D0_FDCHI2_OWNPV;   //!
   TBranch        *b_D0_DIRA_OWNPV;   //!
   TBranch        *b_D0_ORIVX_X;   //!
   TBranch        *b_D0_ORIVX_Y;   //!
   TBranch        *b_D0_ORIVX_Z;   //!
   TBranch        *b_D0_ORIVX_XERR;   //!
   TBranch        *b_D0_ORIVX_YERR;   //!
   TBranch        *b_D0_ORIVX_ZERR;   //!
   TBranch        *b_D0_ORIVX_CHI2;   //!
   TBranch        *b_D0_ORIVX_NDOF;   //!
   TBranch        *b_D0_ORIVX_COV_;   //!
   TBranch        *b_D0_FD_ORIVX;   //!
   TBranch        *b_D0_FDCHI2_ORIVX;   //!
   TBranch        *b_D0_DIRA_ORIVX;   //!
   TBranch        *b_D0_P;   //!
   TBranch        *b_D0_PT;   //!
   TBranch        *b_D0_PE;   //!
   TBranch        *b_D0_PX;   //!
   TBranch        *b_D0_PY;   //!
   TBranch        *b_D0_PZ;   //!
   TBranch        *b_D0_MM;   //!
   TBranch        *b_D0_MMERR;   //!
   TBranch        *b_D0_M;   //!
   TBranch        *b_D0_ID;   //!
   TBranch        *b_Kminus_OWNPV_X;   //!
   TBranch        *b_Kminus_OWNPV_Y;   //!
   TBranch        *b_Kminus_OWNPV_Z;   //!
   TBranch        *b_Kminus_OWNPV_XERR;   //!
   TBranch        *b_Kminus_OWNPV_YERR;   //!
   TBranch        *b_Kminus_OWNPV_ZERR;   //!
   TBranch        *b_Kminus_OWNPV_CHI2;   //!
   TBranch        *b_Kminus_OWNPV_NDOF;   //!
   TBranch        *b_Kminus_OWNPV_COV_;   //!
   TBranch        *b_Kminus_IP_OWNPV;   //!
   TBranch        *b_Kminus_IPCHI2_OWNPV;   //!
   TBranch        *b_Kminus_ORIVX_X;   //!
   TBranch        *b_Kminus_ORIVX_Y;   //!
   TBranch        *b_Kminus_ORIVX_Z;   //!
   TBranch        *b_Kminus_ORIVX_XERR;   //!
   TBranch        *b_Kminus_ORIVX_YERR;   //!
   TBranch        *b_Kminus_ORIVX_ZERR;   //!
   TBranch        *b_Kminus_ORIVX_CHI2;   //!
   TBranch        *b_Kminus_ORIVX_NDOF;   //!
   TBranch        *b_Kminus_ORIVX_COV_;   //!
   TBranch        *b_Kminus_P;   //!
   TBranch        *b_Kminus_PT;   //!
   TBranch        *b_Kminus_PE;   //!
   TBranch        *b_Kminus_PX;   //!
   TBranch        *b_Kminus_PY;   //!
   TBranch        *b_Kminus_PZ;   //!
   TBranch        *b_Kminus_M;   //!
   TBranch        *b_Kminus_ID;   //!
   TBranch        *b_Kminus_PIDe;   //!
   TBranch        *b_Kminus_PIDmu;   //!
   TBranch        *b_Kminus_PIDK;   //!
   TBranch        *b_Kminus_PIDp;   //!
   TBranch        *b_Kminus_ProbNNe;   //!
   TBranch        *b_Kminus_ProbNNk;   //!
   TBranch        *b_Kminus_ProbNNp;   //!
   TBranch        *b_Kminus_ProbNNpi;   //!
   TBranch        *b_Kminus_ProbNNmu;   //!
   TBranch        *b_Kminus_ProbNNghost;   //!
   TBranch        *b_Kminus_hasMuon;   //!
   TBranch        *b_Kminus_isMuon;   //!
   TBranch        *b_Kminus_hasRich;   //!
   TBranch        *b_Kminus_hasCalo;   //!
   TBranch        *b_Kminus_TRACK_Type;   //!
   TBranch        *b_Kminus_TRACK_Key;   //!
   TBranch        *b_Kminus_TRACK_CHI2NDOF;   //!
   TBranch        *b_Kminus_TRACK_PCHI2;   //!
   TBranch        *b_Kminus_TRACK_MatchCHI2;   //!
   TBranch        *b_Kminus_TRACK_GhostProb;   //!
   TBranch        *b_Kminus_TRACK_CloneDist;   //!
   TBranch        *b_Kminus_TRACK_Likelihood;   //!
   TBranch        *b_Piplus1_OWNPV_X;   //!
   TBranch        *b_Piplus1_OWNPV_Y;   //!
   TBranch        *b_Piplus1_OWNPV_Z;   //!
   TBranch        *b_Piplus1_OWNPV_XERR;   //!
   TBranch        *b_Piplus1_OWNPV_YERR;   //!
   TBranch        *b_Piplus1_OWNPV_ZERR;   //!
   TBranch        *b_Piplus1_OWNPV_CHI2;   //!
   TBranch        *b_Piplus1_OWNPV_NDOF;   //!
   TBranch        *b_Piplus1_OWNPV_COV_;   //!
   TBranch        *b_Piplus1_IP_OWNPV;   //!
   TBranch        *b_Piplus1_IPCHI2_OWNPV;   //!
   TBranch        *b_Piplus1_ORIVX_X;   //!
   TBranch        *b_Piplus1_ORIVX_Y;   //!
   TBranch        *b_Piplus1_ORIVX_Z;   //!
   TBranch        *b_Piplus1_ORIVX_XERR;   //!
   TBranch        *b_Piplus1_ORIVX_YERR;   //!
   TBranch        *b_Piplus1_ORIVX_ZERR;   //!
   TBranch        *b_Piplus1_ORIVX_CHI2;   //!
   TBranch        *b_Piplus1_ORIVX_NDOF;   //!
   TBranch        *b_Piplus1_ORIVX_COV_;   //!
   TBranch        *b_Piplus1_P;   //!
   TBranch        *b_Piplus1_PT;   //!
   TBranch        *b_Piplus1_PE;   //!
   TBranch        *b_Piplus1_PX;   //!
   TBranch        *b_Piplus1_PY;   //!
   TBranch        *b_Piplus1_PZ;   //!
   TBranch        *b_Piplus1_M;   //!
   TBranch        *b_Piplus1_ID;   //!
   TBranch        *b_Piplus1_PIDe;   //!
   TBranch        *b_Piplus1_PIDmu;   //!
   TBranch        *b_Piplus1_PIDK;   //!
   TBranch        *b_Piplus1_PIDp;   //!
   TBranch        *b_Piplus1_ProbNNe;   //!
   TBranch        *b_Piplus1_ProbNNk;   //!
   TBranch        *b_Piplus1_ProbNNp;   //!
   TBranch        *b_Piplus1_ProbNNpi;   //!
   TBranch        *b_Piplus1_ProbNNmu;   //!
   TBranch        *b_Piplus1_ProbNNghost;   //!
   TBranch        *b_Piplus1_hasMuon;   //!
   TBranch        *b_Piplus1_isMuon;   //!
   TBranch        *b_Piplus1_hasRich;   //!
   TBranch        *b_Piplus1_hasCalo;   //!
   TBranch        *b_Piplus1_TRACK_Type;   //!
   TBranch        *b_Piplus1_TRACK_Key;   //!
   TBranch        *b_Piplus1_TRACK_CHI2NDOF;   //!
   TBranch        *b_Piplus1_TRACK_PCHI2;   //!
   TBranch        *b_Piplus1_TRACK_MatchCHI2;   //!
   TBranch        *b_Piplus1_TRACK_GhostProb;   //!
   TBranch        *b_Piplus1_TRACK_CloneDist;   //!
   TBranch        *b_Piplus1_TRACK_Likelihood;   //!
   TBranch        *b_Piplus2_OWNPV_X;   //!
   TBranch        *b_Piplus2_OWNPV_Y;   //!
   TBranch        *b_Piplus2_OWNPV_Z;   //!
   TBranch        *b_Piplus2_OWNPV_XERR;   //!
   TBranch        *b_Piplus2_OWNPV_YERR;   //!
   TBranch        *b_Piplus2_OWNPV_ZERR;   //!
   TBranch        *b_Piplus2_OWNPV_CHI2;   //!
   TBranch        *b_Piplus2_OWNPV_NDOF;   //!
   TBranch        *b_Piplus2_OWNPV_COV_;   //!
   TBranch        *b_Piplus2_IP_OWNPV;   //!
   TBranch        *b_Piplus2_IPCHI2_OWNPV;   //!
   TBranch        *b_Piplus2_ORIVX_X;   //!
   TBranch        *b_Piplus2_ORIVX_Y;   //!
   TBranch        *b_Piplus2_ORIVX_Z;   //!
   TBranch        *b_Piplus2_ORIVX_XERR;   //!
   TBranch        *b_Piplus2_ORIVX_YERR;   //!
   TBranch        *b_Piplus2_ORIVX_ZERR;   //!
   TBranch        *b_Piplus2_ORIVX_CHI2;   //!
   TBranch        *b_Piplus2_ORIVX_NDOF;   //!
   TBranch        *b_Piplus2_ORIVX_COV_;   //!
   TBranch        *b_Piplus2_P;   //!
   TBranch        *b_Piplus2_PT;   //!
   TBranch        *b_Piplus2_PE;   //!
   TBranch        *b_Piplus2_PX;   //!
   TBranch        *b_Piplus2_PY;   //!
   TBranch        *b_Piplus2_PZ;   //!
   TBranch        *b_Piplus2_M;   //!
   TBranch        *b_Piplus2_ID;   //!
   TBranch        *b_Piplus2_PIDe;   //!
   TBranch        *b_Piplus2_PIDmu;   //!
   TBranch        *b_Piplus2_PIDK;   //!
   TBranch        *b_Piplus2_PIDp;   //!
   TBranch        *b_Piplus2_ProbNNe;   //!
   TBranch        *b_Piplus2_ProbNNk;   //!
   TBranch        *b_Piplus2_ProbNNp;   //!
   TBranch        *b_Piplus2_ProbNNpi;   //!
   TBranch        *b_Piplus2_ProbNNmu;   //!
   TBranch        *b_Piplus2_ProbNNghost;   //!
   TBranch        *b_Piplus2_hasMuon;   //!
   TBranch        *b_Piplus2_isMuon;   //!
   TBranch        *b_Piplus2_hasRich;   //!
   TBranch        *b_Piplus2_hasCalo;   //!
   TBranch        *b_Piplus2_TRACK_Type;   //!
   TBranch        *b_Piplus2_TRACK_Key;   //!
   TBranch        *b_Piplus2_TRACK_CHI2NDOF;   //!
   TBranch        *b_Piplus2_TRACK_PCHI2;   //!
   TBranch        *b_Piplus2_TRACK_MatchCHI2;   //!
   TBranch        *b_Piplus2_TRACK_GhostProb;   //!
   TBranch        *b_Piplus2_TRACK_CloneDist;   //!
   TBranch        *b_Piplus2_TRACK_Likelihood;   //!
   TBranch        *b_Piminus_OWNPV_X;   //!
   TBranch        *b_Piminus_OWNPV_Y;   //!
   TBranch        *b_Piminus_OWNPV_Z;   //!
   TBranch        *b_Piminus_OWNPV_XERR;   //!
   TBranch        *b_Piminus_OWNPV_YERR;   //!
   TBranch        *b_Piminus_OWNPV_ZERR;   //!
   TBranch        *b_Piminus_OWNPV_CHI2;   //!
   TBranch        *b_Piminus_OWNPV_NDOF;   //!
   TBranch        *b_Piminus_OWNPV_COV_;   //!
   TBranch        *b_Piminus_IP_OWNPV;   //!
   TBranch        *b_Piminus_IPCHI2_OWNPV;   //!
   TBranch        *b_Piminus_ORIVX_X;   //!
   TBranch        *b_Piminus_ORIVX_Y;   //!
   TBranch        *b_Piminus_ORIVX_Z;   //!
   TBranch        *b_Piminus_ORIVX_XERR;   //!
   TBranch        *b_Piminus_ORIVX_YERR;   //!
   TBranch        *b_Piminus_ORIVX_ZERR;   //!
   TBranch        *b_Piminus_ORIVX_CHI2;   //!
   TBranch        *b_Piminus_ORIVX_NDOF;   //!
   TBranch        *b_Piminus_ORIVX_COV_;   //!
   TBranch        *b_Piminus_P;   //!
   TBranch        *b_Piminus_PT;   //!
   TBranch        *b_Piminus_PE;   //!
   TBranch        *b_Piminus_PX;   //!
   TBranch        *b_Piminus_PY;   //!
   TBranch        *b_Piminus_PZ;   //!
   TBranch        *b_Piminus_M;   //!
   TBranch        *b_Piminus_ID;   //!
   TBranch        *b_Piminus_PIDe;   //!
   TBranch        *b_Piminus_PIDmu;   //!
   TBranch        *b_Piminus_PIDK;   //!
   TBranch        *b_Piminus_PIDp;   //!
   TBranch        *b_Piminus_ProbNNe;   //!
   TBranch        *b_Piminus_ProbNNk;   //!
   TBranch        *b_Piminus_ProbNNp;   //!
   TBranch        *b_Piminus_ProbNNpi;   //!
   TBranch        *b_Piminus_ProbNNmu;   //!
   TBranch        *b_Piminus_ProbNNghost;   //!
   TBranch        *b_Piminus_hasMuon;   //!
   TBranch        *b_Piminus_isMuon;   //!
   TBranch        *b_Piminus_hasRich;   //!
   TBranch        *b_Piminus_hasCalo;   //!
   TBranch        *b_Piminus_TRACK_Type;   //!
   TBranch        *b_Piminus_TRACK_Key;   //!
   TBranch        *b_Piminus_TRACK_CHI2NDOF;   //!
   TBranch        *b_Piminus_TRACK_PCHI2;   //!
   TBranch        *b_Piminus_TRACK_MatchCHI2;   //!
   TBranch        *b_Piminus_TRACK_GhostProb;   //!
   TBranch        *b_Piminus_TRACK_CloneDist;   //!
   TBranch        *b_Piminus_TRACK_Likelihood;   //!
   TBranch        *b_SlowPi_OWNPV_X;   //!
   TBranch        *b_SlowPi_OWNPV_Y;   //!
   TBranch        *b_SlowPi_OWNPV_Z;   //!
   TBranch        *b_SlowPi_OWNPV_XERR;   //!
   TBranch        *b_SlowPi_OWNPV_YERR;   //!
   TBranch        *b_SlowPi_OWNPV_ZERR;   //!
   TBranch        *b_SlowPi_OWNPV_CHI2;   //!
   TBranch        *b_SlowPi_OWNPV_NDOF;   //!
   TBranch        *b_SlowPi_OWNPV_COV_;   //!
   TBranch        *b_SlowPi_IP_OWNPV;   //!
   TBranch        *b_SlowPi_IPCHI2_OWNPV;   //!
   TBranch        *b_SlowPi_ORIVX_X;   //!
   TBranch        *b_SlowPi_ORIVX_Y;   //!
   TBranch        *b_SlowPi_ORIVX_Z;   //!
   TBranch        *b_SlowPi_ORIVX_XERR;   //!
   TBranch        *b_SlowPi_ORIVX_YERR;   //!
   TBranch        *b_SlowPi_ORIVX_ZERR;   //!
   TBranch        *b_SlowPi_ORIVX_CHI2;   //!
   TBranch        *b_SlowPi_ORIVX_NDOF;   //!
   TBranch        *b_SlowPi_ORIVX_COV_;   //!
   TBranch        *b_SlowPi_P;   //!
   TBranch        *b_SlowPi_PT;   //!
   TBranch        *b_SlowPi_PE;   //!
   TBranch        *b_SlowPi_PX;   //!
   TBranch        *b_SlowPi_PY;   //!
   TBranch        *b_SlowPi_PZ;   //!
   TBranch        *b_SlowPi_M;   //!
   TBranch        *b_SlowPi_ID;   //!
   TBranch        *b_SlowPi_PIDe;   //!
   TBranch        *b_SlowPi_PIDmu;   //!
   TBranch        *b_SlowPi_PIDK;   //!
   TBranch        *b_SlowPi_PIDp;   //!
   TBranch        *b_SlowPi_ProbNNe;   //!
   TBranch        *b_SlowPi_ProbNNk;   //!
   TBranch        *b_SlowPi_ProbNNp;   //!
   TBranch        *b_SlowPi_ProbNNpi;   //!
   TBranch        *b_SlowPi_ProbNNmu;   //!
   TBranch        *b_SlowPi_ProbNNghost;   //!
   TBranch        *b_SlowPi_hasMuon;   //!
   TBranch        *b_SlowPi_isMuon;   //!
   TBranch        *b_SlowPi_hasRich;   //!
   TBranch        *b_SlowPi_hasCalo;   //!
   TBranch        *b_SlowPi_TRACK_Type;   //!
   TBranch        *b_SlowPi_TRACK_Key;   //!
   TBranch        *b_SlowPi_TRACK_CHI2NDOF;   //!
   TBranch        *b_SlowPi_TRACK_PCHI2;   //!
   TBranch        *b_SlowPi_TRACK_MatchCHI2;   //!
   TBranch        *b_SlowPi_TRACK_GhostProb;   //!
   TBranch        *b_SlowPi_TRACK_CloneDist;   //!
   TBranch        *b_SlowPi_TRACK_Likelihood;   //!
   TBranch        *b_nCandidate;   //!
   TBranch        *b_totCandidates;   //!
   TBranch        *b_EventInSequence;   //!
   TBranch        *b_runNumber;   //!
   TBranch        *b_eventNumber;   //!
   TBranch        *b_BCID;   //!
   TBranch        *b_BCType;   //!
   TBranch        *b_OdinTCK;   //!
   TBranch        *b_L0DUTCK;   //!
   TBranch        *b_HLTTCK;   //!
   TBranch        *b_GpsTime;   //!
   TBranch        *b_Polarity;   //!
   TBranch        *b_L0Global;   //!
   TBranch        *b_Hlt1Global;   //!
   TBranch        *b_Hlt2Global;   //!
   TBranch        *b_L0HadronDecision;   //!
   TBranch        *b_L0nSelections;   //!
   TBranch        *b_Hlt1TrackAllL0Decision;   //!
   TBranch        *b_Hlt1L0AnyDecision;   //!
   TBranch        *b_Hlt1GlobalDecision;   //!
   TBranch        *b_Hlt1nSelections;   //!
   TBranch        *b_Hlt2nSelections;   //!
   TBranch        *b_MaxRoutingBits;   //!
   TBranch        *b_RoutingBits;   //!

   K3PiStudies(TTree *tree=0);
   virtual ~K3PiStudies();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef K3PiStudies_cxx
K3PiStudies::K3PiStudies(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {

#ifdef SINGLE_TREE
      // The following code should be used if you want this class to access
      //       // a single tree instead of a chain
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("DVntuple-Aug13Ca1.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("DVntuple-Aug13Ca1.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("DVntuple-Aug13Ca1.root:/KPPPtuple");
      dir->GetObject("DecayTree",tree);

//
//
#else // SINGLE_TREE
//
      // The following code should be used if you want this class to access a chain
      // of trees.
      TChain * chain = new TChain("DecayTree","");
       chain->Add("DVntuple-Aug13Ca1.root/KPPPtuple/DecayTree");
       chain->Add("DVntuple-Aug13Ca2.root/KPPPtuple/DecayTree");
       chain->Add("DVntuple-Aug13Ca3.root/KPPPtuple/DecayTree");
       chain->Add("DVntuple-Aug13Ca4.root/KPPPtuple/DecayTree");
       chain->Add("DVntuple-Aug13Cb1.root/KPPPtuple/DecayTree");
       chain->Add("DVntuple-Aug13Cb_2_3.root/KPPPtuple/DecayTree");
       chain->Add("DVntuple-Aug13Cb4.root/KPPPtuple/DecayTree");
       chain->Add("DVntuple-Aug13Cc1.root/KPPPtuple/DecayTree");
       chain->Add("DVntuple-Aug13Cc2.root/KPPPtuple/DecayTree");
       chain->Add("DVntuple-Aug13Cc3.root/KPPPtuple/DecayTree");
       chain->Add("DVntuple-Aug13Cc4.root/KPPPtuple/DecayTree");
       chain->Add("DVntuple-Aug13Cd1.root/KPPPtuple/DecayTree");
       chain->Add("DVntuple-Aug13Cd2.root/KPPPtuple/DecayTree");
       chain->Add("DVntuple-Aug13Cd3.root/KPPPtuple/DecayTree");
       chain->Add("DVntuple-Aug13Cd4.root/KPPPtuple/DecayTree");
       chain->Add("DVntuple-Aug13Ce1.root/KPPPtuple/DecayTree");
       chain->Add("DVntuple-Aug13Ce2.root/KPPPtuple/DecayTree");
       chain->Add("DVntuple-Aug13Ce3.root/KPPPtuple/DecayTree");
       chain->Add("DVntuple-Aug13Ce4.root/KPPPtuple/DecayTree");

      tree = chain;
#endif // SINGLE_TREE
   }
   Init(tree);
}

K3PiStudies::~K3PiStudies()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t K3PiStudies::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t K3PiStudies::LoadTree(Long64_t entry)
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
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Dstar_ENDVERTEX_X", &Dstar_ENDVERTEX_X, &b_Dstar_ENDVERTEX_X);
   fChain->SetBranchAddress("Dstar_ENDVERTEX_Y", &Dstar_ENDVERTEX_Y, &b_Dstar_ENDVERTEX_Y);
   fChain->SetBranchAddress("Dstar_ENDVERTEX_Z", &Dstar_ENDVERTEX_Z, &b_Dstar_ENDVERTEX_Z);
   fChain->SetBranchAddress("Dstar_ENDVERTEX_XERR", &Dstar_ENDVERTEX_XERR, &b_Dstar_ENDVERTEX_XERR);
   fChain->SetBranchAddress("Dstar_ENDVERTEX_YERR", &Dstar_ENDVERTEX_YERR, &b_Dstar_ENDVERTEX_YERR);
   fChain->SetBranchAddress("Dstar_ENDVERTEX_ZERR", &Dstar_ENDVERTEX_ZERR, &b_Dstar_ENDVERTEX_ZERR);
   fChain->SetBranchAddress("Dstar_ENDVERTEX_CHI2", &Dstar_ENDVERTEX_CHI2, &b_Dstar_ENDVERTEX_CHI2);
   fChain->SetBranchAddress("Dstar_ENDVERTEX_NDOF", &Dstar_ENDVERTEX_NDOF, &b_Dstar_ENDVERTEX_NDOF);
   fChain->SetBranchAddress("Dstar_ENDVERTEX_COV_", Dstar_ENDVERTEX_COV_, &b_Dstar_ENDVERTEX_COV_);
   fChain->SetBranchAddress("Dstar_OWNPV_X", &Dstar_OWNPV_X, &b_Dstar_OWNPV_X);
   fChain->SetBranchAddress("Dstar_OWNPV_Y", &Dstar_OWNPV_Y, &b_Dstar_OWNPV_Y);
   fChain->SetBranchAddress("Dstar_OWNPV_Z", &Dstar_OWNPV_Z, &b_Dstar_OWNPV_Z);
   fChain->SetBranchAddress("Dstar_OWNPV_XERR", &Dstar_OWNPV_XERR, &b_Dstar_OWNPV_XERR);
   fChain->SetBranchAddress("Dstar_OWNPV_YERR", &Dstar_OWNPV_YERR, &b_Dstar_OWNPV_YERR);
   fChain->SetBranchAddress("Dstar_OWNPV_ZERR", &Dstar_OWNPV_ZERR, &b_Dstar_OWNPV_ZERR);
   fChain->SetBranchAddress("Dstar_OWNPV_CHI2", &Dstar_OWNPV_CHI2, &b_Dstar_OWNPV_CHI2);
   fChain->SetBranchAddress("Dstar_OWNPV_NDOF", &Dstar_OWNPV_NDOF, &b_Dstar_OWNPV_NDOF);
   fChain->SetBranchAddress("Dstar_OWNPV_COV_", Dstar_OWNPV_COV_, &b_Dstar_OWNPV_COV_);
   fChain->SetBranchAddress("Dstar_IP_OWNPV", &Dstar_IP_OWNPV, &b_Dstar_IP_OWNPV);
   fChain->SetBranchAddress("Dstar_IPCHI2_OWNPV", &Dstar_IPCHI2_OWNPV, &b_Dstar_IPCHI2_OWNPV);
   fChain->SetBranchAddress("Dstar_FD_OWNPV", &Dstar_FD_OWNPV, &b_Dstar_FD_OWNPV);
   fChain->SetBranchAddress("Dstar_FDCHI2_OWNPV", &Dstar_FDCHI2_OWNPV, &b_Dstar_FDCHI2_OWNPV);
   fChain->SetBranchAddress("Dstar_DIRA_OWNPV", &Dstar_DIRA_OWNPV, &b_Dstar_DIRA_OWNPV);
   fChain->SetBranchAddress("Dstar_P", &Dstar_P, &b_Dstar_P);
   fChain->SetBranchAddress("Dstar_PT", &Dstar_PT, &b_Dstar_PT);
   fChain->SetBranchAddress("Dstar_PE", &Dstar_PE, &b_Dstar_PE);
   fChain->SetBranchAddress("Dstar_PX", &Dstar_PX, &b_Dstar_PX);
   fChain->SetBranchAddress("Dstar_PY", &Dstar_PY, &b_Dstar_PY);
   fChain->SetBranchAddress("Dstar_PZ", &Dstar_PZ, &b_Dstar_PZ);
   fChain->SetBranchAddress("Dstar_MM", &Dstar_MM, &b_Dstar_MM);
   fChain->SetBranchAddress("Dstar_MMERR", &Dstar_MMERR, &b_Dstar_MMERR);
   fChain->SetBranchAddress("Dstar_M", &Dstar_M, &b_Dstar_M);
   fChain->SetBranchAddress("Dstar_ID", &Dstar_ID, &b_Dstar_ID);
   fChain->SetBranchAddress("Dstar_BPV_nTracks", &Dstar_BPV_nTracks, &b_Dstar_BPV_nTracks);
   fChain->SetBranchAddress("Dstar_PVFit_nPV", &Dstar_PVFit_nPV, &b_Dstar_PVFit_nPV);
   fChain->SetBranchAddress("Dstar_PVFit_D0_Kplus_ID", Dstar_PVFit_D0_Kplus_ID, &b_Dstar_PVFit_D0_Kplus_ID);
   fChain->SetBranchAddress("Dstar_PVFit_D0_Kplus_PE", Dstar_PVFit_D0_Kplus_PE, &b_Dstar_PVFit_D0_Kplus_PE);
   fChain->SetBranchAddress("Dstar_PVFit_D0_Kplus_PX", Dstar_PVFit_D0_Kplus_PX, &b_Dstar_PVFit_D0_Kplus_PX);
   fChain->SetBranchAddress("Dstar_PVFit_D0_Kplus_PY", Dstar_PVFit_D0_Kplus_PY, &b_Dstar_PVFit_D0_Kplus_PY);
   fChain->SetBranchAddress("Dstar_PVFit_D0_Kplus_PZ", Dstar_PVFit_D0_Kplus_PZ, &b_Dstar_PVFit_D0_Kplus_PZ);
   fChain->SetBranchAddress("Dstar_PVFit_D0_M", Dstar_PVFit_D0_M, &b_Dstar_PVFit_D0_M);
   fChain->SetBranchAddress("Dstar_PVFit_D0_MERR", Dstar_PVFit_D0_MERR, &b_Dstar_PVFit_D0_MERR);
   fChain->SetBranchAddress("Dstar_PVFit_D0_P", Dstar_PVFit_D0_P, &b_Dstar_PVFit_D0_P);
   fChain->SetBranchAddress("Dstar_PVFit_D0_PERR", Dstar_PVFit_D0_PERR, &b_Dstar_PVFit_D0_PERR);
   fChain->SetBranchAddress("Dstar_PVFit_D0_ctau", Dstar_PVFit_D0_ctau, &b_Dstar_PVFit_D0_ctau);
   fChain->SetBranchAddress("Dstar_PVFit_D0_ctauErr", Dstar_PVFit_D0_ctauErr, &b_Dstar_PVFit_D0_ctauErr);
   fChain->SetBranchAddress("Dstar_PVFit_D0_decayLength", Dstar_PVFit_D0_decayLength, &b_Dstar_PVFit_D0_decayLength);
   fChain->SetBranchAddress("Dstar_PVFit_D0_decayLengthErr", Dstar_PVFit_D0_decayLengthErr, &b_Dstar_PVFit_D0_decayLengthErr);
   fChain->SetBranchAddress("Dstar_PVFit_D0_piplus_0_ID", Dstar_PVFit_D0_piplus_0_ID, &b_Dstar_PVFit_D0_piplus_0_ID);
   fChain->SetBranchAddress("Dstar_PVFit_D0_piplus_0_PE", Dstar_PVFit_D0_piplus_0_PE, &b_Dstar_PVFit_D0_piplus_0_PE);
   fChain->SetBranchAddress("Dstar_PVFit_D0_piplus_0_PX", Dstar_PVFit_D0_piplus_0_PX, &b_Dstar_PVFit_D0_piplus_0_PX);
   fChain->SetBranchAddress("Dstar_PVFit_D0_piplus_0_PY", Dstar_PVFit_D0_piplus_0_PY, &b_Dstar_PVFit_D0_piplus_0_PY);
   fChain->SetBranchAddress("Dstar_PVFit_D0_piplus_0_PZ", Dstar_PVFit_D0_piplus_0_PZ, &b_Dstar_PVFit_D0_piplus_0_PZ);
   fChain->SetBranchAddress("Dstar_PVFit_D0_piplus_1_ID", Dstar_PVFit_D0_piplus_1_ID, &b_Dstar_PVFit_D0_piplus_1_ID);
   fChain->SetBranchAddress("Dstar_PVFit_D0_piplus_1_PE", Dstar_PVFit_D0_piplus_1_PE, &b_Dstar_PVFit_D0_piplus_1_PE);
   fChain->SetBranchAddress("Dstar_PVFit_D0_piplus_1_PX", Dstar_PVFit_D0_piplus_1_PX, &b_Dstar_PVFit_D0_piplus_1_PX);
   fChain->SetBranchAddress("Dstar_PVFit_D0_piplus_1_PY", Dstar_PVFit_D0_piplus_1_PY, &b_Dstar_PVFit_D0_piplus_1_PY);
   fChain->SetBranchAddress("Dstar_PVFit_D0_piplus_1_PZ", Dstar_PVFit_D0_piplus_1_PZ, &b_Dstar_PVFit_D0_piplus_1_PZ);
   fChain->SetBranchAddress("Dstar_PVFit_D0_piplus_ID", Dstar_PVFit_D0_piplus_ID, &b_Dstar_PVFit_D0_piplus_ID);
   fChain->SetBranchAddress("Dstar_PVFit_D0_piplus_PE", Dstar_PVFit_D0_piplus_PE, &b_Dstar_PVFit_D0_piplus_PE);
   fChain->SetBranchAddress("Dstar_PVFit_D0_piplus_PX", Dstar_PVFit_D0_piplus_PX, &b_Dstar_PVFit_D0_piplus_PX);
   fChain->SetBranchAddress("Dstar_PVFit_D0_piplus_PY", Dstar_PVFit_D0_piplus_PY, &b_Dstar_PVFit_D0_piplus_PY);
   fChain->SetBranchAddress("Dstar_PVFit_D0_piplus_PZ", Dstar_PVFit_D0_piplus_PZ, &b_Dstar_PVFit_D0_piplus_PZ);
   fChain->SetBranchAddress("Dstar_PVFit_M", Dstar_PVFit_M, &b_Dstar_PVFit_M);
   fChain->SetBranchAddress("Dstar_PVFit_MERR", Dstar_PVFit_MERR, &b_Dstar_PVFit_MERR);
   fChain->SetBranchAddress("Dstar_PVFit_P", Dstar_PVFit_P, &b_Dstar_PVFit_P);
   fChain->SetBranchAddress("Dstar_PVFit_PERR", Dstar_PVFit_PERR, &b_Dstar_PVFit_PERR);
   fChain->SetBranchAddress("Dstar_PVFit_PV_X", Dstar_PVFit_PV_X, &b_Dstar_PVFit_PV_X);
   fChain->SetBranchAddress("Dstar_PVFit_PV_Y", Dstar_PVFit_PV_Y, &b_Dstar_PVFit_PV_Y);
   fChain->SetBranchAddress("Dstar_PVFit_PV_Z", Dstar_PVFit_PV_Z, &b_Dstar_PVFit_PV_Z);
   fChain->SetBranchAddress("Dstar_PVFit_PV_key", Dstar_PVFit_PV_key, &b_Dstar_PVFit_PV_key);
   fChain->SetBranchAddress("Dstar_PVFit_chi2", Dstar_PVFit_chi2, &b_Dstar_PVFit_chi2);
   fChain->SetBranchAddress("Dstar_PVFit_ctau", Dstar_PVFit_ctau, &b_Dstar_PVFit_ctau);
   fChain->SetBranchAddress("Dstar_PVFit_ctauErr", Dstar_PVFit_ctauErr, &b_Dstar_PVFit_ctauErr);
   fChain->SetBranchAddress("Dstar_PVFit_decayLength", Dstar_PVFit_decayLength, &b_Dstar_PVFit_decayLength);
   fChain->SetBranchAddress("Dstar_PVFit_decayLengthErr", Dstar_PVFit_decayLengthErr, &b_Dstar_PVFit_decayLengthErr);
   fChain->SetBranchAddress("Dstar_PVFit_nDOF", Dstar_PVFit_nDOF, &b_Dstar_PVFit_nDOF);
   fChain->SetBranchAddress("Dstar_PVFit_nIter", Dstar_PVFit_nIter, &b_Dstar_PVFit_nIter);
   fChain->SetBranchAddress("Dstar_PVFit_piplus_ID", Dstar_PVFit_piplus_ID, &b_Dstar_PVFit_piplus_ID);
   fChain->SetBranchAddress("Dstar_PVFit_piplus_PE", Dstar_PVFit_piplus_PE, &b_Dstar_PVFit_piplus_PE);
   fChain->SetBranchAddress("Dstar_PVFit_piplus_PX", Dstar_PVFit_piplus_PX, &b_Dstar_PVFit_piplus_PX);
   fChain->SetBranchAddress("Dstar_PVFit_piplus_PY", Dstar_PVFit_piplus_PY, &b_Dstar_PVFit_piplus_PY);
   fChain->SetBranchAddress("Dstar_PVFit_piplus_PZ", Dstar_PVFit_piplus_PZ, &b_Dstar_PVFit_piplus_PZ);
   fChain->SetBranchAddress("Dstar_PVFit_status", Dstar_PVFit_status, &b_Dstar_PVFit_status);
   fChain->SetBranchAddress("D0_ENDVERTEX_X", &D0_ENDVERTEX_X, &b_D0_ENDVERTEX_X);
   fChain->SetBranchAddress("D0_ENDVERTEX_Y", &D0_ENDVERTEX_Y, &b_D0_ENDVERTEX_Y);
   fChain->SetBranchAddress("D0_ENDVERTEX_Z", &D0_ENDVERTEX_Z, &b_D0_ENDVERTEX_Z);
   fChain->SetBranchAddress("D0_ENDVERTEX_XERR", &D0_ENDVERTEX_XERR, &b_D0_ENDVERTEX_XERR);
   fChain->SetBranchAddress("D0_ENDVERTEX_YERR", &D0_ENDVERTEX_YERR, &b_D0_ENDVERTEX_YERR);
   fChain->SetBranchAddress("D0_ENDVERTEX_ZERR", &D0_ENDVERTEX_ZERR, &b_D0_ENDVERTEX_ZERR);
   fChain->SetBranchAddress("D0_ENDVERTEX_CHI2", &D0_ENDVERTEX_CHI2, &b_D0_ENDVERTEX_CHI2);
   fChain->SetBranchAddress("D0_ENDVERTEX_NDOF", &D0_ENDVERTEX_NDOF, &b_D0_ENDVERTEX_NDOF);
   fChain->SetBranchAddress("D0_ENDVERTEX_COV_", D0_ENDVERTEX_COV_, &b_D0_ENDVERTEX_COV_);
   fChain->SetBranchAddress("D0_OWNPV_X", &D0_OWNPV_X, &b_D0_OWNPV_X);
   fChain->SetBranchAddress("D0_OWNPV_Y", &D0_OWNPV_Y, &b_D0_OWNPV_Y);
   fChain->SetBranchAddress("D0_OWNPV_Z", &D0_OWNPV_Z, &b_D0_OWNPV_Z);
   fChain->SetBranchAddress("D0_OWNPV_XERR", &D0_OWNPV_XERR, &b_D0_OWNPV_XERR);
   fChain->SetBranchAddress("D0_OWNPV_YERR", &D0_OWNPV_YERR, &b_D0_OWNPV_YERR);
   fChain->SetBranchAddress("D0_OWNPV_ZERR", &D0_OWNPV_ZERR, &b_D0_OWNPV_ZERR);
   fChain->SetBranchAddress("D0_OWNPV_CHI2", &D0_OWNPV_CHI2, &b_D0_OWNPV_CHI2);
   fChain->SetBranchAddress("D0_OWNPV_NDOF", &D0_OWNPV_NDOF, &b_D0_OWNPV_NDOF);
   fChain->SetBranchAddress("D0_OWNPV_COV_", D0_OWNPV_COV_, &b_D0_OWNPV_COV_);
   fChain->SetBranchAddress("D0_IP_OWNPV", &D0_IP_OWNPV, &b_D0_IP_OWNPV);
   fChain->SetBranchAddress("D0_IPCHI2_OWNPV", &D0_IPCHI2_OWNPV, &b_D0_IPCHI2_OWNPV);
   fChain->SetBranchAddress("D0_FD_OWNPV", &D0_FD_OWNPV, &b_D0_FD_OWNPV);
   fChain->SetBranchAddress("D0_FDCHI2_OWNPV", &D0_FDCHI2_OWNPV, &b_D0_FDCHI2_OWNPV);
   fChain->SetBranchAddress("D0_DIRA_OWNPV", &D0_DIRA_OWNPV, &b_D0_DIRA_OWNPV);
   fChain->SetBranchAddress("D0_ORIVX_X", &D0_ORIVX_X, &b_D0_ORIVX_X);
   fChain->SetBranchAddress("D0_ORIVX_Y", &D0_ORIVX_Y, &b_D0_ORIVX_Y);
   fChain->SetBranchAddress("D0_ORIVX_Z", &D0_ORIVX_Z, &b_D0_ORIVX_Z);
   fChain->SetBranchAddress("D0_ORIVX_XERR", &D0_ORIVX_XERR, &b_D0_ORIVX_XERR);
   fChain->SetBranchAddress("D0_ORIVX_YERR", &D0_ORIVX_YERR, &b_D0_ORIVX_YERR);
   fChain->SetBranchAddress("D0_ORIVX_ZERR", &D0_ORIVX_ZERR, &b_D0_ORIVX_ZERR);
   fChain->SetBranchAddress("D0_ORIVX_CHI2", &D0_ORIVX_CHI2, &b_D0_ORIVX_CHI2);
   fChain->SetBranchAddress("D0_ORIVX_NDOF", &D0_ORIVX_NDOF, &b_D0_ORIVX_NDOF);
   fChain->SetBranchAddress("D0_ORIVX_COV_", D0_ORIVX_COV_, &b_D0_ORIVX_COV_);
   fChain->SetBranchAddress("D0_FD_ORIVX", &D0_FD_ORIVX, &b_D0_FD_ORIVX);
   fChain->SetBranchAddress("D0_FDCHI2_ORIVX", &D0_FDCHI2_ORIVX, &b_D0_FDCHI2_ORIVX);
   fChain->SetBranchAddress("D0_DIRA_ORIVX", &D0_DIRA_ORIVX, &b_D0_DIRA_ORIVX);
   fChain->SetBranchAddress("D0_P", &D0_P, &b_D0_P);
   fChain->SetBranchAddress("D0_PT", &D0_PT, &b_D0_PT);
   fChain->SetBranchAddress("D0_PE", &D0_PE, &b_D0_PE);
   fChain->SetBranchAddress("D0_PX", &D0_PX, &b_D0_PX);
   fChain->SetBranchAddress("D0_PY", &D0_PY, &b_D0_PY);
   fChain->SetBranchAddress("D0_PZ", &D0_PZ, &b_D0_PZ);
   fChain->SetBranchAddress("D0_MM", &D0_MM, &b_D0_MM);
   fChain->SetBranchAddress("D0_MMERR", &D0_MMERR, &b_D0_MMERR);
   fChain->SetBranchAddress("D0_M", &D0_M, &b_D0_M);
   fChain->SetBranchAddress("D0_ID", &D0_ID, &b_D0_ID);
   fChain->SetBranchAddress("Kminus_OWNPV_X", &Kminus_OWNPV_X, &b_Kminus_OWNPV_X);
   fChain->SetBranchAddress("Kminus_OWNPV_Y", &Kminus_OWNPV_Y, &b_Kminus_OWNPV_Y);
   fChain->SetBranchAddress("Kminus_OWNPV_Z", &Kminus_OWNPV_Z, &b_Kminus_OWNPV_Z);
   fChain->SetBranchAddress("Kminus_OWNPV_XERR", &Kminus_OWNPV_XERR, &b_Kminus_OWNPV_XERR);
   fChain->SetBranchAddress("Kminus_OWNPV_YERR", &Kminus_OWNPV_YERR, &b_Kminus_OWNPV_YERR);
   fChain->SetBranchAddress("Kminus_OWNPV_ZERR", &Kminus_OWNPV_ZERR, &b_Kminus_OWNPV_ZERR);
   fChain->SetBranchAddress("Kminus_OWNPV_CHI2", &Kminus_OWNPV_CHI2, &b_Kminus_OWNPV_CHI2);
   fChain->SetBranchAddress("Kminus_OWNPV_NDOF", &Kminus_OWNPV_NDOF, &b_Kminus_OWNPV_NDOF);
   fChain->SetBranchAddress("Kminus_OWNPV_COV_", Kminus_OWNPV_COV_, &b_Kminus_OWNPV_COV_);
   fChain->SetBranchAddress("Kminus_IP_OWNPV", &Kminus_IP_OWNPV, &b_Kminus_IP_OWNPV);
   fChain->SetBranchAddress("Kminus_IPCHI2_OWNPV", &Kminus_IPCHI2_OWNPV, &b_Kminus_IPCHI2_OWNPV);
   fChain->SetBranchAddress("Kminus_ORIVX_X", &Kminus_ORIVX_X, &b_Kminus_ORIVX_X);
   fChain->SetBranchAddress("Kminus_ORIVX_Y", &Kminus_ORIVX_Y, &b_Kminus_ORIVX_Y);
   fChain->SetBranchAddress("Kminus_ORIVX_Z", &Kminus_ORIVX_Z, &b_Kminus_ORIVX_Z);
   fChain->SetBranchAddress("Kminus_ORIVX_XERR", &Kminus_ORIVX_XERR, &b_Kminus_ORIVX_XERR);
   fChain->SetBranchAddress("Kminus_ORIVX_YERR", &Kminus_ORIVX_YERR, &b_Kminus_ORIVX_YERR);
   fChain->SetBranchAddress("Kminus_ORIVX_ZERR", &Kminus_ORIVX_ZERR, &b_Kminus_ORIVX_ZERR);
   fChain->SetBranchAddress("Kminus_ORIVX_CHI2", &Kminus_ORIVX_CHI2, &b_Kminus_ORIVX_CHI2);
   fChain->SetBranchAddress("Kminus_ORIVX_NDOF", &Kminus_ORIVX_NDOF, &b_Kminus_ORIVX_NDOF);
   fChain->SetBranchAddress("Kminus_ORIVX_COV_", Kminus_ORIVX_COV_, &b_Kminus_ORIVX_COV_);
   fChain->SetBranchAddress("Kminus_P", &Kminus_P, &b_Kminus_P);
   fChain->SetBranchAddress("Kminus_PT", &Kminus_PT, &b_Kminus_PT);
   fChain->SetBranchAddress("Kminus_PE", &Kminus_PE, &b_Kminus_PE);
   fChain->SetBranchAddress("Kminus_PX", &Kminus_PX, &b_Kminus_PX);
   fChain->SetBranchAddress("Kminus_PY", &Kminus_PY, &b_Kminus_PY);
   fChain->SetBranchAddress("Kminus_PZ", &Kminus_PZ, &b_Kminus_PZ);
   fChain->SetBranchAddress("Kminus_M", &Kminus_M, &b_Kminus_M);
   fChain->SetBranchAddress("Kminus_ID", &Kminus_ID, &b_Kminus_ID);
   fChain->SetBranchAddress("Kminus_PIDe", &Kminus_PIDe, &b_Kminus_PIDe);
   fChain->SetBranchAddress("Kminus_PIDmu", &Kminus_PIDmu, &b_Kminus_PIDmu);
   fChain->SetBranchAddress("Kminus_PIDK", &Kminus_PIDK, &b_Kminus_PIDK);
   fChain->SetBranchAddress("Kminus_PIDp", &Kminus_PIDp, &b_Kminus_PIDp);
   fChain->SetBranchAddress("Kminus_ProbNNe", &Kminus_ProbNNe, &b_Kminus_ProbNNe);
   fChain->SetBranchAddress("Kminus_ProbNNk", &Kminus_ProbNNk, &b_Kminus_ProbNNk);
   fChain->SetBranchAddress("Kminus_ProbNNp", &Kminus_ProbNNp, &b_Kminus_ProbNNp);
   fChain->SetBranchAddress("Kminus_ProbNNpi", &Kminus_ProbNNpi, &b_Kminus_ProbNNpi);
   fChain->SetBranchAddress("Kminus_ProbNNmu", &Kminus_ProbNNmu, &b_Kminus_ProbNNmu);
   fChain->SetBranchAddress("Kminus_ProbNNghost", &Kminus_ProbNNghost, &b_Kminus_ProbNNghost);
   fChain->SetBranchAddress("Kminus_hasMuon", &Kminus_hasMuon, &b_Kminus_hasMuon);
   fChain->SetBranchAddress("Kminus_isMuon", &Kminus_isMuon, &b_Kminus_isMuon);
   fChain->SetBranchAddress("Kminus_hasRich", &Kminus_hasRich, &b_Kminus_hasRich);
   fChain->SetBranchAddress("Kminus_hasCalo", &Kminus_hasCalo, &b_Kminus_hasCalo);
   fChain->SetBranchAddress("Kminus_TRACK_Type", &Kminus_TRACK_Type, &b_Kminus_TRACK_Type);
   fChain->SetBranchAddress("Kminus_TRACK_Key", &Kminus_TRACK_Key, &b_Kminus_TRACK_Key);
   fChain->SetBranchAddress("Kminus_TRACK_CHI2NDOF", &Kminus_TRACK_CHI2NDOF, &b_Kminus_TRACK_CHI2NDOF);
   fChain->SetBranchAddress("Kminus_TRACK_PCHI2", &Kminus_TRACK_PCHI2, &b_Kminus_TRACK_PCHI2);
   fChain->SetBranchAddress("Kminus_TRACK_MatchCHI2", &Kminus_TRACK_MatchCHI2, &b_Kminus_TRACK_MatchCHI2);
   fChain->SetBranchAddress("Kminus_TRACK_GhostProb", &Kminus_TRACK_GhostProb, &b_Kminus_TRACK_GhostProb);
   fChain->SetBranchAddress("Kminus_TRACK_CloneDist", &Kminus_TRACK_CloneDist, &b_Kminus_TRACK_CloneDist);
   fChain->SetBranchAddress("Kminus_TRACK_Likelihood", &Kminus_TRACK_Likelihood, &b_Kminus_TRACK_Likelihood);
   fChain->SetBranchAddress("Piplus1_OWNPV_X", &Piplus1_OWNPV_X, &b_Piplus1_OWNPV_X);
   fChain->SetBranchAddress("Piplus1_OWNPV_Y", &Piplus1_OWNPV_Y, &b_Piplus1_OWNPV_Y);
   fChain->SetBranchAddress("Piplus1_OWNPV_Z", &Piplus1_OWNPV_Z, &b_Piplus1_OWNPV_Z);
   fChain->SetBranchAddress("Piplus1_OWNPV_XERR", &Piplus1_OWNPV_XERR, &b_Piplus1_OWNPV_XERR);
   fChain->SetBranchAddress("Piplus1_OWNPV_YERR", &Piplus1_OWNPV_YERR, &b_Piplus1_OWNPV_YERR);
   fChain->SetBranchAddress("Piplus1_OWNPV_ZERR", &Piplus1_OWNPV_ZERR, &b_Piplus1_OWNPV_ZERR);
   fChain->SetBranchAddress("Piplus1_OWNPV_CHI2", &Piplus1_OWNPV_CHI2, &b_Piplus1_OWNPV_CHI2);
   fChain->SetBranchAddress("Piplus1_OWNPV_NDOF", &Piplus1_OWNPV_NDOF, &b_Piplus1_OWNPV_NDOF);
   fChain->SetBranchAddress("Piplus1_OWNPV_COV_", Piplus1_OWNPV_COV_, &b_Piplus1_OWNPV_COV_);
   fChain->SetBranchAddress("Piplus1_IP_OWNPV", &Piplus1_IP_OWNPV, &b_Piplus1_IP_OWNPV);
   fChain->SetBranchAddress("Piplus1_IPCHI2_OWNPV", &Piplus1_IPCHI2_OWNPV, &b_Piplus1_IPCHI2_OWNPV);
   fChain->SetBranchAddress("Piplus1_ORIVX_X", &Piplus1_ORIVX_X, &b_Piplus1_ORIVX_X);
   fChain->SetBranchAddress("Piplus1_ORIVX_Y", &Piplus1_ORIVX_Y, &b_Piplus1_ORIVX_Y);
   fChain->SetBranchAddress("Piplus1_ORIVX_Z", &Piplus1_ORIVX_Z, &b_Piplus1_ORIVX_Z);
   fChain->SetBranchAddress("Piplus1_ORIVX_XERR", &Piplus1_ORIVX_XERR, &b_Piplus1_ORIVX_XERR);
   fChain->SetBranchAddress("Piplus1_ORIVX_YERR", &Piplus1_ORIVX_YERR, &b_Piplus1_ORIVX_YERR);
   fChain->SetBranchAddress("Piplus1_ORIVX_ZERR", &Piplus1_ORIVX_ZERR, &b_Piplus1_ORIVX_ZERR);
   fChain->SetBranchAddress("Piplus1_ORIVX_CHI2", &Piplus1_ORIVX_CHI2, &b_Piplus1_ORIVX_CHI2);
   fChain->SetBranchAddress("Piplus1_ORIVX_NDOF", &Piplus1_ORIVX_NDOF, &b_Piplus1_ORIVX_NDOF);
   fChain->SetBranchAddress("Piplus1_ORIVX_COV_", Piplus1_ORIVX_COV_, &b_Piplus1_ORIVX_COV_);
   fChain->SetBranchAddress("Piplus1_P", &Piplus1_P, &b_Piplus1_P);
   fChain->SetBranchAddress("Piplus1_PT", &Piplus1_PT, &b_Piplus1_PT);
   fChain->SetBranchAddress("Piplus1_PE", &Piplus1_PE, &b_Piplus1_PE);
   fChain->SetBranchAddress("Piplus1_PX", &Piplus1_PX, &b_Piplus1_PX);
   fChain->SetBranchAddress("Piplus1_PY", &Piplus1_PY, &b_Piplus1_PY);
   fChain->SetBranchAddress("Piplus1_PZ", &Piplus1_PZ, &b_Piplus1_PZ);
   fChain->SetBranchAddress("Piplus1_M", &Piplus1_M, &b_Piplus1_M);
   fChain->SetBranchAddress("Piplus1_ID", &Piplus1_ID, &b_Piplus1_ID);
   fChain->SetBranchAddress("Piplus1_PIDe", &Piplus1_PIDe, &b_Piplus1_PIDe);
   fChain->SetBranchAddress("Piplus1_PIDmu", &Piplus1_PIDmu, &b_Piplus1_PIDmu);
   fChain->SetBranchAddress("Piplus1_PIDK", &Piplus1_PIDK, &b_Piplus1_PIDK);
   fChain->SetBranchAddress("Piplus1_PIDp", &Piplus1_PIDp, &b_Piplus1_PIDp);
   fChain->SetBranchAddress("Piplus1_ProbNNe", &Piplus1_ProbNNe, &b_Piplus1_ProbNNe);
   fChain->SetBranchAddress("Piplus1_ProbNNk", &Piplus1_ProbNNk, &b_Piplus1_ProbNNk);
   fChain->SetBranchAddress("Piplus1_ProbNNp", &Piplus1_ProbNNp, &b_Piplus1_ProbNNp);
   fChain->SetBranchAddress("Piplus1_ProbNNpi", &Piplus1_ProbNNpi, &b_Piplus1_ProbNNpi);
   fChain->SetBranchAddress("Piplus1_ProbNNmu", &Piplus1_ProbNNmu, &b_Piplus1_ProbNNmu);
   fChain->SetBranchAddress("Piplus1_ProbNNghost", &Piplus1_ProbNNghost, &b_Piplus1_ProbNNghost);
   fChain->SetBranchAddress("Piplus1_hasMuon", &Piplus1_hasMuon, &b_Piplus1_hasMuon);
   fChain->SetBranchAddress("Piplus1_isMuon", &Piplus1_isMuon, &b_Piplus1_isMuon);
   fChain->SetBranchAddress("Piplus1_hasRich", &Piplus1_hasRich, &b_Piplus1_hasRich);
   fChain->SetBranchAddress("Piplus1_hasCalo", &Piplus1_hasCalo, &b_Piplus1_hasCalo);
   fChain->SetBranchAddress("Piplus1_TRACK_Type", &Piplus1_TRACK_Type, &b_Piplus1_TRACK_Type);
   fChain->SetBranchAddress("Piplus1_TRACK_Key", &Piplus1_TRACK_Key, &b_Piplus1_TRACK_Key);
   fChain->SetBranchAddress("Piplus1_TRACK_CHI2NDOF", &Piplus1_TRACK_CHI2NDOF, &b_Piplus1_TRACK_CHI2NDOF);
   fChain->SetBranchAddress("Piplus1_TRACK_PCHI2", &Piplus1_TRACK_PCHI2, &b_Piplus1_TRACK_PCHI2);
   fChain->SetBranchAddress("Piplus1_TRACK_MatchCHI2", &Piplus1_TRACK_MatchCHI2, &b_Piplus1_TRACK_MatchCHI2);
   fChain->SetBranchAddress("Piplus1_TRACK_GhostProb", &Piplus1_TRACK_GhostProb, &b_Piplus1_TRACK_GhostProb);
   fChain->SetBranchAddress("Piplus1_TRACK_CloneDist", &Piplus1_TRACK_CloneDist, &b_Piplus1_TRACK_CloneDist);
   fChain->SetBranchAddress("Piplus1_TRACK_Likelihood", &Piplus1_TRACK_Likelihood, &b_Piplus1_TRACK_Likelihood);
   fChain->SetBranchAddress("Piplus2_OWNPV_X", &Piplus2_OWNPV_X, &b_Piplus2_OWNPV_X);
   fChain->SetBranchAddress("Piplus2_OWNPV_Y", &Piplus2_OWNPV_Y, &b_Piplus2_OWNPV_Y);
   fChain->SetBranchAddress("Piplus2_OWNPV_Z", &Piplus2_OWNPV_Z, &b_Piplus2_OWNPV_Z);
   fChain->SetBranchAddress("Piplus2_OWNPV_XERR", &Piplus2_OWNPV_XERR, &b_Piplus2_OWNPV_XERR);
   fChain->SetBranchAddress("Piplus2_OWNPV_YERR", &Piplus2_OWNPV_YERR, &b_Piplus2_OWNPV_YERR);
   fChain->SetBranchAddress("Piplus2_OWNPV_ZERR", &Piplus2_OWNPV_ZERR, &b_Piplus2_OWNPV_ZERR);
   fChain->SetBranchAddress("Piplus2_OWNPV_CHI2", &Piplus2_OWNPV_CHI2, &b_Piplus2_OWNPV_CHI2);
   fChain->SetBranchAddress("Piplus2_OWNPV_NDOF", &Piplus2_OWNPV_NDOF, &b_Piplus2_OWNPV_NDOF);
   fChain->SetBranchAddress("Piplus2_OWNPV_COV_", Piplus2_OWNPV_COV_, &b_Piplus2_OWNPV_COV_);
   fChain->SetBranchAddress("Piplus2_IP_OWNPV", &Piplus2_IP_OWNPV, &b_Piplus2_IP_OWNPV);
   fChain->SetBranchAddress("Piplus2_IPCHI2_OWNPV", &Piplus2_IPCHI2_OWNPV, &b_Piplus2_IPCHI2_OWNPV);
   fChain->SetBranchAddress("Piplus2_ORIVX_X", &Piplus2_ORIVX_X, &b_Piplus2_ORIVX_X);
   fChain->SetBranchAddress("Piplus2_ORIVX_Y", &Piplus2_ORIVX_Y, &b_Piplus2_ORIVX_Y);
   fChain->SetBranchAddress("Piplus2_ORIVX_Z", &Piplus2_ORIVX_Z, &b_Piplus2_ORIVX_Z);
   fChain->SetBranchAddress("Piplus2_ORIVX_XERR", &Piplus2_ORIVX_XERR, &b_Piplus2_ORIVX_XERR);
   fChain->SetBranchAddress("Piplus2_ORIVX_YERR", &Piplus2_ORIVX_YERR, &b_Piplus2_ORIVX_YERR);
   fChain->SetBranchAddress("Piplus2_ORIVX_ZERR", &Piplus2_ORIVX_ZERR, &b_Piplus2_ORIVX_ZERR);
   fChain->SetBranchAddress("Piplus2_ORIVX_CHI2", &Piplus2_ORIVX_CHI2, &b_Piplus2_ORIVX_CHI2);
   fChain->SetBranchAddress("Piplus2_ORIVX_NDOF", &Piplus2_ORIVX_NDOF, &b_Piplus2_ORIVX_NDOF);
   fChain->SetBranchAddress("Piplus2_ORIVX_COV_", Piplus2_ORIVX_COV_, &b_Piplus2_ORIVX_COV_);
   fChain->SetBranchAddress("Piplus2_P", &Piplus2_P, &b_Piplus2_P);
   fChain->SetBranchAddress("Piplus2_PT", &Piplus2_PT, &b_Piplus2_PT);
   fChain->SetBranchAddress("Piplus2_PE", &Piplus2_PE, &b_Piplus2_PE);
   fChain->SetBranchAddress("Piplus2_PX", &Piplus2_PX, &b_Piplus2_PX);
   fChain->SetBranchAddress("Piplus2_PY", &Piplus2_PY, &b_Piplus2_PY);
   fChain->SetBranchAddress("Piplus2_PZ", &Piplus2_PZ, &b_Piplus2_PZ);
   fChain->SetBranchAddress("Piplus2_M", &Piplus2_M, &b_Piplus2_M);
   fChain->SetBranchAddress("Piplus2_ID", &Piplus2_ID, &b_Piplus2_ID);
   fChain->SetBranchAddress("Piplus2_PIDe", &Piplus2_PIDe, &b_Piplus2_PIDe);
   fChain->SetBranchAddress("Piplus2_PIDmu", &Piplus2_PIDmu, &b_Piplus2_PIDmu);
   fChain->SetBranchAddress("Piplus2_PIDK", &Piplus2_PIDK, &b_Piplus2_PIDK);
   fChain->SetBranchAddress("Piplus2_PIDp", &Piplus2_PIDp, &b_Piplus2_PIDp);
   fChain->SetBranchAddress("Piplus2_ProbNNe", &Piplus2_ProbNNe, &b_Piplus2_ProbNNe);
   fChain->SetBranchAddress("Piplus2_ProbNNk", &Piplus2_ProbNNk, &b_Piplus2_ProbNNk);
   fChain->SetBranchAddress("Piplus2_ProbNNp", &Piplus2_ProbNNp, &b_Piplus2_ProbNNp);
   fChain->SetBranchAddress("Piplus2_ProbNNpi", &Piplus2_ProbNNpi, &b_Piplus2_ProbNNpi);
   fChain->SetBranchAddress("Piplus2_ProbNNmu", &Piplus2_ProbNNmu, &b_Piplus2_ProbNNmu);
   fChain->SetBranchAddress("Piplus2_ProbNNghost", &Piplus2_ProbNNghost, &b_Piplus2_ProbNNghost);
   fChain->SetBranchAddress("Piplus2_hasMuon", &Piplus2_hasMuon, &b_Piplus2_hasMuon);
   fChain->SetBranchAddress("Piplus2_isMuon", &Piplus2_isMuon, &b_Piplus2_isMuon);
   fChain->SetBranchAddress("Piplus2_hasRich", &Piplus2_hasRich, &b_Piplus2_hasRich);
   fChain->SetBranchAddress("Piplus2_hasCalo", &Piplus2_hasCalo, &b_Piplus2_hasCalo);
   fChain->SetBranchAddress("Piplus2_TRACK_Type", &Piplus2_TRACK_Type, &b_Piplus2_TRACK_Type);
   fChain->SetBranchAddress("Piplus2_TRACK_Key", &Piplus2_TRACK_Key, &b_Piplus2_TRACK_Key);
   fChain->SetBranchAddress("Piplus2_TRACK_CHI2NDOF", &Piplus2_TRACK_CHI2NDOF, &b_Piplus2_TRACK_CHI2NDOF);
   fChain->SetBranchAddress("Piplus2_TRACK_PCHI2", &Piplus2_TRACK_PCHI2, &b_Piplus2_TRACK_PCHI2);
   fChain->SetBranchAddress("Piplus2_TRACK_MatchCHI2", &Piplus2_TRACK_MatchCHI2, &b_Piplus2_TRACK_MatchCHI2);
   fChain->SetBranchAddress("Piplus2_TRACK_GhostProb", &Piplus2_TRACK_GhostProb, &b_Piplus2_TRACK_GhostProb);
   fChain->SetBranchAddress("Piplus2_TRACK_CloneDist", &Piplus2_TRACK_CloneDist, &b_Piplus2_TRACK_CloneDist);
   fChain->SetBranchAddress("Piplus2_TRACK_Likelihood", &Piplus2_TRACK_Likelihood, &b_Piplus2_TRACK_Likelihood);
   fChain->SetBranchAddress("Piminus_OWNPV_X", &Piminus_OWNPV_X, &b_Piminus_OWNPV_X);
   fChain->SetBranchAddress("Piminus_OWNPV_Y", &Piminus_OWNPV_Y, &b_Piminus_OWNPV_Y);
   fChain->SetBranchAddress("Piminus_OWNPV_Z", &Piminus_OWNPV_Z, &b_Piminus_OWNPV_Z);
   fChain->SetBranchAddress("Piminus_OWNPV_XERR", &Piminus_OWNPV_XERR, &b_Piminus_OWNPV_XERR);
   fChain->SetBranchAddress("Piminus_OWNPV_YERR", &Piminus_OWNPV_YERR, &b_Piminus_OWNPV_YERR);
   fChain->SetBranchAddress("Piminus_OWNPV_ZERR", &Piminus_OWNPV_ZERR, &b_Piminus_OWNPV_ZERR);
   fChain->SetBranchAddress("Piminus_OWNPV_CHI2", &Piminus_OWNPV_CHI2, &b_Piminus_OWNPV_CHI2);
   fChain->SetBranchAddress("Piminus_OWNPV_NDOF", &Piminus_OWNPV_NDOF, &b_Piminus_OWNPV_NDOF);
   fChain->SetBranchAddress("Piminus_OWNPV_COV_", Piminus_OWNPV_COV_, &b_Piminus_OWNPV_COV_);
   fChain->SetBranchAddress("Piminus_IP_OWNPV", &Piminus_IP_OWNPV, &b_Piminus_IP_OWNPV);
   fChain->SetBranchAddress("Piminus_IPCHI2_OWNPV", &Piminus_IPCHI2_OWNPV, &b_Piminus_IPCHI2_OWNPV);
   fChain->SetBranchAddress("Piminus_ORIVX_X", &Piminus_ORIVX_X, &b_Piminus_ORIVX_X);
   fChain->SetBranchAddress("Piminus_ORIVX_Y", &Piminus_ORIVX_Y, &b_Piminus_ORIVX_Y);
   fChain->SetBranchAddress("Piminus_ORIVX_Z", &Piminus_ORIVX_Z, &b_Piminus_ORIVX_Z);
   fChain->SetBranchAddress("Piminus_ORIVX_XERR", &Piminus_ORIVX_XERR, &b_Piminus_ORIVX_XERR);
   fChain->SetBranchAddress("Piminus_ORIVX_YERR", &Piminus_ORIVX_YERR, &b_Piminus_ORIVX_YERR);
   fChain->SetBranchAddress("Piminus_ORIVX_ZERR", &Piminus_ORIVX_ZERR, &b_Piminus_ORIVX_ZERR);
   fChain->SetBranchAddress("Piminus_ORIVX_CHI2", &Piminus_ORIVX_CHI2, &b_Piminus_ORIVX_CHI2);
   fChain->SetBranchAddress("Piminus_ORIVX_NDOF", &Piminus_ORIVX_NDOF, &b_Piminus_ORIVX_NDOF);
   fChain->SetBranchAddress("Piminus_ORIVX_COV_", Piminus_ORIVX_COV_, &b_Piminus_ORIVX_COV_);
   fChain->SetBranchAddress("Piminus_P", &Piminus_P, &b_Piminus_P);
   fChain->SetBranchAddress("Piminus_PT", &Piminus_PT, &b_Piminus_PT);
   fChain->SetBranchAddress("Piminus_PE", &Piminus_PE, &b_Piminus_PE);
   fChain->SetBranchAddress("Piminus_PX", &Piminus_PX, &b_Piminus_PX);
   fChain->SetBranchAddress("Piminus_PY", &Piminus_PY, &b_Piminus_PY);
   fChain->SetBranchAddress("Piminus_PZ", &Piminus_PZ, &b_Piminus_PZ);
   fChain->SetBranchAddress("Piminus_M", &Piminus_M, &b_Piminus_M);
   fChain->SetBranchAddress("Piminus_ID", &Piminus_ID, &b_Piminus_ID);
   fChain->SetBranchAddress("Piminus_PIDe", &Piminus_PIDe, &b_Piminus_PIDe);
   fChain->SetBranchAddress("Piminus_PIDmu", &Piminus_PIDmu, &b_Piminus_PIDmu);
   fChain->SetBranchAddress("Piminus_PIDK", &Piminus_PIDK, &b_Piminus_PIDK);
   fChain->SetBranchAddress("Piminus_PIDp", &Piminus_PIDp, &b_Piminus_PIDp);
   fChain->SetBranchAddress("Piminus_ProbNNe", &Piminus_ProbNNe, &b_Piminus_ProbNNe);
   fChain->SetBranchAddress("Piminus_ProbNNk", &Piminus_ProbNNk, &b_Piminus_ProbNNk);
   fChain->SetBranchAddress("Piminus_ProbNNp", &Piminus_ProbNNp, &b_Piminus_ProbNNp);
   fChain->SetBranchAddress("Piminus_ProbNNpi", &Piminus_ProbNNpi, &b_Piminus_ProbNNpi);
   fChain->SetBranchAddress("Piminus_ProbNNmu", &Piminus_ProbNNmu, &b_Piminus_ProbNNmu);
   fChain->SetBranchAddress("Piminus_ProbNNghost", &Piminus_ProbNNghost, &b_Piminus_ProbNNghost);
   fChain->SetBranchAddress("Piminus_hasMuon", &Piminus_hasMuon, &b_Piminus_hasMuon);
   fChain->SetBranchAddress("Piminus_isMuon", &Piminus_isMuon, &b_Piminus_isMuon);
   fChain->SetBranchAddress("Piminus_hasRich", &Piminus_hasRich, &b_Piminus_hasRich);
   fChain->SetBranchAddress("Piminus_hasCalo", &Piminus_hasCalo, &b_Piminus_hasCalo);
   fChain->SetBranchAddress("Piminus_TRACK_Type", &Piminus_TRACK_Type, &b_Piminus_TRACK_Type);
   fChain->SetBranchAddress("Piminus_TRACK_Key", &Piminus_TRACK_Key, &b_Piminus_TRACK_Key);
   fChain->SetBranchAddress("Piminus_TRACK_CHI2NDOF", &Piminus_TRACK_CHI2NDOF, &b_Piminus_TRACK_CHI2NDOF);
   fChain->SetBranchAddress("Piminus_TRACK_PCHI2", &Piminus_TRACK_PCHI2, &b_Piminus_TRACK_PCHI2);
   fChain->SetBranchAddress("Piminus_TRACK_MatchCHI2", &Piminus_TRACK_MatchCHI2, &b_Piminus_TRACK_MatchCHI2);
   fChain->SetBranchAddress("Piminus_TRACK_GhostProb", &Piminus_TRACK_GhostProb, &b_Piminus_TRACK_GhostProb);
   fChain->SetBranchAddress("Piminus_TRACK_CloneDist", &Piminus_TRACK_CloneDist, &b_Piminus_TRACK_CloneDist);
   fChain->SetBranchAddress("Piminus_TRACK_Likelihood", &Piminus_TRACK_Likelihood, &b_Piminus_TRACK_Likelihood);
   fChain->SetBranchAddress("SlowPi_OWNPV_X", &SlowPi_OWNPV_X, &b_SlowPi_OWNPV_X);
   fChain->SetBranchAddress("SlowPi_OWNPV_Y", &SlowPi_OWNPV_Y, &b_SlowPi_OWNPV_Y);
   fChain->SetBranchAddress("SlowPi_OWNPV_Z", &SlowPi_OWNPV_Z, &b_SlowPi_OWNPV_Z);
   fChain->SetBranchAddress("SlowPi_OWNPV_XERR", &SlowPi_OWNPV_XERR, &b_SlowPi_OWNPV_XERR);
   fChain->SetBranchAddress("SlowPi_OWNPV_YERR", &SlowPi_OWNPV_YERR, &b_SlowPi_OWNPV_YERR);
   fChain->SetBranchAddress("SlowPi_OWNPV_ZERR", &SlowPi_OWNPV_ZERR, &b_SlowPi_OWNPV_ZERR);
   fChain->SetBranchAddress("SlowPi_OWNPV_CHI2", &SlowPi_OWNPV_CHI2, &b_SlowPi_OWNPV_CHI2);
   fChain->SetBranchAddress("SlowPi_OWNPV_NDOF", &SlowPi_OWNPV_NDOF, &b_SlowPi_OWNPV_NDOF);
   fChain->SetBranchAddress("SlowPi_OWNPV_COV_", SlowPi_OWNPV_COV_, &b_SlowPi_OWNPV_COV_);
   fChain->SetBranchAddress("SlowPi_IP_OWNPV", &SlowPi_IP_OWNPV, &b_SlowPi_IP_OWNPV);
   fChain->SetBranchAddress("SlowPi_IPCHI2_OWNPV", &SlowPi_IPCHI2_OWNPV, &b_SlowPi_IPCHI2_OWNPV);
   fChain->SetBranchAddress("SlowPi_ORIVX_X", &SlowPi_ORIVX_X, &b_SlowPi_ORIVX_X);
   fChain->SetBranchAddress("SlowPi_ORIVX_Y", &SlowPi_ORIVX_Y, &b_SlowPi_ORIVX_Y);
   fChain->SetBranchAddress("SlowPi_ORIVX_Z", &SlowPi_ORIVX_Z, &b_SlowPi_ORIVX_Z);
   fChain->SetBranchAddress("SlowPi_ORIVX_XERR", &SlowPi_ORIVX_XERR, &b_SlowPi_ORIVX_XERR);
   fChain->SetBranchAddress("SlowPi_ORIVX_YERR", &SlowPi_ORIVX_YERR, &b_SlowPi_ORIVX_YERR);
   fChain->SetBranchAddress("SlowPi_ORIVX_ZERR", &SlowPi_ORIVX_ZERR, &b_SlowPi_ORIVX_ZERR);
   fChain->SetBranchAddress("SlowPi_ORIVX_CHI2", &SlowPi_ORIVX_CHI2, &b_SlowPi_ORIVX_CHI2);
   fChain->SetBranchAddress("SlowPi_ORIVX_NDOF", &SlowPi_ORIVX_NDOF, &b_SlowPi_ORIVX_NDOF);
   fChain->SetBranchAddress("SlowPi_ORIVX_COV_", SlowPi_ORIVX_COV_, &b_SlowPi_ORIVX_COV_);
   fChain->SetBranchAddress("SlowPi_P", &SlowPi_P, &b_SlowPi_P);
   fChain->SetBranchAddress("SlowPi_PT", &SlowPi_PT, &b_SlowPi_PT);
   fChain->SetBranchAddress("SlowPi_PE", &SlowPi_PE, &b_SlowPi_PE);
   fChain->SetBranchAddress("SlowPi_PX", &SlowPi_PX, &b_SlowPi_PX);
   fChain->SetBranchAddress("SlowPi_PY", &SlowPi_PY, &b_SlowPi_PY);
   fChain->SetBranchAddress("SlowPi_PZ", &SlowPi_PZ, &b_SlowPi_PZ);
   fChain->SetBranchAddress("SlowPi_M", &SlowPi_M, &b_SlowPi_M);
   fChain->SetBranchAddress("SlowPi_ID", &SlowPi_ID, &b_SlowPi_ID);
   fChain->SetBranchAddress("SlowPi_PIDe", &SlowPi_PIDe, &b_SlowPi_PIDe);
   fChain->SetBranchAddress("SlowPi_PIDmu", &SlowPi_PIDmu, &b_SlowPi_PIDmu);
   fChain->SetBranchAddress("SlowPi_PIDK", &SlowPi_PIDK, &b_SlowPi_PIDK);
   fChain->SetBranchAddress("SlowPi_PIDp", &SlowPi_PIDp, &b_SlowPi_PIDp);
   fChain->SetBranchAddress("SlowPi_ProbNNe", &SlowPi_ProbNNe, &b_SlowPi_ProbNNe);
   fChain->SetBranchAddress("SlowPi_ProbNNk", &SlowPi_ProbNNk, &b_SlowPi_ProbNNk);
   fChain->SetBranchAddress("SlowPi_ProbNNp", &SlowPi_ProbNNp, &b_SlowPi_ProbNNp);
   fChain->SetBranchAddress("SlowPi_ProbNNpi", &SlowPi_ProbNNpi, &b_SlowPi_ProbNNpi);
   fChain->SetBranchAddress("SlowPi_ProbNNmu", &SlowPi_ProbNNmu, &b_SlowPi_ProbNNmu);
   fChain->SetBranchAddress("SlowPi_ProbNNghost", &SlowPi_ProbNNghost, &b_SlowPi_ProbNNghost);
   fChain->SetBranchAddress("SlowPi_hasMuon", &SlowPi_hasMuon, &b_SlowPi_hasMuon);
   fChain->SetBranchAddress("SlowPi_isMuon", &SlowPi_isMuon, &b_SlowPi_isMuon);
   fChain->SetBranchAddress("SlowPi_hasRich", &SlowPi_hasRich, &b_SlowPi_hasRich);
   fChain->SetBranchAddress("SlowPi_hasCalo", &SlowPi_hasCalo, &b_SlowPi_hasCalo);
   fChain->SetBranchAddress("SlowPi_TRACK_Type", &SlowPi_TRACK_Type, &b_SlowPi_TRACK_Type);
   fChain->SetBranchAddress("SlowPi_TRACK_Key", &SlowPi_TRACK_Key, &b_SlowPi_TRACK_Key);
   fChain->SetBranchAddress("SlowPi_TRACK_CHI2NDOF", &SlowPi_TRACK_CHI2NDOF, &b_SlowPi_TRACK_CHI2NDOF);
   fChain->SetBranchAddress("SlowPi_TRACK_PCHI2", &SlowPi_TRACK_PCHI2, &b_SlowPi_TRACK_PCHI2);
   fChain->SetBranchAddress("SlowPi_TRACK_MatchCHI2", &SlowPi_TRACK_MatchCHI2, &b_SlowPi_TRACK_MatchCHI2);
   fChain->SetBranchAddress("SlowPi_TRACK_GhostProb", &SlowPi_TRACK_GhostProb, &b_SlowPi_TRACK_GhostProb);
   fChain->SetBranchAddress("SlowPi_TRACK_CloneDist", &SlowPi_TRACK_CloneDist, &b_SlowPi_TRACK_CloneDist);
   fChain->SetBranchAddress("SlowPi_TRACK_Likelihood", &SlowPi_TRACK_Likelihood, &b_SlowPi_TRACK_Likelihood);
   fChain->SetBranchAddress("nCandidate", &nCandidate, &b_nCandidate);
   fChain->SetBranchAddress("totCandidates", &totCandidates, &b_totCandidates);
   fChain->SetBranchAddress("EventInSequence", &EventInSequence, &b_EventInSequence);
   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   fChain->SetBranchAddress("BCID", &BCID, &b_BCID);
   fChain->SetBranchAddress("BCType", &BCType, &b_BCType);
   fChain->SetBranchAddress("OdinTCK", &OdinTCK, &b_OdinTCK);
   fChain->SetBranchAddress("L0DUTCK", &L0DUTCK, &b_L0DUTCK);
   fChain->SetBranchAddress("HLTTCK", &HLTTCK, &b_HLTTCK);
   fChain->SetBranchAddress("GpsTime", &GpsTime, &b_GpsTime);
   fChain->SetBranchAddress("Polarity", &Polarity, &b_Polarity);
   fChain->SetBranchAddress("L0Global", &L0Global, &b_L0Global);
   fChain->SetBranchAddress("Hlt1Global", &Hlt1Global, &b_Hlt1Global);
   fChain->SetBranchAddress("Hlt2Global", &Hlt2Global, &b_Hlt2Global);
   fChain->SetBranchAddress("L0HadronDecision", &L0HadronDecision, &b_L0HadronDecision);
   fChain->SetBranchAddress("L0nSelections", &L0nSelections, &b_L0nSelections);
   fChain->SetBranchAddress("Hlt1TrackAllL0Decision", &Hlt1TrackAllL0Decision, &b_Hlt1TrackAllL0Decision);
   fChain->SetBranchAddress("Hlt1L0AnyDecision", &Hlt1L0AnyDecision, &b_Hlt1L0AnyDecision);
   fChain->SetBranchAddress("Hlt1GlobalDecision", &Hlt1GlobalDecision, &b_Hlt1GlobalDecision);
   fChain->SetBranchAddress("Hlt1nSelections", &Hlt1nSelections, &b_Hlt1nSelections);
   fChain->SetBranchAddress("Hlt2nSelections", &Hlt2nSelections, &b_Hlt2nSelections);
   fChain->SetBranchAddress("MaxRoutingBits", &MaxRoutingBits, &b_MaxRoutingBits);
   fChain->SetBranchAddress("RoutingBits", RoutingBits, &b_RoutingBits);
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
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t K3PiStudies::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef K3PiStudies_cxx
