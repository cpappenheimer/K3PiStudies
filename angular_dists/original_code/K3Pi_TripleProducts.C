#define K3Pi_TripleProducts_cxx
#include "K3Pi_TripleProducts.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TSystem.h>
#include <TLorentzVector.h>
#include <TVector3.h>
#include <iostream>

void K3Pi_TripleProducts::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L K3Pi_TripleProducts.C
//      Root > K3Pi_TripleProducts t
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
TH1 * strippingLevelMassHist   = new TH1D("stripping level M","M(K3Pi)",120,1800.,1920.);
TH1 * cutsAMassHist            = new TH1D("cutsA Mass hist","cut on DeltaM",120,1800.,1920.);
TH1 * massHistB                = new TH1D("mass hist","cuts B",120,1800.,1920.);
TH1 * KminusKprobHist          = new TH1D("K ProbNNk","cutsA",100,0.,1.);
TH1 * massHistAlowKprob        = new TH1D("low KProb","cutsA",120,1800.,1920.);
TH1 * massHistAhighKprob        = new TH1D("high KProb","cutsA",120,1800.,1920.);
Double_t pi = TMath::Pi();
TH1 * allPhiHist                = new TH1D("phi","cutsB; low-mass K,pi",100,0.,2.0*pi);
TH1 * allPhiAHist                = new TH1D("phi","cutsB; low-mass K,pi",100,0.,2.0*pi);
TH1 * allPhiHistD0              = new TH1D("phi for D0","cutsB; low-mass K,pi",100,0.,2.0*pi);
TH1 * allPhiHistD02KstarRho     = new TH1D("phi for D02KstarRho","cutsB; low-mass K,pi",100,0.,2.0*pi);
TH1 * allPhiHistD0bar          = new TH1D("phi for D0bar","cutsB high-mass K,pi",100,0.,2.0*pi);
TH1 * allPhiHistD0bar2KstarRho = new TH1D("phi for D0bar2KstarRho","cutsB high-mass K,pi",100,0.,2.0*pi);
TH2D * cosVsinPlot              = new TH2D("cosine v sine","sanity plot",50,-1.5,1.5,50,-1.5,1.5);
TH2D * cosVsinPlotA             = new TH2D("cosine v sine","sanity plotA ",50,-1.5,1.5,50,-1.5,1.5);
TH2D * mABmCD                   = new TH2D("mAB v mCD","passing cutsB",50,550,1550,50,200.,1300.);
TH2D * mADmCB                   = new TH2D("mAD v mCB","passing cutsB",50,550,1550,50,200.,1300.);
TH2D * KstarPiPiDP1213          = new TH2D("K*,pi-,pi+ DP, s12,s13","K* +- 50 MeV",50,1.0,2.8,50,1.0,2.8);
TH2D * KstarPiPiDP2313          = new TH2D("K*,pi-,pi+ DP, s23,s13","K* +- 50 MeV",50,0.0,1.2,50,1.0,2.8);
TH2D * KstarPiPiDP2312          = new TH2D("K*,pi-,pi+ DP, s23,s12","K* +- 50 MeV",50,0.0,1.2,50,1.0,2.8);
TH1  * mCDforKstar              = new TH1D("for Kstar region","pi,pi mass",110,200.,1300.);
TH1  * mCDforLowKPiMass         = new TH1D("for low K,pi","pi,pi mass",110,200.,1300.);
TH1  * mABforRhoZero            = new TH1D("for Rho region","K,pi mass",70,550,1250);
TH2D * mABmAD                   = new TH2D("mAB v mAD","passing cutsB",50,550,1550,50,550.,1550.);
TH2D * mKPimPiPi                = new TH2D("mKPi v mPiPi","passing cutsB",50,550,1550,50,200.,1300.);
TH2D * mKPimPiPiA               = new TH2D("at higher decay time","mKPi v mPiPi",50,550,1550,50,200.,1300.);
TH2D * sanityPlot               = new TH2D("for all events","tripleProduct v phi",100,-600.,600.,100,0.,2.0*pi);
TH1D * cosThetaAHist            = new TH1D("cosThetaA, cuts B","all mABmCD",100,-1.,1.);
TH1D * cosThetaCHist            = new TH1D("cosThetaC, cuts B","all mABmCD",100,-1.,1.);
TH2D * cosThetaAcosThetaCHist   = new TH2D("cosThetaA v cosThetaC","cutsB",100,-1.,1.,100,-1.,1.);
TH2D * tAtCD02KstarRho          = new TH2D("cosThetaA v cosThetaC for D0","cutsB",100,-1.,1.,100,-1.,1.);
TH2D * tAtCD0bar2KstarRho       = new TH2D("cosThetaA v cosThetaC for D0bar","cutsB",100,-1.,1.,100,-1.,1.);



   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
