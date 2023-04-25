#define K3PiStudies_cxx
#include "K3PiStudies.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TSystem.h>
#include <TLorentzVector.h>
#include <TVector3.h>
#include <iostream>
#include <TLegend.h>
#include <TPaveText.h>

void K3PiStudies::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L K3PiStudies.C
//      Root > K3PiStudies t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

TH1 * strippingLevelDeltaMHist = new TH1D("stripping level DM","DeltaM",80,138.,158.);
TH1 * histDeltaM               = new TH1D("Delta M","with kProb cut",80,138.,158.);
TH1 * histDeltaM_selected      = new TH1D("selected Delta M","with kProb cut",80,138.,158.);
TH1 * strippingLevelMassHist   = new TH1D("stripping level M","M(K3Pi)",120,1800.,1920.);
TH1 * cutsAMassHist            = new TH1D("cutsA Mass hist","cut on DeltaM",120,1800.,1920.);
TH1 * cutsCMassHist            = new TH1D("cutsC Mass hist","cut on DeltaM",120,1800.,1920.);
TH1 * testMassHist             = new TH1D("test Mass hist","cut on DeltaM",120,1800.,1920.);
TH1 * massHistB                = new TH1D("mass hist","cuts B",120,1800.,1920.);
TH1 * d0MassHist               = new TH1D("D0_mass_hist","   ",120,1800.,1920.);
TH1 * d0MassHistSelected       = new TH1D("selected_D0_mass_hist","   ",120,1800.,1920.);
TH1 * d0barMassHist               = new TH1D("D0bar_mass_hist","   ",120,1800.,1920.);
TH1 * d0barMassHistSelected       = new TH1D("selected_D0bar_mass_hist","   ",120,1800.,1920.);
TH2 * thetaXY                  = new TH2D("thetaX,thetaY","cuts B",120,-0.3,0.3,120,-0.3,0.3);
TH1 * KminusKprobHist          = new TH1D("K ProbNNk","cutsA",100,0.,1.);
TH1 * massHistAlowKprob        = new TH1D("low KProb","cutsA",120,1800.,1920.);
TH1 * massHistAhighKprob        = new TH1D("high KProb","cutsA",120,1800.,1920.);
Double_t pi = TMath::Pi();
TH1 * allPhiHist                = new TH1D("phi","cutsB; low-mass K,pi",100,0.,2.0*pi);
TH1 * allPhiAHist                = new TH1D("phi","cutsB; low-mass K,pi",100,0.,2.0*pi);
TH1 * allPhiHistD0              = new TH1D("phi for D0","cutsB; low-mass K,pi",100,0.,2.0*pi);
TH1 * allPhiHistD02KstarRho     = new TH1D("phi for D02KstarRho","cutsB; low-mass K,pi",100,0.,2.0*pi);
TH1 * allPhiHistD02KstarF0     = new TH1D("phi for D02KstarF0","cutsB; low-mass K,pi",100,0.,2.0*pi);
TH1 * allPhiHistD02KappaRho     = new TH1D("phi for D02KappaRho","cutsB; low-mass K,pi",100,0.,2.0*pi);
TH1 * allPhiHistD0bar          = new TH1D("phi for D0bar","cutsB high-mass K,pi",100,0.,2.0*pi);
TH1 * allPhiHistD0bar2KstarRho = new TH1D("phi for D0bar2KstarRho","cutsB high-mass K,pi",100,0.,2.0*pi);
TH1 * allPhiHistD0bar2KstarF0 = new TH1D("phi for D0bar2KstarF0","cutsB high-mass K,pi",100,0.,2.0*pi);
TH1 * allPhiHistD0bar2KappaRho = new TH1D("phi for D0bar2KappaRho","cutsB high-mass K,pi",100,0.,2.0*pi);
TH1 * quad1PhiHistD02KstarRho  = new TH1D("quad1 phi for D02KstarRho","cutsB high-mass K,pi",100,0.,2.0*pi);
TH1 * quad2PhiHistD02KstarRho  = new TH1D("quad2 phi for D02KstarRho","cutsB high-mass K,pi",100,0.,2.0*pi);
TH1 * quad3PhiHistD02KstarRho  = new TH1D("quad3 phi for D02KstarRho","cutsB high-mass K,pi",100,0.,2.0*pi);
TH1 * quad4PhiHistD02KstarRho  = new TH1D("quad4 phi for D02KstarRho","cutsB high-mass K,pi",100,0.,2.0*pi);
TH1 * quad1PhiHistD0bar2KstarRho  = new TH1D("quad1 phi for D0bar2KstarRho","cutsB high-mass K,pi",100,0.,2.0*pi);
TH1 * quad2PhiHistD0bar2KstarRho  = new TH1D("quad2 phi for D0bar2KstarRho","cutsB high-mass K,pi",100,0.,2.0*pi);
TH1 * quad3PhiHistD0bar2KstarRho  = new TH1D("quad3 phi for D0bar2KstarRho","cutsB high-mass K,pi",100,0.,2.0*pi);
TH1 * quad4PhiHistD0bar2KstarRho  = new TH1D("quad4 phi for D0bar2KstarRho","cutsB high-mass K,pi",100,0.,2.0*pi);
TH1 * quad1PhiHistD02KstarF0  = new TH1D("quad1 phi for D02KstarF0","cutsB high-mass K,pi",100,0.,2.0*pi);
TH1 * quad2PhiHistD02KstarF0  = new TH1D("quad2 phi for D02KstarF0","cutsB high-mass K,pi",100,0.,2.0*pi);
TH1 * quad3PhiHistD02KstarF0  = new TH1D("quad3 phi for D02KstarF0","cutsB high-mass K,pi",100,0.,2.0*pi);
TH1 * quad4PhiHistD02KstarF0  = new TH1D("quad4 phi for D02KstarF0","cutsB high-mass K,pi",100,0.,2.0*pi);
TH1 * quad1PhiHistD0bar2KstarF0  = new TH1D("quad1 phi for D0bar2KstarF0","cutsB high-mass K,pi",100,0.,2.0*pi);
TH1 * quad2PhiHistD0bar2KstarF0  = new TH1D("quad2 phi for D0bar2KstarF0","cutsB high-mass K,pi",100,0.,2.0*pi);
TH1 * quad3PhiHistD0bar2KstarF0  = new TH1D("quad3 phi for D0bar2KstarF0","cutsB high-mass K,pi",100,0.,2.0*pi);
TH1 * quad4PhiHistD0bar2KstarF0  = new TH1D("quad4 phi for D0bar2KstarF0","cutsB high-mass K,pi",100,0.,2.0*pi);
TH1 * quad1PhiHistD02KappaRho  = new TH1D("quad1 phi for D02KappaRho","cutsB high-mass K,pi",100,0.,2.0*pi);
TH1 * quad2PhiHistD02KappaRho  = new TH1D("quad2 phi for D02KappaRho","cutsB high-mass K,pi",100,0.,2.0*pi);
TH1 * quad3PhiHistD02KappaRho  = new TH1D("quad3 phi for D02KappaRho","cutsB high-mass K,pi",100,0.,2.0*pi);
TH1 * quad4PhiHistD02KappaRho  = new TH1D("quad4 phi for D02KappaRho","cutsB high-mass K,pi",100,0.,2.0*pi);
TH1 * quad1PhiHistD0bar2KappaRho  = new TH1D("quad1 phi for D0bar2KappaRho","cutsB high-mass K,pi",100,0.,2.0*pi);
TH1 * quad2PhiHistD0bar2KappaRho  = new TH1D("quad2 phi for D0bar2KappaRho","cutsB high-mass K,pi",100,0.,2.0*pi);
TH1 * quad3PhiHistD0bar2KappaRho  = new TH1D("quad3 phi for D0bar2KappaRho","cutsB high-mass K,pi",100,0.,2.0*pi);
TH1 * quad4PhiHistD0bar2KappaRho  = new TH1D("quad4 phi for D0bar2KappaRho","cutsB high-mass K,pi",100,0.,2.0*pi);
TH2D * cosVsinPlot              = new TH2D("cosine v sine","sanity plot",50,-1.5,1.5,50,-1.5,1.5);
TH2D * cosVsinPlotA             = new TH2D("cosine v sine","sanity plotA ",50,-1.5,1.5,50,-1.5,1.5);
TH2D * mABmCD                   = new TH2D("mAB_v_mCD","passing cutsB",50,550,1300.,50,200.,1300.);
TH2D * mABmCDForLowKPiPi    = new TH2D("mAB_v_mCD for Low KPiPi","passing cutsB",50,550,1300.,50,200.,1300.);
TH2D * mADmCB                   = new TH2D("mAD_v_mCB","passing cutsB",50,550,1550,50,200.,1300.);
TH2D * KstarPiPiDP1213          = new TH2D("K*,pi-,pi+ DP, s12,s13","K* +- 50 MeV",50,1.0,2.8,50,1.0,2.8);
TH2D * KstarPiPiDP2313          = new TH2D("K*,pi-,pi+ DP, s23,s13","K* +- 50 MeV",50,0.0,1.2,50,1.0,2.8);
TH2D * KstarPiPiDP2312          = new TH2D("K*,pi-,pi+ DP, s23,s12","K* +- 50 MeV",50,0.0,1.2,50,1.0,2.8);
TH1  * mCDforKstar              = new TH1D("for Kstar region","pi,pi mass",110,200.,1300.);
TH1  * mCDforLowKPiMass         = new TH1D("for low K,pi","pi,pi mass",110,200.,1300.);
TH1  * mABforRhoZero            = new TH1D("for Rho region","K,pi mass",70,550,1250);
TH2D * mABmAD                   = new TH2D("mAB_v_mAD","passing cutsB",50,550,1550,50,550.,1550.);
TH2D * mABmADForKappaRho         = new TH2D("mAB_v_mA, for Kappa RhoD","passing cutsB",50,550,1550,50,550.,1550.);
TH2D * mABmADForKstarRho        = new TH2D("mAB_v_mAD, K*Rho","passing cutsB",50,550,1550,50,550.,1550.);
TH2D * mABmADForKstarF0         = new TH2D("mAB_v_mAD, K* f0","passing cutsB",50,550,1550,50,550.,1550.);
TH2D * mABmADzoomed             = new TH2D("mAB_v_mAD zoomedin","passing cutsB",25,600,850,25,600.,850.);

TH1D * mPiPiForLowKPiPi         = new TH1D("mPiPi","for low KPiPi mass",100,280.,780.);
TH2D * mKPimPiPi                = new TH2D("mKPi v mPiPi","passing cutsB",50,550,1550,50,200.,1300.);
TH2D * mKPimPiPiA               = new TH2D("at higher decay time","mKPi v mPiPi",50,550,1550,50,200.,1300.);
TH2D * sanityPlot               = new TH2D("for all events","tripleProduct v phi",100,-600.,600.,100,0.,2.0*pi);
TH1D * cosThetaAHist            = new TH1D("cosThetaA, cuts B","all mABmCD",100,-1.,1.);
TH1D * cosThetaCHist            = new TH1D("cosThetaC, cuts B","all mABmCD",100,-1.,1.);
TH2D * cosThetaAcosThetaCHist   = new TH2D("cosThetaA v cosThetaC","cutsB",100,-1.,1.,100,-1.,1.);
TH2D * tAtCD02KstarRho          = new TH2D("cosThetaA v cosThetaC for D0","cutsB",100,-1.,1.,100,-1.,1.);
TH2D * tAtCD0bar2KstarRho       = new TH2D("cosThetaA v cosThetaC for D0bar","cutsB",100,-1.,1.,100,-1.,1.);
TH2D * tAtCD02KstarF0          = new TH2D("cosThetaA v cosThetaC for D0","cutsB",100,-1.,1.,100,-1.,1.);
TH2D * tAtCD0bar2KstarF0       = new TH2D("cosThetaA v cosThetaC for D0bar","cutsB",100,-1.,1.,100,-1.,1.);
TH2D * tAtCD02KappaRho          = new TH2D("cosThetaA v cosThetaC for D0","cutsB",100,-1.,1.,100,-1.,1.);
TH2D * tAtCD0bar2KappaRho       = new TH2D("cosThetaA v cosThetaC for D0bar","cutsB",100,-1.,1.,100,-1.,1.);

TH2D * d0PhaseSpace              = new TH2D("d0PhaseSpace","p v pT",8,40000.,200000.,6,4000.,16000.);
TH2D * d0barPhaseSpace           = new TH2D("d0barPhaseSpace","p v pT",8,40000.,200000.,6,4000.,16000.);
TH2D * rat           = new TH2D("rat","p v pT",8,40000.,200000.,6,4000.,16000.);

TH1D * mABD_corner = new TH1D("mABD_corner","m(K,pi+,pi+) in the corner",120,750.,1350.);

TH1D * piMinusEnergyHist     = new TH1D("pi_minus_energy","passing cutsB",80,100.,900.);
TH1D * piMinusEnergyHistD0   = new TH1D("pi_minus_energy_D0","passing cutsB",80,100.,900.);
TH1D * piMinusEnergyHistD0bar  = new TH1D("pi_minus_energy_D0bar","passing cutsB",80,100.,900.);
TH1D * piPlusBEnergyHist     = new TH1D("pi_plusB_energy","passing cutsB",80,100.,900.);
TH1D * piPlusBEnergyHistD0     = new TH1D("pi_plusB_energy_D0","passing cutsB",80,100.,900.);
TH1D * piPlusBEnergyHistD0bar     = new TH1D("pi_plusB_energy_D0bar","passing cutsB",80,100.,900.);
TH1D * piPlusDEnergyHist     = new TH1D("pi_plusD_energy","passing cutsB",80,100.,900.);
TH1D * piPlusDEnergyHistD0     = new TH1D("pi_plusD_energy_D0","passing cutsB",80,100.,900.);
TH1D * piPlusDEnergyHistD0bar     = new TH1D("pi_plusD_energy_D0bar","passing cutsB",80,100.,900.);
TH1D * KMinusEnergyHist     = new TH1D("K_minus_energy","passing cutsB",120,400.,1000.);
TH1D * KMinusEnergyHistD0   = new TH1D("K_minus_energy_D0","passing cutsB",120,400.,1000.);
TH1D * KMinusEnergyHistD0bar  = new TH1D("K_minus_energy_D0bar","passing cutsB",120,400.,1000.);

TH1D * cornerPiPlusPiPlusMassHist  = new TH1D("mPiPlusPiPlus corner","for low KPiPi mass",100,280.,1280.);
TH1D * cornerPiMinusPiPlusMassHist  = new TH1D("mPiMinusPiPlus corner","for low KPiPi mass",100,280.,1280.);
TH1D * cornerKMinusPiMinusMassHist  = new TH1D("mKMinusPiMinus corner","for low KPiPi mass",100,600.,1600.);
TH1D * cornerKMinusPiPlusMassHist  = new TH1D("mKMinusPiPlus corner","for low KPiPi mass",100,600.,1600.);

TH1D * cornerKMinusEnergyHist      = new TH1D("eKMinus corner","for low KPiPi mass",100,400.,900.);
TH1D * cornerPiMinusEnergyHist     = new TH1D("ePiMinus corner","for low KPiPi mass",120,400.,1000.);
TH1D * cornerPiPlusEnergyHist      = new TH1D("ePiPlus corner","for low KPiPi mass",100,100.,600.);

TH1D * cornerKMinusPzHist          = new TH1D("pzKMinus corner","for low KPiPi mass",100,-1000.,1000.);
TH1D * cornerPiMinusPzHist         = new TH1D("pzPiMinus corner","for low KPiPi mass",100,-1000.,1000.);
TH1D * cornerPiPlusPzHist          = new TH1D("pzPiPlus corner","for low KPiPi mass",100,-1000.,1000.);

TH1D * cornerKPiPiMassSqHist       = new TH1D("KPiPi massSq corner","for low KPiPi mass",100,0.4,3.4);
TH1D * KPiPiMassSqHist             = new TH1D("KPiPi massSq","for cutsB",100,0.4,3.4);
TH1D * cornerKminusHelictyCosineHist = new TH1D("KminusHelictyCosineHist corner","in the corner",100,-1.,1.);

TH1D *  KmPipPipAllHist = new TH1D("all cutsB events","mK-Pi+Pi+",100,750.,1750.);
TH1D *  KmPipPipNotKstarRhoCand = new TH1D(" cutsB, not K*Rho","mK-Pi+Pi+",100,750.,1750.);
  TString  d0AsymStr;
  TString  d0AsymErrStr;
  TString  d0barAsymStr;
  TString  d0barAsymErrStr;
  TString  cpAsymStr;
  TString  cpAsymErrStr;
  TString  DiffABStr;
  TString  d0Sin2PhiAsymStr;
  TString  d0Sin2PhiAsymErrStr;
  TString  d0barSin2PhiAsymStr;
  TString  d0barSin2PhiAsymErrStr;
  TString  cpSin2PhiAsymStr;
  TString  cpSin2PhiAsymErrStr;
  TString  DiffSin2PhiStr;
  TString  nd0Str;
  TString  nd0barStr;

  Double_t nD0;
  Double_t nD0bar;

 TPaveText *pt1 = new TPaveText(0.60,0.65,0.98,0.94,"NDC"); // NDC sets coords
 TPaveText *pt2 = new TPaveText(0.70,0.80,0.90,0.90,"NDC"); // NDC sets coords


  Long64_t nentries = fChain->GetEntriesFast();
  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
//  for (Long64_t jentry=0; jentry<100000;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

//  begin per event code

      bool KstarRhoCand = false;
      bool KstarF0Cand = false;
      bool KappaRhoCand = false; 
      bool K1290Cand = false;
      bool newK950Cand = false;
  
      Double_t kProbCut = 0.20;

      strippingLevelDeltaMHist->Fill(Dstar_MM-D0_MM);
      strippingLevelMassHist->Fill(D0_MM);

      Double_t DeltaM = Dstar_PVFit_M[0]-Dstar_PVFit_D0_M[0];
      bool cutsA = false;
      if ( abs(DeltaM-145.457)<0.7 ) {
        cutsA = true;
      }

      if (Kminus_ProbNNk > kProbCut) {
        histDeltaM->Fill(DeltaM);
        if (cutsA) {
          histDeltaM_selected->Fill(DeltaM);
        }
      }



      if (cutsA) {
        cutsAMassHist->Fill(D0_MM);
        KminusKprobHist->Fill(Kminus_ProbNNk);
        if (Kminus_ProbNNk < kProbCut) {
          massHistAlowKprob->Fill(D0_MM);
        } else {
          massHistAhighKprob->Fill(D0_MM);
        }
      }

      bool selectedMass = false;
      if (D0_MM> 1850 && D0_MM<1882) {
        selectedMass = true;
      }
      bool cutsB = false;
      Double_t thetaX=0;
      Double_t thetaY=0;
      if (cutsA && (Kminus_ProbNNk>kProbCut) 
           && D0_PT>5000 && D0_IPCHI2_OWNPV<9 && SlowPi_IPCHI2_OWNPV<9
           && Dstar_PVFit_D0_ctau[0]>0.410 
           && Piplus1_ProbNNmu < 0.50 && Piplus2_ProbNNmu <0.5
           && SlowPi_ProbNNpi >0.05 && SlowPi_ProbNNmu <0.50
           && SlowPi_ProbNNe<0.50
           && D0_P>40000 && D0_PT<16000) {
        if (D0_ID > 0) {
          d0MassHist->Fill(D0_MM);
          if (selectedMass) {
           d0MassHistSelected->Fill(D0_MM);
           d0PhaseSpace->Fill(D0_P,D0_PT);
          }
        } else {
          d0barMassHist->Fill(D0_MM);
          if (selectedMass) {
           d0barMassHistSelected->Fill(D0_MM);
           d0barPhaseSpace->Fill(D0_P,D0_PT);
          }
        }
      
        if (selectedMass) { 
          cutsB = true;
        }
        massHistB->Fill(D0_MM);
        thetaX = atan(D0_PX/D0_PZ);
        thetaY = atan(D0_PY/D0_PZ);
        thetaXY->Fill(thetaX,thetaY);
      }
      
      if (cutsA && Kminus_ProbNNk>kProbCut && abs(atan(D0_PX/D0_PZ))>0.02 &&
          abs(atan(D0_PY/D0_PZ))>0.02) {
        testMassHist->Fill(D0_MM);
      }
        
      if (cutsA && Kminus_ProbNNk>kProbCut && abs(thetaX)>0.02 && abs(thetaY)>0.02) {
        cutsCMassHist->Fill(D0_MM);
      }
      
      bool cutsC = false;
      if (cutsB && abs(atan(D0_PX/D0_PZ))>0.02 &&
          abs(atan(D0_PY/D0_PZ))>0.02) {
        cutsC = true;
      }


//  At this point we have a good enough set of cuts to begin lookiing at the angles defined
//  by triple products.  

//  The first step is to create four-vectors for the D0 daughters.
//  The second step is to choose which pi+ to associate with the K- (or CC). We will
//    discriminate on the basis of (K,pi) invariant mass.
//  Once the choice of pairs is made, define tracks (a), (b), (c), (d) and create
//    their four-vectors in the D0 CM.  From these, extract the three-vectors
//    and calculate the sine of the angle between the (K-.pi+) plane and the (pi-,pi+) plane
    
      TLorentzVector kminus_4vec;
      TLorentzVector piminus_4vec;
      TLorentzVector piplus1_4vec;
      TLorentzVector piplus2_4vec;

      if (cutsB) {
        kminus_4vec.SetPxPyPzE(Kminus_PX, Kminus_PY, Kminus_PZ, Kminus_PE);
        piminus_4vec.SetPxPyPzE(Piminus_PX, Piminus_PY, Piminus_PZ, Piminus_PE);
        piplus1_4vec.SetPxPyPzE(Piplus1_PX, Piplus1_PY, Piplus1_PZ, Piplus1_PE);
        piplus2_4vec.SetPxPyPzE(Piplus2_PX, Piplus2_PY, Piplus2_PZ, Piplus2_PE);

        TLorentzVector kpiplus1_4vec = kminus_4vec+piplus1_4vec;
        TLorentzVector kpiplus2_4vec = kminus_4vec+piplus2_4vec;

        Double_t mkpi1 = kpiplus1_4vec.M();
        Double_t mkpi2 = kpiplus2_4vec.M();

        TLorentzVector piB_4vec;
        TLorentzVector piD_4vec;
        if (mkpi1 < mkpi2) {
          piB_4vec = piplus1_4vec;
          piD_4vec = piplus2_4vec;
        } else {
          piB_4vec = piplus2_4vec;
          piD_4vec = piplus1_4vec;
        }

        TLorentzVector D0_4vec = kminus_4vec + piminus_4vec + piplus1_4vec + piplus2_4vec;
        Double_t energy = D0_4vec.E();
        TVector3 beta;
        beta.SetXYZ(D0_4vec.Px()/energy, D0_4vec.Py()/energy, D0_4vec.Pz()/energy);

// mds         cout << "D0 4-mom = " << D0_4vec.Px() << ",    "
// mds                               << D0_4vec.Py() << ",    "
// mds                               << D0_4vec.Pz() << ",    "
// mds                               << D0_4vec.E() << endl;
// mds         cout << "beta =   " << beta.X() << ",  " << beta.Y() << ",  " << beta.Z() <<  endl;
//        cout << " beta =   " <<  beta.X() << "  ,  " << beta.Y()  << "  ,  " << beta.Z() ;
        
        TLorentzVector D0_CM_4vec = D0_4vec;
        D0_CM_4vec.Boost(-1.*beta);
// mds         cout << "D0_CM 4-mom = " << D0_CM_4vec.Px() << ",    "
// mds                                  << D0_CM_4vec.Py() << ",    "
// mds                                  << D0_CM_4vec.Pz() << ",    "
// mds                                  << D0_CM_4vec.E() << endl;
      

//  create the D0 daughter four-vectors, first in the lab, and then boosted into the D0 CM

      TLorentzVector pA_4vec = kminus_4vec;
      TLorentzVector pB_4vec = piB_4vec;
      TLorentzVector pC_4vec = piminus_4vec;
      TLorentzVector pD_4vec = piD_4vec;

      pA_4vec.Boost(-1.*beta);
      pB_4vec.Boost(-1.*beta);
      pC_4vec.Boost(-1.*beta);
      pD_4vec.Boost(-1.*beta);

      TLorentzVector pAD_4vec = pA_4vec + pD_4vec;
      TLorentzVector pCB_4vec = pC_4vec + pB_4vec;
      TLorentzVector pABD_4vec = pA_4vec + pB_4vec + pD_4vec;

      Double_t piMinusEnergy = pC_4vec.E();
      piMinusEnergyHist->Fill(piMinusEnergy);
      KMinusEnergyHist->Fill(pA_4vec.E());
      piPlusBEnergyHist->Fill(pB_4vec.E());
      piPlusDEnergyHist->Fill(pD_4vec.E());
      KPiPiMassSqHist->Fill(pABD_4vec.M()*pABD_4vec.M()/1000000.);  // /1000000 to get GeV**2

      if (D0_ID > 0) {
        piMinusEnergyHistD0->Fill(piMinusEnergy);
        KMinusEnergyHistD0->Fill(pA_4vec.E());
        piPlusBEnergyHistD0->Fill(pB_4vec.E());
        piPlusDEnergyHistD0->Fill(pD_4vec.E());
      } else {
        piMinusEnergyHistD0bar->Fill(piMinusEnergy);
        KMinusEnergyHistD0bar->Fill(pA_4vec.E());
        piPlusBEnergyHistD0bar->Fill(pB_4vec.E());
        piPlusDEnergyHistD0bar->Fill(pD_4vec.E());
      }

//  as a sanity check, compare the D0 four-momentum with the sum of the daughter four-momenta:

// mds OK       TLorentzVector diff;
// mds OK       diff = D0_CM_4vec - pA_4vec - pB_4vec - pC_4vec - pD_4vec;
// mds OK 
// mds OK         cout << "pA 4-mom = " << pA_4vec.Px() << ",    "
// mds OK                                  << pA_4vec.Py() << ",    "
// mds OK                                  << pA_4vec.Pz() << ",    "
// mds OK                                  << pA_4vec.E() << ",    " 
// mds OK                                  << pA_4vec.M() << endl;
// mds OK 
// mds OK         cout << "pB 4-mom = " << pB_4vec.Px() << ",    "
// mds OK                                  << pB_4vec.Py() << ",    "
// mds OK                                  << pB_4vec.Pz() << ",    "
// mds OK                                  << pB_4vec.E() << ",    " 
// mds OK                                  << pB_4vec.M() << endl;
// mds OK 
// mds OK         cout << "pC 4-mom = " << pC_4vec.Px() << ",    "
// mds OK                                  << pC_4vec.Py() << ",    "
// mds OK                                  << pC_4vec.Pz() << ",    "
// mds OK                                  << pC_4vec.E() << ",    " 
// mds OK                                  << pC_4vec.M() << endl;
// mds OK 
// mds OK         cout << "pD 4-mom = " << pD_4vec.Px() << ",    "
// mds OK                                  << pD_4vec.Py() << ",    "
// mds OK                                  << pD_4vec.Pz() << ",    "
// mds OK                                  << pD_4vec.E() << ",    " 
// mds OK                                  << pD_4vec.M() << endl;
// mds OK 
// mds OK       cout << "diff.E()  =   " << diff.E() << endl;
// mds OK       cout << "CM diff 4-mom =  " << diff.Px() << ",    "
// mds OK                                   << diff.Py() << ",    "
// mds OK                                   << diff.Pz() << ",    "
// mds OK                                   << diff.E() << endl;
// mds OK       

//  note that pA_4vec, pB_4vec, etc., are in the D0 CM.
//  we are going to define zhat as the pA_3vec+pB_3vec direction.
//  to consider the helicity angles of the AB and CD pairs in their
//  respective CMs, we should make Lorentz transformations along 
//  the zhat (or -zhat) directions. Note that the CD system is moving
//  along the -zhat direction to start.
      TLorentzVector pAB_4vec = pA_4vec + pB_4vec;
        Double_t energyAB = pAB_4vec.E();
        TVector3 betaAB;
        betaAB.SetXYZ(pAB_4vec.Px()/energyAB, pAB_4vec.Py()/energyAB, pAB_4vec.Pz()/energyAB);
        TLorentzVector pAprime_4vec = pA_4vec;
        pAprime_4vec.Boost(-1.*betaAB);
        TLorentzVector pBprime_4vec = pB_4vec;
        pBprime_4vec.Boost(-1.*betaAB);

      TLorentzVector pCD_4vec = pC_4vec + pD_4vec;
        Double_t energyCD = pCD_4vec.E();
        TVector3 betaCD;
        betaCD.SetXYZ(pCD_4vec.Px()/energyCD, pCD_4vec.Py()/energyCD, pCD_4vec.Pz()/energyCD);
        TLorentzVector pCprime_4vec = pC_4vec;
        pCprime_4vec.Boost(-1.*betaCD);
        TLorentzVector pDprime_4vec = pD_4vec;
        pDprime_4vec.Boost(-1.*betaCD);

      TLorentzVector pABC_4vec = pA_4vec + pB_4vec + pC_4vec;
      Double_t mAB = pAB_4vec.M();  // m(K*bar) candidate
      Double_t mABC = pABC_4vec.M(); // m(K*bar,pi-);
      Double_t mABD = pABD_4vec.M(); // m(K*bar,pi+);
      Double_t mCD = pCD_4vec.M();   // m(pi-,pi+);
      mABmCD->Fill(pAB_4vec.M(),pCD_4vec.M());
      mKPimPiPi->Fill(pAB_4vec.M(),pCD_4vec.M());


      if (abs(pAB_4vec.M()-892) < 50) {
// these are K*,pi-,pi+ candidates

//  first, look at the pi-,pi+ inv mass for these candidates
        mCDforKstar->Fill(pCD_4vec.M());

//  next, make the K*,pi-,pi+ "Dalitz plot" for these candidates
        Double_t s12 = mABC*mABC*0.000001;  // converted from MeV^2 to Gev^2
        Double_t s13 = mABD*mABD*0.000001;  // converted from MeV^2 to Gev^2
        Double_t s23 = mCD*mCD*0.000001;    // converted from MeV^2 to Gev^2
        KstarPiPiDP1213->Fill(s12,s13);
        KstarPiPiDP2313->Fill(s23,s13);
        KstarPiPiDP2312->Fill(s23,s12);
      }
      if (pAB_4vec.M()<800) {
        mCDforLowKPiMass->Fill(pCD_4vec.M());
      }
      if (abs(pCD_4vec.M()-775)<150) {
        mABforRhoZero->Fill(pAB_4vec.M());
      }

// mds      if (D0_TAU > 0.0010) {
// mds        mKPimPiPiA->Fill(pAB_4vec.M(),pCD_4vec.M());
// mds      }

      TVector3 pAB_3vec = pAB_4vec.Vect();
      TVector3 pCD_3vec = pCD_4vec.Vect();
      TVector3 pA_3vec = pA_4vec.Vect();
      TVector3 pB_3vec = pB_4vec.Vect();
      TVector3 pC_3vec = pC_4vec.Vect();
      TVector3 pD_3vec = pD_4vec.Vect();

      TVector3 pAprime_3vec = pAprime_4vec.Vect();
      TVector3 pBprime_3vec = pBprime_4vec.Vect();
      TVector3 pCprime_3vec = pCprime_4vec.Vect();
      TVector3 pDprime_3vec = pDprime_4vec.Vect();

      TVector3 zhat = pAB_3vec.Unit();
      TVector3 yhat = (pA_3vec.Cross(pB_3vec)).Unit();
      TVector3 xhat = (yhat.Cross(zhat)).Unit();

      TVector3 yhatPrime = (pC_3vec.Cross(pD_3vec)).Unit();

      Double_t cosPhi = (yhat.Dot(yhatPrime));
      Double_t sinPhi = (xhat.Dot(yhatPrime));
      cosVsinPlot->Fill(cosPhi,sinPhi);
      Double_t phi    = TMath::ATan2(sinPhi,cosPhi);
      Double_t altPhi = TMath::ATan2(sinPhi,cosPhi);

      if (phi < 0) {
        phi = 2.0*pi+phi;
      }

      Double_t tripleProduct = yhat.Dot(pC_3vec);



// as a sanity check, compare phi with Adrian's Triple Product
// using zhat rather than p_a \cross p_b for convvenience of visualization
// mds       if (jentry % 100 == 0) {
// mds         cout << "jentry =   " << jentry << endl;
// mds       }
      if (jentry<00) {
        cout << "jentry =   " << jentry << endl;
        cout << "pA_3vec  ";
        pA_3vec.Print();
        pAprime_4vec.Print();
        cout << "pB_3vec  ";
        pB_3vec.Print();
        pBprime_4vec.Print();
        cout << "pC_3vec  "; 
        pC_3vec.Print();
        pCprime_4vec.Print();
        cout << "pD_3vec  ";
        pD_3vec.Print();
        pDprime_4vec.Print();
        cout << "pAB_3vec  ";
        pAB_3vec.Print();
        cout << "zhat   ";
        zhat.Print();
        cout <<  "yhat   ";
        yhat.Print();
        cout << "pCD_3vec  ";
        pCD_3vec.Print();
        cout << "yhatPrime  ";
        yhatPrime.Print(); 
        Double_t angle = yhat.Angle(yhatPrime);
        cout << "angle from Angle =  " << angle << "  and phi =  " << phi  << "  and altPhi =  " << altPhi << endl;
      }

        Double_t paX = pA_3vec.Dot(xhat);
        Double_t pbX = pB_3vec.Dot(xhat);
        Double_t pcX = pC_3vec.Dot(xhat);
        Double_t pdX = pD_3vec.Dot(xhat);
        Double_t paY = pA_3vec.Dot(yhat);
        Double_t pbY = pB_3vec.Dot(yhat);
        Double_t pcY = pC_3vec.Dot(yhat);
        Double_t pdY = pD_3vec.Dot(yhat);
        Double_t paZ = pA_3vec.Dot(zhat);
        Double_t pbZ = pB_3vec.Dot(zhat);
        Double_t pcZ = pC_3vec.Dot(zhat);
        Double_t pdZ = pD_3vec.Dot(zhat);
        Double_t paPrimeX = pAprime_3vec.Dot(xhat);
        Double_t pbPrimeX = pBprime_3vec.Dot(xhat);
        Double_t pcPrimeX = pCprime_3vec.Dot(xhat);
        Double_t pdPrimeX = pDprime_3vec.Dot(xhat);
        Double_t paPrimeY = pAprime_3vec.Dot(yhat);
        Double_t pbPrimeY = pBprime_3vec.Dot(yhat);
        Double_t pcPrimeY = pCprime_3vec.Dot(yhat);
        Double_t pdPrimeY = pDprime_3vec.Dot(yhat);
        Double_t paPrimeZ = pAprime_3vec.Dot(zhat);
        Double_t pbPrimeZ = pBprime_3vec.Dot(zhat);
        Double_t pcPrimeZ = pCprime_3vec.Dot(zhat);
        Double_t pdPrimeZ = pDprime_3vec.Dot(zhat);

        Double_t paPrimeMag = sqrt(paPrimeX*paPrimeX+paPrimeY*paPrimeY+paPrimeZ*paPrimeZ);
        Double_t paPrimePT  = sqrt(paPrimeX*paPrimeX+paPrimeY*paPrimeY);
        Double_t cosThetaA  = paPrimeZ/paPrimeMag;
        Double_t sinThetaA  = paPrimePT/paPrimeMag;
        Double_t sin2ThetaA = 2.0*sinThetaA*cosThetaA;

        Double_t pcPrimeMag = sqrt(pcPrimeX*pcPrimeX+pcPrimeY*pcPrimeY+pcPrimeZ*pcPrimeZ);
        Double_t pcPrimePT  = sqrt(pcPrimeX*pcPrimeX+pcPrimeY*pcPrimeY);
        Double_t cosThetaC  = pcPrimeZ/pcPrimeMag;
        Double_t sinThetaC  = pcPrimePT/pcPrimeMag;
        Double_t sin2ThetaC = 2.0*sinThetaC*cosThetaC;


        int quadrant = 0;
        if (sin2ThetaA < 0 && sin2ThetaC < 0) {
          quadrant = 1;
        } else if (sin2ThetaA < 0 && sin2ThetaC > 0) {
          quadrant = 2;
        } else if (sin2ThetaA > 0 && sin2ThetaC < 0) {
          quadrant = 3;
        } else if (sin2ThetaA > 0 && sin2ThetaC > 0) {
          quadrant = 4;
        }

        cosThetaAHist->Fill(cosThetaA);
        cosThetaCHist->Fill(cosThetaC);
        cosThetaAcosThetaCHist->Fill(cosThetaA,cosThetaC);

     if (jentry < 00) {
        cout << "paX, paY, paZ =   " << paX << "   " << paY  << "   " << paZ << endl;
        cout << "pbX, pbY, pbZ =   " << pbX << "   " << pbY  << "   " << pbZ << endl;
        cout << "pcX, pcY, pcZ =   " << pcX << "   " << pcY  << "   " << pcZ << endl;
        cout << "pdX, pdY, pdZ =   " << pdX << "   " << pdY  << "   " << pdZ << endl;
        cout << "paPrimeX, paPrimeY, paPrimeZ =   " << paPrimeX << "   " << paPrimeY  << "   " << paPrimeZ << endl;
        cout << "pbPrimeX, pbPrimeY, pbPrimeZ =   " << pbPrimeX << "   " << pbPrimeY  << "   " << pbPrimeZ << endl;
        cout << "pcPrimeX, pcPrimeY, pcPrimeZ =   " << pcPrimeX << "   " << pcPrimeY  << "   " << pcPrimeZ << endl;
        cout << "pdPrimeX, pdPrimeY, pdPrimeZ =   " << pdPrimeX << "   " << pdPrimeY  << "   " << pdPrimeZ << endl;
        cout << "cosThetaA =  " <<  cosThetaA << "   and cosThetaC =  " << cosThetaC << endl;
      }

      sanityPlot->Fill(tripleProduct,phi);

      allPhiHist->Fill(phi);
      if (D0_ID > 0) {
        allPhiHistD0->Fill(phi);
      } else {
        allPhiHistD0bar->Fill(phi);
      }

// look at phi for events in the K*,rho region, separating into D0 and D0bar samples
      if (abs(mAB-892)<35 && abs(mCD-775<100)) {   //// this looks at K*,rho region
        KstarRhoCand = true;
        mABmADForKstarRho->Fill(pAB_4vec.M(),pAD_4vec.M());
        if (D0_ID>0) {
          allPhiHistD02KstarRho->Fill(phi);
          if (quadrant == 1) {
            quad1PhiHistD02KstarRho->Fill(phi);
          } else if (quadrant == 2) {
            quad2PhiHistD02KstarRho->Fill(phi);
          } else if (quadrant == 3) {
            quad3PhiHistD02KstarRho->Fill(phi);
          } else if (quadrant == 4) {
            quad4PhiHistD02KstarRho->Fill(phi);
          }
          tAtCD02KstarRho->Fill(cosThetaA,cosThetaC);
        } else {
          allPhiHistD0bar2KstarRho->Fill(phi);
          if (quadrant == 1) {
            quad1PhiHistD0bar2KstarRho->Fill(phi);
          } else if (quadrant == 2) {
            quad2PhiHistD0bar2KstarRho->Fill(phi);
          } else if (quadrant == 3) {
            quad3PhiHistD0bar2KstarRho->Fill(phi);
          } else if (quadrant == 4) {
            quad4PhiHistD0bar2KstarRho->Fill(phi);
          }
          tAtCD0bar2KstarRho->Fill(cosThetaA,cosThetaC);
        }
      }

// look at phi for events in the K*,f0 region, separating into D0 and D0bar samples
      if (abs(mAB-892)<35 && mCD<550) {   /////  this looks at "K*,f0" region
        KstarF0Cand = true;
        mABmADForKstarF0->Fill(pAB_4vec.M(),pAD_4vec.M());
        if (D0_ID>0) {
          allPhiHistD02KstarF0->Fill(phi);
          if (quadrant == 1) {
            quad1PhiHistD02KstarF0->Fill(phi);
          } else if (quadrant == 2) {
            quad2PhiHistD02KstarF0->Fill(phi);
          } else if (quadrant == 3) {
            quad3PhiHistD02KstarF0->Fill(phi);
          } else if (quadrant == 4) {
            quad4PhiHistD02KstarF0->Fill(phi);
          }
          tAtCD02KstarF0->Fill(cosThetaA,cosThetaC);
        } else {
          allPhiHistD0bar2KstarF0->Fill(phi);
          if (quadrant == 1) {
            quad1PhiHistD0bar2KstarF0->Fill(phi);
          } else if (quadrant == 2) {
            quad2PhiHistD0bar2KstarF0->Fill(phi);
          } else if (quadrant == 3) {
            quad3PhiHistD0bar2KstarF0->Fill(phi);
          } else if (quadrant == 4) {
            quad4PhiHistD0bar2KstarF0->Fill(phi);
          }
          tAtCD0bar2KstarF0->Fill(cosThetaA,cosThetaC);
        }
      }

// look at phi for events in the Kappa,rho region, separating into D0 and D0bar samples
      if (mAB<775 && abs(mCD-775<75)) {     /////  this looks at "kappa,rho" region
        KappaRhoCand = true;
        mABmADForKappaRho->Fill(pAB_4vec.M(),pAD_4vec.M());
        if (D0_ID>0) {
          allPhiHistD02KappaRho->Fill(phi);
          if (quadrant == 1) {
            quad1PhiHistD02KappaRho->Fill(phi);
          } else if (quadrant == 2) {
            quad2PhiHistD02KappaRho->Fill(phi);
          } else if (quadrant == 3) {
            quad3PhiHistD02KappaRho->Fill(phi);
          } else if (quadrant == 4) {
            quad4PhiHistD02KappaRho->Fill(phi);
          }
          tAtCD02KappaRho->Fill(cosThetaA,cosThetaC);
        } else {
          allPhiHistD0bar2KappaRho->Fill(phi);
          if (quadrant == 1) {
            quad1PhiHistD0bar2KappaRho->Fill(phi);
          } else if (quadrant == 2) {
            quad2PhiHistD0bar2KappaRho->Fill(phi);
          } else if (quadrant == 3) {
            quad3PhiHistD0bar2KappaRho->Fill(phi);
          } else if (quadrant == 4) {
            quad4PhiHistD0bar2KappaRho->Fill(phi);
          }
          tAtCD0bar2KappaRho->Fill(cosThetaA,cosThetaC);
        }
      }
//  now, repeat using the high-mass K,pi pair to define the reference plane

      mADmCB->Fill(pAD_4vec.M(),pCB_4vec.M());
      mKPimPiPi->Fill(pAD_4vec.M(),pCB_4vec.M());
      mABmAD->Fill(pAB_4vec.M(),pAD_4vec.M());
      mABmADzoomed->Fill(pAB_4vec.M(),pAD_4vec.M());

      if ( pAB_4vec.M()<850 && pAD_4vec.M()<850 )  {
        TLorentzVector pABDlocal = pA_4vec + pB_4vec + pD_4vec;
        mABD_corner->Fill(pABDlocal.M());
        cornerKPiPiMassSqHist->Fill(pABDlocal.M()*pABDlocal.M()/1000000.);   //  divide by 1000000 to get GeV**2

        TLorentzVector pBD = pB_4vec + pD_4vec;		// pi+,pi+
        mPiPiForLowKPiPi->Fill(pBD.M());
        mABmCDForLowKPiPi->Fill(pAB_4vec.M(),pCD_4vec.M());
        cornerKMinusEnergyHist->Fill(pA_4vec.E());
        cornerPiMinusEnergyHist->Fill(pC_4vec.E());
        cornerPiPlusEnergyHist->Fill(pB_4vec.E());
        cornerPiPlusEnergyHist->Fill(pD_4vec.E());
        TLorentzVector pAC = pA_4vec + pC_4vec;		// K-,pi-
        TLorentzVector pAB = pA_4vec + pB_4vec;		// K-,pi+
        TLorentzVector pAD = pA_4vec + pD_4vec;		// K-,pi+
        TLorentzVector pCB = pC_4vec + pB_4vec;		// pi-,pi+
        TLorentzVector pCD = pC_4vec + pD_4vec;		// pi-,pi+
        cornerKMinusPiMinusMassHist->Fill(pAC.M());
        cornerKMinusPiPlusMassHist->Fill(pAB.M());
        cornerKMinusPiPlusMassHist->Fill(pAD.M());
        cornerPiMinusPiPlusMassHist->Fill(pCB.M());
        cornerPiMinusPiPlusMassHist->Fill(pCD.M());
        cornerPiPlusPiPlusMassHist->Fill(pBD.M());

        TVector3 localZhat = pC_3vec.Unit();
        Double_t pAz = localZhat.Dot(pA_3vec);
        Double_t pBz = localZhat.Dot(pB_3vec);
        Double_t pCz = localZhat.Dot(pC_3vec);
        Double_t pDz = localZhat.Dot(pD_3vec);

        cornerKMinusPzHist->Fill(pAz);
        cornerPiPlusPzHist->Fill(pBz);
        cornerPiMinusPzHist->Fill(pCz);
        cornerPiPlusPzHist->Fill(pDz);

        Double_t energyABD = pABD_4vec.E();
        TVector3 betaABD;
        betaABD.SetXYZ(pABD_4vec.Px()/energyABD, pABD_4vec.Py()/energyABD, pABD_4vec.Pz()/energyABD);
        TLorentzVector pAlocal_4vec = pA_4vec;
        pAlocal_4vec.Boost(-1.*betaABD);
        TLorentzVector pBlocal_4vec = pB_4vec;
        pBlocal_4vec.Boost(-1.*betaABD);
        TLorentzVector pDlocal_4vec = pD_4vec;
        pDlocal_4vec.Boost(-1.*betaABD);
        TVector3 pAlocal_3vec = pAlocal_4vec.Vect();
        TVector3 pBlocal_3vec = pBlocal_4vec.Vect();
        TVector3 pDlocal_3vec = pDlocal_4vec.Vect();
        Double_t cosThetaK = localZhat.Dot(pAlocal_3vec.Unit());
        cornerKminusHelictyCosineHist->Fill(cosThetaK);
      }

// mds      if (D0_TAU > 0.0010) {
// mds        mKPimPiPiA->Fill(pAD_4vec.M(),pCB_4vec.M());
// mds      }

      TVector3 pAD_3vec = pAD_4vec.Vect();
      TVector3 pCB_3vec = pCB_4vec.Vect();

      TVector3 zhatA = pAD_3vec.Unit();
      TVector3 yhatA = (pA_3vec.Cross(pD_3vec)).Unit();
      TVector3 xhatA = (yhatA.Cross(zhatA)).Unit();

      TVector3 yhatAPrime = (pC_3vec.Cross(pB_3vec)).Unit();

      Double_t cosPhiA = (yhatA.Dot(yhatAPrime));
      Double_t sinPhiA = (xhatA.Dot(yhatAPrime));
      cosVsinPlotA->Fill(cosPhiA,sinPhiA);
      Double_t phiA    = TMath::ATan2(sinPhiA,cosPhiA);
      if (phiA < 0) {
        phiA = 2.0*pi+phiA;
      }

      allPhiAHist->Fill(phiA);


// Sept 14 additions

      KmPipPipAllHist->Fill(mABD);
      if (!KstarRhoCand) {
        KmPipPipNotKstarRhoCand->Fill(mABD);
      }


      }  //  end of if (cutsB) { .... 
      
   }  // end of per event code

   TCanvas c1;

   TFile * myOutputFile = new TFile("myOutputFile.root","RECREATE");


   strippingLevelDeltaMHist->Draw();
   c1.SaveAs("strippingLevelDeltaMHist.png");

   strippingLevelMassHist->Draw();
   c1.SaveAs("strippingLevelMassHist.png");

   cutsAMassHist->Draw();
   c1.SaveAs("cutsAMassHist.png");

   cutsCMassHist->Draw();
   c1.SaveAs("cutsCMassHist.png");

   testMassHist->Draw();
   c1.SaveAs("testMassHist.png");

   massHistB->Draw();
   c1.SaveAs("massHistB.png");

   thetaXY->Draw("COLZ");
   c1.SaveAs("thetaXY.png");

   KminusKprobHist->Draw();
   c1.SaveAs("KminusKprobHist.png");

   massHistAlowKprob->Draw();
   c1.SaveAs("massHistAlowKprob.png");

   massHistAhighKprob->Draw();
   c1.SaveAs("massHistAhighKprob.png");

   allPhiHist->Draw();
   c1.SaveAs("allPhiHist.png");

   allPhiHist->Draw();
   c1.SaveAs("allPhiHist.png");

   allPhiHistD0->Draw();
   c1.SaveAs("allPhiHistD0.png");

   allPhiHistD0bar->Draw();
   c1.SaveAs("allPhiHistD0bar.png");

   allPhiHistD02KstarRho->Draw();
   c1.SaveAs("allPhiHistD02KstarRho.png");

   allPhiHistD02KstarRho->SetLineColor(kBlue);
   allPhiHistD02KstarRho->SetLineWidth(2);
   Double_t d02KstarRhoEntries = allPhiHistD02KstarRho->GetEntries();
   nD0 = d02KstarRhoEntries;
   allPhiHistD02KstarRho->Scale(1.00/d02KstarRhoEntries);
   allPhiHistD02KstarRho->Draw();
   allPhiHistD0bar2KstarRho->SetLineColor(kRed+1);
   allPhiHistD0bar2KstarRho->SetLineWidth(2);
   Double_t d0bar2KstarRhoEntries = allPhiHistD0bar2KstarRho->GetEntries();
   nD0bar = d0bar2KstarRhoEntries;
   allPhiHistD0bar2KstarRho->Scale(1.00/d0bar2KstarRhoEntries);
   allPhiHistD0bar2KstarRho->Draw("same");
   c1.SetLogy(0);
   c1.SaveAs("comparePhiKstarRho.png");
   c1.SetLogy(0);

   gStyle->SetOptStat(0);

//  ***  begin KstarRho calculations & plotting  ***
//  do asymmetry calculations before re-scaling the distributions
  
   nD0 = quad1PhiHistD02KstarRho->GetEntries();
   nD0bar = quad1PhiHistD0bar2KstarRho->GetEntries();
   Double_t scale = nD0/nD0bar;
   Double_t nD0Above = 0;
   Double_t nD0barAbove = 0;