//   for (Long64_t jentry=0; jentry<100000;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

//  begin per event code

      Double_t kProbCut = 0.10;

      strippingLevelDeltaMHist->Fill(Dstar_MM-D0_MM);
      strippingLevelMassHist->Fill(D0_MM);

      Double_t DeltaM = Dstar_MM-D0_MM;

      bool cutsA = false;
      if ( (DeltaM > 144.5) && (DeltaM < 146.5) ) {
        cutsA = true;
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
      
      bool cutsB = false;
      if (cutsA && (Kminus_ProbNNk>kProbCut) && D0_M>1850 && D0_M<1885) {
        cutsB = true;
        massHistB->Fill(D0_MM);
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
      TLorentzVector pABD_4vec = pA_4vec + pB_4vec + pD_4vec;
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

      if (D0_TAU > 0.0010) {
        mKPimPiPiA->Fill(pAB_4vec.M(),pCD_4vec.M());
      }

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

      if (jentry<20) {
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

        Double_t cosThetaA = paPrimeZ/sqrt(paPrimeX*paPrimeX+paPrimeY*paPrimeY+paPrimeZ*paPrimeZ);
        Double_t cosThetaC = pcPrimeZ/sqrt(pcPrimeX*pcPrimeX+pcPrimeY*pcPrimeY+pcPrimeZ*pcPrimeZ);

        cosThetaAHist->Fill(cosThetaA);
        cosThetaCHist->Fill(cosThetaC);
        cosThetaAcosThetaCHist->Fill(cosThetaA,cosThetaC);

     if (jentry < 20) {
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
      if (abs(mAB-892)<35 && abs(mCD-775<100)) {
        if (D0_ID>0) {
          allPhiHistD02KstarRho->Fill(phi);
          tAtCD02KstarRho->Fill(cosThetaA,cosThetaC);
        } else {
          allPhiHistD0bar2KstarRho->Fill(phi);
          tAtCD0bar2KstarRho->Fill(cosThetaA,cosThetaC);
        }
      }

//  now, repeat using the high-mass K,pi pair to define the reference plane

      TLorentzVector pAD_4vec = pA_4vec + pD_4vec;
      TLorentzVector pCB_4vec = pC_4vec + pB_4vec;
      mADmCB->Fill(pAD_4vec.M(),pCB_4vec.M());
      mKPimPiPi->Fill(pAD_4vec.M(),pCB_4vec.M());
      mABmAD->Fill(pAB_4vec.M(),pAD_4vec.M());
      if (D0_TAU > 0.0010) {
        mKPimPiPiA->Fill(pAD_4vec.M(),pCB_4vec.M());
      }

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

      }  //  end of if (cutsB) { .... 
      
   }  // end of per event code

   TCanvas c1;

   strippingLevelDeltaMHist->Draw();
   c1.SaveAs("strippingLevelDeltaMHist.png");

   strippingLevelMassHist->Draw();
   c1.SaveAs("strippingLevelMassHist.png");

   cutsAMassHist->Draw();
   c1.SaveAs("cutsAMassHist.png");

   massHistB->Draw();
   c1.SaveAs("massHistB.png");

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
   allPhiHistD02KstarRho->Scale(1.00/d02KstarRhoEntries);
   allPhiHistD02KstarRho->Draw();
   allPhiHistD0bar2KstarRho->SetLineColor(kRed+1);
   allPhiHistD0bar2KstarRho->SetLineWidth(2);
   Double_t d0bar2KstarRhoEntries = allPhiHistD0bar2KstarRho->GetEntries();
   allPhiHistD0bar2KstarRho->Scale(1.00/d0bar2KstarRhoEntries);
   allPhiHistD0bar2KstarRho->Draw("same");
   c1.SetLogy(0);
   c1.SaveAs("comparePhiKstarRho.png");
   c1.SetLogy(0);

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

   mABmCD->Draw("COLZ");
   c1.SaveAs("mABmCD.png");

   mABmCD->Draw("SURF1");
   c1.SaveAs("mABmCDSurf1.png");


   mADmCB->Draw("COLZ");
   c1.SaveAs("mADmCB.png");

   mABmAD->Draw("COLZ");
   c1.SaveAs("mABmAD.png");

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


}