//  change meaning of "Above" and "Below" to refer to  sign(sin(phi)), 
//  rather than phi above or below pi.
   for (int bin=0; bin<51; bin++) {
     nD0Above = nD0Above+quad1PhiHistD02KstarRho->GetBinContent(bin);
     nD0barAbove = nD0barAbove+quad1PhiHistD0bar2KstarRho->GetBinContent(bin);
   }
   
   Double_t nD0Below = 0;
   Double_t nD0barBelow = 0;
   for (int bin=51; bin<101; bin++) {
     nD0Below = nD0Below+quad1PhiHistD02KstarRho->GetBinContent(bin);
     nD0barBelow = nD0barBelow+quad1PhiHistD0bar2KstarRho->GetBinContent(bin);
   }

   Double_t D0AB_asymmetry = (nD0Above-nD0Below)/(nD0Above+nD0Below);
   Double_t D0AB_asymmetryErr = sqrt( (1.0 - D0AB_asymmetry*D0AB_asymmetry)/(nD0Above+nD0Below) );

   cout <<  endl << "For Quad 1 " << endl;
   cout << " nD0Above =   " << nD0Above << endl;
   cout << " nD0Below =   " << nD0Below << endl;
   cout << " D0AB_asymmetry =   " << D0AB_asymmetry << "  +-  " << D0AB_asymmetryErr << endl << endl;
   
   Double_t D0barAB_asymmetry = (nD0barAbove-nD0barBelow)/(nD0barAbove+nD0barBelow);
   Double_t D0barAB_asymmetryErr = sqrt( (1.0 - D0barAB_asymmetry*D0barAB_asymmetry)/(nD0barAbove+nD0barBelow) );

   cout << " nD0barAbove =   " << nD0barAbove << endl;
   cout << " nD0barBelow =   " << nD0barBelow << endl;
   cout << " D0barAB_asymmetry =   " << D0barAB_asymmetry 
            << "  +-  " << D0barAB_asymmetryErr << endl << endl;

   Double_t weight1 = 1./(D0AB_asymmetryErr*D0AB_asymmetryErr);
   Double_t weight2 = 1./(D0barAB_asymmetryErr*D0barAB_asymmetryErr);

   Double_t CPAsymmetry = (D0AB_asymmetry*weight1+D0barAB_asymmetry*weight2)/(weight1+weight2);
   Double_t CPAsymmetryErr = sqrt(1./(weight1+weight2));
   Double_t DiffAB = (D0AB_asymmetry*weight1-D0barAB_asymmetry*weight2)/(weight1+weight2);
   
   cout << "  CP Asymmetry =   " << CPAsymmetry << "  +-  " << CPAsymmetryErr << endl << endl;
   
  
   Double_t nD0Sin2PhiPlus = 0; 
   Double_t nD0barSin2PhiPlus = 0;

   Double_t nD0Sin2PhiMinus = 0; 
   Double_t nD0barSin2PhiMinus = 0;

   for (int bin=1; bin<26; bin++) {
     nD0Sin2PhiPlus = nD0Sin2PhiPlus+quad1PhiHistD02KstarRho->GetBinContent(bin);
     nD0barSin2PhiPlus = nD0barSin2PhiPlus+quad1PhiHistD0bar2KstarRho->GetBinContent(bin);
   }
   for (int bin=51; bin<76; bin++) {
     nD0Sin2PhiPlus = nD0Sin2PhiPlus+quad1PhiHistD02KstarRho->GetBinContent(bin);
     nD0barSin2PhiPlus = nD0barSin2PhiPlus+quad1PhiHistD0bar2KstarRho->GetBinContent(bin);
   }

   for (int bin=25; bin<51; bin++) {
     nD0Sin2PhiMinus = nD0Sin2PhiMinus+quad1PhiHistD02KstarRho->GetBinContent(bin);
     nD0barSin2PhiMinus = nD0barSin2PhiMinus+quad1PhiHistD0bar2KstarRho->GetBinContent(bin);
   }
   for (int bin=75; bin<101; bin++) {
     nD0Sin2PhiMinus = nD0Sin2PhiMinus+quad1PhiHistD02KstarRho->GetBinContent(bin);
     nD0barSin2PhiMinus = nD0barSin2PhiMinus+quad1PhiHistD0bar2KstarRho->GetBinContent(bin);
   }

   Double_t D0Sin2Phi_asymmetry = (nD0Sin2PhiPlus-nD0Sin2PhiMinus)/(nD0Sin2PhiPlus+nD0Sin2PhiMinus);
   Double_t D0Sin2Phi_asymmetryErr = sqrt( (1.0 - D0Sin2Phi_asymmetry*D0Sin2Phi_asymmetry)/
                                      (nD0Sin2PhiPlus+nD0Sin2PhiMinus) );

   Double_t D0barSin2Phi_asymmetry = (nD0barSin2PhiPlus-nD0barSin2PhiMinus) /
                                      (nD0barSin2PhiPlus+nD0barSin2PhiMinus);
   Double_t D0barSin2Phi_asymmetryErr = sqrt( (1.0 - D0barSin2Phi_asymmetry*D0barSin2Phi_asymmetry)/
                                         (nD0barSin2PhiPlus+nD0barSin2PhiMinus) );

   weight1 = 1./(D0Sin2Phi_asymmetryErr*D0Sin2Phi_asymmetryErr);
   weight2 = 1./(D0barSin2Phi_asymmetryErr*D0barSin2Phi_asymmetryErr);

   Double_t Sin2PhiCP_asymmetry = (D0Sin2Phi_asymmetry*weight1+D0barSin2Phi_asymmetry*weight2)/
                                   (weight1+weight2);
   Double_t Sin2PhiCP_asymmetryErr = sqrt(1./(weight1+weight2));

   Double_t DiffSin2Phi = (D0Sin2Phi_asymmetry*weight1-D0barSin2Phi_asymmetry*weight2)/(weight1+weight2);

   cout << "D0Sin2Phi_asymmetry =  " << D0Sin2Phi_asymmetry << "  +-  " <<
                D0Sin2Phi_asymmetryErr << endl;
   cout << "D0barSin2Phi_asymmetry =  " << D0barSin2Phi_asymmetry << "  +-  " <<
                D0barSin2Phi_asymmetryErr << endl;
   cout << " Sin2PhiCP_asymmetry =    " << Sin2PhiCP_asymmetry << "  +-  " <<
                 Sin2PhiCP_asymmetryErr << endl << endl;
  

   Double_t maximum = quad1PhiHistD0bar2KstarRho->GetMaximum();
    cout << "max from quad1PhiHistD0bar2KstarRho->GetMaximum() = " << maximum << endl;
   quad1PhiHistD0bar2KstarRho->Draw();
   quad1PhiHistD02KstarRho->SetLineColor(kBlue);
   quad1PhiHistD02KstarRho->SetLineWidth(2);
   d02KstarRhoEntries = quad1PhiHistD02KstarRho->GetEntries();
   quad1PhiHistD02KstarRho->Scale(1.00/d02KstarRhoEntries);
   quad1PhiHistD02KstarRho->GetXaxis()->SetTitleSize(0.06);
   quad1PhiHistD02KstarRho->GetXaxis()->SetTitleOffset(0.75);
   quad1PhiHistD02KstarRho->GetXaxis()->SetLabelFont(62);
   quad1PhiHistD02KstarRho->GetXaxis()->CenterTitle(true);
   quad1PhiHistD02KstarRho->SetTitle("(K*, #rho)  - Quad 1");
   quad1PhiHistD02KstarRho->SetXTitle("#phi [radians]");
   quad1PhiHistD02KstarRho->GetYaxis()->SetTitleSize(0.06);
   quad1PhiHistD02KstarRho->GetYaxis()->SetTitleOffset(0.75);
   quad1PhiHistD02KstarRho->SetYTitle("fraction per 2#pi/100 radians");
   TLegend * leg = new TLegend(0.12,0.76,0.32,0.89);
   leg->SetHeader("The Samples");
   leg->AddEntry(quad1PhiHistD02KstarRho,"D^{0}","L");
   quad1PhiHistD02KstarRho->Draw();
   quad1PhiHistD0bar2KstarRho->SetLineColor(kRed+1);
   quad1PhiHistD0bar2KstarRho->SetLineWidth(2);
   d0bar2KstarRhoEntries = quad1PhiHistD0bar2KstarRho->GetEntries();
   quad1PhiHistD0bar2KstarRho->Scale(1.00/d0bar2KstarRhoEntries);
   quad1PhiHistD02KstarRho->GetYaxis()->SetRangeUser(0.,1.25*maximum/d02KstarRhoEntries);
   quad1PhiHistD02KstarRho->GetXaxis()->SetTitleSize(0.06);
   quad1PhiHistD02KstarRho->GetXaxis()->SetTitleOffset(0.75);
   quad1PhiHistD02KstarRho->GetXaxis()->SetLabelFont(62);
   quad1PhiHistD02KstarRho->GetXaxis()->CenterTitle(true);
   quad1PhiHistD02KstarRho->SetTitle("(K*, #rho)  - Quad 1");
   quad1PhiHistD02KstarRho->SetXTitle("#phi [radians]");
   quad1PhiHistD02KstarRho->GetYaxis()->SetTitleSize(0.06);
   quad1PhiHistD02KstarRho->GetYaxis()->SetTitleOffset(0.75);
   quad1PhiHistD02KstarRho->SetYTitle("fraction per 2#pi/100 radians");
   leg->AddEntry(quad1PhiHistD0bar2KstarRho,"#bar{D}^{0}","L");
   quad1PhiHistD0bar2KstarRho->Draw("same");
   leg->Draw();
   pt1->Clear();
   d0AsymStr.Form("%4.1f\n",100.*D0AB_asymmetry);
   d0AsymErrStr.Form("%4.1f\n",100.*D0AB_asymmetryErr);
   d0barAsymStr.Form("%4.1f\n",100.*D0barAB_asymmetry);
   d0barAsymErrStr.Form("%4.1f\n",100.*D0barAB_asymmetryErr);
   cpAsymStr.Form("%4.1f\n",100.*CPAsymmetry);
   cpAsymErrStr.Form("%4.1f\n",100.*CPAsymmetryErr);
   DiffABStr.Form("%4.1f\n",100.*DiffAB);
   d0Sin2PhiAsymStr.Form("%4.1f\n",100.*D0Sin2Phi_asymmetry);
   d0Sin2PhiAsymErrStr.Form("%4.1f\n",100.*D0Sin2Phi_asymmetryErr);
   d0barSin2PhiAsymStr.Form("%4.1f\n",100.*D0barSin2Phi_asymmetry);
   d0barSin2PhiAsymErrStr.Form("%4.1f\n",100.*D0barSin2Phi_asymmetryErr);
   cpSin2PhiAsymStr.Form("%4.1f\n",100.*Sin2PhiCP_asymmetry);
   cpSin2PhiAsymErrStr.Form("%4.1f\n",100.*Sin2PhiCP_asymmetryErr);
   DiffSin2PhiStr.Form("%4.1f\n",100.*DiffSin2Phi);
   pt1->AddText("asymmetries");
   pt1->AddText("sin(#phi)             sin(2#phi)");
   pt1->AddText("D^{0}:  ( "+d0AsymStr+" #pm "+d0AsymErrStr+")%   ("
         +d0Sin2PhiAsymStr+" #pm "+d0Sin2PhiAsymErrStr+")%");
   pt1->AddText("#bar{D}^{0}:  ( "+d0barAsymStr+" #pm "+d0barAsymErrStr+")%   ("
         +d0barSin2PhiAsymStr+" #pm "+d0barSin2PhiAsymErrStr+")%");
   pt1->AddText("CP:   ( "+cpAsymStr+" #pm "+cpAsymErrStr+")%   ("
         +cpSin2PhiAsymStr+" #pm "+cpSin2PhiAsymErrStr+")%");
   pt1->AddText("D^{0}-#bar{D}^{0}:  ("+DiffABStr+" #pm "+cpAsymErrStr+")%   ("
         +DiffSin2PhiStr+" #pm "+cpSin2PhiAsymErrStr+")%");
   nd0Str.Form("%6.0f\n",nD0);
   nd0barStr.Form("%6.0f\n",nD0bar);
   pt1->AddText("n(D^{0}) = "+nd0Str+"           n(#bar{D}^{0}) = "+nd0barStr);
   pt1->Draw();
   c1.SaveAs("compareQuad1PhiKstarRho.png");
   c1.SetLogy(0);


/////////  start with Quad 2

//  do asymmetry calculations before re-scaling the distributions
  
   nD0 = quad2PhiHistD02KstarRho->GetEntries();
   nD0bar = quad2PhiHistD0bar2KstarRho->GetEntries();
   scale = nD0/nD0bar;
   nD0Above = 0;
   nD0barAbove = 0;
   for (int bin=0; bin<51; bin++) {
     nD0Above = nD0Above+quad2PhiHistD02KstarRho->GetBinContent(bin);
     nD0barAbove = nD0barAbove+quad2PhiHistD0bar2KstarRho->GetBinContent(bin);
   }
   
   nD0Below = 0;
   nD0barBelow = 0;
   for (int bin=51; bin<101; bin++) {
     nD0Below = nD0Below+quad2PhiHistD02KstarRho->GetBinContent(bin);
     nD0barBelow = nD0barBelow+quad2PhiHistD0bar2KstarRho->GetBinContent(bin);
   }

   D0AB_asymmetry = (nD0Above-nD0Below)/(nD0Above+nD0Below);
   D0AB_asymmetryErr = sqrt( (1.0 - D0AB_asymmetry*D0AB_asymmetry)/(nD0Above+nD0Below) );

   cout <<  endl << "For Quad 2 " << endl;
   cout << " nD0Above =   " << nD0Above << endl;
   cout << " nD0Below =   " << nD0Below << endl;
   cout << " D0AB_asymmetry =   " << D0AB_asymmetry << "  +-  " << D0AB_asymmetryErr << endl << endl;
   
   D0barAB_asymmetry = (nD0barAbove-nD0barBelow)/(nD0barAbove+nD0barBelow);
   D0barAB_asymmetryErr = sqrt( (1.0 - D0barAB_asymmetry*D0barAB_asymmetry)/(nD0barAbove+nD0barBelow) );

   cout << " nD0barAbove =   " << nD0barAbove << endl;
   cout << " nD0barBelow =   " << nD0barBelow << endl;
   cout << " D0barAB_asymmetry =   " << D0barAB_asymmetry 
            << "  +-  " << D0barAB_asymmetryErr << endl << endl;

   weight1 = 1./(D0AB_asymmetryErr*D0AB_asymmetryErr);
   weight2 = 1./(D0barAB_asymmetryErr*D0barAB_asymmetryErr);

   CPAsymmetry = (D0AB_asymmetry*weight1+D0barAB_asymmetry*weight2)/(weight1+weight2);
   CPAsymmetryErr = sqrt(1./(weight1+weight2));
   DiffAB = (D0AB_asymmetry*weight1-D0barAB_asymmetry*weight2)/(weight1+weight2);
   cout << "  CP Asymmetry =   " << CPAsymmetry << "  +-  " << CPAsymmetryErr << endl << endl;


   nD0Sin2PhiPlus = 0; 
   nD0barSin2PhiPlus = 0;

   nD0Sin2PhiMinus = 0; 
   nD0barSin2PhiMinus = 0;

   for (int bin=1; bin<26; bin++) {
     nD0Sin2PhiPlus = nD0Sin2PhiPlus+quad2PhiHistD02KstarRho->GetBinContent(bin);
     nD0barSin2PhiPlus = nD0barSin2PhiPlus+quad2PhiHistD0bar2KstarRho->GetBinContent(bin);
   }
   for (int bin=51; bin<76; bin++) {
     nD0Sin2PhiPlus = nD0Sin2PhiPlus+quad2PhiHistD02KstarRho->GetBinContent(bin);
     nD0barSin2PhiPlus = nD0barSin2PhiPlus+quad2PhiHistD0bar2KstarRho->GetBinContent(bin);
   }

   for (int bin=25; bin<51; bin++) {
     nD0Sin2PhiMinus = nD0Sin2PhiMinus+quad2PhiHistD02KstarRho->GetBinContent(bin);
     nD0barSin2PhiMinus = nD0barSin2PhiMinus+quad2PhiHistD0bar2KstarRho->GetBinContent(bin);
   }
   for (int bin=75; bin<101; bin++) {
     nD0Sin2PhiMinus = nD0Sin2PhiMinus+quad2PhiHistD02KstarRho->GetBinContent(bin);
     nD0barSin2PhiMinus = nD0barSin2PhiMinus+quad2PhiHistD0bar2KstarRho->GetBinContent(bin);
   }

   D0Sin2Phi_asymmetry = (nD0Sin2PhiPlus-nD0Sin2PhiMinus)/(nD0Sin2PhiPlus+nD0Sin2PhiMinus);
   D0Sin2Phi_asymmetryErr = sqrt( (1.0 - D0Sin2Phi_asymmetry*D0Sin2Phi_asymmetry)/
                             (nD0Sin2PhiPlus+nD0Sin2PhiMinus) );

   D0barSin2Phi_asymmetry = (nD0barSin2PhiPlus-nD0barSin2PhiMinus) /
                             (nD0barSin2PhiPlus+nD0barSin2PhiMinus);
   D0barSin2Phi_asymmetryErr = sqrt( (1.0 - D0barSin2Phi_asymmetry*D0barSin2Phi_asymmetry)/
                                         (nD0barSin2PhiPlus+nD0barSin2PhiMinus) );

   weight1 = 1./(D0Sin2Phi_asymmetryErr*D0Sin2Phi_asymmetryErr);
   weight2 = 1./(D0barSin2Phi_asymmetryErr*D0barSin2Phi_asymmetryErr);

   Sin2PhiCP_asymmetry = (D0Sin2Phi_asymmetry*weight1+D0barSin2Phi_asymmetry*weight2)/
                                   (weight1+weight2);
   Sin2PhiCP_asymmetryErr = sqrt(1./(weight1+weight2));

   DiffSin2Phi = (D0Sin2Phi_asymmetry*weight1-D0barSin2Phi_asymmetry*weight2)/(weight1+weight2);



   cout << "D0Sin2Phi_asymmetry =  " << D0Sin2Phi_asymmetry << "  +-  " <<
                D0Sin2Phi_asymmetryErr << endl;
   cout << "D0barSin2Phi_asymmetry =  " << D0barSin2Phi_asymmetry << "  +-  " <<
                D0barSin2Phi_asymmetryErr << endl;
   cout << " Sin2PhiCP_asymmetry =    " << Sin2PhiCP_asymmetry << "  +-  " <<
                 Sin2PhiCP_asymmetryErr << endl << endl;
  
   maximum = quad2PhiHistD0bar2KstarRho->GetMaximum();
    cout << "max from quad2PhiHistD0bar2KstarRho->GetMaximum() = " << maximum << endl;
   quad2PhiHistD02KstarRho->SetLineColor(kBlue);
   quad2PhiHistD02KstarRho->SetLineWidth(2);
   d02KstarRhoEntries = quad2PhiHistD02KstarRho->GetEntries();
   nD0 = d02KstarRhoEntries;
   quad2PhiHistD02KstarRho->Scale(1.00/d02KstarRhoEntries);
   quad2PhiHistD0bar2KstarRho->SetLineColor(kRed+1);
   quad2PhiHistD0bar2KstarRho->SetLineWidth(2);
   d0bar2KstarRhoEntries = quad2PhiHistD0bar2KstarRho->GetEntries();
   nD0bar = d0bar2KstarRhoEntries;
   quad2PhiHistD0bar2KstarRho->Scale(1.00/d0bar2KstarRhoEntries);
   quad2PhiHistD02KstarRho->GetYaxis()->SetRangeUser(0.,1.25*maximum/d02KstarRhoEntries);
   quad2PhiHistD02KstarRho->GetXaxis()->SetTitleSize(0.06);
   quad2PhiHistD02KstarRho->GetXaxis()->SetTitleOffset(0.75);
   quad2PhiHistD02KstarRho->GetXaxis()->SetLabelFont(62);
   quad2PhiHistD02KstarRho->GetXaxis()->CenterTitle(true);
   quad2PhiHistD02KstarRho->SetTitle("(K*, #rho)  - Quad 2");
   quad2PhiHistD02KstarRho->SetXTitle("#phi [radians]");
   quad2PhiHistD02KstarRho->GetYaxis()->SetTitleSize(0.06);
   quad2PhiHistD02KstarRho->GetYaxis()->SetTitleOffset(0.75);
   quad2PhiHistD02KstarRho->SetYTitle("fraction per 2#pi/100 radians");
   nd0Str.Form("%6.0f\n",nD0);
   nd0barStr.Form("%6.0f\n",nD0bar);
   pt1->AddText("n(D^{0}) = "+nd0Str+"           n(#bar{D}^{0}) = "+nd0barStr);
   quad2PhiHistD02KstarRho->Draw();
   leg->Clear();
   leg->SetHeader("The Samples");
   leg->AddEntry(quad2PhiHistD02KstarRho,"D^{0}","L");
   quad2PhiHistD0bar2KstarRho->Draw("same");
   leg->AddEntry(quad2PhiHistD0bar2KstarRho,"#bar{D}^{0}","L");
   leg->Draw();
   pt1->Clear();
   d0AsymStr.Form("%4.1f\n",100.*D0AB_asymmetry);
   d0AsymErrStr.Form("%4.1f\n",100.*D0AB_asymmetryErr);
   d0barAsymStr.Form("%4.1f\n",100.*D0barAB_asymmetry);
   d0barAsymErrStr.Form("%4.1f\n",100.*D0barAB_asymmetryErr);
   cpAsymStr.Form("%4.1f\n",100.*CPAsymmetry);
   cpAsymErrStr.Form("%4.1f\n",100.*CPAsymmetryErr);
   DiffABStr.Form("%4.1f\n",100.*DiffAB);
   d0Sin2PhiAsymStr.Form("%4.1f\n",100.*D0Sin2Phi_asymmetry);
   d0Sin2PhiAsymErrStr.Form("%4.1f\n",100.*D0Sin2Phi_asymmetryErr);
   d0barSin2PhiAsymStr.Form("%4.1f\n",100.*D0barSin2Phi_asymmetry);
   d0barSin2PhiAsymErrStr.Form("%4.1f\n",100.*D0barSin2Phi_asymmetryErr);
   cpSin2PhiAsymStr.Form("%4.1f\n",100.*Sin2PhiCP_asymmetry);
   cpSin2PhiAsymErrStr.Form("%4.1f\n",100.*Sin2PhiCP_asymmetryErr);
   DiffSin2PhiStr.Form("%4.1f\n",100.*DiffSin2Phi);
   pt1->AddText("asymmetries");
   pt1->AddText("sin(#phi)             sin(2#phi)");
   pt1->AddText("D^{0}:  ( "+d0AsymStr+" #pm "+d0AsymErrStr+")%   ("
         +d0Sin2PhiAsymStr+" #pm "+d0Sin2PhiAsymErrStr+")%");
   pt1->AddText("#bar{D}^{0}:  ( "+d0barAsymStr+" #pm "+d0barAsymErrStr+")%   ("
         +d0barSin2PhiAsymStr+" #pm "+d0barSin2PhiAsymErrStr+")%");
   pt1->AddText("CP:   ( "+cpAsymStr+" #pm "+cpAsymErrStr+")%   ("
         +cpSin2PhiAsymStr+" #pm "+cpSin2PhiAsymErrStr+")%");
   pt1->AddText("D^{0}-#bar{D}^{0}:  ("+DiffABStr+" #pm "+cpAsymErrStr+")%   ("
         +DiffSin2PhiStr+" #pm "+cpSin2PhiAsymErrStr+")%");
   nd0Str.Form("%6.0f\n",nD0);
   nd0barStr.Form("%6.0f\n",nD0bar);
   pt1->AddText("n(D^{0}) = "+nd0Str+"           n(#bar{D}^{0}) = "+nd0barStr);
   pt1->Draw();
   c1.SaveAs("compareQuad2PhiKstarRho.png");
   c1.SetLogy(0);

/////////  start with Quad 3

//  do asymmetry calculations before re-scaling the distributions
  
   nD0 = quad3PhiHistD02KstarRho->GetEntries();
   nD0bar = quad3PhiHistD0bar2KstarRho->GetEntries();
   scale = nD0/nD0bar;
   nD0Above = 0;
   nD0barAbove = 0;
   for (int bin=0; bin<51; bin++) {
     nD0Above = nD0Above+quad3PhiHistD02KstarRho->GetBinContent(bin);
     nD0barAbove = nD0barAbove+quad3PhiHistD0bar2KstarRho->GetBinContent(bin);
   }
   
   nD0Below = 0;
   nD0barBelow = 0;
   for (int bin=51; bin<101; bin++) {
     nD0Below = nD0Below+quad3PhiHistD02KstarRho->GetBinContent(bin);
     nD0barBelow = nD0barBelow+quad3PhiHistD0bar2KstarRho->GetBinContent(bin);
   }

   D0AB_asymmetry = (nD0Above-nD0Below)/(nD0Above+nD0Below);
   D0AB_asymmetryErr = sqrt( (1.0 - D0AB_asymmetry*D0AB_asymmetry)/(nD0Above+nD0Below) );

   cout <<  endl << "For Quad 3 " << endl;
   cout << " nD0Above =   " << nD0Above << endl;
   cout << " nD0Below =   " << nD0Below << endl;
   cout << " D0AB_asymmetry =   " << D0AB_asymmetry << "  +-  " << D0AB_asymmetryErr << endl << endl;
   
   D0barAB_asymmetry = (nD0barAbove-nD0barBelow)/(nD0barAbove+nD0barBelow);
   D0barAB_asymmetryErr = sqrt( (1.0 - D0barAB_asymmetry*D0barAB_asymmetry)/(nD0barAbove+nD0barBelow) );

   cout << " nD0barAbove =   " << nD0barAbove << endl;
   cout << " nD0barBelow =   " << nD0barBelow << endl;
   cout << " D0barAB_asymmetry =   " << D0barAB_asymmetry 
            << "  +-  " << D0barAB_asymmetryErr << endl << endl;

   weight1 = 1./(D0AB_asymmetryErr*D0AB_asymmetryErr);
   weight2 = 1./(D0barAB_asymmetryErr*D0barAB_asymmetryErr);

   CPAsymmetry = (D0AB_asymmetry*weight1+D0barAB_asymmetry*weight2)/(weight1+weight2);
   CPAsymmetryErr = sqrt(1./(weight1+weight2));
   DiffAB = (D0AB_asymmetry*weight1-D0barAB_asymmetry*weight2)/(weight1+weight2);

   cout << "  CP Asymmetry =   " << CPAsymmetry << "  +-  " << CPAsymmetryErr << endl << endl;

  
   nD0Sin2PhiPlus = 0; 
   nD0barSin2PhiPlus = 0;

   nD0Sin2PhiMinus = 0; 
   nD0barSin2PhiMinus = 0;

   for (int bin=1; bin<26; bin++) {
     nD0Sin2PhiPlus = nD0Sin2PhiPlus+quad3PhiHistD02KstarRho->GetBinContent(bin);
     nD0barSin2PhiPlus = nD0barSin2PhiPlus+quad3PhiHistD0bar2KstarRho->GetBinContent(bin);
   }
   for (int bin=51; bin<76; bin++) {
     nD0Sin2PhiPlus = nD0Sin2PhiPlus+quad3PhiHistD02KstarRho->GetBinContent(bin);
     nD0barSin2PhiPlus = nD0barSin2PhiPlus+quad3PhiHistD0bar2KstarRho->GetBinContent(bin);
   }

   for (int bin=25; bin<51; bin++) {
     nD0Sin2PhiMinus = nD0Sin2PhiMinus+quad3PhiHistD02KstarRho->GetBinContent(bin);
     nD0barSin2PhiMinus = nD0barSin2PhiMinus+quad3PhiHistD0bar2KstarRho->GetBinContent(bin);
   }
   for (int bin=75; bin<101; bin++) {
     nD0Sin2PhiMinus = nD0Sin2PhiMinus+quad3PhiHistD02KstarRho->GetBinContent(bin);
     nD0barSin2PhiMinus = nD0barSin2PhiMinus+quad3PhiHistD0bar2KstarRho->GetBinContent(bin);
   }

   D0Sin2Phi_asymmetry = (nD0Sin2PhiPlus-nD0Sin2PhiMinus)/(nD0Sin2PhiPlus+nD0Sin2PhiMinus);
   D0Sin2Phi_asymmetryErr = sqrt( (1.0 - D0Sin2Phi_asymmetry*D0Sin2Phi_asymmetry)/
                             (nD0Sin2PhiPlus+nD0Sin2PhiMinus) );

   D0barSin2Phi_asymmetry = (nD0barSin2PhiPlus-nD0barSin2PhiMinus) /
                             (nD0barSin2PhiPlus+nD0barSin2PhiMinus);
   D0barSin2Phi_asymmetryErr = sqrt( (1.0 - D0barSin2Phi_asymmetry*D0barSin2Phi_asymmetry)/
                                         (nD0barSin2PhiPlus+nD0barSin2PhiMinus) );

   weight1 = 1./(D0Sin2Phi_asymmetryErr*D0Sin2Phi_asymmetryErr);
   weight2 = 1./(D0barSin2Phi_asymmetryErr*D0barSin2Phi_asymmetryErr);

   Sin2PhiCP_asymmetry = (D0Sin2Phi_asymmetry*weight1+D0barSin2Phi_asymmetry*weight2)/
                                   (weight1+weight2);
   Sin2PhiCP_asymmetryErr = sqrt(1./(weight1+weight2));

   DiffSin2Phi = (D0Sin2Phi_asymmetry*weight1-D0barSin2Phi_asymmetry*weight2)/(weight1+weight2);


   cout << "D0Sin2Phi_asymmetry =  " << D0Sin2Phi_asymmetry << "  +-  " <<
                D0Sin2Phi_asymmetryErr << endl;
   cout << "D0barSin2Phi_asymmetry =  " << D0barSin2Phi_asymmetry << "  +-  " <<
                D0barSin2Phi_asymmetryErr << endl;
   cout << " Sin2PhiCP_asymmetry =    " << Sin2PhiCP_asymmetry << "  +-  " <<
                 Sin2PhiCP_asymmetryErr << endl << endl;
  
   maximum = quad3PhiHistD0bar2KstarRho->GetMaximum();
    cout << "max from quad3PhiHistD0bar2KstarRho->GetMaximum() = " << maximum << endl;
   quad3PhiHistD0bar2KstarRho->Draw();
   quad3PhiHistD02KstarRho->SetLineColor(kBlue);
   quad3PhiHistD02KstarRho->SetLineWidth(2);
   d02KstarRhoEntries = quad3PhiHistD02KstarRho->GetEntries();
   quad3PhiHistD02KstarRho->Scale(1.00/d02KstarRhoEntries);
   quad3PhiHistD02KstarRho->GetXaxis()->SetTitleSize(0.06);
   quad3PhiHistD02KstarRho->GetXaxis()->SetTitleOffset(0.75);
   quad3PhiHistD02KstarRho->GetXaxis()->SetLabelFont(62);
   quad3PhiHistD02KstarRho->GetXaxis()->CenterTitle(true);
   quad3PhiHistD02KstarRho->SetTitle("(K*, #rho)  - Quad 3");
   quad3PhiHistD02KstarRho->SetXTitle("#phi [radians]");
   quad3PhiHistD02KstarRho->GetYaxis()->SetTitleSize(0.06);
   quad3PhiHistD02KstarRho->GetYaxis()->SetTitleOffset(0.75);
   quad3PhiHistD02KstarRho->SetYTitle("fraction per 2#pi/100 radians");
   quad3PhiHistD02KstarRho->Draw();
   leg->Clear();
   leg->SetHeader("The Samples");
   leg->AddEntry(quad3PhiHistD02KstarRho,"D^{0}","L");
   quad3PhiHistD02KstarRho->Draw();
   quad3PhiHistD0bar2KstarRho->SetLineColor(kRed+1);
   quad3PhiHistD0bar2KstarRho->SetLineWidth(2);
   d0bar2KstarRhoEntries = quad3PhiHistD0bar2KstarRho->GetEntries();
   quad3PhiHistD0bar2KstarRho->Scale(1.00/d0bar2KstarRhoEntries);
   quad3PhiHistD02KstarRho->GetYaxis()->SetRangeUser(0.,1.25*maximum/d02KstarRhoEntries);
   quad3PhiHistD0bar2KstarRho->Draw("same");
   leg->AddEntry(quad3PhiHistD0bar2KstarRho,"#bar{D}^{0}","L");
   leg->Draw();
   pt1->Clear();
   d0AsymStr.Form("%4.1f\n",100.*D0AB_asymmetry);
   d0AsymErrStr.Form("%4.1f\n",100.*D0AB_asymmetryErr);
   d0barAsymStr.Form("%4.1f\n",100.*D0barAB_asymmetry);
   d0barAsymErrStr.Form("%4.1f\n",100.*D0barAB_asymmetryErr);
   cpAsymStr.Form("%4.1f\n",100.*CPAsymmetry);
   cpAsymErrStr.Form("%4.1f\n",100.*CPAsymmetryErr);
   DiffABStr.Form("%4.1f\n",100.*DiffAB);
   d0Sin2PhiAsymStr.Form("%4.1f\n",100.*D0Sin2Phi_asymmetry);
   d0Sin2PhiAsymErrStr.Form("%4.1f\n",100.*D0Sin2Phi_asymmetryErr);
   d0barSin2PhiAsymStr.Form("%4.1f\n",100.*D0barSin2Phi_asymmetry);
   d0barSin2PhiAsymErrStr.Form("%4.1f\n",100.*D0barSin2Phi_asymmetryErr);
   cpSin2PhiAsymStr.Form("%4.1f\n",100.*Sin2PhiCP_asymmetry);
   cpSin2PhiAsymErrStr.Form("%4.1f\n",100.*Sin2PhiCP_asymmetryErr);
   DiffSin2PhiStr.Form("%4.1f\n",100.*DiffSin2Phi);
   pt1->AddText("asymmetries");
   pt1->AddText("sin(#phi)             sin(2#phi)");
   pt1->AddText("D^{0}:  ( "+d0AsymStr+" #pm "+d0AsymErrStr+")%   ("
         +d0Sin2PhiAsymStr+" #pm "+d0Sin2PhiAsymErrStr+")%");
   pt1->AddText("#bar{D}^{0}:  ( "+d0barAsymStr+" #pm "+d0barAsymErrStr+")%   ("
         +d0barSin2PhiAsymStr+" #pm "+d0barSin2PhiAsymErrStr+")%");
   pt1->AddText("CP:   ( "+cpAsymStr+" #pm "+cpAsymErrStr+")%   ("
         +cpSin2PhiAsymStr+" #pm "+cpSin2PhiAsymErrStr+")%");
   pt1->AddText("D^{0}-#bar{D}^{0}:  ("+DiffABStr+" #pm "+cpAsymErrStr+")%   ("
         +DiffSin2PhiStr+" #pm "+cpSin2PhiAsymErrStr+")%");
   nd0Str.Form("%6.0f\n",nD0);
   nd0barStr.Form("%6.0f\n",nD0bar);
   pt1->AddText("n(D^{0}) = "+nd0Str+"           n(#bar{D}^{0}) = "+nd0barStr);
   pt1->Draw();
   c1.SaveAs("compareQuad3PhiKstarRho.png");
   c1.SetLogy(0);

/////////  start with Quad 4

//  do asymmetry calculations before re-scaling the distributions
  
   nD0 = quad4PhiHistD02KstarRho->GetEntries();
   nD0bar = quad4PhiHistD0bar2KstarRho->GetEntries();
   scale = nD0/nD0bar;
   nD0Above = 0;
   nD0barAbove = 0;
   for (int bin=0; bin<51; bin++) {
     nD0Above = nD0Above+quad4PhiHistD02KstarRho->GetBinContent(bin);
     nD0barAbove = nD0barAbove+quad4PhiHistD0bar2KstarRho->GetBinContent(bin);
   }
   
   nD0Below = 0;
   nD0barBelow = 0;
   for (int bin=51; bin<101; bin++) {
     nD0Below = nD0Below+quad4PhiHistD02KstarRho->GetBinContent(bin);
     nD0barBelow = nD0barBelow+quad4PhiHistD0bar2KstarRho->GetBinContent(bin);
   }

   D0AB_asymmetry = (nD0Above-nD0Below)/(nD0Above+nD0Below);
   D0AB_asymmetryErr = sqrt( (1.0 - D0AB_asymmetry*D0AB_asymmetry)/(nD0Above+nD0Below) );

   cout <<  endl << "For Quad 4 " << endl;
   cout << " nD0Above =   " << nD0Above << endl;
   cout << " nD0Below =   " << nD0Below << endl;
   cout << " D0AB_asymmetry =   " << D0AB_asymmetry << "  +-  " << D0AB_asymmetryErr << endl << endl;
   
   D0barAB_asymmetry = (nD0barAbove-nD0barBelow)/(nD0barAbove+nD0barBelow);
   D0barAB_asymmetryErr = sqrt( (1.0 - D0barAB_asymmetry*D0barAB_asymmetry)/(nD0barAbove+nD0barBelow) );

   cout << " nD0barAbove =   " << nD0barAbove << endl;
   cout << " nD0barBelow =   " << nD0barBelow << endl;
   cout << " D0barAB_asymmetry =   " << D0barAB_asymmetry 
            << "  +-  " << D0barAB_asymmetryErr << endl << endl;

   weight1 = 1./(D0AB_asymmetryErr*D0AB_asymmetryErr);
   weight2 = 1./(D0barAB_asymmetryErr*D0barAB_asymmetryErr);

   CPAsymmetry = (D0AB_asymmetry*weight1+D0barAB_asymmetry*weight2)/(weight1+weight2);
   CPAsymmetryErr = sqrt(1./(weight1+weight2));
   DiffAB = (D0AB_asymmetry*weight1-D0barAB_asymmetry*weight2)/(weight1+weight2);

   cout << "  CP Asymmetry =   " << CPAsymmetry << "  +-  " << CPAsymmetryErr << endl << endl;

  
   nD0Sin2PhiPlus = 0; 
   nD0barSin2PhiPlus = 0;

   nD0Sin2PhiMinus = 0; 
   nD0barSin2PhiMinus = 0;

   for (int bin=1; bin<26; bin++) {
     nD0Sin2PhiPlus = nD0Sin2PhiPlus+quad4PhiHistD02KstarRho->GetBinContent(bin);
     nD0barSin2PhiPlus = nD0barSin2PhiPlus+quad4PhiHistD0bar2KstarRho->GetBinContent(bin);
   }
   for (int bin=51; bin<76; bin++) {
     nD0Sin2PhiPlus = nD0Sin2PhiPlus+quad4PhiHistD02KstarRho->GetBinContent(bin);
     nD0barSin2PhiPlus = nD0barSin2PhiPlus+quad4PhiHistD0bar2KstarRho->GetBinContent(bin);
   }

   for (int bin=25; bin<51; bin++) {
     nD0Sin2PhiMinus = nD0Sin2PhiMinus+quad4PhiHistD02KstarRho->GetBinContent(bin);
     nD0barSin2PhiMinus = nD0barSin2PhiMinus+quad4PhiHistD0bar2KstarRho->GetBinContent(bin);
   }
   for (int bin=75; bin<101; bin++) {
     nD0Sin2PhiMinus = nD0Sin2PhiMinus+quad4PhiHistD02KstarRho->GetBinContent(bin);
     nD0barSin2PhiMinus = nD0barSin2PhiMinus+quad4PhiHistD0bar2KstarRho->GetBinContent(bin);
   }

   D0Sin2Phi_asymmetry = (nD0Sin2PhiPlus-nD0Sin2PhiMinus)/(nD0Sin2PhiPlus+nD0Sin2PhiMinus);
   D0Sin2Phi_asymmetryErr = sqrt( (1.0 - D0Sin2Phi_asymmetry*D0Sin2Phi_asymmetry)/
                             (nD0Sin2PhiPlus+nD0Sin2PhiMinus) );

   D0barSin2Phi_asymmetry = (nD0barSin2PhiPlus-nD0barSin2PhiMinus) /
                             (nD0barSin2PhiPlus+nD0barSin2PhiMinus);
   D0barSin2Phi_asymmetryErr = sqrt( (1.0 - D0barSin2Phi_asymmetry*D0barSin2Phi_asymmetry)/
                                         (nD0barSin2PhiPlus+nD0barSin2PhiMinus) );

   weight1 = 1./(D0Sin2Phi_asymmetryErr*D0Sin2Phi_asymmetryErr);
   weight2 = 1./(D0barSin2Phi_asymmetryErr*D0barSin2Phi_asymmetryErr);

   Sin2PhiCP_asymmetry = (D0Sin2Phi_asymmetry*weight1+D0barSin2Phi_asymmetry*weight2)/
                                   (weight1+weight2);
   Sin2PhiCP_asymmetryErr = sqrt(1./(weight1+weight2));

   DiffSin2Phi = (D0Sin2Phi_asymmetry*weight1-D0barSin2Phi_asymmetry*weight2)/(weight1+weight2);


   cout << "D0Sin2Phi_asymmetry =  " << D0Sin2Phi_asymmetry << "  +-  " <<
                D0Sin2Phi_asymmetryErr << endl;
   cout << "D0barSin2Phi_asymmetry =  " << D0barSin2Phi_asymmetry << "  +-  " <<
                D0barSin2Phi_asymmetryErr << endl;
   cout << " Sin2PhiCP_asymmetry =    " << Sin2PhiCP_asymmetry << "  +-  " <<
                 Sin2PhiCP_asymmetryErr << endl << endl;
  
   maximum = quad4PhiHistD0bar2KstarRho->GetMaximum();
    cout << "max from quad4PhiHistD0bar2KstarRho->GetMaximum() = " << maximum << endl;
   quad4PhiHistD02KstarRho->SetLineColor(kBlue);
   quad4PhiHistD02KstarRho->SetLineWidth(2);
   d02KstarRhoEntries = quad4PhiHistD02KstarRho->GetEntries();
   quad4PhiHistD02KstarRho->Scale(1.00/d02KstarRhoEntries);
   quad4PhiHistD02KstarRho->GetXaxis()->SetTitleSize(0.06);
   quad4PhiHistD02KstarRho->GetXaxis()->SetTitleOffset(0.75);
   quad4PhiHistD02KstarRho->GetXaxis()->SetLabelFont(62);
   quad4PhiHistD02KstarRho->GetXaxis()->CenterTitle(true);
   quad4PhiHistD02KstarRho->SetTitle("(K*, #rho)  - Quad 4");
   quad4PhiHistD02KstarRho->SetXTitle("#phi [radians]");
   quad4PhiHistD02KstarRho->GetYaxis()->SetTitleSize(0.06);
   quad4PhiHistD02KstarRho->GetYaxis()->SetTitleOffset(0.75);
   quad4PhiHistD02KstarRho->SetYTitle("fraction per 2#pi/100 radians");
   quad4PhiHistD02KstarRho->Draw();
   leg->Clear();
   leg->SetHeader("The Samples");
   leg->AddEntry(quad4PhiHistD02KstarRho,"D^{0}","L");
   quad4PhiHistD02KstarRho->Draw();
   quad4PhiHistD0bar2KstarRho->SetLineColor(kRed+1);
   quad4PhiHistD0bar2KstarRho->SetLineWidth(2);
   d0bar2KstarRhoEntries = quad4PhiHistD0bar2KstarRho->GetEntries();
   quad4PhiHistD0bar2KstarRho->Scale(1.00/d0bar2KstarRhoEntries);
   quad4PhiHistD02KstarRho->GetYaxis()->SetRangeUser(0.,1.25*maximum/d02KstarRhoEntries);
   quad4PhiHistD0bar2KstarRho->Draw("same");
   leg->AddEntry(quad4PhiHistD0bar2KstarRho,"#bar{D}^{0}","L");
   leg->Draw();
   pt1->Clear();
   d0AsymStr.Form("%4.1f\n",100.*D0AB_asymmetry);
   d0AsymErrStr.Form("%4.1f\n",100.*D0AB_asymmetryErr);
   d0barAsymStr.Form("%4.1f\n",100.*D0barAB_asymmetry);
   d0barAsymErrStr.Form("%4.1f\n",100.*D0barAB_asymmetryErr);
   cpAsymStr.Form("%4.1f\n",100.*CPAsymmetry);
   cpAsymErrStr.Form("%4.1f\n",100.*CPAsymmetryErr);
   DiffABStr.Form("%4.1f\n",100.*DiffAB);
   d0Sin2PhiAsymStr.Form("%4.1f\n",100.*D0Sin2Phi_asymmetry);
   d0Sin2PhiAsymErrStr.Form("%4.1f\n",100.*D0Sin2Phi_asymmetryErr);
   d0barSin2PhiAsymStr.Form("%4.1f\n",100.*D0barSin2Phi_asymmetry);
   d0barSin2PhiAsymErrStr.Form("%4.1f\n",100.*D0barSin2Phi_asymmetryErr);
   cpSin2PhiAsymStr.Form("%4.1f\n",100.*Sin2PhiCP_asymmetry);
   cpSin2PhiAsymErrStr.Form("%4.1f\n",100.*Sin2PhiCP_asymmetryErr);
   DiffSin2PhiStr.Form("%4.1f\n",100.*DiffSin2Phi);
   pt1->AddText("asymmetries");
   pt1->AddText("sin(#phi)             sin(2#phi)");
   pt1->AddText("D^{0}:  ( "+d0AsymStr+" #pm "+d0AsymErrStr+")%   ("
         +d0Sin2PhiAsymStr+" #pm "+d0Sin2PhiAsymErrStr+")%");
   pt1->AddText("#bar{D}^{0}:  ( "+d0barAsymStr+" #pm "+d0barAsymErrStr+")%   ("
         +d0barSin2PhiAsymStr+" #pm "+d0barSin2PhiAsymErrStr+")%");
   pt1->AddText("CP:   ( "+cpAsymStr+" #pm "+cpAsymErrStr+")%   ("
         +cpSin2PhiAsymStr+" #pm "+cpSin2PhiAsymErrStr+")%");
   pt1->AddText("D^{0}-#bar{D}^{0}:  ("+DiffABStr+" #pm "+cpAsymErrStr+")%   ("
         +DiffSin2PhiStr+" #pm "+cpSin2PhiAsymErrStr+")%");
   nd0Str.Form("%6.0f\n",nD0);
   nd0barStr.Form("%6.0f\n",nD0bar);
   pt1->AddText("n(D^{0}) = "+nd0Str+"           n(#bar{D}^{0}) = "+nd0barStr);
   pt1->Draw();
   c1.SaveAs("compareQuad4PhiKstarRho.png");
   c1.SetLogy(0);


//  ***  end of KstarRho calculations & plotting  ***


//  ***  begin KstarF0 calculations & plotting  ***
//  do asymmetry calculations before re-scaling the distributions
  
   nD0 = quad1PhiHistD02KstarF0->GetEntries();
   nD0bar = quad1PhiHistD0bar2KstarF0->GetEntries();
   scale = nD0/nD0bar;
   nD0Above = 0;
   nD0barAbove = 0;
//  change meaning of "Above" and "Below" to refer to  sign(sin(phi)), 
//  rather than phi above or below pi.
   for (int bin=0; bin<51; bin++) {
     nD0Above = nD0Above+quad1PhiHistD02KstarF0->GetBinContent(bin);
     nD0barAbove = nD0barAbove+quad1PhiHistD0bar2KstarF0->GetBinContent(bin);
   }
   
   nD0Below = 0;
   nD0barBelow = 0;
   for (int bin=51; bin<101; bin++) {
     nD0Below = nD0Below+quad1PhiHistD02KstarF0->GetBinContent(bin);
     nD0barBelow = nD0barBelow+quad1PhiHistD0bar2KstarF0->GetBinContent(bin);
   }

   D0AB_asymmetry = (nD0Above-nD0Below)/(nD0Above+nD0Below);
   D0AB_asymmetryErr = sqrt( (1.0 - D0AB_asymmetry*D0AB_asymmetry)/(nD0Above+nD0Below) );

   cout <<  endl << "For Quad 1 " << endl;
   cout << " nD0Above =   " << nD0Above << endl;
   cout << " nD0Below =   " << nD0Below << endl;
   cout << " D0AB_asymmetry =   " << D0AB_asymmetry << "  +-  " << D0AB_asymmetryErr << endl << endl;
   
   D0barAB_asymmetry = (nD0barAbove-nD0barBelow)/(nD0barAbove+nD0barBelow);
   D0barAB_asymmetryErr = sqrt( (1.0 - D0barAB_asymmetry*D0barAB_asymmetry)/(nD0barAbove+nD0barBelow) );

   cout << " nD0barAbove =   " << nD0barAbove << endl;
   cout << " nD0barBelow =   " << nD0barBelow << endl;
   cout << " D0barAB_asymmetry =   " << D0barAB_asymmetry 
            << "  +-  " << D0barAB_asymmetryErr << endl << endl;

   weight1 = 1./(D0AB_asymmetryErr*D0AB_asymmetryErr);
   weight2 = 1./(D0barAB_asymmetryErr*D0barAB_asymmetryErr);

   CPAsymmetry = (D0AB_asymmetry*weight1+D0barAB_asymmetry*weight2)/(weight1+weight2);
   CPAsymmetryErr = sqrt(1./(weight1+weight2));
   DiffAB = (D0AB_asymmetry*weight1-D0barAB_asymmetry*weight2)/(weight1+weight2);
   
   cout << "  CP Asymmetry =   " << CPAsymmetry << "  +-  " << CPAsymmetryErr << endl << endl;
   
  
   nD0Sin2PhiPlus = 0; 
   nD0barSin2PhiPlus = 0;

   nD0Sin2PhiMinus = 0; 
   nD0barSin2PhiMinus = 0;

   for (int bin=1; bin<26; bin++) {
     nD0Sin2PhiPlus = nD0Sin2PhiPlus+quad1PhiHistD02KstarF0->GetBinContent(bin);
     nD0barSin2PhiPlus = nD0barSin2PhiPlus+quad1PhiHistD0bar2KstarF0->GetBinContent(bin);
   }
   for (int bin=51; bin<76; bin++) {
     nD0Sin2PhiPlus = nD0Sin2PhiPlus+quad1PhiHistD02KstarF0->GetBinContent(bin);
     nD0barSin2PhiPlus = nD0barSin2PhiPlus+quad1PhiHistD0bar2KstarF0->GetBinContent(bin);
   }

   for (int bin=25; bin<51; bin++) {
     nD0Sin2PhiMinus = nD0Sin2PhiMinus+quad1PhiHistD02KstarF0->GetBinContent(bin);
     nD0barSin2PhiMinus = nD0barSin2PhiMinus+quad1PhiHistD0bar2KstarF0->GetBinContent(bin);
   }
   for (int bin=75; bin<101; bin++) {
     nD0Sin2PhiMinus = nD0Sin2PhiMinus+quad1PhiHistD02KstarF0->GetBinContent(bin);
     nD0barSin2PhiMinus = nD0barSin2PhiMinus+quad1PhiHistD0bar2KstarF0->GetBinContent(bin);
   }

   D0Sin2Phi_asymmetry = (nD0Sin2PhiPlus-nD0Sin2PhiMinus)/(nD0Sin2PhiPlus+nD0Sin2PhiMinus);
   D0Sin2Phi_asymmetryErr = sqrt( (1.0 - D0Sin2Phi_asymmetry*D0Sin2Phi_asymmetry)/
                                      (nD0Sin2PhiPlus+nD0Sin2PhiMinus) );

   D0barSin2Phi_asymmetry = (nD0barSin2PhiPlus-nD0barSin2PhiMinus) /
                                      (nD0barSin2PhiPlus+nD0barSin2PhiMinus);
   D0barSin2Phi_asymmetryErr = sqrt( (1.0 - D0barSin2Phi_asymmetry*D0barSin2Phi_asymmetry)/
                                         (nD0barSin2PhiPlus+nD0barSin2PhiMinus) );

   weight1 = 1./(D0Sin2Phi_asymmetryErr*D0Sin2Phi_asymmetryErr);
   weight2 = 1./(D0barSin2Phi_asymmetryErr*D0barSin2Phi_asymmetryErr);

   Sin2PhiCP_asymmetry = (D0Sin2Phi_asymmetry*weight1+D0barSin2Phi_asymmetry*weight2)/
                                   (weight1+weight2);
   Sin2PhiCP_asymmetryErr = sqrt(1./(weight1+weight2));

   DiffSin2Phi = (D0Sin2Phi_asymmetry*weight1-D0barSin2Phi_asymmetry*weight2)/(weight1+weight2);

   cout << "D0Sin2Phi_asymmetry =  " << D0Sin2Phi_asymmetry << "  +-  " <<
                D0Sin2Phi_asymmetryErr << endl;
   cout << "D0barSin2Phi_asymmetry =  " << D0barSin2Phi_asymmetry << "  +-  " <<
                D0barSin2Phi_asymmetryErr << endl;
   cout << " Sin2PhiCP_asymmetry =    " << Sin2PhiCP_asymmetry << "  +-  " <<
                 Sin2PhiCP_asymmetryErr << endl << endl;
  

   maximum = quad1PhiHistD0bar2KstarF0->GetMaximum();
    cout << "max from quad1PhiHistD0bar2KstarF0->GetMaximum() = " << maximum << endl;
   quad1PhiHistD0bar2KstarF0->Draw();
   quad1PhiHistD02KstarF0->SetLineColor(kBlue);
   quad1PhiHistD02KstarF0->SetLineWidth(2);
   Double_t d02KstarF0Entries = quad1PhiHistD02KstarF0->GetEntries();
   quad1PhiHistD02KstarF0->Scale(1.00/d02KstarF0Entries);
   quad1PhiHistD02KstarF0->GetXaxis()->SetTitleSize(0.06);
   quad1PhiHistD02KstarF0->GetXaxis()->SetTitleOffset(0.75);
   quad1PhiHistD02KstarF0->GetXaxis()->SetLabelFont(62);
   quad1PhiHistD02KstarF0->GetXaxis()->CenterTitle(true);
   quad1PhiHistD02KstarF0->SetTitle("(K*, f(0))  - Quad 1");
   quad1PhiHistD02KstarF0->SetXTitle("#phi [radians]");
   quad1PhiHistD02KstarF0->GetYaxis()->SetTitleSize(0.06);
   quad1PhiHistD02KstarF0->GetYaxis()->SetTitleOffset(0.75);
   quad1PhiHistD02KstarF0->SetYTitle("fraction per 2#pi/100 radians");
   leg->Clear();
   leg->SetHeader("The Samples");
   leg->AddEntry(quad1PhiHistD02KstarF0,"D^{0}","L");
   quad1PhiHistD02KstarF0->Draw();
   quad1PhiHistD0bar2KstarF0->SetLineColor(kRed+1);
   quad1PhiHistD0bar2KstarF0->SetLineWidth(2);
   Double_t d0bar2KstarF0Entries = quad1PhiHistD0bar2KstarF0->GetEntries();
   quad1PhiHistD0bar2KstarF0->Scale(1.00/d0bar2KstarF0Entries);
   quad1PhiHistD02KstarF0->GetYaxis()->SetRangeUser(0.,1.25*maximum/d02KstarF0Entries);
   quad1PhiHistD02KstarF0->GetXaxis()->SetTitleSize(0.06);
   quad1PhiHistD02KstarF0->GetXaxis()->SetTitleOffset(0.75);
   quad1PhiHistD02KstarF0->GetXaxis()->SetLabelFont(62);
   quad1PhiHistD02KstarF0->GetXaxis()->CenterTitle(true);
   quad1PhiHistD02KstarF0->SetTitle("(K*, f(0))  - Quad 1");
   quad1PhiHistD02KstarF0->SetXTitle("#phi [radians]");
   quad1PhiHistD02KstarF0->GetYaxis()->SetTitleSize(0.06);
   quad1PhiHistD02KstarF0->GetYaxis()->SetTitleOffset(0.75);
   quad1PhiHistD02KstarF0->SetYTitle("fraction per 2#pi/100 radians");
   leg->AddEntry(quad1PhiHistD0bar2KstarF0,"#bar{D}^{0}","L");
   quad1PhiHistD0bar2KstarF0->Draw("same");
   leg->Draw();
   pt1->Clear();
   d0AsymStr.Form("%4.1f\n",100.*D0AB_asymmetry);
   d0AsymErrStr.Form("%4.1f\n",100.*D0AB_asymmetryErr);
   d0barAsymStr.Form("%4.1f\n",100.*D0barAB_asymmetry);
   d0barAsymErrStr.Form("%4.1f\n",100.*D0barAB_asymmetryErr);
   cpAsymStr.Form("%4.1f\n",100.*CPAsymmetry);
   cpAsymErrStr.Form("%4.1f\n",100.*CPAsymmetryErr);
   DiffABStr.Form("%4.1f\n",100.*DiffAB);
   d0Sin2PhiAsymStr.Form("%4.1f\n",100.*D0Sin2Phi_asymmetry);
   d0Sin2PhiAsymErrStr.Form("%4.1f\n",100.*D0Sin2Phi_asymmetryErr);
   d0barSin2PhiAsymStr.Form("%4.1f\n",100.*D0barSin2Phi_asymmetry);
   d0barSin2PhiAsymErrStr.Form("%4.1f\n",100.*D0barSin2Phi_asymmetryErr);
   cpSin2PhiAsymStr.Form("%4.1f\n",100.*Sin2PhiCP_asymmetry);
   cpSin2PhiAsymErrStr.Form("%4.1f\n",100.*Sin2PhiCP_asymmetryErr);
   DiffSin2PhiStr.Form("%4.1f\n",100.*DiffSin2Phi);
   pt1->AddText("asymmetries");
   pt1->AddText("sin(#phi)             sin(2#phi)");
   pt1->AddText("D^{0}:  ( "+d0AsymStr+" #pm "+d0AsymErrStr+")%   ("
         +d0Sin2PhiAsymStr+" #pm "+d0Sin2PhiAsymErrStr+")%");
   pt1->AddText("#bar{D}^{0}:  ( "+d0barAsymStr+" #pm "+d0barAsymErrStr+")%   ("
         +d0barSin2PhiAsymStr+" #pm "+d0barSin2PhiAsymErrStr+")%");
   pt1->AddText("CP:   ( "+cpAsymStr+" #pm "+cpAsymErrStr+")%   ("
         +cpSin2PhiAsymStr+" #pm "+cpSin2PhiAsymErrStr+")%");
   pt1->AddText("D^{0}-#bar{D}^{0}:  ("+DiffABStr+" #pm "+cpAsymErrStr+")%   ("
         +DiffSin2PhiStr+" #pm "+cpSin2PhiAsymErrStr+")%");
   nd0Str.Form("%6.0f\n",nD0);
   nd0barStr.Form("%6.0f\n",nD0bar);
   pt1->AddText("n(D^{0}) = "+nd0Str+"           n(#bar{D}^{0}) = "+nd0barStr);
   pt1->Draw();
   c1.SaveAs("compareQuad1PhiKstarF0.png");
   c1.SetLogy(0);


/////////  start with Quad 2

//  do asymmetry calculations before re-scaling the distributions
  
   nD0 = quad2PhiHistD02KstarF0->GetEntries();
   nD0bar = quad2PhiHistD0bar2KstarF0->GetEntries();
   scale = nD0/nD0bar;
   nD0Above = 0;
   nD0barAbove = 0;
   for (int bin=0; bin<51; bin++) {
     nD0Above = nD0Above+quad2PhiHistD02KstarF0->GetBinContent(bin);
     nD0barAbove = nD0barAbove+quad2PhiHistD0bar2KstarF0->GetBinContent(bin);
   }
   
   nD0Below = 0;
   nD0barBelow = 0;
   for (int bin=51; bin<101; bin++) {
     nD0Below = nD0Below+quad2PhiHistD02KstarF0->GetBinContent(bin);
     nD0barBelow = nD0barBelow+quad2PhiHistD0bar2KstarF0->GetBinContent(bin);
   }

   D0AB_asymmetry = (nD0Above-nD0Below)/(nD0Above+nD0Below);
   D0AB_asymmetryErr = sqrt( (1.0 - D0AB_asymmetry*D0AB_asymmetry)/(nD0Above+nD0Below) );

   cout <<  endl << "For Quad 2 " << endl;
   cout << " nD0Above =   " << nD0Above << endl;
   cout << " nD0Below =   " << nD0Below << endl;
   cout << " D0AB_asymmetry =   " << D0AB_asymmetry << "  +-  " << D0AB_asymmetryErr << endl << endl;
   
   D0barAB_asymmetry = (nD0barAbove-nD0barBelow)/(nD0barAbove+nD0barBelow);
   D0barAB_asymmetryErr = sqrt( (1.0 - D0barAB_asymmetry*D0barAB_asymmetry)/(nD0barAbove+nD0barBelow) );

   cout << " nD0barAbove =   " << nD0barAbove << endl;
   cout << " nD0barBelow =   " << nD0barBelow << endl;
   cout << " D0barAB_asymmetry =   " << D0barAB_asymmetry 
            << "  +-  " << D0barAB_asymmetryErr << endl << endl;

   weight1 = 1./(D0AB_asymmetryErr*D0AB_asymmetryErr);
   weight2 = 1./(D0barAB_asymmetryErr*D0barAB_asymmetryErr);

   CPAsymmetry = (D0AB_asymmetry*weight1+D0barAB_asymmetry*weight2)/(weight1+weight2);
   CPAsymmetryErr = sqrt(1./(weight1+weight2));
   DiffAB = (D0AB_asymmetry*weight1-D0barAB_asymmetry*weight2)/(weight1+weight2);
   cout << "  CP Asymmetry =   " << CPAsymmetry << "  +-  " << CPAsymmetryErr << endl << endl;


   nD0Sin2PhiPlus = 0; 
   nD0barSin2PhiPlus = 0;

   nD0Sin2PhiMinus = 0; 
   nD0barSin2PhiMinus = 0;

   for (int bin=1; bin<26; bin++) {
     nD0Sin2PhiPlus = nD0Sin2PhiPlus+quad2PhiHistD02KstarF0->GetBinContent(bin);
     nD0barSin2PhiPlus = nD0barSin2PhiPlus+quad2PhiHistD0bar2KstarF0->GetBinContent(bin);
   }
   for (int bin=51; bin<76; bin++) {
     nD0Sin2PhiPlus = nD0Sin2PhiPlus+quad2PhiHistD02KstarF0->GetBinContent(bin);
     nD0barSin2PhiPlus = nD0barSin2PhiPlus+quad2PhiHistD0bar2KstarF0->GetBinContent(bin);
   }

   for (int bin=25; bin<51; bin++) {
     nD0Sin2PhiMinus = nD0Sin2PhiMinus+quad2PhiHistD02KstarF0->GetBinContent(bin);
     nD0barSin2PhiMinus = nD0barSin2PhiMinus+quad2PhiHistD0bar2KstarF0->GetBinContent(bin);
   }
   for (int bin=75; bin<101; bin++) {
     nD0Sin2PhiMinus = nD0Sin2PhiMinus+quad2PhiHistD02KstarF0->GetBinContent(bin);
     nD0barSin2PhiMinus = nD0barSin2PhiMinus+quad2PhiHistD0bar2KstarF0->GetBinContent(bin);
   }

   D0Sin2Phi_asymmetry = (nD0Sin2PhiPlus-nD0Sin2PhiMinus)/(nD0Sin2PhiPlus+nD0Sin2PhiMinus);
   D0Sin2Phi_asymmetryErr = sqrt( (1.0 - D0Sin2Phi_asymmetry*D0Sin2Phi_asymmetry)/
                             (nD0Sin2PhiPlus+nD0Sin2PhiMinus) );

   D0barSin2Phi_asymmetry = (nD0barSin2PhiPlus-nD0barSin2PhiMinus) /
                             (nD0barSin2PhiPlus+nD0barSin2PhiMinus);
   D0barSin2Phi_asymmetryErr = sqrt( (1.0 - D0barSin2Phi_asymmetry*D0barSin2Phi_asymmetry)/
                                         (nD0barSin2PhiPlus+nD0barSin2PhiMinus) );

   weight1 = 1./(D0Sin2Phi_asymmetryErr*D0Sin2Phi_asymmetryErr);
   weight2 = 1./(D0barSin2Phi_asymmetryErr*D0barSin2Phi_asymmetryErr);

   Sin2PhiCP_asymmetry = (D0Sin2Phi_asymmetry*weight1+D0barSin2Phi_asymmetry*weight2)/
                                   (weight1+weight2);
   Sin2PhiCP_asymmetryErr = sqrt(1./(weight1+weight2));

   DiffSin2Phi = (D0Sin2Phi_asymmetry*weight1-D0barSin2Phi_asymmetry*weight2)/(weight1+weight2);



   cout << "D0Sin2Phi_asymmetry =  " << D0Sin2Phi_asymmetry << "  +-  " <<
                D0Sin2Phi_asymmetryErr << endl;
   cout << "D0barSin2Phi_asymmetry =  " << D0barSin2Phi_asymmetry << "  +-  " <<
                D0barSin2Phi_asymmetryErr << endl;
   cout << " Sin2PhiCP_asymmetry =    " << Sin2PhiCP_asymmetry << "  +-  " <<
                 Sin2PhiCP_asymmetryErr << endl << endl;
  
   maximum = quad2PhiHistD0bar2KstarF0->GetMaximum();
    cout << "max from quad2PhiHistD0bar2KstarF0->GetMaximum() = " << maximum << endl;
   quad2PhiHistD02KstarF0->SetLineColor(kBlue);
   quad2PhiHistD02KstarF0->SetLineWidth(2);
   d02KstarF0Entries = quad2PhiHistD02KstarF0->GetEntries();
   quad2PhiHistD02KstarF0->Scale(1.00/d02KstarF0Entries);
   quad2PhiHistD0bar2KstarF0->SetLineColor(kRed+1);
   quad2PhiHistD0bar2KstarF0->SetLineWidth(2);
   d0bar2KstarF0Entries = quad2PhiHistD0bar2KstarF0->GetEntries();
   quad2PhiHistD0bar2KstarF0->Scale(1.00/d0bar2KstarF0Entries);
   quad2PhiHistD02KstarF0->GetYaxis()->SetRangeUser(0.,1.25*maximum/d02KstarF0Entries);
   quad2PhiHistD02KstarF0->GetXaxis()->SetTitleSize(0.06);
   quad2PhiHistD02KstarF0->GetXaxis()->SetTitleOffset(0.75);
   quad2PhiHistD02KstarF0->GetXaxis()->SetLabelFont(62);
   quad2PhiHistD02KstarF0->GetXaxis()->CenterTitle(true);
   quad2PhiHistD02KstarF0->SetTitle("(K*, f(0))  - Quad 2");
   quad2PhiHistD02KstarF0->SetXTitle("#phi [radians]");
   quad2PhiHistD02KstarF0->GetYaxis()->SetTitleSize(0.06);
   quad2PhiHistD02KstarF0->GetYaxis()->SetTitleOffset(0.75);
   quad2PhiHistD02KstarF0->SetYTitle("fraction per 2#pi/100 radians");
   quad2PhiHistD02KstarF0->Draw();
   leg->Clear();
   leg->SetHeader("The Samples");
   leg->AddEntry(quad2PhiHistD02KstarF0,"D^{0}","L");
   quad2PhiHistD0bar2KstarF0->Draw("same");
   leg->AddEntry(quad2PhiHistD0bar2KstarF0,"#bar{D}^{0}","L");
   leg->Draw();
   pt1->Clear();
   d0AsymStr.Form("%4.1f\n",100.*D0AB_asymmetry);
   d0AsymErrStr.Form("%4.1f\n",100.*D0AB_asymmetryErr);
   d0barAsymStr.Form("%4.1f\n",100.*D0barAB_asymmetry);
   d0barAsymErrStr.Form("%4.1f\n",100.*D0barAB_asymmetryErr);
   cpAsymStr.Form("%4.1f\n",100.*CPAsymmetry);
   cpAsymErrStr.Form("%4.1f\n",100.*CPAsymmetryErr);
   DiffABStr.Form("%4.1f\n",100.*DiffAB);
   d0Sin2PhiAsymStr.Form("%4.1f\n",100.*D0Sin2Phi_asymmetry);
   d0Sin2PhiAsymErrStr.Form("%4.1f\n",100.*D0Sin2Phi_asymmetryErr);
   d0barSin2PhiAsymStr.Form("%4.1f\n",100.*D0barSin2Phi_asymmetry);
   d0barSin2PhiAsymErrStr.Form("%4.1f\n",100.*D0barSin2Phi_asymmetryErr);
   cpSin2PhiAsymStr.Form("%4.1f\n",100.*Sin2PhiCP_asymmetry);
   cpSin2PhiAsymErrStr.Form("%4.1f\n",100.*Sin2PhiCP_asymmetryErr);
   DiffSin2PhiStr.Form("%4.1f\n",100.*DiffSin2Phi);
   pt1->AddText("asymmetries");
   pt1->AddText("sin(#phi)             sin(2#phi)");
   pt1->AddText("D^{0}:  ( "+d0AsymStr+" #pm "+d0AsymErrStr+")%   ("
         +d0Sin2PhiAsymStr+" #pm "+d0Sin2PhiAsymErrStr+")%");
   pt1->AddText("#bar{D}^{0}:  ( "+d0barAsymStr+" #pm "+d0barAsymErrStr+")%   ("
         +d0barSin2PhiAsymStr+" #pm "+d0barSin2PhiAsymErrStr+")%");
   pt1->AddText("CP:   ( "+cpAsymStr+" #pm "+cpAsymErrStr+")%   ("
         +cpSin2PhiAsymStr+" #pm "+cpSin2PhiAsymErrStr+")%");
   pt1->AddText("D^{0}-#bar{D}^{0}:  ("+DiffABStr+" #pm "+cpAsymErrStr+")%   ("
         +DiffSin2PhiStr+" #pm "+cpSin2PhiAsymErrStr+")%");
   nd0Str.Form("%6.0f\n",nD0);
   nd0barStr.Form("%6.0f\n",nD0bar);
   pt1->AddText("n(D^{0}) = "+nd0Str+"           n(#bar{D}^{0}) = "+nd0barStr);
   pt1->Draw();
   c1.SaveAs("compareQuad2PhiKstarF0.png");
   c1.SetLogy(0);

/////////  start with Quad 3

//  do asymmetry calculations before re-scaling the distributions
  
   nD0 = quad3PhiHistD02KstarF0->GetEntries();
   nD0bar = quad3PhiHistD0bar2KstarF0->GetEntries();
   scale = nD0/nD0bar;
   nD0Above = 0;
   nD0barAbove = 0;
   for (int bin=0; bin<51; bin++) {
     nD0Above = nD0Above+quad3PhiHistD02KstarF0->GetBinContent(bin);
     nD0barAbove = nD0barAbove+quad3PhiHistD0bar2KstarF0->GetBinContent(bin);
   }
   
   nD0Below = 0;
   nD0barBelow = 0;
   for (int bin=51; bin<101; bin++) {
     nD0Below = nD0Below+quad3PhiHistD02KstarF0->GetBinContent(bin);
     nD0barBelow = nD0barBelow+quad3PhiHistD0bar2KstarF0->GetBinContent(bin);
   }

   D0AB_asymmetry = (nD0Above-nD0Below)/(nD0Above+nD0Below);
   D0AB_asymmetryErr = sqrt( (1.0 - D0AB_asymmetry*D0AB_asymmetry)/(nD0Above+nD0Below) );

   cout <<  endl << "For Quad 3 " << endl;
   cout << " nD0Above =   " << nD0Above << endl;
   cout << " nD0Below =   " << nD0Below << endl;
   cout << " D0AB_asymmetry =   " << D0AB_asymmetry << "  +-  " << D0AB_asymmetryErr << endl << endl;
   
   D0barAB_asymmetry = (nD0barAbove-nD0barBelow)/(nD0barAbove+nD0barBelow);
   D0barAB_asymmetryErr = sqrt( (1.0 - D0barAB_asymmetry*D0barAB_asymmetry)/(nD0barAbove+nD0barBelow) );

   cout << " nD0barAbove =   " << nD0barAbove << endl;
   cout << " nD0barBelow =   " << nD0barBelow << endl;
   cout << " D0barAB_asymmetry =   " << D0barAB_asymmetry 
            << "  +-  " << D0barAB_asymmetryErr << endl << endl;

   weight1 = 1./(D0AB_asymmetryErr*D0AB_asymmetryErr);
   weight2 = 1./(D0barAB_asymmetryErr*D0barAB_asymmetryErr);

   CPAsymmetry = (D0AB_asymmetry*weight1+D0barAB_asymmetry*weight2)/(weight1+weight2);
   CPAsymmetryErr = sqrt(1./(weight1+weight2));
   DiffAB = (D0AB_asymmetry*weight1-D0barAB_asymmetry*weight2)/(weight1+weight2);

   cout << "  CP Asymmetry =   " << CPAsymmetry << "  +-  " << CPAsymmetryErr << endl << endl;

  
   nD0Sin2PhiPlus = 0; 
   nD0barSin2PhiPlus = 0;

   nD0Sin2PhiMinus = 0; 
   nD0barSin2PhiMinus = 0;

   for (int bin=1; bin<26; bin++) {
     nD0Sin2PhiPlus = nD0Sin2PhiPlus+quad3PhiHistD02KstarF0->GetBinContent(bin);
     nD0barSin2PhiPlus = nD0barSin2PhiPlus+quad3PhiHistD0bar2KstarF0->GetBinContent(bin);
   }
   for (int bin=51; bin<76; bin++) {
     nD0Sin2PhiPlus = nD0Sin2PhiPlus+quad3PhiHistD02KstarF0->GetBinContent(bin);
     nD0barSin2PhiPlus = nD0barSin2PhiPlus+quad3PhiHistD0bar2KstarF0->GetBinContent(bin);
   }

   for (int bin=25; bin<51; bin++) {
     nD0Sin2PhiMinus = nD0Sin2PhiMinus+quad3PhiHistD02KstarF0->GetBinContent(bin);
     nD0barSin2PhiMinus = nD0barSin2PhiMinus+quad3PhiHistD0bar2KstarF0->GetBinContent(bin);
   }
   for (int bin=75; bin<101; bin++) {
     nD0Sin2PhiMinus = nD0Sin2PhiMinus+quad3PhiHistD02KstarF0->GetBinContent(bin);
     nD0barSin2PhiMinus = nD0barSin2PhiMinus+quad3PhiHistD0bar2KstarF0->GetBinContent(bin);
   }

   D0Sin2Phi_asymmetry = (nD0Sin2PhiPlus-nD0Sin2PhiMinus)/(nD0Sin2PhiPlus+nD0Sin2PhiMinus);
   D0Sin2Phi_asymmetryErr = sqrt( (1.0 - D0Sin2Phi_asymmetry*D0Sin2Phi_asymmetry)/
                             (nD0Sin2PhiPlus+nD0Sin2PhiMinus) );

   D0barSin2Phi_asymmetry = (nD0barSin2PhiPlus-nD0barSin2PhiMinus) /
                             (nD0barSin2PhiPlus+nD0barSin2PhiMinus);
   D0barSin2Phi_asymmetryErr = sqrt( (1.0 - D0barSin2Phi_asymmetry*D0barSin2Phi_asymmetry)/
                                         (nD0barSin2PhiPlus+nD0barSin2PhiMinus) );

   weight1 = 1./(D0Sin2Phi_asymmetryErr*D0Sin2Phi_asymmetryErr);
   weight2 = 1./(D0barSin2Phi_asymmetryErr*D0barSin2Phi_asymmetryErr);

   Sin2PhiCP_asymmetry = (D0Sin2Phi_asymmetry*weight1+D0barSin2Phi_asymmetry*weight2)/
                                   (weight1+weight2);
   Sin2PhiCP_asymmetryErr = sqrt(1./(weight1+weight2));

   DiffSin2Phi = (D0Sin2Phi_asymmetry*weight1-D0barSin2Phi_asymmetry*weight2)/(weight1+weight2);


   cout << "D0Sin2Phi_asymmetry =  " << D0Sin2Phi_asymmetry << "  +-  " <<
                D0Sin2Phi_asymmetryErr << endl;
   cout << "D0barSin2Phi_asymmetry =  " << D0barSin2Phi_asymmetry << "  +-  " <<
                D0barSin2Phi_asymmetryErr << endl;
   cout << " Sin2PhiCP_asymmetry =    " << Sin2PhiCP_asymmetry << "  +-  " <<
                 Sin2PhiCP_asymmetryErr << endl << endl;
  
   maximum = quad3PhiHistD0bar2KstarF0->GetMaximum();
    cout << "max from quad3PhiHistD0bar2KstarF0->GetMaximum() = " << maximum << endl;
   quad3PhiHistD0bar2KstarF0->Draw();
   quad3PhiHistD02KstarF0->SetLineColor(kBlue);
   quad3PhiHistD02KstarF0->SetLineWidth(2);
   d02KstarF0Entries = quad3PhiHistD02KstarF0->GetEntries();
   quad3PhiHistD02KstarF0->Scale(1.00/d02KstarF0Entries);
   quad3PhiHistD02KstarF0->GetXaxis()->SetTitleSize(0.06);
   quad3PhiHistD02KstarF0->GetXaxis()->SetTitleOffset(0.75);
   quad3PhiHistD02KstarF0->GetXaxis()->SetLabelFont(62);
   quad3PhiHistD02KstarF0->GetXaxis()->CenterTitle(true);
   quad3PhiHistD02KstarF0->SetTitle("(K*, f(0))  - Quad 3");
   quad3PhiHistD02KstarF0->SetXTitle("#phi [radians]");
   quad3PhiHistD02KstarF0->GetYaxis()->SetTitleSize(0.06);
   quad3PhiHistD02KstarF0->GetYaxis()->SetTitleOffset(0.75);
   quad3PhiHistD02KstarF0->SetYTitle("fraction per 2#pi/100 radians");
   quad3PhiHistD02KstarF0->Draw();
   leg->Clear();
   leg->SetHeader("The Samples");
   leg->AddEntry(quad3PhiHistD02KstarF0,"D^{0}","L");
   quad3PhiHistD02KstarF0->Draw();
   quad3PhiHistD0bar2KstarF0->SetLineColor(kRed+1);
   quad3PhiHistD0bar2KstarF0->SetLineWidth(2);
   d0bar2KstarF0Entries = quad3PhiHistD0bar2KstarF0->GetEntries();
   quad3PhiHistD0bar2KstarF0->Scale(1.00/d0bar2KstarF0Entries);
   quad3PhiHistD02KstarF0->GetYaxis()->SetRangeUser(0.,1.25*maximum/d02KstarF0Entries);
   quad3PhiHistD0bar2KstarF0->Draw("same");
   leg->AddEntry(quad3PhiHistD0bar2KstarF0,"#bar{D}^{0}","L");
   leg->Draw();
   pt1->Clear();
   d0AsymStr.Form("%4.1f\n",100.*D0AB_asymmetry);
   d0AsymErrStr.Form("%4.1f\n",100.*D0AB_asymmetryErr);
   d0barAsymStr.Form("%4.1f\n",100.*D0barAB_asymmetry);
   d0barAsymErrStr.Form("%4.1f\n",100.*D0barAB_asymmetryErr);
   cpAsymStr.Form("%4.1f\n",100.*CPAsymmetry);
   cpAsymErrStr.Form("%4.1f\n",100.*CPAsymmetryErr);
   DiffABStr.Form("%4.1f\n",100.*DiffAB);
   d0Sin2PhiAsymStr.Form("%4.1f\n",100.*D0Sin2Phi_asymmetry);
   d0Sin2PhiAsymErrStr.Form("%4.1f\n",100.*D0Sin2Phi_asymmetryErr);
   d0barSin2PhiAsymStr.Form("%4.1f\n",100.*D0barSin2Phi_asymmetry);
   d0barSin2PhiAsymErrStr.Form("%4.1f\n",100.*D0barSin2Phi_asymmetryErr);
   cpSin2PhiAsymStr.Form("%4.1f\n",100.*Sin2PhiCP_asymmetry);
   cpSin2PhiAsymErrStr.Form("%4.1f\n",100.*Sin2PhiCP_asymmetryErr);
   DiffSin2PhiStr.Form("%4.1f\n",100.*DiffSin2Phi);
   pt1->AddText("asymmetries");
   pt1->AddText("sin(#phi)             sin(2#phi)");
   pt1->AddText("D^{0}:  ( "+d0AsymStr+" #pm "+d0AsymErrStr+")%   ("
         +d0Sin2PhiAsymStr+" #pm "+d0Sin2PhiAsymErrStr+")%");
   pt1->AddText("#bar{D}^{0}:  ( "+d0barAsymStr+" #pm "+d0barAsymErrStr+")%   ("
         +d0barSin2PhiAsymStr+" #pm "+d0barSin2PhiAsymErrStr+")%");
   pt1->AddText("CP:   ( "+cpAsymStr+" #pm "+cpAsymErrStr+")%   ("
         +cpSin2PhiAsymStr+" #pm "+cpSin2PhiAsymErrStr+")%");
   pt1->AddText("D^{0}-#bar{D}^{0}:  ("+DiffABStr+" #pm "+cpAsymErrStr+")%   ("
         +DiffSin2PhiStr+" #pm "+cpSin2PhiAsymErrStr+")%");
   nd0Str.Form("%6.0f\n",nD0);
   nd0barStr.Form("%6.0f\n",nD0bar);
   pt1->AddText("n(D^{0}) = "+nd0Str+"           n(#bar{D}^{0}) = "+nd0barStr);
   pt1->Draw();
   c1.SaveAs("compareQuad3PhiKstarF0.png");
   c1.SetLogy(0);

/////////  start with Quad 4

//  do asymmetry calculations before re-scaling the distributions
  
   nD0 = quad4PhiHistD02KstarF0->GetEntries();
   nD0bar = quad4PhiHistD0bar2KstarF0->GetEntries();
   scale = nD0/nD0bar;
   nD0Above = 0;
   nD0barAbove = 0;
   for (int bin=0; bin<51; bin++) {
     nD0Above = nD0Above+quad4PhiHistD02KstarF0->GetBinContent(bin);
     nD0barAbove = nD0barAbove+quad4PhiHistD0bar2KstarF0->GetBinContent(bin);
   }
   
   nD0Below = 0;
   nD0barBelow = 0;
   for (int bin=51; bin<101; bin++) {
     nD0Below = nD0Below+quad4PhiHistD02KstarF0->GetBinContent(bin);
     nD0barBelow = nD0barBelow+quad4PhiHistD0bar2KstarF0->GetBinContent(bin);
   }

   D0AB_asymmetry = (nD0Above-nD0Below)/(nD0Above+nD0Below);
   D0AB_asymmetryErr = sqrt( (1.0 - D0AB_asymmetry*D0AB_asymmetry)/(nD0Above+nD0Below) );

   cout <<  endl << "For Quad 4 " << endl;
   cout << " nD0Above =   " << nD0Above << endl;
   cout << " nD0Below =   " << nD0Below << endl;
   cout << " D0AB_asymmetry =   " << D0AB_asymmetry << "  +-  " << D0AB_asymmetryErr << endl << endl;
   
   D0barAB_asymmetry = (nD0barAbove-nD0barBelow)/(nD0barAbove+nD0barBelow);
   D0barAB_asymmetryErr = sqrt( (1.0 - D0barAB_asymmetry*D0barAB_asymmetry)/(nD0barAbove+nD0barBelow) );

   cout << " nD0barAbove =   " << nD0barAbove << endl;
   cout << " nD0barBelow =   " << nD0barBelow << endl;
   cout << " D0barAB_asymmetry =   " << D0barAB_asymmetry 
            << "  +-  " << D0barAB_asymmetryErr << endl << endl;

   weight1 = 1./(D0AB_asymmetryErr*D0AB_asymmetryErr);
   weight2 = 1./(D0barAB_asymmetryErr*D0barAB_asymmetryErr);

   CPAsymmetry = (D0AB_asymmetry*weight1+D0barAB_asymmetry*weight2)/(weight1+weight2);
   CPAsymmetryErr = sqrt(1./(weight1+weight2));
   DiffAB = (D0AB_asymmetry*weight1-D0barAB_asymmetry*weight2)/(weight1+weight2);

   cout << "  CP Asymmetry =   " << CPAsymmetry << "  +-  " << CPAsymmetryErr << endl << endl;

  
   nD0Sin2PhiPlus = 0; 
   nD0barSin2PhiPlus = 0;

   nD0Sin2PhiMinus = 0; 
   nD0barSin2PhiMinus = 0;

   for (int bin=1; bin<26; bin++) {
     nD0Sin2PhiPlus = nD0Sin2PhiPlus+quad4PhiHistD02KstarF0->GetBinContent(bin);
     nD0barSin2PhiPlus = nD0barSin2PhiPlus+quad4PhiHistD0bar2KstarF0->GetBinContent(bin);
   }
   for (int bin=51; bin<76; bin++) {
     nD0Sin2PhiPlus = nD0Sin2PhiPlus+quad4PhiHistD02KstarF0->GetBinContent(bin);
     nD0barSin2PhiPlus = nD0barSin2PhiPlus+quad4PhiHistD0bar2KstarF0->GetBinContent(bin);
   }

   for (int bin=25; bin<51; bin++) {
     nD0Sin2PhiMinus = nD0Sin2PhiMinus+quad4PhiHistD02KstarF0->GetBinContent(bin);
     nD0barSin2PhiMinus = nD0barSin2PhiMinus+quad4PhiHistD0bar2KstarF0->GetBinContent(bin);
   }
   for (int bin=75; bin<101; bin++) {
     nD0Sin2PhiMinus = nD0Sin2PhiMinus+quad4PhiHistD02KstarF0->GetBinContent(bin);
     nD0barSin2PhiMinus = nD0barSin2PhiMinus+quad4PhiHistD0bar2KstarF0->GetBinContent(bin);
   }

   D0Sin2Phi_asymmetry = (nD0Sin2PhiPlus-nD0Sin2PhiMinus)/(nD0Sin2PhiPlus+nD0Sin2PhiMinus);
   D0Sin2Phi_asymmetryErr = sqrt( (1.0 - D0Sin2Phi_asymmetry*D0Sin2Phi_asymmetry)/
                             (nD0Sin2PhiPlus+nD0Sin2PhiMinus) );

   D0barSin2Phi_asymmetry = (nD0barSin2PhiPlus-nD0barSin2PhiMinus) /
                             (nD0barSin2PhiPlus+nD0barSin2PhiMinus);
   D0barSin2Phi_asymmetryErr = sqrt( (1.0 - D0barSin2Phi_asymmetry*D0barSin2Phi_asymmetry)/
                                         (nD0barSin2PhiPlus+nD0barSin2PhiMinus) );

   weight1 = 1./(D0Sin2Phi_asymmetryErr*D0Sin2Phi_asymmetryErr);
   weight2 = 1./(D0barSin2Phi_asymmetryErr*D0barSin2Phi_asymmetryErr);

   Sin2PhiCP_asymmetry = (D0Sin2Phi_asymmetry*weight1+D0barSin2Phi_asymmetry*weight2)/
                                   (weight1+weight2);
   Sin2PhiCP_asymmetryErr = sqrt(1./(weight1+weight2));

   DiffSin2Phi = (D0Sin2Phi_asymmetry*weight1-D0barSin2Phi_asymmetry*weight2)/(weight1+weight2);


   cout << "D0Sin2Phi_asymmetry =  " << D0Sin2Phi_asymmetry << "  +-  " <<
                D0Sin2Phi_asymmetryErr << endl;
   cout << "D0barSin2Phi_asymmetry =  " << D0barSin2Phi_asymmetry << "  +-  " <<
                D0barSin2Phi_asymmetryErr << endl;
   cout << " Sin2PhiCP_asymmetry =    " << Sin2PhiCP_asymmetry << "  +-  " <<
                 Sin2PhiCP_asymmetryErr << endl << endl;
  
   maximum = quad4PhiHistD0bar2KstarF0->GetMaximum();
    cout << "max from quad4PhiHistD0bar2KstarF0->GetMaximum() = " << maximum << endl;
   quad4PhiHistD02KstarF0->SetLineColor(kBlue);
   quad4PhiHistD02KstarF0->SetLineWidth(2);
   d02KstarF0Entries = quad4PhiHistD02KstarF0->GetEntries();
   quad4PhiHistD02KstarF0->Scale(1.00/d02KstarF0Entries);
   quad4PhiHistD02KstarF0->GetXaxis()->SetTitleSize(0.06);
   quad4PhiHistD02KstarF0->GetXaxis()->SetTitleOffset(0.75);
   quad4PhiHistD02KstarF0->GetXaxis()->SetLabelFont(62);
   quad4PhiHistD02KstarF0->GetXaxis()->CenterTitle(true);
   quad4PhiHistD02KstarF0->SetTitle("(K*, f(0))  - Quad 4");
   quad4PhiHistD02KstarF0->SetXTitle("#phi [radians]");
   quad4PhiHistD02KstarF0->GetYaxis()->SetTitleSize(0.06);
   quad4PhiHistD02KstarF0->GetYaxis()->SetTitleOffset(0.75);
   quad4PhiHistD02KstarF0->SetYTitle("fraction per 2#pi/100 radians");
   quad4PhiHistD02KstarF0->Draw();
   leg->Clear();
   leg->SetHeader("The Samples");
   leg->AddEntry(quad4PhiHistD02KstarF0,"D^{0}","L");
   quad4PhiHistD02KstarF0->Draw();
   quad4PhiHistD0bar2KstarF0->SetLineColor(kRed+1);
   quad4PhiHistD0bar2KstarF0->SetLineWidth(2);
   d0bar2KstarF0Entries = quad4PhiHistD0bar2KstarF0->GetEntries();
   quad4PhiHistD0bar2KstarF0->Scale(1.00/d0bar2KstarF0Entries);
   quad4PhiHistD02KstarF0->GetYaxis()->SetRangeUser(0.,1.25*maximum/d02KstarF0Entries);
   quad4PhiHistD0bar2KstarF0->Draw("same");
   leg->AddEntry(quad4PhiHistD0bar2KstarF0,"#bar{D}^{0}","L");
   leg->Draw();
   pt1->Clear();
   d0AsymStr.Form("%4.1f\n",100.*D0AB_asymmetry);
   d0AsymErrStr.Form("%4.1f\n",100.*D0AB_asymmetryErr);
   d0barAsymStr.Form("%4.1f\n",100.*D0barAB_asymmetry);
   d0barAsymErrStr.Form("%4.1f\n",100.*D0barAB_asymmetryErr);
   cpAsymStr.Form("%4.1f\n",100.*CPAsymmetry);
   cpAsymErrStr.Form("%4.1f\n",100.*CPAsymmetryErr);
   DiffABStr.Form("%4.1f\n",100.*DiffAB);
   d0Sin2PhiAsymStr.Form("%4.1f\n",100.*D0Sin2Phi_asymmetry);
   d0Sin2PhiAsymErrStr.Form("%4.1f\n",100.*D0Sin2Phi_asymmetryErr);
   d0barSin2PhiAsymStr.Form("%4.1f\n",100.*D0barSin2Phi_asymmetry);
   d0barSin2PhiAsymErrStr.Form("%4.1f\n",100.*D0barSin2Phi_asymmetryErr);
   cpSin2PhiAsymStr.Form("%4.1f\n",100.*Sin2PhiCP_asymmetry);
   cpSin2PhiAsymErrStr.Form("%4.1f\n",100.*Sin2PhiCP_asymmetryErr);
   DiffSin2PhiStr.Form("%4.1f\n",100.*DiffSin2Phi);
   pt1->AddText("asymmetries");
   pt1->AddText("sin(#phi)             sin(2#phi)");
   pt1->AddText("D^{0}:  ( "+d0AsymStr+" #pm "+d0AsymErrStr+")%   ("
         +d0Sin2PhiAsymStr+" #pm "+d0Sin2PhiAsymErrStr+")%");
   pt1->AddText("#bar{D}^{0}:  ( "+d0barAsymStr+" #pm "+d0barAsymErrStr+")%   ("
         +d0barSin2PhiAsymStr+" #pm "+d0barSin2PhiAsymErrStr+")%");
   pt1->AddText("CP:   ( "+cpAsymStr+" #pm "+cpAsymErrStr+")%   ("
         +cpSin2PhiAsymStr+" #pm "+cpSin2PhiAsymErrStr+")%");
   pt1->AddText("D^{0}-#bar{D}^{0}:  ("+DiffABStr+" #pm "+cpAsymErrStr+")%   ("
         +DiffSin2PhiStr+" #pm "+cpSin2PhiAsymErrStr+")%");
   nd0Str.Form("%6.0f\n",nD0);
   nd0barStr.Form("%6.0f\n",nD0bar);
   pt1->AddText("n(D^{0}) = "+nd0Str+"           n(#bar{D}^{0}) = "+nd0barStr);
   pt1->Draw();
   c1.SaveAs("compareQuad4PhiKstarF0.png");
   c1.SetLogy(0);


//  ***  end of KstarF0 calculations & plotting  ***


//  ***  begin Kappa,rho calculations & plotting  ***
//  do asymmetry calculations before re-scaling the distributions
  
   nD0 = quad1PhiHistD02KappaRho->GetEntries();
   nD0bar = quad1PhiHistD0bar2KappaRho->GetEntries();
   scale = nD0/nD0bar;
   nD0Above = 0;
   nD0barAbove = 0;
//  change meaning of "Above" and "Below" to refer to  sign(sin(phi)), 
//  rather than phi above or below pi.
   for (int bin=0; bin<51; bin++) {
     nD0Above = nD0Above+quad1PhiHistD02KappaRho->GetBinContent(bin);
     nD0barAbove = nD0barAbove+quad1PhiHistD0bar2KappaRho->GetBinContent(bin);
   }
   
   nD0Below = 0;
   nD0barBelow = 0;
   for (int bin=51; bin<101; bin++) {
     nD0Below = nD0Below+quad1PhiHistD02KappaRho->GetBinContent(bin);
     nD0barBelow = nD0barBelow+quad1PhiHistD0bar2KappaRho->GetBinContent(bin);
   }

   D0AB_asymmetry = (nD0Above-nD0Below)/(nD0Above+nD0Below);
   D0AB_asymmetryErr = sqrt( (1.0 - D0AB_asymmetry*D0AB_asymmetry)/(nD0Above+nD0Below) );

   cout <<  endl << "For Quad 1 " << endl;
   cout << " nD0Above =   " << nD0Above << endl;
   cout << " nD0Below =   " << nD0Below << endl;
   cout << " D0AB_asymmetry =   " << D0AB_asymmetry << "  +-  " << D0AB_asymmetryErr << endl << endl;
   
   D0barAB_asymmetry = (nD0barAbove-nD0barBelow)/(nD0barAbove+nD0barBelow);
   D0barAB_asymmetryErr = sqrt( (1.0 - D0barAB_asymmetry*D0barAB_asymmetry)/(nD0barAbove+nD0barBelow) );

   cout << " nD0barAbove =   " << nD0barAbove << endl;
   cout << " nD0barBelow =   " << nD0barBelow << endl;
   cout << " D0barAB_asymmetry =   " << D0barAB_asymmetry 
            << "  +-  " << D0barAB_asymmetryErr << endl << endl;

   weight1 = 1./(D0AB_asymmetryErr*D0AB_asymmetryErr);
   weight2 = 1./(D0barAB_asymmetryErr*D0barAB_asymmetryErr);

   CPAsymmetry = (D0AB_asymmetry*weight1+D0barAB_asymmetry*weight2)/(weight1+weight2);
   CPAsymmetryErr = sqrt(1./(weight1+weight2));
   DiffAB = (D0AB_asymmetry*weight1-D0barAB_asymmetry*weight2)/(weight1+weight2);
   
   cout << "  CP Asymmetry =   " << CPAsymmetry << "  +-  " << CPAsymmetryErr << endl << endl;
   
  
   nD0Sin2PhiPlus = 0; 
   nD0barSin2PhiPlus = 0;

   nD0Sin2PhiMinus = 0; 
   nD0barSin2PhiMinus = 0;

   for (int bin=1; bin<26; bin++) {
     nD0Sin2PhiPlus = nD0Sin2PhiPlus+quad1PhiHistD02KappaRho->GetBinContent(bin);
     nD0barSin2PhiPlus = nD0barSin2PhiPlus+quad1PhiHistD0bar2KappaRho->GetBinContent(bin);
   }
   for (int bin=51; bin<76; bin++) {
     nD0Sin2PhiPlus = nD0Sin2PhiPlus+quad1PhiHistD02KappaRho->GetBinContent(bin);
     nD0barSin2PhiPlus = nD0barSin2PhiPlus+quad1PhiHistD0bar2KappaRho->GetBinContent(bin);
   }

   for (int bin=25; bin<51; bin++) {
     nD0Sin2PhiMinus = nD0Sin2PhiMinus+quad1PhiHistD02KappaRho->GetBinContent(bin);
     nD0barSin2PhiMinus = nD0barSin2PhiMinus+quad1PhiHistD0bar2KappaRho->GetBinContent(bin);
   }
   for (int bin=75; bin<101; bin++) {
     nD0Sin2PhiMinus = nD0Sin2PhiMinus+quad1PhiHistD02KappaRho->GetBinContent(bin);
     nD0barSin2PhiMinus = nD0barSin2PhiMinus+quad1PhiHistD0bar2KappaRho->GetBinContent(bin);
   }

   D0Sin2Phi_asymmetry = (nD0Sin2PhiPlus-nD0Sin2PhiMinus)/(nD0Sin2PhiPlus+nD0Sin2PhiMinus);
   D0Sin2Phi_asymmetryErr = sqrt( (1.0 - D0Sin2Phi_asymmetry*D0Sin2Phi_asymmetry)/
                                      (nD0Sin2PhiPlus+nD0Sin2PhiMinus) );

   D0barSin2Phi_asymmetry = (nD0barSin2PhiPlus-nD0barSin2PhiMinus) /
                                      (nD0barSin2PhiPlus+nD0barSin2PhiMinus);
   D0barSin2Phi_asymmetryErr = sqrt( (1.0 - D0barSin2Phi_asymmetry*D0barSin2Phi_asymmetry)/
                                         (nD0barSin2PhiPlus+nD0barSin2PhiMinus) );

   weight1 = 1./(D0Sin2Phi_asymmetryErr*D0Sin2Phi_asymmetryErr);
   weight2 = 1./(D0barSin2Phi_asymmetryErr*D0barSin2Phi_asymmetryErr);

   Sin2PhiCP_asymmetry = (D0Sin2Phi_asymmetry*weight1+D0barSin2Phi_asymmetry*weight2)/
                                   (weight1+weight2);
   Sin2PhiCP_asymmetryErr = sqrt(1./(weight1+weight2));

   DiffSin2Phi = (D0Sin2Phi_asymmetry*weight1-D0barSin2Phi_asymmetry*weight2)/(weight1+weight2);

   cout << "D0Sin2Phi_asymmetry =  " << D0Sin2Phi_asymmetry << "  +-  " <<
                D0Sin2Phi_asymmetryErr << endl;
   cout << "D0barSin2Phi_asymmetry =  " << D0barSin2Phi_asymmetry << "  +-  " <<
                D0barSin2Phi_asymmetryErr << endl;
   cout << " Sin2PhiCP_asymmetry =    " << Sin2PhiCP_asymmetry << "  +-  " <<
                 Sin2PhiCP_asymmetryErr << endl << endl;
  

   maximum = quad1PhiHistD0bar2KappaRho->GetMaximum();
    cout << "max from quad1PhiHistD0bar2KappaRho->GetMaximum() = " << maximum << endl;
   quad1PhiHistD0bar2KappaRho->Draw();
   quad1PhiHistD02KappaRho->SetLineColor(kBlue);
   quad1PhiHistD02KappaRho->SetLineWidth(2);
   Double_t d02KappaRhoEntries = quad1PhiHistD02KappaRho->GetEntries();
   quad1PhiHistD02KappaRho->Scale(1.00/d02KappaRhoEntries);
   quad1PhiHistD02KappaRho->GetXaxis()->SetTitleSize(0.06);
   quad1PhiHistD02KappaRho->GetXaxis()->SetTitleOffset(0.75);
   quad1PhiHistD02KappaRho->GetXaxis()->SetLabelFont(62);
   quad1PhiHistD02KappaRho->GetXaxis()->CenterTitle(true);
   quad1PhiHistD02KappaRho->SetTitle("(#kappa, #rho)  - Quad 1");
   quad1PhiHistD02KappaRho->SetXTitle("#phi [radians]");
   quad1PhiHistD02KappaRho->GetYaxis()->SetTitleSize(0.06);
   quad1PhiHistD02KappaRho->GetYaxis()->SetTitleOffset(0.75);
   quad1PhiHistD02KappaRho->SetYTitle("fraction per 2#pi/100 radians");
   leg->Clear();
   leg->SetHeader("The Samples");
   leg->AddEntry(quad1PhiHistD02KappaRho,"D^{0}","L");
   quad1PhiHistD02KappaRho->Draw();
   quad1PhiHistD0bar2KappaRho->SetLineColor(kRed+1);
   quad1PhiHistD0bar2KappaRho->SetLineWidth(2);
   Double_t d0bar2KappaRhoEntries = quad1PhiHistD0bar2KappaRho->GetEntries();
   quad1PhiHistD0bar2KappaRho->Scale(1.00/d0bar2KappaRhoEntries);
   quad1PhiHistD02KappaRho->GetYaxis()->SetRangeUser(0.,1.25*maximum/d02KappaRhoEntries);
   quad1PhiHistD02KappaRho->GetXaxis()->SetTitleSize(0.06);
   quad1PhiHistD02KappaRho->GetXaxis()->SetTitleOffset(0.75);
   quad1PhiHistD02KappaRho->GetXaxis()->SetLabelFont(62);
   quad1PhiHistD02KappaRho->GetXaxis()->CenterTitle(true);
   quad1PhiHistD02KappaRho->SetTitle("(#kappa, #rho)  - Quad 1");
   quad1PhiHistD02KappaRho->SetXTitle("#phi [radians]");
   quad1PhiHistD02KappaRho->GetYaxis()->SetTitleSize(0.06);
   quad1PhiHistD02KappaRho->GetYaxis()->SetTitleOffset(0.75);
   quad1PhiHistD02KappaRho->SetYTitle("fraction per 2#pi/100 radians");
   leg->AddEntry(quad1PhiHistD0bar2KappaRho,"#bar{D}^{0}","L");
   quad1PhiHistD0bar2KappaRho->Draw("same");
   leg->Draw();
   pt1->Clear();
   d0AsymStr.Form("%4.1f\n",100.*D0AB_asymmetry);
   d0AsymErrStr.Form("%4.1f\n",100.*D0AB_asymmetryErr);
   d0barAsymStr.Form("%4.1f\n",100.*D0barAB_asymmetry);
   d0barAsymErrStr.Form("%4.1f\n",100.*D0barAB_asymmetryErr);
   cpAsymStr.Form("%4.1f\n",100.*CPAsymmetry);
   cpAsymErrStr.Form("%4.1f\n",100.*CPAsymmetryErr);
   DiffABStr.Form("%4.1f\n",100.*DiffAB);
   d0Sin2PhiAsymStr.Form("%4.1f\n",100.*D0Sin2Phi_asymmetry);
   d0Sin2PhiAsymErrStr.Form("%4.1f\n",100.*D0Sin2Phi_asymmetryErr);
   d0barSin2PhiAsymStr.Form("%4.1f\n",100.*D0barSin2Phi_asymmetry);
   d0barSin2PhiAsymErrStr.Form("%4.1f\n",100.*D0barSin2Phi_asymmetryErr);
   cpSin2PhiAsymStr.Form("%4.1f\n",100.*Sin2PhiCP_asymmetry);
   cpSin2PhiAsymErrStr.Form("%4.1f\n",100.*Sin2PhiCP_asymmetryErr);
   DiffSin2PhiStr.Form("%4.1f\n",100.*DiffSin2Phi);
   pt1->AddText("asymmetries");
   pt1->AddText("sin(#phi)             sin(2#phi)");
   pt1->AddText("D^{0}:  ( "+d0AsymStr+" #pm "+d0AsymErrStr+")%   ("
         +d0Sin2PhiAsymStr+" #pm "+d0Sin2PhiAsymErrStr+")%");
   pt1->AddText("#bar{D}^{0}:  ( "+d0barAsymStr+" #pm "+d0barAsymErrStr+")%   ("
         +d0barSin2PhiAsymStr+" #pm "+d0barSin2PhiAsymErrStr+")%");
   pt1->AddText("CP:   ( "+cpAsymStr+" #pm "+cpAsymErrStr+")%   ("
         +cpSin2PhiAsymStr+" #pm "+cpSin2PhiAsymErrStr+")%");
   pt1->AddText("D^{0}-#bar{D}^{0}:  ("+DiffABStr+" #pm "+cpAsymErrStr+")%   ("
         +DiffSin2PhiStr+" #pm "+cpSin2PhiAsymErrStr+")%");
   nd0Str.Form("%6.0f\n",nD0);
   nd0barStr.Form("%6.0f\n",nD0bar);
   pt1->AddText("n(D^{0}) = "+nd0Str+"           n(#bar{D}^{0}) = "+nd0barStr);
   pt1->Draw();
   c1.SaveAs("compareQuad1PhiKappaRho.png");
   c1.SetLogy(0);


/////////  start with Quad 2

//  do asymmetry calculations before re-scaling the distributions
  
   nD0 = quad2PhiHistD02KappaRho->GetEntries();
   nD0bar = quad2PhiHistD0bar2KappaRho->GetEntries();
   scale = nD0/nD0bar;
   nD0Above = 0;
   nD0barAbove = 0;
   for (int bin=0; bin<51; bin++) {
     nD0Above = nD0Above+quad2PhiHistD02KappaRho->GetBinContent(bin);
     nD0barAbove = nD0barAbove+quad2PhiHistD0bar2KappaRho->GetBinContent(bin);
   }
   
   nD0Below = 0;
   nD0barBelow = 0;
   for (int bin=51; bin<101; bin++) {
     nD0Below = nD0Below+quad2PhiHistD02KappaRho->GetBinContent(bin);
     nD0barBelow = nD0barBelow+quad2PhiHistD0bar2KappaRho->GetBinContent(bin);
   }

   D0AB_asymmetry = (nD0Above-nD0Below)/(nD0Above+nD0Below);
   D0AB_asymmetryErr = sqrt( (1.0 - D0AB_asymmetry*D0AB_asymmetry)/(nD0Above+nD0Below) );

   cout <<  endl << "For Quad 2 " << endl;
   cout << " nD0Above =   " << nD0Above << endl;
   cout << " nD0Below =   " << nD0Below << endl;
   cout << " D0AB_asymmetry =   " << D0AB_asymmetry << "  +-  " << D0AB_asymmetryErr << endl << endl;
   
   D0barAB_asymmetry = (nD0barAbove-nD0barBelow)/(nD0barAbove+nD0barBelow);
   D0barAB_asymmetryErr = sqrt( (1.0 - D0barAB_asymmetry*D0barAB_asymmetry)/(nD0barAbove+nD0barBelow) );

   cout << " nD0barAbove =   " << nD0barAbove << endl;
   cout << " nD0barBelow =   " << nD0barBelow << endl;
   cout << " D0barAB_asymmetry =   " << D0barAB_asymmetry 
            << "  +-  " << D0barAB_asymmetryErr << endl << endl;

   weight1 = 1./(D0AB_asymmetryErr*D0AB_asymmetryErr);
   weight2 = 1./(D0barAB_asymmetryErr*D0barAB_asymmetryErr);

   CPAsymmetry = (D0AB_asymmetry*weight1+D0barAB_asymmetry*weight2)/(weight1+weight2);
   CPAsymmetryErr = sqrt(1./(weight1+weight2));
   DiffAB = (D0AB_asymmetry*weight1-D0barAB_asymmetry*weight2)/(weight1+weight2);
   cout << "  CP Asymmetry =   " << CPAsymmetry << "  +-  " << CPAsymmetryErr << endl << endl;


   nD0Sin2PhiPlus = 0; 
   nD0barSin2PhiPlus = 0;

   nD0Sin2PhiMinus = 0; 
   nD0barSin2PhiMinus = 0;

   for (int bin=1; bin<26; bin++) {
     nD0Sin2PhiPlus = nD0Sin2PhiPlus+quad2PhiHistD02KappaRho->GetBinContent(bin);
     nD0barSin2PhiPlus = nD0barSin2PhiPlus+quad2PhiHistD0bar2KappaRho->GetBinContent(bin);
   }
   for (int bin=51; bin<76; bin++) {
     nD0Sin2PhiPlus = nD0Sin2PhiPlus+quad2PhiHistD02KappaRho->GetBinContent(bin);
     nD0barSin2PhiPlus = nD0barSin2PhiPlus+quad2PhiHistD0bar2KappaRho->GetBinContent(bin);
   }

   for (int bin=25; bin<51; bin++) {
     nD0Sin2PhiMinus = nD0Sin2PhiMinus+quad2PhiHistD02KappaRho->GetBinContent(bin);
     nD0barSin2PhiMinus = nD0barSin2PhiMinus+quad2PhiHistD0bar2KappaRho->GetBinContent(bin);
   }
   for (int bin=75; bin<101; bin++) {
     nD0Sin2PhiMinus = nD0Sin2PhiMinus+quad2PhiHistD02KappaRho->GetBinContent(bin);
     nD0barSin2PhiMinus = nD0barSin2PhiMinus+quad2PhiHistD0bar2KappaRho->GetBinContent(bin);
   }

   D0Sin2Phi_asymmetry = (nD0Sin2PhiPlus-nD0Sin2PhiMinus)/(nD0Sin2PhiPlus+nD0Sin2PhiMinus);
   D0Sin2Phi_asymmetryErr = sqrt( (1.0 - D0Sin2Phi_asymmetry*D0Sin2Phi_asymmetry)/
                             (nD0Sin2PhiPlus+nD0Sin2PhiMinus) );

   D0barSin2Phi_asymmetry = (nD0barSin2PhiPlus-nD0barSin2PhiMinus) /
                             (nD0barSin2PhiPlus+nD0barSin2PhiMinus);
   D0barSin2Phi_asymmetryErr = sqrt( (1.0 - D0barSin2Phi_asymmetry*D0barSin2Phi_asymmetry)/
                                         (nD0barSin2PhiPlus+nD0barSin2PhiMinus) );

   weight1 = 1./(D0Sin2Phi_asymmetryErr*D0Sin2Phi_asymmetryErr);
   weight2 = 1./(D0barSin2Phi_asymmetryErr*D0barSin2Phi_asymmetryErr);

   Sin2PhiCP_asymmetry = (D0Sin2Phi_asymmetry*weight1+D0barSin2Phi_asymmetry*weight2)/
                                   (weight1+weight2);
   Sin2PhiCP_asymmetryErr = sqrt(1./(weight1+weight2));

   DiffSin2Phi = (D0Sin2Phi_asymmetry*weight1-D0barSin2Phi_asymmetry*weight2)/(weight1+weight2);



   cout << "D0Sin2Phi_asymmetry =  " << D0Sin2Phi_asymmetry << "  +-  " <<
                D0Sin2Phi_asymmetryErr << endl;
   cout << "D0barSin2Phi_asymmetry =  " << D0barSin2Phi_asymmetry << "  +-  " <<
                D0barSin2Phi_asymmetryErr << endl;
   cout << " Sin2PhiCP_asymmetry =    " << Sin2PhiCP_asymmetry << "  +-  " <<
                 Sin2PhiCP_asymmetryErr << endl << endl;
  
   maximum = quad2PhiHistD0bar2KappaRho->GetMaximum();
    cout << "max from quad2PhiHistD0bar2KappaRho->GetMaximum() = " << maximum << endl;
   quad2PhiHistD02KappaRho->SetLineColor(kBlue);
   quad2PhiHistD02KappaRho->SetLineWidth(2);
   d02KappaRhoEntries = quad2PhiHistD02KappaRho->GetEntries();
   quad2PhiHistD02KappaRho->Scale(1.00/d02KappaRhoEntries);
   quad2PhiHistD0bar2KappaRho->SetLineColor(kRed+1);
   quad2PhiHistD0bar2KappaRho->SetLineWidth(2);
   d0bar2KappaRhoEntries = quad2PhiHistD0bar2KappaRho->GetEntries();
   quad2PhiHistD0bar2KappaRho->Scale(1.00/d0bar2KappaRhoEntries);
   quad2PhiHistD02KappaRho->GetYaxis()->SetRangeUser(0.,1.25*maximum/d02KappaRhoEntries);
   quad2PhiHistD02KappaRho->GetXaxis()->SetTitleSize(0.06);
   quad2PhiHistD02KappaRho->GetXaxis()->SetTitleOffset(0.75);
   quad2PhiHistD02KappaRho->GetXaxis()->SetLabelFont(62);
   quad2PhiHistD02KappaRho->GetXaxis()->CenterTitle(true);
   quad2PhiHistD02KappaRho->SetTitle("(#kappa,#rho)  - Quad 2");
   quad2PhiHistD02KappaRho->SetXTitle("#phi [radians]");
   quad2PhiHistD02KappaRho->GetYaxis()->SetTitleSize(0.06);
   quad2PhiHistD02KappaRho->GetYaxis()->SetTitleOffset(0.75);
   quad2PhiHistD02KappaRho->SetYTitle("fraction per 2#pi/100 radians");
   quad2PhiHistD02KappaRho->Draw();
   leg->Clear();
   leg->SetHeader("The Samples");
   leg->AddEntry(quad2PhiHistD02KappaRho,"D^{0}","L");
   quad2PhiHistD0bar2KappaRho->Draw("same");
   leg->AddEntry(quad2PhiHistD0bar2KappaRho,"#bar{D}^{0}","L");
   leg->Draw();
   pt1->Clear();
   d0AsymStr.Form("%4.1f\n",100.*D0AB_asymmetry);
   d0AsymErrStr.Form("%4.1f\n",100.*D0AB_asymmetryErr);
   d0barAsymStr.Form("%4.1f\n",100.*D0barAB_asymmetry);
   d0barAsymErrStr.Form("%4.1f\n",100.*D0barAB_asymmetryErr);
   cpAsymStr.Form("%4.1f\n",100.*CPAsymmetry);
   cpAsymErrStr.Form("%4.1f\n",100.*CPAsymmetryErr);
   DiffABStr.Form("%4.1f\n",100.*DiffAB);
   d0Sin2PhiAsymStr.Form("%4.1f\n",100.*D0Sin2Phi_asymmetry);
   d0Sin2PhiAsymErrStr.Form("%4.1f\n",100.*D0Sin2Phi_asymmetryErr);
   d0barSin2PhiAsymStr.Form("%4.1f\n",100.*D0barSin2Phi_asymmetry);
   d0barSin2PhiAsymErrStr.Form("%4.1f\n",100.*D0barSin2Phi_asymmetryErr);
   cpSin2PhiAsymStr.Form("%4.1f\n",100.*Sin2PhiCP_asymmetry);
   cpSin2PhiAsymErrStr.Form("%4.1f\n",100.*Sin2PhiCP_asymmetryErr);
   DiffSin2PhiStr.Form("%4.1f\n",100.*DiffSin2Phi);
   pt1->AddText("asymmetries");
   pt1->AddText("sin(#phi)             sin(2#phi)");
   pt1->AddText("D^{0}:  ( "+d0AsymStr+" #pm "+d0AsymErrStr+")%   ("
         +d0Sin2PhiAsymStr+" #pm "+d0Sin2PhiAsymErrStr+")%");
   pt1->AddText("#bar{D}^{0}:  ( "+d0barAsymStr+" #pm "+d0barAsymErrStr+")%   ("
         +d0barSin2PhiAsymStr+" #pm "+d0barSin2PhiAsymErrStr+")%");
   pt1->AddText("CP:   ( "+cpAsymStr+" #pm "+cpAsymErrStr+")%   ("
         +cpSin2PhiAsymStr+" #pm "+cpSin2PhiAsymErrStr+")%");
   pt1->AddText("D^{0}-#bar{D}^{0}:  ("+DiffABStr+" #pm "+cpAsymErrStr+")%   ("
         +DiffSin2PhiStr+" #pm "+cpSin2PhiAsymErrStr+")%");
   nd0Str.Form("%6.0f\n",nD0);
   nd0barStr.Form("%6.0f\n",nD0bar);
   pt1->AddText("n(D^{0}) = "+nd0Str+"           n(#bar{D}^{0}) = "+nd0barStr);
   pt1->Draw();
   c1.SaveAs("compareQuad2PhiKappaRho.png");
   c1.SetLogy(0);

/////////  start with Quad 3

//  do asymmetry calculations before re-scaling the distributions
  
   nD0 = quad3PhiHistD02KappaRho->GetEntries();
   nD0bar = quad3PhiHistD0bar2KappaRho->GetEntries();
   scale = nD0/nD0bar;
   nD0Above = 0;
   nD0barAbove = 0;
   for (int bin=0; bin<51; bin++) {
     nD0Above = nD0Above+quad3PhiHistD02KappaRho->GetBinContent(bin);
     nD0barAbove = nD0barAbove+quad3PhiHistD0bar2KappaRho->GetBinContent(bin);
   }
   
   nD0Below = 0;
   nD0barBelow = 0;
   for (int bin=51; bin<101; bin++) {
     nD0Below = nD0Below+quad3PhiHistD02KappaRho->GetBinContent(bin);
     nD0barBelow = nD0barBelow+quad3PhiHistD0bar2KappaRho->GetBinContent(bin);
   }

   D0AB_asymmetry = (nD0Above-nD0Below)/(nD0Above+nD0Below);
   D0AB_asymmetryErr = sqrt( (1.0 - D0AB_asymmetry*D0AB_asymmetry)/(nD0Above+nD0Below) );

   cout <<  endl << "For Quad 3 " << endl;
   cout << " nD0Above =   " << nD0Above << endl;
   cout << " nD0Below =   " << nD0Below << endl;
   cout << " D0AB_asymmetry =   " << D0AB_asymmetry << "  +-  " << D0AB_asymmetryErr << endl << endl;
   
   D0barAB_asymmetry = (nD0barAbove-nD0barBelow)/(nD0barAbove+nD0barBelow);
   D0barAB_asymmetryErr = sqrt( (1.0 - D0barAB_asymmetry*D0barAB_asymmetry)/(nD0barAbove+nD0barBelow) );

   cout << " nD0barAbove =   " << nD0barAbove << endl;
   cout << " nD0barBelow =   " << nD0barBelow << endl;
   cout << " D0barAB_asymmetry =   " << D0barAB_asymmetry 
            << "  +-  " << D0barAB_asymmetryErr << endl << endl;

   weight1 = 1./(D0AB_asymmetryErr*D0AB_asymmetryErr);
   weight2 = 1./(D0barAB_asymmetryErr*D0barAB_asymmetryErr);

   CPAsymmetry = (D0AB_asymmetry*weight1+D0barAB_asymmetry*weight2)/(weight1+weight2);
   CPAsymmetryErr = sqrt(1./(weight1+weight2));
   DiffAB = (D0AB_asymmetry*weight1-D0barAB_asymmetry*weight2)/(weight1+weight2);

   cout << "  CP Asymmetry =   " << CPAsymmetry << "  +-  " << CPAsymmetryErr << endl << endl;

  
   nD0Sin2PhiPlus = 0; 
   nD0barSin2PhiPlus = 0;

   nD0Sin2PhiMinus = 0; 
   nD0barSin2PhiMinus = 0;

   for (int bin=1; bin<26; bin++) {
     nD0Sin2PhiPlus = nD0Sin2PhiPlus+quad3PhiHistD02KappaRho->GetBinContent(bin);
     nD0barSin2PhiPlus = nD0barSin2PhiPlus+quad3PhiHistD0bar2KappaRho->GetBinContent(bin);
   }
   for (int bin=51; bin<76; bin++) {
     nD0Sin2PhiPlus = nD0Sin2PhiPlus+quad3PhiHistD02KappaRho->GetBinContent(bin);
     nD0barSin2PhiPlus = nD0barSin2PhiPlus+quad3PhiHistD0bar2KappaRho->GetBinContent(bin);
   }

   for (int bin=25; bin<51; bin++) {
     nD0Sin2PhiMinus = nD0Sin2PhiMinus+quad3PhiHistD02KappaRho->GetBinContent(bin);
     nD0barSin2PhiMinus = nD0barSin2PhiMinus+quad3PhiHistD0bar2KappaRho->GetBinContent(bin);
   }
   for (int bin=75; bin<101; bin++) {
     nD0Sin2PhiMinus = nD0Sin2PhiMinus+quad3PhiHistD02KappaRho->GetBinContent(bin);
     nD0barSin2PhiMinus = nD0barSin2PhiMinus+quad3PhiHistD0bar2KappaRho->GetBinContent(bin);
   }

   D0Sin2Phi_asymmetry = (nD0Sin2PhiPlus-nD0Sin2PhiMinus)/(nD0Sin2PhiPlus+nD0Sin2PhiMinus);
   D0Sin2Phi_asymmetryErr = sqrt( (1.0 - D0Sin2Phi_asymmetry*D0Sin2Phi_asymmetry)/
                             (nD0Sin2PhiPlus+nD0Sin2PhiMinus) );

   D0barSin2Phi_asymmetry = (nD0barSin2PhiPlus-nD0barSin2PhiMinus) /
                             (nD0barSin2PhiPlus+nD0barSin2PhiMinus);
   D0barSin2Phi_asymmetryErr = sqrt( (1.0 - D0barSin2Phi_asymmetry*D0barSin2Phi_asymmetry)/
                                         (nD0barSin2PhiPlus+nD0barSin2PhiMinus) );

   weight1 = 1./(D0Sin2Phi_asymmetryErr*D0Sin2Phi_asymmetryErr);
   weight2 = 1./(D0barSin2Phi_asymmetryErr*D0barSin2Phi_asymmetryErr);

   Sin2PhiCP_asymmetry = (D0Sin2Phi_asymmetry*weight1+D0barSin2Phi_asymmetry*weight2)/
                                   (weight1+weight2);
   Sin2PhiCP_asymmetryErr = sqrt(1./(weight1+weight2));

   DiffSin2Phi = (D0Sin2Phi_asymmetry*weight1-D0barSin2Phi_asymmetry*weight2)/(weight1+weight2);


   cout << "D0Sin2Phi_asymmetry =  " << D0Sin2Phi_asymmetry << "  +-  " <<
                D0Sin2Phi_asymmetryErr << endl;
   cout << "D0barSin2Phi_asymmetry =  " << D0barSin2Phi_asymmetry << "  +-  " <<
                D0barSin2Phi_asymmetryErr << endl;
   cout << " Sin2PhiCP_asymmetry =    " << Sin2PhiCP_asymmetry << "  +-  " <<
                 Sin2PhiCP_asymmetryErr << endl << endl;
  
   maximum = quad3PhiHistD0bar2KappaRho->GetMaximum();
    cout << "max from quad3PhiHistD0bar2KappaRho->GetMaximum() = " << maximum << endl;
   quad3PhiHistD0bar2KappaRho->Draw();
   quad3PhiHistD02KappaRho->SetLineColor(kBlue);
   quad3PhiHistD02KappaRho->SetLineWidth(2);
   d02KappaRhoEntries = quad3PhiHistD02KappaRho->GetEntries();
   quad3PhiHistD02KappaRho->Scale(1.00/d02KappaRhoEntries);
   quad3PhiHistD02KappaRho->GetXaxis()->SetTitleSize(0.06);
   quad3PhiHistD02KappaRho->GetXaxis()->SetTitleOffset(0.75);
   quad3PhiHistD02KappaRho->GetXaxis()->SetLabelFont(62);
   quad3PhiHistD02KappaRho->GetXaxis()->CenterTitle(true);
   quad3PhiHistD02KappaRho->SetTitle("(#kappa, #rho)  - Quad 3");
   quad3PhiHistD02KappaRho->SetXTitle("#phi [radians]");
   quad3PhiHistD02KappaRho->GetYaxis()->SetTitleSize(0.06);
   quad3PhiHistD02KappaRho->GetYaxis()->SetTitleOffset(0.75);
   quad3PhiHistD02KappaRho->SetYTitle("fraction per 2#pi/100 radians");
   quad3PhiHistD02KappaRho->Draw();
   leg->Clear();
   leg->SetHeader("The Samples");
   leg->AddEntry(quad3PhiHistD02KappaRho,"D^{0}","L");
   quad3PhiHistD02KappaRho->Draw();
   quad3PhiHistD0bar2KappaRho->SetLineColor(kRed+1);
   quad3PhiHistD0bar2KappaRho->SetLineWidth(2);
   d0bar2KappaRhoEntries = quad3PhiHistD0bar2KappaRho->GetEntries();
   quad3PhiHistD0bar2KappaRho->Scale(1.00/d0bar2KappaRhoEntries);
   quad3PhiHistD02KappaRho->GetYaxis()->SetRangeUser(0.,1.25*maximum/d02KappaRhoEntries);
   quad3PhiHistD0bar2KappaRho->Draw("same");
   leg->AddEntry(quad3PhiHistD0bar2KappaRho,"#bar{D}^{0}","L");
   leg->Draw();
   pt1->Clear();
   d0AsymStr.Form("%4.1f\n",100.*D0AB_asymmetry);
   d0AsymErrStr.Form("%4.1f\n",100.*D0AB_asymmetryErr);
   d0barAsymStr.Form("%4.1f\n",100.*D0barAB_asymmetry);
   d0barAsymErrStr.Form("%4.1f\n",100.*D0barAB_asymmetryErr);
   cpAsymStr.Form("%4.1f\n",100.*CPAsymmetry);
   cpAsymErrStr.Form("%4.1f\n",100.*CPAsymmetryErr);
   DiffABStr.Form("%4.1f\n",100.*DiffAB);
   d0Sin2PhiAsymStr.Form("%4.1f\n",100.*D0Sin2Phi_asymmetry);
   d0Sin2PhiAsymErrStr.Form("%4.1f\n",100.*D0Sin2Phi_asymmetryErr);
   d0barSin2PhiAsymStr.Form("%4.1f\n",100.*D0barSin2Phi_asymmetry);
   d0barSin2PhiAsymErrStr.Form("%4.1f\n",100.*D0barSin2Phi_asymmetryErr);
   cpSin2PhiAsymStr.Form("%4.1f\n",100.*Sin2PhiCP_asymmetry);
   cpSin2PhiAsymErrStr.Form("%4.1f\n",100.*Sin2PhiCP_asymmetryErr);
   DiffSin2PhiStr.Form("%4.1f\n",100.*DiffSin2Phi);
   pt1->AddText("asymmetries");
   pt1->AddText("sin(#phi)             sin(2#phi)");
   pt1->AddText("D^{0}:  ( "+d0AsymStr+" #pm "+d0AsymErrStr+")%   ("
         +d0Sin2PhiAsymStr+" #pm "+d0Sin2PhiAsymErrStr+")%");
   pt1->AddText("#bar{D}^{0}:  ( "+d0barAsymStr+" #pm "+d0barAsymErrStr+")%   ("
         +d0barSin2PhiAsymStr+" #pm "+d0barSin2PhiAsymErrStr+")%");
   pt1->AddText("CP:   ( "+cpAsymStr+" #pm "+cpAsymErrStr+")%   ("
         +cpSin2PhiAsymStr+" #pm "+cpSin2PhiAsymErrStr+")%");
   pt1->AddText("D^{0}-#bar{D}^{0}:  ("+DiffABStr+" #pm "+cpAsymErrStr+")%   ("
         +DiffSin2PhiStr+" #pm "+cpSin2PhiAsymErrStr+")%");
   nd0Str.Form("%6.0f\n",nD0);
   nd0barStr.Form("%6.0f\n",nD0bar);
   pt1->AddText("n(D^{0}) = "+nd0Str+"           n(#bar{D}^{0}) = "+nd0barStr);
   pt1->Draw();
   c1.SaveAs("compareQuad3PhiKappaRho.png");
   c1.SetLogy(0);

/////////  start with Quad 4

//  do asymmetry calculations before re-scaling the distributions
  
   nD0 = quad4PhiHistD02KappaRho->GetEntries();
   nD0bar = quad4PhiHistD0bar2KappaRho->GetEntries();
   scale = nD0/nD0bar;
   nD0Above = 0;
   nD0barAbove = 0;
   for (int bin=0; bin<51; bin++) {
     nD0Above = nD0Above+quad4PhiHistD02KappaRho->GetBinContent(bin);
     nD0barAbove = nD0barAbove+quad4PhiHistD0bar2KappaRho->GetBinContent(bin);
   }
   
   nD0Below = 0;
   nD0barBelow = 0;
   for (int bin=51; bin<101; bin++) {
     nD0Below = nD0Below+quad4PhiHistD02KappaRho->GetBinContent(bin);
     nD0barBelow = nD0barBelow+quad4PhiHistD0bar2KappaRho->GetBinContent(bin);
   }

   D0AB_asymmetry = (nD0Above-nD0Below)/(nD0Above+nD0Below);
   D0AB_asymmetryErr = sqrt( (1.0 - D0AB_asymmetry*D0AB_asymmetry)/(nD0Above+nD0Below) );

   cout <<  endl << "For Quad 4 " << endl;
   cout << " nD0Above =   " << nD0Above << endl;
   cout << " nD0Below =   " << nD0Below << endl;
   cout << " D0AB_asymmetry =   " << D0AB_asymmetry << "  +-  " << D0AB_asymmetryErr << endl << endl;
   
   D0barAB_asymmetry = (nD0barAbove-nD0barBelow)/(nD0barAbove+nD0barBelow);
   D0barAB_asymmetryErr = sqrt( (1.0 - D0barAB_asymmetry*D0barAB_asymmetry)/(nD0barAbove+nD0barBelow) );

   cout << " nD0barAbove =   " << nD0barAbove << endl;
   cout << " nD0barBelow =   " << nD0barBelow << endl;
   cout << " D0barAB_asymmetry =   " << D0barAB_asymmetry 
            << "  +-  " << D0barAB_asymmetryErr << endl << endl;

   weight1 = 1./(D0AB_asymmetryErr*D0AB_asymmetryErr);
   weight2 = 1./(D0barAB_asymmetryErr*D0barAB_asymmetryErr);

   CPAsymmetry = (D0AB_asymmetry*weight1+D0barAB_asymmetry*weight2)/(weight1+weight2);
   CPAsymmetryErr = sqrt(1./(weight1+weight2));
   DiffAB = (D0AB_asymmetry*weight1-D0barAB_asymmetry*weight2)/(weight1+weight2);

   cout << "  CP Asymmetry =   " << CPAsymmetry << "  +-  " << CPAsymmetryErr << endl << endl;

  
   nD0Sin2PhiPlus = 0; 
   nD0barSin2PhiPlus = 0;

   nD0Sin2PhiMinus = 0; 
   nD0barSin2PhiMinus = 0;

   for (int bin=1; bin<26; bin++) {
     nD0Sin2PhiPlus = nD0Sin2PhiPlus+quad4PhiHistD02KappaRho->GetBinContent(bin);
     nD0barSin2PhiPlus = nD0barSin2PhiPlus+quad4PhiHistD0bar2KappaRho->GetBinContent(bin);
   }
   for (int bin=51; bin<76; bin++) {
     nD0Sin2PhiPlus = nD0Sin2PhiPlus+quad4PhiHistD02KappaRho->GetBinContent(bin);
     nD0barSin2PhiPlus = nD0barSin2PhiPlus+quad4PhiHistD0bar2KappaRho->GetBinContent(bin);
   }

   for (int bin=25; bin<51; bin++) {
     nD0Sin2PhiMinus = nD0Sin2PhiMinus+quad4PhiHistD02KappaRho->GetBinContent(bin);
     nD0barSin2PhiMinus = nD0barSin2PhiMinus+quad4PhiHistD0bar2KappaRho->GetBinContent(bin);
   }
   for (int bin=75; bin<101; bin++) {
     nD0Sin2PhiMinus = nD0Sin2PhiMinus+quad4PhiHistD02KappaRho->GetBinContent(bin);
     nD0barSin2PhiMinus = nD0barSin2PhiMinus+quad4PhiHistD0bar2KappaRho->GetBinContent(bin);
   }

   D0Sin2Phi_asymmetry = (nD0Sin2PhiPlus-nD0Sin2PhiMinus)/(nD0Sin2PhiPlus+nD0Sin2PhiMinus);
   D0Sin2Phi_asymmetryErr = sqrt( (1.0 - D0Sin2Phi_asymmetry*D0Sin2Phi_asymmetry)/
                             (nD0Sin2PhiPlus+nD0Sin2PhiMinus) );

   D0barSin2Phi_asymmetry = (nD0barSin2PhiPlus-nD0barSin2PhiMinus) /
                             (nD0barSin2PhiPlus+nD0barSin2PhiMinus);
   D0barSin2Phi_asymmetryErr = sqrt( (1.0 - D0barSin2Phi_asymmetry*D0barSin2Phi_asymmetry)/
                                         (nD0barSin2PhiPlus+nD0barSin2PhiMinus) );

   weight1 = 1./(D0Sin2Phi_asymmetryErr*D0Sin2Phi_asymmetryErr);
   weight2 = 1./(D0barSin2Phi_asymmetryErr*D0barSin2Phi_asymmetryErr);

   Sin2PhiCP_asymmetry = (D0Sin2Phi_asymmetry*weight1+D0barSin2Phi_asymmetry*weight2)/
                                   (weight1+weight2);
   Sin2PhiCP_asymmetryErr = sqrt(1./(weight1+weight2));

   DiffSin2Phi = (D0Sin2Phi_asymmetry*weight1-D0barSin2Phi_asymmetry*weight2)/(weight1+weight2);


   cout << "D0Sin2Phi_asymmetry =  " << D0Sin2Phi_asymmetry << "  +-  " <<
                D0Sin2Phi_asymmetryErr << endl;
   cout << "D0barSin2Phi_asymmetry =  " << D0barSin2Phi_asymmetry << "  +-  " <<
                D0barSin2Phi_asymmetryErr << endl;
   cout << " Sin2PhiCP_asymmetry =    " << Sin2PhiCP_asymmetry << "  +-  " <<
                 Sin2PhiCP_asymmetryErr << endl << endl;
  
   maximum = quad4PhiHistD0bar2KappaRho->GetMaximum();
    cout << "max from quad4PhiHistD0bar2KappaRho->GetMaximum() = " << maximum << endl;
   quad4PhiHistD02KappaRho->SetLineColor(kBlue);
   quad4PhiHistD02KappaRho->SetLineWidth(2);
   d02KappaRhoEntries = quad4PhiHistD02KappaRho->GetEntries();
   quad4PhiHistD02KappaRho->Scale(1.00/d02KappaRhoEntries);
   quad4PhiHistD02KappaRho->GetXaxis()->SetTitleSize(0.06);
   quad4PhiHistD02KappaRho->GetXaxis()->SetTitleOffset(0.75);
   quad4PhiHistD02KappaRho->GetXaxis()->SetLabelFont(62);
   quad4PhiHistD02KappaRho->GetXaxis()->CenterTitle(true);
   quad4PhiHistD02KappaRho->SetTitle("(#kappa, #rho)  - Quad 4");
   quad4PhiHistD02KappaRho->SetXTitle("#phi [radians]");
   quad4PhiHistD02KappaRho->GetYaxis()->SetTitleSize(0.06);
   quad4PhiHistD02KappaRho->GetYaxis()->SetTitleOffset(0.75);
   quad4PhiHistD02KappaRho->SetYTitle("fraction per 2#pi/100 radians");
   quad4PhiHistD02KappaRho->Draw();
   leg->Clear();
   leg->SetHeader("The Samples");
   leg->AddEntry(quad4PhiHistD02KappaRho,"D^{0}","L");
   quad4PhiHistD02KappaRho->Draw();
   quad4PhiHistD0bar2KappaRho->SetLineColor(kRed+1);
   quad4PhiHistD0bar2KappaRho->SetLineWidth(2);
   d0bar2KappaRhoEntries = quad4PhiHistD0bar2KappaRho->GetEntries();
   quad4PhiHistD0bar2KappaRho->Scale(1.00/d0bar2KappaRhoEntries);
   quad4PhiHistD02KappaRho->GetYaxis()->SetRangeUser(0.,1.25*maximum/d02KappaRhoEntries);
   quad4PhiHistD0bar2KappaRho->Draw("same");
   leg->AddEntry(quad4PhiHistD0bar2KappaRho,"#bar{D}^{0}","L");
   leg->Draw();
   pt1->Clear();
   d0AsymStr.Form("%4.1f\n",100.*D0AB_asymmetry);
   d0AsymErrStr.Form("%4.1f\n",100.*D0AB_asymmetryErr);
   d0barAsymStr.Form("%4.1f\n",100.*D0barAB_asymmetry);
   d0barAsymErrStr.Form("%4.1f\n",100.*D0barAB_asymmetryErr);
   cpAsymStr.Form("%4.1f\n",100.*CPAsymmetry);
   cpAsymErrStr.Form("%4.1f\n",100.*CPAsymmetryErr);
   DiffABStr.Form("%4.1f\n",100.*DiffAB);
   d0Sin2PhiAsymStr.Form("%4.1f\n",100.*D0Sin2Phi_asymmetry);
   d0Sin2PhiAsymErrStr.Form("%4.1f\n",100.*D0Sin2Phi_asymmetryErr);
   d0barSin2PhiAsymStr.Form("%4.1f\n",100.*D0barSin2Phi_asymmetry);
   d0barSin2PhiAsymErrStr.Form("%4.1f\n",100.*D0barSin2Phi_asymmetryErr);
   cpSin2PhiAsymStr.Form("%4.1f\n",100.*Sin2PhiCP_asymmetry);
   cpSin2PhiAsymErrStr.Form("%4.1f\n",100.*Sin2PhiCP_asymmetryErr);
   DiffSin2PhiStr.Form("%4.1f\n",100.*DiffSin2Phi);
   pt1->AddText("asymmetries");
   pt1->AddText("sin(#phi)             sin(2#phi)");
   pt1->AddText("D^{0}:  ( "+d0AsymStr+" #pm "+d0AsymErrStr+")%   ("
         +d0Sin2PhiAsymStr+" #pm "+d0Sin2PhiAsymErrStr+")%");
   pt1->AddText("#bar{D}^{0}:  ( "+d0barAsymStr+" #pm "+d0barAsymErrStr+")%   ("
         +d0barSin2PhiAsymStr+" #pm "+d0barSin2PhiAsymErrStr+")%");
   pt1->AddText("CP:   ( "+cpAsymStr+" #pm "+cpAsymErrStr+")%   ("
         +cpSin2PhiAsymStr+" #pm "+cpSin2PhiAsymErrStr+")%");
   pt1->AddText("D^{0}-#bar{D}^{0}:  ("+DiffABStr+" #pm "+cpAsymErrStr+")%   ("
         +DiffSin2PhiStr+" #pm "+cpSin2PhiAsymErrStr+")%");
   nd0Str.Form("%6.0f\n",nD0);
   nd0barStr.Form("%6.0f\n",nD0bar);
   pt1->AddText("n(D^{0}) = "+nd0Str+"           n(#bar{D}^{0}) = "+nd0barStr);
   pt1->Draw();
   c1.SaveAs("compareQuad4PhiKappaRho.png");
   c1.SetLogy(0);


//  ***  end of KappaRho calculations & plotting  ***



//  
   gStyle->SetOptStat(1111);

   allPhiHistD0bar2KstarRho->Draw();
   c1.SaveAs("allPhiHistD0bar2KstarRho.png");

   mCDforKstar->Draw();
   c1.SaveAs("mCDforKstar.png");

   mCDforLowKPiMass->Draw();
   c1.SaveAs("mCDforLowKPiMass.png");

   mABforRhoZero->Draw();
   c1.SaveAs("mABforRhoZero.png");

   cosVsinPlot->Draw();
   c1.SaveAs("cosVsinPlot.png");

   cosVsinPlotA->Draw();
   c1.SaveAs("cosVsinPlot.png");

   gStyle->SetOptStat(0);
   mABmCD->GetXaxis()->SetTitleSize(0.05);
   mABmCD->GetXaxis()->SetTitleOffset(0.90);
   mABmCD->GetXaxis()->SetLabelFont(62);
   mABmCD->GetXaxis()->SetLabelSize(0.04);
   mABmCD->GetXaxis()->CenterTitle(true);
   mABmCD->SetTitle("m(K#pi)_{low} v. m(#pi^{-}#pi^{+})");
   mABmCD->SetXTitle("mass(K#pi)_{low} [MeV]");
   mABmCD->GetYaxis()->SetTitleSize(0.05);
   mABmCD->GetYaxis()->SetLabelSize(0.04);
   mABmCD->GetYaxis()->SetTitleOffset(0.90);
   mABmCD->GetYaxis()->SetLabelFont(62);
   mABmCD->SetYTitle("m(#pi^{-}#pi^{+}) [MeV]");
   mABmCD->SetLineColor(kBlue);
   mABmCD->SetLineWidth(2);
   mABmCD->Draw("COLZ");
   c1.SetLogy(1);
   c1.SaveAs("mABmCD.png");
   c1.SetLogy(0);

   gPad->SetLogz();
   c1.SaveAs("mABmCD_logColor.png");
   gPad->SetLogz(0);

   Double_t temp = mABmCD->GetMaximum();
   mABmCD->SetMaximum(temp/3.);
   mABmCD->Draw("COLZ");
   c1.SaveAs("mABmCD_capped.png"); 
   mABmCD->SetMaximum(temp);

   mABmCD->GetXaxis()->SetTitleOffset(1.50);
   mABmCD->GetYaxis()->SetTitleOffset(1.50);
   mABmCD->Draw("SURF1");
   c1.SaveAs("mABmCDSurf1.png");


   mADmCB->Draw("COLZ");
   c1.SaveAs("mADmCB.png");

  gStyle->SetOptStat(0);
   mABmAD->GetXaxis()->SetTitleSize(0.05);
   mABmAD->GetXaxis()->SetTitleOffset(0.90);
   mABmAD->GetXaxis()->SetLabelFont(62);
   mABmAD->GetXaxis()->SetLabelSize(0.04);
   mABmAD->GetXaxis()->CenterTitle(true);
   mABmAD->SetTitle("m(K#pi)_{low} v. m(K#pi)_{high}");
   mABmAD->SetXTitle("mass(K#pi)_{low} [MeV]");
   mABmAD->GetYaxis()->SetTitleSize(0.05);
   mABmAD->GetYaxis()->SetLabelSize(0.04);
   mABmAD->GetYaxis()->SetTitleOffset(0.90);
   mABmAD->GetYaxis()->SetLabelFont(62);
   mABmAD->SetYTitle("mass(K#pi)_{high} [MeV]");
   mABmAD->SetLineColor(kBlue);
   mABmAD->SetLineWidth(2);
   mABmAD->Draw("COLZ");
   mABmAD->Draw("COLZ");
   c1.SaveAs("mABmAD.png");
   mABmAD->Write();

   mABmADzoomed->GetXaxis()->SetTitleSize(0.05);
   mABmADzoomed->GetXaxis()->SetTitleOffset(0.90);
   mABmADzoomed->GetXaxis()->SetLabelFont(62);
   mABmADzoomed->GetXaxis()->SetLabelSize(0.04);
   mABmADzoomed->GetXaxis()->CenterTitle(true);
   mABmADzoomed->SetTitle("m(K#pi)_{low} v. m(K#pi)_{high}");
   mABmADzoomed->SetXTitle("mass(K#pi)_{low} [MeV]");
   mABmADzoomed->GetYaxis()->SetTitleSize(0.05);
   mABmADzoomed->GetYaxis()->SetLabelSize(0.04);
   mABmADzoomed->GetYaxis()->SetTitleOffset(0.90);
   mABmADzoomed->GetYaxis()->SetLabelFont(62);
   mABmADzoomed->SetYTitle("mass(K#pi)_{high} [MeV]");
   mABmADzoomed->SetLineColor(kBlue);
   mABmADzoomed->SetLineWidth(2);
   mABmADzoomed->Draw("COLZ");
   mABmADzoomed->Draw("COLZ");
   c1.SaveAs("mABmADzoomed.png");
   mABmADzoomed->Write();

   mABmADzoomed->SetFillColor(kYellow);
   mABmADzoomed->Draw("LEGO1 0");
   c1.SaveAs("mABmADzoomedLego.png");

   mKPimPiPi->Draw("COLZ");
   c1.SaveAs("mKPimPiPi.png");

   mKPimPiPiA->Draw("COLZ");
   c1.SaveAs("mKPimPiPiA.png");

   mKPimPiPi->SetFillColor(kYellow);
   mKPimPiPi->Draw("LEGO1 0");
   c1.SaveAs("mKPimPiPiLego.png");

   mKPimPiPiA->SetFillColor(kYellow);
   mKPimPiPiA->Draw("LEGO1 0");
   c1.SaveAs("mKPimPiPiALego.png");

   mKPimPiPi->Draw("SURF1");
   c1.SaveAs("mKPimPiPiSurf1.png");

   mKPimPiPiA->Draw("SURF1");
   c1.SaveAs("mKPimPiPiASurf1.png");

   mKPimPiPi->Draw("SURF3");
   c1.SaveAs("mKPimPiPiSurf3.png");

   mKPimPiPiA->Draw("SURF3");
   c1.SaveAs("mKPimPiPiASurf3.png");

   KstarPiPiDP1213->Draw("SURF1");
   c1.SaveAs("KstarPiPiDP1213Surf1.png");

   KstarPiPiDP1213->Draw("COLZ");
   c1.SaveAs("KstarPiPiDP1213.png");

   KstarPiPiDP2313->Draw("SURF1");
   c1.SaveAs("KstarPiPiDP2313Surf1.png");

   KstarPiPiDP2313->Draw("COLZ");
   c1.SaveAs("KstarPiPiDP2313.png");

   KstarPiPiDP2312->Draw("SURF1");
   c1.SaveAs("KstarPiPiDP2312Surf1.png");

   KstarPiPiDP2312->Draw("COLZ");
   c1.SaveAs("KstarPiPiDP2312.png");

   sanityPlot->Draw("COLZ");
   c1.SaveAs("sanityPlot.png");  

   cosThetaAHist->Draw();
   c1.SaveAs("cosThetaAHist.png");

   cosThetaCHist->Draw();
   c1.SaveAs("cosThetaCHist.png");

   cosThetaAcosThetaCHist->Draw("COLZ");
   c1.SaveAs("cosThetaAcosThetaCHist.png");

   tAtCD02KstarRho->Draw("COLZ");
   c1.SaveAs("tAtCD02KstarRho.png");

   tAtCD0bar2KstarRho->Draw("COLZ");
   c1.SaveAs("tAtCD0bar2KstarRho.png");

   quad1PhiHistD02KstarRho->Draw();
   c1.SaveAs("quad1PhiHistD02KstarRho.png");

   quad2PhiHistD02KstarRho->Draw();
   c1.SaveAs("quad2PhiHistD02KstarRho.png");

   quad3PhiHistD02KstarRho->Draw();
   c1.SaveAs("quad3PhiHistD02KstarRho.png");

   quad4PhiHistD02KstarRho->Draw();
   c1.SaveAs("quad4PhiHistD02KstarRho.png");

   quad1PhiHistD0bar2KstarRho->Draw();
   c1.SaveAs("quad1PhiHistD0bar2KstarRho.png");

   quad2PhiHistD0bar2KstarRho->Draw();
   c1.SaveAs("quad2PhiHistD0bar2KstarRho.png");

   quad3PhiHistD0bar2KstarRho->Draw();
   c1.SaveAs("quad3PhiHistD0bar2KstarRho.png");

   quad4PhiHistD0bar2KstarRho->Draw();
   c1.SaveAs("quad4PhiHistD0bar2KstarRho.png");

//
   gStyle->SetOptStat(0);

   histDeltaM->GetXaxis()->SetTitleSize(0.06);
   histDeltaM->GetXaxis()->SetTitleOffset(0.75);
   histDeltaM->GetXaxis()->SetLabelFont(62);
   histDeltaM->GetXaxis()->CenterTitle(true);
   histDeltaM->SetTitle("#Delta(M)");
   histDeltaM->SetXTitle("#Delta(M) [MeV]");
   histDeltaM->GetYaxis()->SetTitleSize(0.06);
   histDeltaM->GetYaxis()->SetTitleOffset(0.75);
   histDeltaM->GetYaxis()->SetLabelFont(62);
   histDeltaM->SetYTitle("events per 250 keV");
   histDeltaM->SetLineColor(kBlue);
   histDeltaM->SetLineWidth(2);
   histDeltaM->Draw();
   histDeltaM_selected->SetFillColor(kGreen);
   histDeltaM_selected->SetFillStyle(1001);
   histDeltaM_selected->Draw("same");
   histDeltaM->Draw("same");
   c1.SaveAs("histDeltaM.png");

   d0MassHist->GetXaxis()->SetTitleSize(0.06);
   d0MassHist->GetXaxis()->SetTitleOffset(0.75);
   d0MassHist->GetXaxis()->SetLabelFont(62);
   d0MassHist->GetXaxis()->CenterTitle(true);
   d0MassHist->SetTitle("D^{0} Sample");
   d0MassHist->SetXTitle("mass(K#pi#pi#pi) [MeV]");
   d0MassHist->GetYaxis()->SetTitleSize(0.06);
   d0MassHist->GetYaxis()->SetTitleOffset(0.75);
   d0MassHist->GetYaxis()->SetLabelFont(62);
   d0MassHist->SetYTitle("events per  MeV");
   d0MassHist->SetLineColor(kBlue);
   d0MassHist->SetLineWidth(2);
   d0MassHist->Draw();
   d0MassHistSelected->SetFillColor(kGreen);
   d0MassHistSelected->SetFillStyle(1001);
   d0MassHistSelected->Draw("same");
   d0MassHist->Draw("same");
   c1.SaveAs("d0MassHist.png");

   d0MassHist->Write();  //  this will be written to myOutputFile.root
   d0MassHistSelected->Write();

   d0barMassHist->GetXaxis()->SetTitleSize(0.06);
   d0barMassHist->GetXaxis()->SetTitleOffset(0.75);
   d0barMassHist->GetXaxis()->SetLabelFont(62);
   d0barMassHist->GetXaxis()->CenterTitle(true);
   d0barMassHist->SetTitle("#bar{D}^{0} Sample");
   d0barMassHist->SetXTitle("mass(K#pi#pi#pi) [MeV]");
   d0barMassHist->GetYaxis()->SetTitleSize(0.06);
   d0barMassHist->GetYaxis()->SetTitleOffset(0.75);
   d0barMassHist->GetYaxis()->SetLabelFont(62);
   d0barMassHist->SetYTitle("events per  MeV");
   d0barMassHist->SetLineColor(kBlue);
   d0barMassHist->SetLineWidth(2);
   d0barMassHist->Draw();
   d0barMassHistSelected->SetFillColor(kGreen);
   d0barMassHistSelected->SetFillStyle(1001);
   d0barMassHistSelected->Draw("same");
   d0barMassHist->Draw("same");
   c1.SaveAs("d0barMassHist.png");
   d0barMassHist->Write();
   d0barMassHistSelected->Write();

   nD0 = d0MassHist->GetEntries();
   nD0bar = d0barMassHist->GetEntries();
   d0MassHist->Scale(1./nD0);
   d0MassHist->SetTitle("Compare D and #bar{D}");
   d0MassHist->SetYTitle("fraction per  MeV");
   d0barMassHist->Scale(1./nD0bar);
   d0barMassHist->SetLineColor(kRed+1);
   leg->Clear();
   leg->SetHeader("The Samples");
   leg->AddEntry(d0MassHist,"D^{0}","L");
   leg->AddEntry(d0barMassHist,"#bar{D}^{0}","L");
   d0MassHist->Draw();
   leg->Draw();

   d0MassHistSelected->Scale(1./nD0);
   d0MassHistSelected->SetFillColor(kGreen);
   d0MassHistSelected->SetFillStyle(1001);
   d0MassHistSelected->Draw("same");
   d0barMassHist->Draw("same");
   d0MassHist->Draw("same");
 
   nd0Str.Form("%6.0f\n",nD0);
   nd0barStr.Form("%6.0f\n",nD0bar);
   pt2->AddText("n(D^{0}) = "+nd0Str);
   pt2->AddText("n(#bar{D}^{0}) = "+nd0barStr);
   pt2->Draw();
   c1.SaveAs("D_Dbar_Comparison.png");
   c1.SetLogy(1);
   c1.SaveAs("D_Dbar_ComparisonLogScale.png");
   c1.SetLogy(0);

   d0PhaseSpace->Draw("COLZ");
   c1.SaveAs("d0PhaseSpace.png");

   d0barPhaseSpace->Draw("COLZ");
   c1.SaveAs("d0barPhaseSpace.png");

   d0PhaseSpace->Sumw2();
   d0barPhaseSpace->Sumw2();
   rat->SetName("Ratio");
   rat->Divide(d0PhaseSpace,d0barPhaseSpace,1.,1.,"B");
   rat->Draw("COLZ");
   c1.SaveAs("phaseSpaceRatio.png");

   rat->SetFillColor(kYellow);
   rat->Draw("LEGO1 0");
   c1.SaveAs("phaseSpaceRatioLego.png");

    mABD_corner->Draw();
    c1.SaveAs("mABD_corner.png");
    mABD_corner->Write();

    mPiPiForLowKPiPi->GetXaxis()->SetTitleSize(0.05);
    mPiPiForLowKPiPi->GetXaxis()->SetTitleOffset(0.90);
    mPiPiForLowKPiPi->GetXaxis()->SetLabelFont(62);
    mPiPiForLowKPiPi->GetXaxis()->SetLabelSize(0.04);
    mPiPiForLowKPiPi->GetXaxis()->CenterTitle(true);
    mPiPiForLowKPiPi->SetTitle("m(#pi^{+}#pi^{+}) for low M(K^{-}#pi^{+}#pi^{+})}");
    mPiPiForLowKPiPi->SetXTitle("mass(#pi^{+}#pi^{+})     [MeV]");
    mPiPiForLowKPiPi->GetYaxis()->SetTitleSize(0.05);
    mPiPiForLowKPiPi->GetYaxis()->SetLabelSize(0.04);
    mPiPiForLowKPiPi->GetYaxis()->SetTitleOffset(0.90);
    mPiPiForLowKPiPi->GetYaxis()->SetLabelFont(62);
    mPiPiForLowKPiPi->SetYTitle(" events per 5 MeV");
    mPiPiForLowKPiPi->SetLineColor(kBlue);
    mPiPiForLowKPiPi->SetLineWidth(2);
    mPiPiForLowKPiPi->Draw();
    c1.SaveAs("mPiPiForLowKPiPi.png");

    mABmCDForLowKPiPi->GetXaxis()->SetTitleSize(0.05);
    mABmCDForLowKPiPi->GetXaxis()->SetTitleOffset(0.90);
    mABmCDForLowKPiPi->GetXaxis()->SetLabelFont(62);
    mABmCDForLowKPiPi->GetXaxis()->SetLabelSize(0.04);
    mABmCDForLowKPiPi->GetXaxis()->CenterTitle(true);
    mABmCDForLowKPiPi->SetTitle("m(K#pi)_{low} v. m(K#pi)_{high}");
    mABmCDForLowKPiPi->SetXTitle("mass(K#pi)_{low} [MeV]");
    mABmCDForLowKPiPi->GetYaxis()->SetTitleSize(0.05);
    mABmCDForLowKPiPi->GetYaxis()->SetLabelSize(0.04);
    mABmCDForLowKPiPi->GetYaxis()->SetTitleOffset(0.90);
    mABmCDForLowKPiPi->GetYaxis()->SetLabelFont(62);
    mABmCDForLowKPiPi->SetYTitle("mass(#pi^{-}#pi^{+})_{high} [MeV]");
    mABmCDForLowKPiPi->SetLineColor(kBlue);
    mABmCDForLowKPiPi->SetLineWidth(2);
    mABmCDForLowKPiPi->Draw("COLZ");
    c1.SaveAs("mABmCDForLowKPiPi.png");

    mABmADForKstarRho->Draw("COLZ");
    c1.SaveAs("mABmADForKstarRho.png");

    mABmADForKstarF0->Draw("COLZ");
    c1.SaveAs("mABmADForKstarF0.png");

    mABmADForKappaRho->Draw("COLZ");
    c1.SaveAs("mABmADForKappaRho.png");

    piMinusEnergyHist->Draw();
    c1.SaveAs("piMinusEnergyHist.png");
    piMinusEnergyHist->Write();

    piMinusEnergyHistD0->Draw();
    c1.SaveAs("piMinusEnergyHistD0.png");
    piMinusEnergyHistD0->Write();

    piMinusEnergyHistD0bar->Draw();
    c1.SaveAs("piMinusEnergyHistD0bar.png");
    piMinusEnergyHistD0bar->Write();

    piPlusBEnergyHist->Draw();
    c1.SaveAs("piPlusBEnergyHist.png");
    piPlusBEnergyHist->Write();

    piPlusBEnergyHistD0->Draw();
    c1.SaveAs("piPlusBEnergyHistD0.png");
    piPlusBEnergyHistD0->Write();

    piPlusBEnergyHistD0bar->Draw();
    c1.SaveAs("piPlusBEnergyHistD0bar.png");
    piPlusBEnergyHistD0bar->Write();

    piPlusDEnergyHist->Draw();
    c1.SaveAs("piPlusDEnergyHist.png");
    piPlusDEnergyHist->Write();

    piPlusDEnergyHistD0->Draw();
    c1.SaveAs("piPlusDEnergyHistD0.png");
    piPlusDEnergyHistD0->Write();

    piPlusDEnergyHistD0bar->Draw();
    c1.SaveAs("piPlusDEnergyHistD0bar.png");
    piPlusDEnergyHistD0bar->Write();

    TH1D  piPlusEnergyHist = *piPlusBEnergyHist + *piPlusDEnergyHist;
    piPlusEnergyHist.SetNameTitle("piPlusEnergyHist","sum of piPlusB and piPlusD");
    piPlusEnergyHist.Draw();
    c1.SaveAs("piPlusEnergyHist.png");
    piPlusEnergyHist.Write();

    TH1D  piPlusEnergyHistD0 = *piPlusBEnergyHistD0 + *piPlusDEnergyHistD0;
    piPlusEnergyHistD0.SetNameTitle("piPlusEnergyHistD0","sum of piPlusB and piPlusD");
    piPlusEnergyHistD0.Draw();
    c1.SaveAs("piPlusEnergyHistD0.png");
    piPlusEnergyHistD0.Write();

    TH1D  piPlusEnergyHistD0bar = *piPlusBEnergyHistD0bar + *piPlusDEnergyHistD0bar;
    piPlusEnergyHistD0bar.SetNameTitle("piPlusEnergyHistD0bar","sum of piPlusB and piPlusD");
    piPlusEnergyHistD0bar.Draw();
    c1.SaveAs("piPlusEnergyHistD0bar.png");
    piPlusEnergyHistD0bar.Write();

    KMinusEnergyHist->Draw();
    c1.SaveAs("KMinusEnergyHist.png");
    KMinusEnergyHist->Write();

    KMinusEnergyHistD0->Draw();
    c1.SaveAs("KMinusEnergyHistD0.png");
    KMinusEnergyHistD0->Write();

    KMinusEnergyHistD0bar->Draw();
    c1.SaveAs("KMinusEnergyHistD0bar.png");
    KMinusEnergyHistD0bar->Write();

    KmPipPipAllHist->Draw();
    c1.SaveAs("KmPipPipAllHist.png");

    KmPipPipNotKstarRhoCand->Draw();
    c1.SaveAs("KmPipPipNostKstarRhoCand.png");

    cornerKMinusEnergyHist->Draw();
    cornerKMinusEnergyHist->Write();
    c1.SaveAs("cornerKMinusEnergyHist.png");

    cornerPiMinusEnergyHist->Draw();
    cornerPiMinusEnergyHist->Write();
    c1.SaveAs("cornerPiMinusEnergyHist.png");

    cornerPiPlusEnergyHist->Draw();
    cornerPiPlusEnergyHist->Write();
    c1.SaveAs("cornerPiPlusEnergyHist.png");

    cornerKMinusPiMinusMassHist->Draw();
    cornerKMinusPiMinusMassHist->Write();
    c1.SaveAs("cornerKMinusPiMinusMassHist.png");

    cornerKMinusPiPlusMassHist->Draw();
    cornerKMinusPiPlusMassHist->Write();
    c1.SaveAs("cornerKMinusPiPlusMassHist.png");

    cornerPiMinusPiPlusMassHist->Draw();
    cornerPiMinusPiPlusMassHist->Write();
    c1.SaveAs("cornerPiMinusPiPlusMassHist.png");

    cornerPiPlusPiPlusMassHist->Draw();
    cornerPiPlusPiPlusMassHist->Write();
    c1.SaveAs("cornerPiPlusPiPlusMassHist.png");

    cornerKMinusPzHist->Draw();
    cornerKMinusPzHist->Write();
    c1.SaveAs("cornerKMinusPzHist.png");

    cornerPiMinusPzHist->Draw();
    cornerPiMinusPzHist->Write();
    c1.SaveAs("cornerPiMinusPzHist.png");

    cornerPiPlusPzHist->Draw();
    cornerPiPlusPzHist->Write();
    c1.SaveAs("cornerPiPlusPzHist.png");

    cornerKPiPiMassSqHist->Draw();
    cornerKPiPiMassSqHist->Write();
    c1.SaveAs("cornerKPiPiMassSqHist.png");    

    KPiPiMassSqHist->Draw();
    KPiPiMassSqHist->Write();
    c1.SaveAs("KPiPiMassSqHist.png");    

    cornerKminusHelictyCosineHist->Draw();
    cornerKminusHelictyCosineHist->Write();
    c1.SaveAs("cornerKminusHelictyCosineHist.png");


    myOutputFile->Write();
    myOutputFile->Close();
}
